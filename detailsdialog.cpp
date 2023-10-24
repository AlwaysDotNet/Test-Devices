#include "detailsdialog.h"
#include "ui_detailsdialog.h"

DetailsDialog::DetailsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint|
                       Qt::Dialog);

}

DetailsDialog::~DetailsDialog()
{
    delete ui;
}

void DetailsDialog::setDetailText(const QString &qs)
{
    ui->detailBrowser->setText(qs);
}

void DetailsDialog::on_closeBtn_clicked()
{
    this->accept();
}


void DetailsDialog::on_extBtn_clicked()
{
    this->accept();
}

