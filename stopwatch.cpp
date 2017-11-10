#include "stopwatch.h"

// Constructor
StopWatch::StopWatch(QObject *parent) :
    QObject(parent)
{
    overallTime = 0;
    overallPause = 0;
    lapPause = 0;

    _isStarted = false;
    _isPaused = false;
}

// Destructor
StopWatch::~StopWatch()
{
    elapsedTime.clear();
}

// isStarted()
bool StopWatch::isStarted()
{ return _isStarted; }

// isPaused()
bool StopWatch::isPaused()
{ return _isPaused; }

// Start the timer
void StopWatch::start()
{
    if (!isStarted())
    {
        time.restart();
        lapTime.restart();

        // Initial all variables
        overallTime = 0;
        overallPause = 0;
        lapPause = 0;

        // Set the start flag
        _isStarted = true;
    }
}

// Stop the timer
void StopWatch::stop()
{
    if (isStarted())
    {
        // Save overall time
        overallTime = time.elapsed();

        // Reset flag
        _isStarted = false;
    }
}

// Split
void StopWatch::split()
{
    int currentLapTime;

    // Save current lap time
    currentLapTime = lapTime.elapsed();

    // Restart the lap time
    lapTime.restart();

    // Store
    elapsedTime.push_back(currentLapTime - lapPause);

    // Manage the pause time
    overallPause += lapPause;
    lapPause = 0;
}

void StopWatch::pause()
{
    if (!isPaused())
    {
        pauseTime.restart();
        _isPaused = true;
    }
}

void StopWatch::unpause()
{
    if (isPaused())
    {
        lapPause += pauseTime.elapsed();
        _isPaused = false;
    }
}

QString StopWatch::getOverallTime()
{
    if (_isStarted)
        overallTime = time.elapsed();

    if (_isPaused)
        return fromMSecs(overallTime - overallPause - lapPause - pauseTime.elapsed());
    else
        return fromMSecs(overallTime - overallPause - lapPause);
}

QString StopWatch::getCurrentLapTime() const
{
    if (_isPaused)
        return fromMSecs(lapTime.elapsed() - lapPause - pauseTime.elapsed());
    else
        return fromMSecs(lapTime.elapsed() - lapPause);
}

QString StopWatch::getLapTime(unsigned int lap) const
{
    if (lap < elapsedTime.size())
        return fromMSecs(elapsedTime[lap]);
    else
        return QString("00:00.000");
}

QString StopWatch::fromMSecs(int ms) const
{
    static QString elapsedTime;

    // Derive all time components from msecs
    int s = ms / 1000; ms %= 1000;
    int m = s / 60; s %= 60;

    // Convert the time to formatted text
    elapsedTime.sprintf("%02d:%02d.%03d", m, s, ms);

    return elapsedTime;
}
