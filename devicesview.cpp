#include "devicesview.h"

DevicesView::DevicesView(Device *dv,QWidget *parent)
{

    this->m_div = dv;//Просто указатель можно использовть QSharedP
    this->setAllocator();//Выделение памяти
    this->setAtributsWidget();//Установка стилов и атрибутов для виджета
    //Установка рамки
    this->setUpHintLabel();
    //Установка даных
    this->setUpData(dv);
    this->setUpHintLabel();
    this->setUpUi();

    //Установка основного виджета
    this->setLayout(this->m_mainLayout);
    connect(m_detailsBtn, &QPushButton::clicked, this, &DevicesView::onDetailsBtnClicked);
    this->setMinimumHeight(200);
    this->setMinimumWidth(300);
    this->setMaximumWidth(500);
}

DevicesView::~DevicesView()
{
   //Освобождение памяти
   delete m_cache;
   delete m_dateFirm;
   delete m_description;
   delete m_verFirmware;
   delete m_lblHintDevice;
   delete m_mainLayout;
   qDebug() <<"IM here";
   delete m_detailsBtn;
}

void DevicesView::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void DevicesView::setAtributsWidget()
{
    //Установим флаги окна
    QString qcss = "QWidget{"
                   "background-color:rgba(255, 255, 255, 1);"
                   "border-radius:16px;}";
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setStyleSheet(qcss);
    //Стил QPushButon
    QString qBtnStyle = "QPushButton {padding: 9px 16px 11px 14px;"
                        "background: #4480F3;"
                        "color:rgba(255,255,255,1);"
                        "font-size:14px;"
                        "border-radius: 8px;"
                        "font-family:Times New Roman;"
                        "}"
                        "QPushButton:hover{"
                        "font-size:16px;"
                        "border-radius:12px;}";

    this->m_detailsBtn->setStyleSheet(qBtnStyle);
    this->m_detailsBtn->setMaximumHeight(30);
    this->m_detailsBtn->setMaximumWidth(100);
}

void DevicesView::setUpHintLabel()
{
    this->m_stCache.setText("Кэш");
    this->m_stDate.setText("Дата прошивки:");
    this->m_stDes.setText("описание");
    this->m_stVersion.setText("Версия прошивки:");
    this->m_information.setText("Информация по прошивке");
}

void DevicesView::setUpData(Device *dv)
{
    if (dv!=nullptr)
    {
        this->m_cache->setText(dv->getCache());
        this->m_dateFirm->setText(dv->getDateFirm());
        auto cur =  dv->getDescription();
        if(cur.length()>MAX_LEN_DESCRIPTION)
        {
        QString cpy = "";
        for(qsizetype i=0;i<MAX_LEN_DESCRIPTION-3;i++)
        {
            cpy +=cur[i];
        }
        cpy += "...";
        this->m_description->setText(cpy);
        }
        else
        this->m_description->setText(cur);
        this->m_verFirmware ->setText(dv->getVersionFirm());
        this->m_lblHintDevice->setText(dv->getName());
    }
}
//
void DevicesView::setUpUi()
{


    this->m_gridLayout->setContentsMargins(5,5,7,7);
    this->m_gridLayout->setDefaultPositioning(2,Qt::Horizontal);
    this->m_gridLayout->setSizeConstraint(QGridLayout::SetMaximumSize);
    //Уставнока элементов формы
    this->m_gridLayout->addWidget(&this->m_stVersion,
                                  0,0);
    this->m_gridLayout->addWidget(this->m_verFirmware,
                                  0,1);


    this->m_gridLayout->addWidget(&this->m_stDate,
                                  1,0);
    this->m_gridLayout->addWidget(this->m_dateFirm,
                                  1,1);

    this->m_gridLayout->addWidget(&this->m_stDes,
                                  2,0);
    this->m_gridLayout->addWidget(this->m_description,
                                  2,1);

    this->m_gridLayout->addWidget(&this->m_stCache,
                                  3,0);
    this->m_gridLayout->addWidget(this->m_cache,
                                  3,1);
    this->m_gridLayout->addWidget(this->m_detailsBtn,
                                  4,0);
    this->m_mainLayout->addWidget(this->m_lblHintDevice,1,Qt::AlignCenter);
    this->m_mainLayout->addWidget(&this->m_information,1,Qt::AlignLeft);
    this->m_mainLayout->addLayout(this->m_gridLayout);
}

void DevicesView::setAllocator()
{

    this->m_cache = new QLabel();
    this->m_dateFirm = new QLabel();
    this->m_description = new QLabel();
    this->m_description->setWordWrap(true);//Перенос строки
    this->m_verFirmware = new QLabel();
    this->m_mainLayout = new QVBoxLayout();
    this->m_gridLayout = new QGridLayout();
    this->m_lblHintDevice = new QLabel();
    //
    this->m_cache->setAlignment(Qt::AlignLeft);
    this->m_dateFirm->setAlignment(Qt::AlignLeft);
    this->m_description->setAlignment(Qt::AlignLeft);
    this->m_verFirmware->setAlignment(Qt::AlignLeft);
    this->m_detailsBtn = new QPushButton(tr("Детали"));
    QFont fnt("Times New Roman",12,1);//inter выглядет ужасно
    this->setFont(fnt);
    this->m_information.setFont(QFont("Times New Roman", 14, 1));
    this->m_lblHintDevice->setFont(QFont("Times New Roman",16,1));
}

//Что бы виджет смогла вместится в layout
QSize DevicesView::sizeHint() const
{
    return QSize(width()+4,height()+4);
}

void DevicesView::onDetailsBtnClicked()
{
    if(this->m_div)
    {
        //Отправим описание
        emit this->sendDescription(m_div->getDescription());
    }
}
