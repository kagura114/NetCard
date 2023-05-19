#include "viewstudentinfo.h"
#include "ui_viewstudentinfo.h"
ViewStudentInfo::ViewStudentInfo(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewStudentInfo)
{
    //Init
    admin = a;
    ui->setupUi(this);
    //init UI
    ui->Qname->setStyleSheet("QPushButton{"
                             "font: 25 14pt '微软雅黑 regular';"                              //字体大小，形状
                             "color: rgb(0,0,0);"                                            //字体颜色
                             "background-color: rgb(255,248,220);"                           //背景颜色
                             "border: 2px groove gray;"                                      //设置控件边属性为2像素，凹槽形式为灰色
                             "border-radius:15px;"                                           //元素边框产生圆角，且四个角的水平和垂直半径为15px
                             "padding:2px 4px;"                                              //控制内边距像素
                             "border-style: outset;}"                                        //边框的凸边部分的样式
                             "QPushButton:hover{background-color: rgb(22,218,208);}"         //鼠标悬停在边框时的边框颜色
                             "QPushButton:pressed{background-color: rgb(17,171,164);}"       //鼠标点击边框时的边框颜色
                             "border:2px solid rgb(20,196,188);");                           //边框粗细-颜色-圆角设置
    ui->QID->setStyleSheet("QPushButton{"
                           "font: 25 14pt '微软雅黑 regular';"                                //字体大小，形状
                           "color: rgb(0,0,0);"                                              //字体颜色
                           "background-color: rgb(255,248,220);"                             //背景颜色
                           "border: 2px groove gray;"                                        //设置控件边属性为2像素，凹槽形式为灰色
                           "border-radius:15px;"                                             //元素边框产生圆角，且四个角的水平和垂直半径为15px
                           "padding:2px 4px;"                                                //控制内边距像素
                           "border-style: outset;}"                                          //边框的凸边部分的样式
                           "QPushButton:hover{background-color: rgb(22,218,208);}"           //鼠标悬停在边框时的边框颜色
                           "QPushButton:pressed{background-color: rgb(17,171,164);}"         //鼠标点击边框时的边框颜色
                           "border:2px solid rgb(20,196,188);");                             //边框粗细-颜色-圆角设置
    ui->QSchoolID->setStyleSheet("QPushButton{"
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
    ui->condition->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                          //字体
                                 "color: rgb(31,31,31);"                                     //字体颜色
                                 "padding-left:20px;"                                        //内边距-字体缩进
                                 "background-color: rgb(255, 255, 255);"                     //背景颜色
                                 "border:2px solid rgb(20,196,188);"                         //2像素宽度和2像素高度的实线边框
                                 "border-radius:15px;");                                     //边框粗细-颜色-圆角设置"
    this->setStyleSheet("background-color: qlineargradient"                                  //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255,255,240, 255), stop:1 rgba(255,255,240, 255));");
    this->show();
}
ViewStudentInfo::~ViewStudentInfo()
{
    delete ui;
}
void ViewStudentInfo::on_QID_clicked()
{
    try {
        auto s = admin->SearchStudent((uint32_t)stoi(ui->condition->text().toStdString()));   //卡号
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
    this->close();                                                                           //关闭此前界面
}
void ViewStudentInfo::on_QSchoolID_clicked()
{
    try {
        auto s = admin->SearchStudent(ui->condition->text().toStdString(),true);             //学号string+bool
        if (s!=nullptr)
        {
        QString info = QString::fromStdString(s->GetInfo());
        QMessageBox messageBox;
        messageBox.information(nullptr,"结果",info);
        messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","没有找到这个学号的学生！");
            messageBox.setFixedSize(500,200);
        }
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","遇到了严重的错误！");
        messageBox.setFixedSize(500,200);
    }
    this->close();                                                                             //关闭此前界面
}
void ViewStudentInfo::on_Qname_clicked()
{
    try {
        auto s = admin->SearchStudent(ui->condition->text().toStdString());                    //姓名单string
        if (s!=nullptr)
        {
        QString info = QString::fromStdString(s->GetInfo());
        QMessageBox messageBox;
        messageBox.information(nullptr,"结果",info);
        messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","没有找到这个名字的学生！");
            messageBox.setFixedSize(500,200);
        }
    } catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","遇到了严重的错误！");
        messageBox.setFixedSize(500,200);
    }
    this->close();                                                                             //关闭此前界面
}
