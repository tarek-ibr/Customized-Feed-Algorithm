#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include "Accounts.h"
#include "Article.h"
#include <QMediaPlayer>
#include <qvideowidget.h>
#include <QTextToSpeech>
#include <QtMultimedia>
#include <QVideoWidget>
#include <QAudioDevice>
#include "post.h"

namespace Ui {
class userform;
}

class userform : public QDialog
{
    Q_OBJECT

public:
    explicit userform(QWidget *parent  ,Users& );
    ~userform();
    Users & user;
    QWidget *login;
    Article currArticle;
    customVector<Article> userArticles;
    QTextToSpeech *textToSpeech;
    QMediaPlayer* player;
    QVideoWidget* videoWidget;
    QAudioOutput* audioOutput;

    bool liked = false;
    bool notInterested = false;
    bool listening = false;
    bool firstListen = true;
    bool watching = true;
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::userform *ui;
    post* p;
    void closeEvent(QCloseEvent *event);


};


#endif // USERFORM_H
