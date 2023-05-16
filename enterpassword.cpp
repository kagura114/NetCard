#include "enterpassword.h"
#include "ui_enterpassword.h"

EnterPassword::EnterPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPassword)
{
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->pushButton_2->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->lineEdit->setEchoMode(QLineEdit::Password);//输入密码为黑点

}

EnterPassword::~EnterPassword()
{
    delete ui;
}
