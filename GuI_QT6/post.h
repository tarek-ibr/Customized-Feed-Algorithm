#ifndef POST_H
#define POST_H

#include <QDialog>
#include "Accounts.h"
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class post;
}

class post : public QDialog
{
    Q_OBJECT

public:
    explicit post(QWidget *parent , Users* u);
    ~post();

private slots:
    void on_pushButton_clicked();

private:
    Ui::post *ui;
    Users* user;
};

#endif // POST_H
