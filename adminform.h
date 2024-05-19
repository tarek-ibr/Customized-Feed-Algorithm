#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QDialog>
#include "Accounts.h"

namespace Ui {
class adminform;
}

class adminform : public QDialog
{
    Q_OBJECT

public:
    explicit adminform(QWidget *parent = nullptr , const Admins& = Admins());
    ~adminform();

private:
    Ui::adminform *ui;
};

#endif // ADMINFORM_H
