#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QDialog>
#include "Accounts.h"
#include "Date.h"

namespace Ui {
class adminform;
}

class adminform : public QDialog
{
    Q_OBJECT

public:
    explicit adminform(QWidget *parent  ,  Admins&);
    ~adminform();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::adminform *ui;
    Admins& admin;
    QWidget* login;
};

#endif // ADMINFORM_H
