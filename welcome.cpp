#include "welcome.h"
#include "./ui_welcome.h"

Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
    ui->NewFile->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->ReadFile->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                               "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                               "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                               "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                               "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    //ui->Welcome_Label->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");

}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::on_NewFile_clicked()
{
    this->close();//关闭当前界面
    auto* c = new CreateProject(nullptr,true);
    c->show();
}


void Welcome::on_ReadFile_clicked()
{
    this->close();//关闭当前界面
    auto* c = new CreateProject(nullptr,false);
    c->show();
}

