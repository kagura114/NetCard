/*
    menu .{h/cpp/ui}
    功能菜单页面
    管理员和普通用户共用，需要权限部分需要手动鉴权
    如果管理员登录头部文字会改变以提示权限提升
*/


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
