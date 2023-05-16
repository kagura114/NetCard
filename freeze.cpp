#include "freeze.h"
#include "ui_freeze.h"

Freeze::Freeze(Admin *a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Freeze)
{
    this->admin = a;
    ui->setupUi(this);
    ui->change_mode->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                   "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                   "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                   "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                   "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->query_state->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                   "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                   "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                   "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                   "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->exit_btn->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->enter_id->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                                "color: rgb(31,31,31);"  //字体颜色
                                "padding-left:20px;"       //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);" //背景颜色
                                "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    //最后显示完成的页面
    this->show();
}

Freeze::~Freeze()
{
    delete ui;
}

void Freeze::on_change_mode_clicked()
{

}


void Freeze::on_query_state_clicked()
{

}


void Freeze::on_exit_btn_clicked()
{
    this->close();
}

