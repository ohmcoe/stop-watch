#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Initial new time object
    time = new QTime();

    // Initial display refresher
    refresher = new QTimer(this);
    connect(refresher, SIGNAL(timeout()), this, SLOT(refresh()));

    // Reset the display
    ui->lcdTime->display("00:00.000");

    // Connect the UI components to our slots
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(start()));
    connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(ui->btnSplit, SIGNAL(clicked()), this, SLOT(split()));

    // Stop the refresher
    refresher->stop();
}

void Widget::start()
{
    // Reset lap counter
    lap = 0;

    // Clear Log
    ui->txtLog->clear();

    // Log the start time
    ui->txtLog->append("Start");

    // Restart the time
    time->restart();

    // Start display refresher
    refresher->start();
}

void Widget::stop()
{
    QString *overallTime = NULL;
    QString *elapsedTime = NULL;

    // Save the elapsed time as fast as possible
    int overall = time->elapsed();

    // Calculate the elapsed time
    overallTime = fromMs(overall);

    // Stop the timer
    refresher->stop();

    // Increment the lap counter
    lap++;

    if (lap > 1)
    {
        // Log the lap's elapsed time
        elapsedTime = fromMs(overall - lastLapElapsed);
        ui->txtLog->append("Last Lap: " + *overallTime + " (+" + *elapsedTime + ")");

        // TODO: Best Run
        // TODO: Average Run
    }
    else
    {
        // Log the stop time
        ui->txtLog->append("Stop: " + *overallTime);
    }

    // Collect garbage
    if (overallTime != NULL)
        delete overallTime;
    if (elapsedTime != NULL)
        delete elapsedTime;
}

void Widget::split()
{
    QString *overallTime = NULL;
    QString *elapsedTime = NULL;

    // Save the elapsed time as fast as possible
    int overall = time->elapsed();

    // Increment the lap counter
    lap++;

    // Create a log line
    QString log;
    log = "Lap " + QString::number(lap) + ": ";

    // Log the overall time
    overallTime = fromMs(overall);
    log += *overallTime;

    if (lap > 1)
    {
        // Log the lap's elapsed time
        elapsedTime = fromMs(overall - lastLapElapsed);
        log += " (+" + *elapsedTime + ")";
    }

    // Display the log
    ui->txtLog->append(log);

    // Save the lap's elapsed time
    lastLapElapsed = overall;

    // Collect Garbage
    if (overallTime != NULL)
        delete overallTime;
    if (elapsedTime != NULL)
        delete elapsedTime;
}

void Widget::refresh()
{
    QString *elapsedTime = NULL;

    // Calculate the elapsed time
    elapsedTime = fromMs(time->elapsed());

    // Display
    ui->lcdTime->display(*elapsedTime);

    // Collect garbage
    if (elapsedTime != NULL)
        delete elapsedTime;
}

QString* Widget::fromMs(int ms)
{
    // Derive all time components from msecs
    int s = ms / 1000; ms %= 1000;
    int m = s / 60; s %= 60;

    // Convert the time to formatted text
    QString *elapsedTime;
    elapsedTime = new QString();
    elapsedTime->sprintf("%02d:%02d.%03d", m, s, ms);

    return elapsedTime;
}

Widget::~Widget()
{
    // Time object has no parent, delete it
    delete time;

    delete ui;
}
