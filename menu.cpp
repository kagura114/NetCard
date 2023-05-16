#include "menu.h"
#include "ui_menu.h"

Menu::Menu(Admin* admi,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    this->admin = admi;
    ui->setupUi(this);
    refresh_ui();

    ui->AddStudent->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->ViewData->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->SaveData->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->UsenUnuse->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->FreezenUnF->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,255,255, 255), stop:1 rgba(240,255,255, 255));");
}

Menu::~Menu()
{
    delete ui;
}

void Menu::refresh_ui(){
    if (admin->isLogin())
        ui->label->setText("[管理员]功能列表");
    else
        ui->label->setText("功能列表");
}

void Menu::on_AddStudent_clicked()
{
    //打开添加学生页面
    auto* c = new AddStudent(this->admin);
    refresh_ui();

}


void Menu::on_FreezenUnF_clicked()
{
    auto *f = new Freeze(admin);
    refresh_ui();

}


void Menu::on_SaveData_clicked()
{
    //保存数据
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
    admin->status = Admin::LOGOUT;//最后登出
    refresh_ui();

}


void Menu::on_UsenUnuse_clicked()
{
    auto *v = new UsePC(admin);
    refresh_ui();


}


void Menu::on_ViewData_clicked()
{
    auto *v = new ViewStudentInfo(admin);
    refresh_ui();

}

