#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    QMessageBox msg;
    msg.setText( QString("war %1 \n %2 \n %3").arg(50).arg(5555).arg(90) );
    msg.setWindowTitle("warning");
    msg.exec();
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}
