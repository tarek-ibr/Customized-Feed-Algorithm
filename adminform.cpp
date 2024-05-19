#include "adminform.h"
#include "ui_adminform.h"
#include "mainwindow.h"

adminform::adminform(QWidget *parent , const Admins & a)
    : QDialog(parent)
    , ui(new Ui::adminform)
{

    ui->setupUi(this);
    setFixedSize(width(), height());


}

adminform::~adminform()
{
    delete ui;
}
