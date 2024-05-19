#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QIcon>
#include "Article.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QWidget { background-color: #2D2D30; color: #E5E5E5; }");
    this->setWindowIcon(QIcon("bro.ico"));
    ui->pushButton->setStyleSheet("border: 1px solid white;");
    Admins::getAdmins().clear();
    Users::getUsers().clear();
    Article::getArticles().clear();
    Admins::loadAdmin();
    Users::loadUsers();
    Article::loadArticles();

    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int flag = 0;
    for(int i=0;i<users.size();i++)
    {
        if(users[i].getusername().c_str() == ui->lineEdit->text() && ui->lineEdit_2->text() == users[i].getpassword().c_str() )
        {
            flag=1;
            this->hide();
            form2= new userform(this,users[i]);
            form2->user = users[i];
            form2->show();
            break;
        }
    }
    for(int i=0;i<admins.size();i++)
    {
        if(admins[i].getusername().c_str() == ui->lineEdit->text() && ui->lineEdit_2->text() == admins[i].getpassword().c_str() )
        {
            flag=1;
            this->hide();
            admin = new adminform(this,admins[i]);
            admin->show();
            break;
        }
    }


    if(flag ==0)
     QMessageBox::warning(this, "Login", "Invalid username or password.");
    //create account

}

