#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    ui->frame->layout()->setAlignment(Qt::AlignTop);
    this->dlg=new DetailsDialog(this);

    this->setWindowFlags(Qt::FramelessWindowHint|
                         Qt::Tool);

    m_cntr = new QDevicesController();
    m_cntr->addToBase(Device("Обновление устройства DTYU4656",
                             "32.578.11.0.1",
                             QDate::fromString("21.06.2022","dd.MM.yyyy"),
                             "Какое то описание прошивки может быть длинным в несколько строчек текста"
                             "расположенном тут",
                             "rtyjghngbERTYJGHBvvcbgxR578765434fdgHJHnbvcxesdtfyghbv"));
    m_cntr->addToBase(Device("Обновление устройства DTYU4656",
                             "32.578.11.0.1",
                             QDate::fromString("21.06.2022","dd.MM.yyyy"),
                             "Какое то описание прошивки может быть длинным в несколько строчек текста"
                             "расположенном тут",
                             "rtyjghngbERTYJGHBvvcbgxR578765434fdgHJHnbvcxesdtfyghbv"));
    m_cntr->addToBase(Device("Обновление устройства DTYU4656",
                             "32.578.11.0.1",
                             QDate::fromString("21.06.2022","dd.MM.yyyy"),
                             "Какое то описание прошивки может быть длинным в несколько строчек текста"
                             "расположенном тут",
                             "rtyjghngbERTYJGHBvvcbgxR578765434fdgHJHnbvcxesdtfyghbv"));
    m_cntr->toListWidget(this);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_cntr;
    delete dlg;
}

QListWidget *MainWindow::getListWidget()
{
    return ui->listWidget;
}


void MainWindow::on_hlpBtn_clicked()
{
    QApplication::quit();
}

void MainWindow::on_show_details(const QString &qs)
{
    dlg->setDetailText(qs);
    dlg->show();
}


