#include "userform.h"
#include "ui_userform.h"
#include <QMessageBox>
#include <QDebug>
userform::userform(QWidget *parent,  Users& u)
    : QDialog(parent)
    , ui(new Ui::userform),user(u)
{
    login= parent;
    ui->setupUi(this);

    textToSpeech = new QTextToSpeech(this);
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    player->setVideoOutput(videoWidget);
    player->setLoops(10);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);
    videoWidget->setGeometry(250,0,651,639);
    textToSpeech->setRate(0.01);
    textToSpeech->setVoice(textToSpeech->availableVoices()[0]);
    this->user=u;
    setFixedSize(width(), height());
    userArticles = Article::getArticles();
    user.loadSeenVector();
    user.loadPrefrenceVector();
    user.buildHeap(userArticles);
    currArticle = user.getArticle();
    videoWidget->setVisible(false);
    if(currArticle.getType() == "video"){
        ui->pushButton_6->setText("pause");
        videoWidget->setVisible(true);
        string path ="videos/"+ currArticle.getContent()+".mp4";
        player->setSource(QUrl::fromLocalFile(QString(path.c_str())));
        player->play();
    }
    else
    {
        ui->pushButton_6->setText("Read Aloud");
        ui->plainTextEdit->setPlainText(currArticle.getContent().c_str());
    }
    ui->title->setText("Title: "+QString(currArticle.getTitle().c_str()));
    ui->category->setText("Category: "+QString(currArticle.getCategory().c_str()));
    ui->date->setText("Date: "+QString(currArticle.getPublicationDate().getDate().c_str()));
    ui->author->setText("Author: "+QString(currArticle.getAuthor().c_str()));
    ui->plainTextEdit->setReadOnly(true);
    ui->plainTextEdit->setStyleSheet("background-color: #232222; color: white;");
    this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkgreen");
    this->ui->pushButton->setStyleSheet("background-color: red;border: 1px solid white;");
    this->ui->pushButton_3->setStyleSheet("border: 1px solid white;");
    this->ui->pushButton_4->setStyleSheet("border: 1px solid white; background-color: darkcyan");
    this->ui->pushButton_5->setStyleSheet("border: 1px solid white; background-color: darkred");
    this->ui->pushButton_6->setStyleSheet("border: 1px solid white; background-color: #26a95f");
    this->ui->pushButton_7->setStyleSheet("border: 1px solid white; background-color: darkcyan");

}

userform::~userform()

{
    delete ui;
    delete textToSpeech;
}

void userform::on_pushButton_3_clicked()
{

    currArticle=user.getArticle();
    if(currArticle.getType() == "article"){
    player->pause();
    videoWidget->setVisible(false);
    firstListen=true;
    listening = false;
    ui->pushButton_6->setText("Read Aloud");
    textToSpeech->pause();

    ui->plainTextEdit->setPlainText(currArticle.getContent().c_str());
    }
    else
    {
        ui->pushButton_6->setText("pause");
        videoWidget->setVisible(true);
        string path = "videos/" +currArticle.getContent()+".mp4";
        player->setSource(QUrl::fromLocalFile(QString(path.c_str())));
        player->play();

    }
    if(ui->pushButton->isEnabled())
    {
        this->ui->pushButton_2->setStyleSheet("border: 1px solid white; background-color: darkgreen");
        this->ui->pushButton_2->setEnabled(true);
        this->ui->pushButton_5->setStyleSheet("border: 1px solid white; background-color: darkred");
        this->ui->pushButton_5->setEnabled(true);
    }
    ui->title->setText("Title: "+QString(currArticle.getTitle().c_str()));
    ui->category->setText("Category: "+QString(currArticle.getCategory().c_str()));
    ui->date->setText("Date: "+QString(currArticle.getPublicationDate().getDate().c_str()));
    ui->author->setText("Author: "+QString(currArticle.getAuthor().c_str()));

    //this->ui->textBrowser->setText(this->user->getmaxarticle()->content.c_str());
    //this->user->getmaxarticle()
}


void userform::on_pushButton_2_clicked()
{
    if(this->ui->plainTextEdit->toPlainText() != ""){
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

}


void userform::on_pushButton_clicked()
{   player->pause();
    user.saveSeenVector();
    Article::saveArticles();
    Users::saveUsers();
    login->show();
    textToSpeech->pause();
    this->hide();
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
    if (!(ui->checkBox->isChecked() || ui->checkBox_2->isChecked() || ui->checkBox_3->isChecked() || ui->checkBox_4->isChecked() || ui->checkBox_5->isChecked() || ui->checkBox_6->isChecked() || ui->checkBox_7->isChecked() || ui->checkBox_8->isChecked() || ui->checkBox_9->isChecked() || ui->checkBox_10->isChecked() || ui->checkBox_11->isChecked() || ui->checkBox_12->isChecked() || ui->checkBox_13->isChecked() ))
        userArticles = Article::getArticles();
    if (ui->checkBox_14->isChecked() && !ui->checkBox_15->isChecked())
        userArticles = Users::filterByType(userArticles, "article");
    if (ui->checkBox_15->isChecked() && !ui->checkBox_14->isChecked())
        userArticles = Users::filterByType(userArticles, "video");
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


void userform::on_pushButton_6_clicked()
{
    if(currArticle.getType() == "article"){
    if(firstListen){
        textToSpeech->say(ui->plainTextEdit->toPlainText());
        listening = true;
        firstListen = false;
        ui->pushButton_6->setText("Stop");
    }
    else{
    if(listening){
        textToSpeech->pause();
        listening = false;
        ui->pushButton_6->setText("Continue");
    }
    else
    {
        textToSpeech->resume();
        listening = true;
        ui->pushButton_6->setText("Stop");
    }

    }
    }
    else
    {
        if (watching)
        {
            watching=false;
            player->pause();
            ui->pushButton_6->setText("Continue");
        }
        else
        {
            watching = true;
            player->play();
            ui->pushButton_6->setText("pause");
        }
    }

}
void userform::closeEvent(QCloseEvent *event)
{
    user.savePrefrenceVector();
    user.saveSeenVector();
    Users::saveUsers();
    Admins::saveAdmins();
    Article::saveArticles();
    QApplication::quit();
}


void userform::on_pushButton_7_clicked()
{
    p = new post(this, &user);
    p->show();
}


