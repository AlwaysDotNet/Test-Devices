#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <QString>
#include <QDate>
#include <utility>
//Модел
class QObject;
class QString;

class Device:public QObject
{
    Q_OBJECT
public:
    explicit Device();
    Device(const QString& name,const QString&ver,const QDate& d, const QString &des,
           const QString& ch);
    Device(const Device&dv);
    Device& operator=(Device&&d);
    Device(Device&&d);
    ~Device(){qDebug()<<"Destroy";}
    //Геттеры
    QString getName()const;
    QString getVersionFirm()const;
    QString getDateFirm()const;
    QString getDescription()const;
    QString getCache()const;
    QDate getSetDate()const;
    //Сеттеры
    void setName(const QString& );
    void setVersionFirmw(const QString&);
    void setDate(const QString&);
    void setDescription(const QString &);
    void setCache(const QString &);

private:
    QString m_dName;//Название
    QString m_version;//Версия firmware
    QDate m_date;//Дата прошивки
    QString m_desc;//Описание устройство
    QString m_cache;//Кэш

};

#endif // DEVICE_H
