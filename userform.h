#ifndef USERFORM_H
#define USERFORM_H

#include <QDialog>
#include "Accounts.h"
#include "Article.h"


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


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::userform *ui;

};

#endif // USERFORM_H