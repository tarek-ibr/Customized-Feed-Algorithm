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
    ui->pushButton->setStyleSheet("background-color: #26a95f;border: 1px solid white;");
    Admins::getAdmins().clear();
    Users::getUsers().clear();
    Article::getArticles().clear();
    Admins::loadAdmin();
    Users::loadUsers();
    Article::loadArticles();
    this->ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    this->ui->pushButton_2->setStyleSheet("color : #26a95f; background-color : transparent; ");
    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "Register")
    {
        if(Admins::registerNewUser(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString()))
        {
            QMessageBox::information(this,"INFO","Member Registered Successfully");
            Users::saveUsers();
        }
        else
        {
            QMessageBox::warning(this,"INFO","Member Exists / Error Happened");
        }
        ui->pushButton->setText("Login");
    }
    else
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
    }
    //create account

}


void MainWindow::on_label_4_linkActivated(const QString &link)
{
    QMessageBox::warning(this, "Login", "Invalid username or password.");
    //create account
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="Login")
    {
        ui->label_3->setText("Dont Have an Accout?");
        ui->pushButton_2->setGeometry(210,180,71,24);
        ui->pushButton->setText("Login");
        ui->pushButton_2->setText("Create One.");
    }
    else
    {
    this->ui->pushButton->setText("Register");
    ui->pushButton_2->setGeometry(170,180,71,24);
    ui->label_3->setText("Wanna Go back?");
    ui->pushButton_2->setText("Login");
    }

}

