#include "adminform.h"
#include "ui_adminform.h"
#include "mainwindow.h"
#include <QMessageBox>

adminform::adminform(QWidget *parent ,  Admins & a)
    : QDialog(parent)
    , ui(new Ui::adminform) , admin(a)
{

    ui->setupUi(this);
    setFixedSize(width(), height());
    login = parent;
     this->ui->tabWidget->setStyleSheet("QTabBar::tab {border: 1px solid green; background-color : #2D2D30 ;color: white; }");
     this->ui->lineEdit_5->setEchoMode(QLineEdit::Password);
     this->ui->pushButton->setStyleSheet("background-color: #26a95f;border: 1px solid white;");
     this->ui->pushButton_2->setStyleSheet("background-color: #26a95f;border: 1px solid white;");
     this->ui->pushButton_3->setStyleSheet("background-color: #26a95f;border: 1px solid white;");
     this->ui->pushButton_5->setStyleSheet("background-color: darkred;border: 1px solid white;");
     this->ui->pushButton_4->setStyleSheet("background-color: darkred;border: 1px solid white;");

}

adminform::~adminform()
{
    delete ui;
}

void adminform::on_pushButton_2_clicked()
{
    if(admin.registerNewUser(ui->lineEdit_4->text().toStdString(),ui->lineEdit_5->text().toStdString()))
    {
       QMessageBox::information(this,"INFO","Member Registered Successfully");
        Users::saveUsers();
    }
    else
    {
        QMessageBox::warning(this,"INFO","Member Exists / Error Happened");
    }

}


void adminform::on_pushButton_3_clicked()
{
    if(admin.removeUser(ui->lineEdit_6->text().toStdString()))
    {
        QMessageBox::information(this,"INFO","Member Removed Successfully");
        Users::saveUsers();
    }
    else
    {
        QMessageBox::warning(this,"INFO","Member Not Found");
    }

}


void adminform::on_pushButton_clicked()
{
    admin.addArticle(Article(ui->lineEdit->text().toStdString(),
                             ui->plainTextEdit->toPlainText().toStdString()
                             ,ui->lineEdit_2->text().toStdString()
                             ,ui->lineEdit_3->text().toStdString()
                             ,ui->lineEdit_7->text().toStdString()
                             ,Date::getCrrentDate()));
    Article::saveArticles();
    QMessageBox::information(this,"INFO","Article Added Successfully");
    //title(""), content(""), category(""), source(""), author(""), publicationDate(0,0,0)
}




void adminform::on_tabWidget_currentChanged(int index)
{

}


void adminform::on_pushButton_4_clicked()
{
    login->show();
    this->close();
}


void adminform::on_pushButton_5_clicked()
{
    login->show();
    this->close();
}

