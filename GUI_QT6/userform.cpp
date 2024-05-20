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
    userArticles = Article::getArticles();
    user.loadSeenVector();
    user.loadPrefrenceVector();
    user.buildHeap(userArticles);
    currArticle = user.getArticle();
    ui->plainTextEdit->setPlainText(currArticle.getContent().c_str());
    ui->title->setText("Title: "+QString(currArticle.getTitle().c_str()));
    ui->category->setText("Category: "+QString(currArticle.getCategory().c_str()));
    ui->date->setText("Date: "+QString(currArticle.getPublicationDate().getDate().c_str()));
    ui->author->setText("Author: "+QString(currArticle.getAuthor().c_str()));
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setStyleSheet("background-color: #232222; color: white;");
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkgreen");
    this->ui->pushButton->setStyleSheet("border: 1px solid white;");
    this->ui->pushButton_3->setStyleSheet("border: 1px solid white;");
    this->ui->pushButton_4->setStyleSheet("border: 1px solid white;");
    this->ui->pushButton_5->setStyleSheet("border: 1px solid white; background-color: darkred");


}

userform::~userform()

{
    delete ui;
}

void userform::on_pushButton_3_clicked()
{
    if(ui->pushButton->isEnabled())
    {
        this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkgreen");
        this->ui->pushButton_2->setEnabled(true);
        this->ui->pushButton_5->setStyleSheet("border: 1px solid white; background-color: darkred");
        this->ui->pushButton_5->setEnabled(true);
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
    if(!liked){
    this->ui->pushButton_5->setEnabled(false);
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white;background-color: grey");
    user.likeArticle(currArticle.getCategory());
    liked = true;
    }
    else
    {
    this->ui->pushButton_5->setEnabled(true);
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white;background-color: darkgreen");
    user.removeLikeArticle(currArticle.getCategory());
    liked = false;
    }
    user.buildHeap(userArticles);
    user.savePrefrenceVector();
    user.saveSeenVector();

}


void userform::on_pushButton_clicked()
{
    user.saveSeenVector();
    Article::saveArticles();
    Users::saveUsers();
    login->show();
    this->close();
}


void userform::on_pushButton_4_clicked()
{
    userArticles.clear();
    if(ui->checkBox->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_2->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_2->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_3->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_3->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_4->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_4->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_5->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_5->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_6->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_6->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_6->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_6->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_7->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_7->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_8->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_8->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_9->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_9->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_10->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_10->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_11->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_11->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_12->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_12->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    if(ui->checkBox_13->isChecked())
    {
        customVector<Article> Filter = user.filterByCategory(ui->checkBox_13->text().toStdString());
        for(int i=0;i<Filter.size();i++)
        {
            userArticles.push(Filter[i]);
        }
    }
    user.buildHeap(userArticles);
}


void userform::on_pushButton_5_clicked()
{
    if(!notInterested){
        this->ui->pushButton_2->setEnabled(false);
        this->ui->pushButton_5->setStyleSheet("border: 1px solid white;background-color: grey");
        user.notInterested(currArticle.getCategory());
        notInterested = true;
    }
    else
    {
        this->ui->pushButton_2->setEnabled(true);
        this->ui->pushButton_5->setStyleSheet("border: 1px solid white;background-color: darkred");
        user.removeNotInterested(currArticle.getCategory());
        notInterested = false;
    }
    user.buildHeap(userArticles);
    user.savePrefrenceVector();
    user.saveSeenVector();
}

