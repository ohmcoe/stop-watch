/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcdTime;
    QLabel *logoHWC;
    QTextBrowser *txtLog;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnStop;
    QPushButton *btnStart;
    QPushButton *btnSplit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(631, 401);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/stop_watch_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        lcdTime = new QLCDNumber(Widget);
        lcdTime->setObjectName(QStringLiteral("lcdTime"));
        lcdTime->setGeometry(QRect(10, 10, 601, 141));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setItalic(true);
        lcdTime->setFont(font);
        lcdTime->setFrameShape(QFrame::NoFrame);
        lcdTime->setDigitCount(9);
        lcdTime->setSegmentStyle(QLCDNumber::Flat);
        lcdTime->setProperty("value", QVariant(8.88889e+08));
        lcdTime->setProperty("intValue", QVariant(888888888));
        logoHWC = new QLabel(Widget);
        logoHWC->setObjectName(QStringLiteral("logoHWC"));
        logoHWC->setGeometry(QRect(240, 320, 151, 71));
        logoHWC->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
        logoHWC->setScaledContents(true);
        txtLog = new QTextBrowser(Widget);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        txtLog->setGeometry(QRect(10, 210, 611, 101));
        txtLog->setOpenLinks(false);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 160, 611, 41));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnStop = new QPushButton(layoutWidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btnStop, 0, 1, 1, 1);

        btnStart = new QPushButton(layoutWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        sizePolicy1.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btnStart, 0, 0, 1, 1);

        btnSplit = new QPushButton(layoutWidget);
        btnSplit->setObjectName(QStringLiteral("btnSplit"));
        sizePolicy1.setHeightForWidth(btnSplit->sizePolicy().hasHeightForWidth());
        btnSplit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(btnSplit, 0, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Stop Watch", Q_NULLPTR));
        logoHWC->setText(QString());
        btnStop->setText(QApplication::translate("Widget", "Stop", Q_NULLPTR));
        btnStart->setText(QApplication::translate("Widget", "Start", Q_NULLPTR));
        btnSplit->setText(QApplication::translate("Widget", "Split (Lap)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
