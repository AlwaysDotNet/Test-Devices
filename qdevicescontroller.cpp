#include "qdevicescontroller.h"

QDevicesController::QDevicesController()
{
   //Создание объектов
}

QDevicesController::~QDevicesController()
{
   for(size_t i =0;i<m_items.size();i++)
       delete m_items[i];
   for(size_t i = 0;i<m_views.size();i++)
       delete m_views[i];
}

void QDevicesController::addToBase(const Device &dv)
{
   this->m_base.push_back(device_uniq(new Device(dv)));
}

void QDevicesController::deleteToBase(const Device &dv)
{
   //Удаление
}

void QDevicesController::clear()
{
   this->m_base.clear();
}

void QDevicesController::toListWidget(MainWindow* wnd)
{
   auto wdg=wnd->getListWidget();
   wdg->clear();
   for(auto &un:this->m_base)
   {
       auto view = new DevicesView(un.get());
       view->setMaximumHeight(250);
       qDebug()<<wdg->width();
       auto item = new QListWidgetItem(wdg);
       item->setSizeHint(view->sizeHint());
       wdg->setItemWidget(item,view);
       m_views.push_back(view);
       m_items.push_back(item);
       //кнока детали
       connect(view, &DevicesView::sendDescription,wnd,&MainWindow::on_show_details);
   }
}



