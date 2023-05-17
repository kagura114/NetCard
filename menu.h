#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QScreen>
#include "admin.h"
#include "student.h"
#include "addstudent.h"
#include "viewstudentinfo.h"
#include "freeze.h"
#include "usepc.h"
#include "enterpassword.h"
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    Menu(Admin* admin,QWidget *parent = nullptr);
    Admin* admin;
    ~Menu();

private slots:
    void on_AddStudent_clicked();

    void on_FreezenUnF_clicked();

    void on_SaveData_clicked();

    void on_UsenUnuse_clicked();

    void on_ViewData_clicked();

    void refresh_ui();
    void on_lio_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
