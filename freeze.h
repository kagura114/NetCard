#ifndef FREEZE_H
#define FREEZE_H

#include <QWidget>
#include "admin.h"
#include "enterpassword.h"
namespace Ui {
class Freeze;
}

class Freeze : public QWidget
{
    Q_OBJECT

public:
    Freeze(Admin* a,QWidget *parent = nullptr);
    ~Freeze();

private slots:
    void on_change_mode_clicked();

    void on_query_state_clicked();

    void on_exit_btn_clicked();

    void reset();

private:
    Ui::Freeze *ui;
    Admin* admin;
    Student *student;
};

#endif // FREEZE_H
