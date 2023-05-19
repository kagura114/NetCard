#include "menu.h"
#include "ui_menu.h"
Menu::Menu(Admin* admi,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    this->admin = admi;
    ui->setupUi(this);
    ui->AddStudent->setStyleSheet("QPushButton{"
                                  "font: 25 14pt '微软雅黑 regular';"                          //字体大小，形状
                                  "color: rgb(0,0,0);"                                        //字体颜色
                                  "background-color: rgb(255,248,220);"                       //背景颜色
                                  "border: 2px groove gray;"                                  //设置控件边属性为2像素，凹槽形式为灰色
                                  "border-radius:15px;"                                       //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                  "padding:2px 4px;"                                          //控制内边距像素
                                  "border-style: outset;}"                                    //边框的凸边部分的样式
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"     //鼠标悬停在边框时的边框颜色
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"   //鼠标点击边框时的边框颜色
                                  "border:2px solid rgb(20,196,188);");                       //边框粗细-颜色-圆角设置
    ui->ViewData->setStyleSheet("QPushButton{"
                                "font: 25 14pt '微软雅黑 regular';"                             //字体大小，形状
                                "color: rgb(0,0,0);"                                           //字体颜色
                                "background-color: rgb(255,248,220);"                          //背景颜色
                                "border: 2px groove gray;"                                     //设置控件边属性为2像素，凹槽形式为灰色
                                "border-radius:15px;"                                          //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                "padding:2px 4px;"                                             //控制内边距像素
                                "border-style: outset;}"                                       //边框的凸边部分的样式
                                "QPushButton:hover{background-color: rgb(22,218,208);}"        //鼠标悬停在边框时的边框颜色
                                "QPushButton:pressed{background-color: rgb(17,171,164);}"      //鼠标点击边框时的边框颜色
                                "border:2px solid rgb(20,196,188);");                          //边框粗细-颜色-圆角设置
    ui->SaveData->setStyleSheet("QPushButton{"
                                "font: 25 14pt '微软雅黑 regular';"                             //字体大小，形状
                                "color: rgb(0,0,0);"                                           //字体颜色
                                "background-color: rgb(255,248,220);"                          //背景颜色
                                "border: 2px groove gray;"                                     //设置控件边属性为2像素，凹槽形式为灰色
                                "border-radius:15px;"                                          //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                "padding:2px 4px;"                                             //控制内边距像素
                                "border-style: outset;}"                                       //边框的凸边部分的样式
                                "QPushButton:hover{background-color: rgb(22,218,208);}"        //鼠标悬停在边框时的边框颜色
                                "QPushButton:pressed{background-color: rgb(17,171,164);}"      //鼠标点击边框时的边框颜色
                                "border:2px solid rgb(20,196,188);");                          //边框粗细-颜色-圆角设置
    ui->UsenUnuse->setStyleSheet("QPushButton{"
                                 "font: 25 14pt '微软雅黑 regular';"                            //字体大小，形状
                                 "color: rgb(0,0,0);"                                          //字体颜色
                                 "background-color: rgb(255,248,220);"                         //背景颜色
                                 "border: 2px groove gray;"                                    //设置控件边属性为2像素，凹槽形式为灰色
                                 "border-radius:15px;"                                         //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                 "padding:2px 4px;"                                            //控制内边距像素
                                 "border-style: outset;}"                                      //边框的凸边部分的样式
                                 "QPushButton:hover{background-color: rgb(22,218,208);}"       //鼠标悬停在边框时的边框颜色
                                 "QPushButton:pressed{background-color: rgb(17,171,164);}"     //鼠标点击边框时的边框颜色
                                 "border:2px solid rgb(20,196,188);");                         //边框粗细-颜色-圆角设置
    ui->FreezenUnF->setStyleSheet("QPushButton{"
                                  "font: 25 14pt '微软雅黑 regular';"                           //字体大小，形状
                                  "color: rgb(0,0,0);"                                         //字体颜色
                                  "background-color: rgb(255,248,220);"                        //背景颜色
                                  "border: 2px groove gray;"                                   //设置控件边属性为2像素，凹槽形式为灰色
                                  "border-radius:15px;"                                        //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                  "padding:2px 4px;"                                           //控制内边距像素
                                  "border-style: outset;}"                                     //边框的凸边部分的样式
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"      //鼠标悬停在边框时的边框颜色
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"    //鼠标点击边框时的边框颜色
                                  "border:2px solid rgb(20,196,188);");                        //边框粗细-颜色-圆角设置
    ui->lio->setStyleSheet("QPushButton{"
                           "font: 25 14pt '微软雅黑 regular';"                                  //字体大小，形状
                           "color: rgb(0,0,0);"                                                //字体颜色
                           "background-color: rgb(255,248,220);"                               //背景颜色
                           "border: 2px groove gray;"                                          //设置控件边属性为2像素，凹槽形式为灰色
                           "border-radius:15px;"                                               //元素边框产生圆角，且四个角的水平和垂直半径为15px
                           "padding:2px 4px;"                                                  //控制内边距像素
                           "border-style: outset;}"                                            //边框的凸边部分的样式
                           "QPushButton:hover{background-color: rgb(22,218,208);}"             //鼠标悬停在边框时的边框颜色
                           "QPushButton:pressed{background-color: rgb(17,171,164);}"           //鼠标点击边框时的边框颜色
                           "border:2px solid rgb(20,196,188);");                               //边框粗细-颜色-圆角设置
    this->setStyleSheet("background-color: qlineargradient"                                    //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(238,238,209, 255), stop:1 rgba(238,238,209, 255));");
}

Menu::~Menu()
{
    delete ui;
}
void Menu::refresh_ui()                                //控制头部文字，刷新ui
{
    auto *newP = new Menu(admin);
    if (admin->isLogin())
        newP->ui->label->setText("[管理员]功能列表");
    else
        newP->ui->label->setText("功能列表");
    newP->move(60,60);                                 //跳出功能页面时，不要挡住其他页面
    newP->show();
    this->close();
}
void Menu::on_AddStudent_clicked()                     //打开添加学生页面
{
    auto* c = new AddStudent(this->admin);
    refresh_ui();
}
void Menu::on_FreezenUnF_clicked()                     //解冻/冻结功能
{
    auto *f = new Freeze(admin);
    refresh_ui();
}
void Menu::on_SaveData_clicked()                       //保存数据功能
{
    try {
        admin->Save();
        QMessageBox messageBox;
        messageBox.information(nullptr,"信息","保存成功！");
        messageBox.setFixedSize(500,200);
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","保存失败！");
        messageBox.setFixedSize(500,200);
    }
    if (admin->status!=Admin::LOCK)                    //防止管理员被意外解除锁定
        admin->status = Admin::LOGOUT;                 //最后登出
    refresh_ui();
}
void Menu::on_UsenUnuse_clicked()                      //上/下机功能
{
    auto *v = new UsePC(admin);
    refresh_ui();
}
void Menu::on_ViewData_clicked()                       //查看学生信息功能
{
    auto *v = new ViewStudentInfo(admin);
    refresh_ui();
}
void Menu::on_lio_clicked()                            //登录/退出操作
{
    if (admin->isLogin()){
        admin->status=admin->LOGOUT;
        refresh_ui();
    }
    else
    {
        auto *e = new EnterPassword(admin);
        ui->label->setText("[管理员]功能列表");           //标题
    }
}
