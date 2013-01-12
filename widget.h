#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>
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
    bool isStarted;
    bool isPaused;
    unsigned int lap;
    void inline appendLog(const QString &log);

};

#endif // WIDGET_H
