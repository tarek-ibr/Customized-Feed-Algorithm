#include "userform.h"
#include "ui_userform.h"
#include <QMessageBox>

userform::userform(QWidget *parent,  Users& u)
    : QDialog(parent)
    , ui(new Ui::userform),user(u)
{
    login= parent;
    ui->setupUi(this);

    this->user=u;
    user.loadPrefrenceVector();
    user.buildHeap(Article::getArticles());
    currArticle = user.getArticle();
    ui->plainTextEdit->setPlainText(currArticle.getContent().c_str());
    ui->title->setText("Title: "+QString(currArticle.getTitle().c_str()));
    ui->category->setText("Category: "+QString(currArticle.getCategory().c_str()));
    ui->date->setText("Date: "+QString(currArticle.getPublicationDate().getDate().c_str()));
    ui->author->setText("Author: "+QString(currArticle.getAuthor().c_str()));
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setStyleSheet("color: white;");
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkred");
    this->ui->pushButton->setStyleSheet("border: 1px solid white;");
    this->ui->pushButton_3->setStyleSheet("border: 1px solid white;");
}

userform::~userform()

{
    delete ui;
}

void userform::on_pushButton_3_clicked()
{
    if(ui->pushButton->isEnabled())
    {
        this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkred");
        this->ui->pushButton_2->setEnabled(true);
    }

    currArticle=user.getArticle();

    ui->plainTextEdit->setPlainText(currArticle.getContent().c_str());
    ui->title->setText("Title: "+QString(currArticle.getTitle().c_str()));
    ui->category->setText("Category: "+QString(currArticle.getCategory().c_str()));
    ui->date->setText("Date: "+QString(currArticle.getPublicationDate().getDate().c_str()));
    ui->author->setText("Author: "+QString(currArticle.getAuthor().c_str()));

    //this->ui->textBrowser->setText(this->user->getmaxarticle()->content.c_str());
    //this->user->getmaxarticle()
}


void userform::on_pushButton_2_clicked()
{
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white;background-color: green");
    this->ui->pushButton_2->setEnabled(false);
    user.likeArticle(currArticle.getCategory());
    user.savePrefrenceVector();

}


void userform::on_pushButton_clicked()
{
    Article::saveArticles();
    Users::saveUsers();
    login->show();
    this->hide();
}

