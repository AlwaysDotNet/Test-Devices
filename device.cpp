#include "device.h"

Device::Device()
{
    //Конструктор по умолчание
    this->m_date=QDate::currentDate();
    this->m_desc = "-";
    this->m_dName = "-";
    this->m_version = "-";
    this->m_cache = "-";
}

Device::Device(const QString &name, const QString &ver, const QDate &d, const QString &des, const QString &ch)
{
    this->m_dName=name;
    this->m_date=d;
    this->m_desc=des;
    this->m_version=ver;
    this->m_cache=ch;
}

Device::Device(const Device &dv)
{
    this->m_date = dv.getSetDate();
    this->m_desc = dv.getDescription();
    this->m_dName = dv.getName();
    this->m_version = dv.getVersionFirm();
    this->m_cache = dv.getCache();

}

Device &Device::operator=(Device &&dv)
{
    if(this!=&dv)
    {

        this->m_date = dv.getSetDate();
        this->m_desc = dv.getDescription();
        this->m_dName = dv.getName();
        this->m_version = dv.getVersionFirm();
        this->m_cache = dv.getCache();
    }
    return *this;
}

Device::Device(Device &&dv)
{
    if(this!=&dv)
    {

        this->m_date = dv.getSetDate();
        this->m_desc = dv.getDescription();
        this->m_dName = dv.getName();
        this->m_version = dv.getVersionFirm();
        this->m_cache = dv.getCache();
    }
}

QString Device::getName() const
{
    return this->m_dName;
}

QString Device::getVersionFirm() const
{
    return this->m_version;
}

QString Device::getDateFirm() const
{
    return m_date.toString("dd.MM.yyyy");
}

QString Device::getDescription() const
{
    return this->m_desc;
}

QString Device::getCache() const
{
    return this->m_cache;
}

QDate Device::getSetDate() const
{
    return this->m_date;
}

void Device::setName(const QString &dName)
{
    this->m_dName =  dName;
}

void Device::setVersionFirmw(const QString &frmVersion)
{
    this->m_version = frmVersion;
}

void Device::setDate(const QString &dt)
{
    //Возможно ошибка
    this->m_date = QDate::fromString(dt,"dd.MM.yyyy");
}

void Device::setDescription(const QString &desc)
{
    this->m_desc = desc;
}

void Device::setCache(const QString &cache)
{
    this->m_cache = cache;
}
