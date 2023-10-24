#ifndef QDEVICESCONTROLLER_H
#define QDEVICESCONTROLLER_H

#include <QObject>
#include <QListWidget>
#include <QListWidgetItem>
#include "device.h"
#include <vector>
#include <memory>
#include "devicesview.h"
#include "mainwindow.h"

//Контроллер для MVC
class Device;
using std::unique_ptr;//Умный указатель
using device_uniq = unique_ptr<Device>;
using device_view_uniq = unique_ptr<DevicesView>;

using std::vector;
class DevicesView;
class MainWindow;
class QDevicesController:public QObject
{
    Q_OBJECT
public:
    explicit QDevicesController();
    ~QDevicesController();//Деструктор
    void addToBase(const Device& dv);//Добавление
    void deleteToBase(const Device& dv);//Удаление (нот имлемент)
    void clear();//Очистка
    void toListWidget(MainWindow *wnd);//Отрисовка

private:
    vector<device_uniq>m_base;//База данных
    vector<DevicesView*>m_views;
    vector<QListWidgetItem*>m_items;
};

#endif // QDEVICESCONTROLLER_H
