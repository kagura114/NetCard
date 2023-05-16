#include "viewstudentinfo.h"
#include "ui_viewstudentinfo.h"

ViewStudentInfo::ViewStudentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewStudentInfo)
{
    ui->setupUi(this);
    ui->Qname->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->QID->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->QSchoolID->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
}

ViewStudentInfo::~ViewStudentInfo()
{
    delete ui;
}

void ViewStudentInfo::on_QID_clicked()
{

}


void ViewStudentInfo::on_QSchoolID_clicked()
{

}


void ViewStudentInfo::on_Qname_clicked()
{

}

