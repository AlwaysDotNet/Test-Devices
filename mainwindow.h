#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qdevicescontroller.h"
#include "detailsdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QDevicesController;
class DetailsDialog;//Использование диалогово окна
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QListWidget *getListWidget();
public slots:
    void on_hlpBtn_clicked();//Выход
    void on_show_details(const QString &qs);//Вывод данных

private:
    Ui::MainWindow *ui;
    QDevicesController *m_cntr;//Контроллер
    DetailsDialog *dlg;//Диаологовое окно

};
#endif // MAINWINDOW_H
