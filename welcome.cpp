#include "welcome.h"
#include "./ui_welcome.h"
Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->NewFile->setStyleSheet("QPushButton{"
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
    ui->ReadFile->setStyleSheet("QPushButton{"
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
    this->setStyleSheet("background-color: qlineargradient"                                 //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,255,240, 255), stop:1 rgba(240,255,240, 255));");
}
Welcome::~Welcome()
{
    delete ui;
}
void Welcome::on_NewFile_clicked()
{
    this->close();                              //关闭当前界面
    auto* c = new CreateProject(nullptr,true);  //true控制是否前往新建流程
    c->show();
}
void Welcome::on_ReadFile_clicked()
{
    this->close();                               //关闭当前界面
    auto* c = new CreateProject(nullptr,false);
    c->show();
}
