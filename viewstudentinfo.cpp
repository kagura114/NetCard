#include "viewstudentinfo.h"
#include "ui_viewstudentinfo.h"

ViewStudentInfo::ViewStudentInfo(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewStudentInfo)
{
    admin = a;
    ui->setupUi(this);
<<<<<<< HEAD
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
=======

>>>>>>> f8b383be4f9aeb4015e175bc7f077ac91e45c40f

    this->show();
}

ViewStudentInfo::~ViewStudentInfo()
{
    delete ui;
}

void ViewStudentInfo::on_QID_clicked()
{
    try {
        auto s = admin->SearchStudent((uint32_t)stoi(ui->condition->text().toStdString()));
        if (s!=nullptr)
        {
        QString info = QString::fromStdString(s->GetInfo());
        QMessageBox messageBox;
        messageBox.information(nullptr,"结果",info);
        messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","没有找到持有这个卡号的学生！");
            messageBox.setFixedSize(500,200);
        }
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","遇到了严重的错误！");
        messageBox.setFixedSize(500,200);
    }
    this->close();

}


void ViewStudentInfo::on_QSchoolID_clicked()
{
    try {
        auto s = admin->SearchStudent(ui->condition->text().toStdString(),true);//学号string+bool
        if (s!=nullptr)
        {
        QString info = QString::fromStdString(s->GetInfo());
        QMessageBox messageBox;
        messageBox.information(nullptr,"结果",info);
        messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","没有找到持有这个卡号的学生！");
            messageBox.setFixedSize(500,200);
        }
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","遇到了严重的错误！");
        messageBox.setFixedSize(500,200);
    }
    this->close();
}


void ViewStudentInfo::on_Qname_clicked()
{
    try {
        auto s = admin->SearchStudent(ui->condition->text().toStdString());//姓名单string
        if (s!=nullptr)
        {
        QString info = QString::fromStdString(s->GetInfo());
        QMessageBox messageBox;
        messageBox.information(nullptr,"结果",info);
        messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","没有找到持有这个卡号的学生！");
            messageBox.setFixedSize(500,200);
        }
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","遇到了严重的错误！");
        messageBox.setFixedSize(500,200);
    }
    this->close();
}

