#include "usepc.h"
#include "ui_usepc.h"

UsePC::UsePC(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsePC)
{
    ui->setupUi(this);
    this->admin = a;
    this->student = nullptr;


    //最后显示完成的页面
    this->show();
}

UsePC::~UsePC()
{
    delete ui;
}

void UsePC::on_change_mode_clicked()
{
    if(ui->change_mode->text()=="功能"){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请先查询状态！");
        messageBox.setFixedSize(500,200);
    }else if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
    }else if(ui->change_mode->text()=="--"){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","该状态下不允许操作");
        messageBox.setFixedSize(500,200);
    }else if(this->student==nullptr){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请重新查询");
        messageBox.setFixedSize(500,200);
        ui->change_mode->setText("功能");
    }else if(ui->change_mode->text()=="上机"){
        student->start_worktime();
        student->status = Student::status::LOGIN;
        string s = student->name + "在" + student->toNormalTime(student->start_time) + " 开始上机！";
        QMessageBox messageBox;
        QString qstr = QString::fromStdString(s);
        messageBox.information(0,"结果",qstr.fromStdString(s));
        messageBox.setFixedSize(500,200);
    }

}



void UsePC::on_query_state_clicked()
{
    if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
    }else{
        auto* s = admin->SearchStudent(ui->enter_id->text().toStdString());
        if (s==nullptr){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","无法查询到所要的学号");
            messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            switch(s->status){
            case Student::status::LOGIN: //上机
                messageBox.information(0,"结果","正在上机中，让管理员点击右边按钮以下机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("下机");
                this->student = s;
                break;
            case Student::status::NORMAL: //下机
                messageBox.information(0,"结果","没有上机，请点击右边按钮上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("上机");
                this->student = s;
                break;

            case Student::status::LOST: //挂失
                messageBox.critical(0,"结果","已挂失，不可上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("--");
                break;

            case Student::status::FREEZE: //冻结
                messageBox.critical(0,"结果","已冻结，不可上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("--");
                break;

            }


        }
    }
}




void UsePC::on_exit_btn_clicked()
{
    this->close();
}
