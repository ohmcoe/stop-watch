#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>

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
    QTime *time;
    QTimer *timer;
    QTimer *refresher;
    unsigned int lap;
    int lastLapElapsed;
    QString *fromMs(int ms);

};

#endif // WIDGET_H
