#include "mainwindow.h"

#include <QApplication>
#include "devicesview.h"
#include "device.h"
#include <QDebug>
#include "detailsdialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow  wnd;
    wnd.show();
    return a.exec();
}
