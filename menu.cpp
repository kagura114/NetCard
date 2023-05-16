#include "menu.h"
#include "ui_menu.h"

Menu::Menu(Admin* admi,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    this->admin = admi;
    ui->setupUi(this);
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

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_AddStudent_clicked()
{
    //打开添加学生页面
    auto* c = new AddStudent(this->admin);
}


void Menu::on_FreezenUnF_clicked()
{
    //打开冻结解冻界面
}


void Menu::on_SaveData_clicked()
{
    //保存数据
}


void Menu::on_UsenUnuse_clicked()
{

}


void Menu::on_ViewData_clicked()
{

}

