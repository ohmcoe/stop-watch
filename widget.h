#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QShortcut>
#include "stopwatch.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void start();
    void stop();
    void split();
    void refresh();

private:
    Ui::Widget *ui;
    StopWatch *sw;
    QTimer *refresher;
    QShortcut *startPauseShortcut;
    QShortcut *stopShortcut;
    QShortcut *splitShortcut;
    bool isStarted;
    bool isPaused;
    unsigned int lap;
    unsigned int pauseCount;
    unsigned int totalPauseCount;
    void inline appendLog(const QString &log);

};

#endif // WIDGET_H
