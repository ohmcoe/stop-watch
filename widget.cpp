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

    // Start display refresher
    refresher->start(1);
}

void Widget::start()
{
    if (!isStarted)
    {
        // Log the start event
        appendLog("Started");

        // Configure the UI
        ui->btnStart->setText("Pause");
        ui->btnStop->setEnabled(true);
        ui->btnSplit->setEnabled(true);

        // Reset the lap counter
        lap = 0;

        // Flag as started
        isStarted = true;

        // GO !!
        sw->start();
    }
    else if (!isPaused)
    {
        // Pause the time ASAP
        sw->pause();

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
    sw->stop();

    if (lap < 1)
        appendLog("Stopped: " + sw->getOverallTime());
    else
        appendLog("Last Lap: " + sw->getOverallTime() + " (+" + sw->getCurrentLapTime() + ")");

    ui->btnStart->setText("Start");
    ui->btnStop->setEnabled(false);
    ui->btnSplit->setEnabled(false);

    isStarted = false;
}

void Widget::split()
{
    QString overallTime;
    QString currentLapTime;

    // Save the overallTime
    overallTime = sw->getOverallTime();

    // Split
    sw->split();

    // Get the last lap time
    currentLapTime = sw->getLapTime(lap);

    // Increment the lap counter
    lap++;

    // Log the overall time and lap time
    appendLog("Lap " + QString::number(lap) + ": " + overallTime + " (+" + currentLapTime + ")");
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
