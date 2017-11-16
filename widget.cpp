#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Variable Default
    isStarted = false;
    isPaused = false;
    lap = 0;
    pauseCount = 0;
    totalPauseCount = 0;

    // Construct new objects
    sw = new StopWatch(0);
    refresher = new QTimer(0);

    // Disable UI components
    ui->btnStop->setEnabled(false);
    ui->btnSplit->setEnabled(false);

    // Connect the signal slot
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(start()));
    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->btnSplit, SIGNAL(clicked()), this, SLOT(split()));
    connect(refresher, SIGNAL(timeout()), this, SLOT(refresh()));

    // Add shortcut
    startPauseShortcut = new QShortcut(QKeySequence("A"), this);
    stopShortcut = new QShortcut(QKeySequence("S"), this);
    splitShortcut = new QShortcut(QKeySequence("D"), this);
    connect(startPauseShortcut, SIGNAL(activated()), ui->btnStart, SLOT(click()));
    connect(stopShortcut, SIGNAL(activated()), ui->btnStop, SLOT(click()));
    connect(splitShortcut, SIGNAL(activated()), ui->btnSplit, SLOT(click()));

    // Start display refresher
    refresher->start(1);
}

void Widget::start()
{
    if (!isStarted)
    {
        // Clear the log
        ui->txtLog->clear();

        // Log the start event
        appendLog("Started");

        // Configure the UI
        ui->btnStart->setText("Pause");
        ui->btnStop->setEnabled(true);
        ui->btnSplit->setEnabled(true);

        // Reset the counters
        lap = 0;
        pauseCount = 0;
        totalPauseCount = 0;

        // Flag as started
        isStarted = true;

        // GO !!
        sw->start();
    }
    else if (!isPaused)
    {
        // Pause the time ASAP
        sw->pause();

        // Increment the pause count
        pauseCount++;

        // Log the pause event
        appendLog("Paused");

        // Configure the UI
        ui->btnStart->setText("Unpause");
        ui->btnStop->setEnabled(false);
        ui->btnSplit->setEnabled(false);

        // Flag as paused
        isPaused = true;
    }
    else
    {
        // Unpause
        sw->unpause();

        // Configure the UI
        ui->btnStart->setText("Pause");
        ui->btnStop->setEnabled(true);
        ui->btnSplit->setEnabled(true);

        // Flag as not paused
        isPaused = false;
    }
}

void Widget::stop()
{
    QString log;

    // Trig the stop of StopWatch ASAP
    sw->stop();

    // Only one lap
    if (lap < 1)
        log = "Stopped: " + sw->getOverallTime();

    // Multi-laps
    else
        log = "Last Lap: " + sw->getOverallTime() + " (+" + sw->getCurrentLapTime() + ")";

    // Log the pause count (if available)
    if (pauseCount > 0)
        log += " with " + QString::number(pauseCount) + " pauses";

    appendLog(log);

    // Display the total pause count (if available)
    if (totalPauseCount > 0)
        appendLog("Total pauses: " + QString::number(totalPauseCount));

    // Configure UI
    ui->btnStart->setText("Start");
    ui->btnStop->setEnabled(false);
    ui->btnSplit->setEnabled(false);


    // Reset the started flag
    isStarted = false;
}

void Widget::split()
{
    QString overallTime;
    QString currentLapTime;
    QString log;

    // Save the overallTime
    overallTime = sw->getOverallTime();

    // Split
    sw->split();

    // Get the last lap time
    currentLapTime = sw->getLapTime(lap);

    // Increment the lap counter
    lap++;

    // Log the overall time and lap time
    log = "Lap " + QString::number(lap) + ": " + overallTime + " (+" + currentLapTime + ")";

    // Log the pause count (if available)
    if (pauseCount > 0)
        log += " with " + QString::number(pauseCount) + " pauses";

    // Accumulate pause count
    totalPauseCount += pauseCount;

    // Reset pause counter
    pauseCount = 0;

    appendLog(log);
}

void Widget::refresh()
{
    ui->lcdTime->display(sw->getOverallTime());
}

Widget::~Widget()
{
    delete sw;
    delete refresher;
    delete ui;
}

void inline Widget::appendLog(const QString &log)
{
    ui->txtLog->append(log);
}
