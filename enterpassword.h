#ifndef ENTERPASSWORD_H
#define ENTERPASSWORD_H

#include <QWidget>
#include "admin.h"
namespace Ui {
class EnterPassword;
}

class EnterPassword : public QWidget
{
    Q_OBJECT

public:
    EnterPassword(Admin* ad,QWidget *parent = nullptr);
    ~EnterPassword();
    bool GetState();
    bool inOperation;

private slots:
    void on_Submit_clicked();

private:
    Ui::EnterPassword *ui;
    Admin* admin;
    bool State;
};

#endif // ENTERPASSWORD_H
