#include "widget.h"
#include <QApplication>
#include <QtPlugin>

Q_IMPORT_PLUGIN(qico)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    
    return a.exec();
}
