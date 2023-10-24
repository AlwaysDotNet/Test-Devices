#ifndef DEVICESVIEW_H
#define DEVICESVIEW_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QRect>
#include <QStyleOption>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include "device.h"
#include <QPushButton>
//На основе MVC - View для просмотра детали устройстрво
class QWidget;
class QGridLayout;
class QVBoxLayout;
class Device;
class QPushButton;
//Выиджет который представляеть наш модел в нашем случае -это устройства
class DevicesView:public QWidget
{
    Q_OBJECT
public:
    //Конструктор окна
   explicit DevicesView(Device *dv,QWidget *parent=nullptr);
    ~DevicesView();//Деструктор представление
   inline static qsizetype MAX_LEN_DESCRIPTION = 55;//Количество букв который будет выводится в описание ...

protected:
    void paintEvent(QPaintEvent *event) override;

private:

    QLabel *m_lblHintDevice;//Название девайса
    QLabel *m_verFirmware;//Версия прошивк
    QLabel *m_dateFirm;//Дата прошивк
    QLabel *m_description;//Описание
    QLabel *m_cache;//Кэш
    //Заголовки
    QLabel m_stVersion;
    QLabel m_stDate;
    QLabel m_stDes;
    QLabel m_stCache;
    QLabel m_information;
    //рамки
    QVBoxLayout *m_mainLayout;
    QGridLayout *m_gridLayout;
    //Кнопка
    QPushButton *m_detailsBtn;

    // Установка статических значение
    void setAtributsWidget();//Установка атрибута и стили
    void setUpHintLabel();
    void setUpData(Device *dv);
    void setUpUi();//Установка layout
    void setAllocator();//Выделение памяти
    //Указатель на класс-не копируем
    Device *m_div;

    // QWidget interface
public:
    QSize sizeHint() const override;
//Сигнали слоты

public slots:
    void onDetailsBtnClicked();//Слот нажатие кнопки

signals:
    void sendDescription(const QString &qs);//Сигнал для отправки описание

};

#endif // DEVICESVIEW_H
