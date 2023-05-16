#include "addstudent.h"
#include "ui_addstudent.h"

AddStudent::AddStudent(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    this->admin = a;
    this->show();
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_Submit_clicked()
{
    try {
        //读取数据
        auto *s = new Student();
        s->name = ui->Name->text().toStdString();
        s->id = stoi(ui->ID->text().toStdString());
        s->SchoolID = ui->SchoolID->text().toStdString();
        //验证密码
        auto *c = new EnterPassword(admin);

        if(admin->status==Admin::LOGIN)
        {
            admin->AddStudent(s);
            QMessageBox messageBox;
            messageBox.information(nullptr,"信息","创建成功！");
            messageBox.setFixedSize(500,200);
        }
        else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","未登录！");
            messageBox.setFixedSize(500,200);
            this->close();
        }

    }
    catch(std::invalid_argument){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","ID格式错误！只允许数字！");
        messageBox.setFixedSize(500,200);
        ui->ID->clear();
    }
    catch(std::out_of_range){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","ID格式错误！位数过多！");
        messageBox.setFixedSize(500,200);
        ui->ID->clear();
    }
    catch(overflow_error){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","ID格式错误！过长！");
        messageBox.setFixedSize(500,200);
        ui->ID->clear();
    }
    catch(underflow_error){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","ID格式错误！");
        messageBox.setFixedSize(500,200);
        ui->ID->clear();
    }
    catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","添加学生失败！");
        messageBox.setFixedSize(500,200);
    }

    this->close();//关闭当前界面
}

