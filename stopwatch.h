#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QThread>
#include <vector>

using std::vector;

class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = 0);
    ~StopWatch();
    bool isStarted();
    bool isPaused();
    void start();
    void stop();
    void pause();
    void unpause();
    void split();
    unsigned int numberOfLaps();
    QString getOverallTime();
    QString getCurrentLapTime() const;
    QString getLapTime(unsigned int lap) const;
    
signals:
    
public slots:
    
private:
    QTime time;
    QTime lapTime;
    QTime pauseTime;

    int overallTime;
    int overallPause;
    int lapPause;

    vector<int> elapsedTime;
    bool _isStarted;
    bool _isPaused;

    QString fromMSecs(int ms) const;

};

#endif // STOPWATCH_H
