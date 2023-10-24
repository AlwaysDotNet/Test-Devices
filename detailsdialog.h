#ifndef DETAILSDIALOG_H
#define DETAILSDIALOG_H

#include <QDialog>

namespace Ui {
class DetailsDialog;
}

class DetailsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsDialog(QWidget *parent = nullptr);
    ~DetailsDialog();

    void setDetailText(const QString& qs);//Уставнока текста

 private slots:
    void on_closeBtn_clicked();


    void on_extBtn_clicked();

private:
    Ui::DetailsDialog *ui;
};

#endif // DETAILSDIALOG_H
