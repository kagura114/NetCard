#include "usepc.h"
#include "ui_usepc.h"

UsePC::UsePC(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsePC)
{
    ui->setupUi(this);
    this->admin = a;
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
this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,255,255, 255), stop:1 rgba(240,255,255, 255));");
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
    }else if(ui->change_mode->text()=="下机"){
        if(!admin->isLogin()){  //需要登录
            QMessageBox messageBox;
            messageBox.critical(0,"Error","请先登录");
            messageBox.setFixedSize(500,200);
            auto *c = new EnterPassword(admin);
        }else{
        student->finish_worktime();
        student->status = Student::status::NORMAL;
        string s = student->name + "在" + student->toNormalTime(student->finish_time) + " 结束上机！";
        QMessageBox messageBox;
        QString qstr = QString::fromStdString(s);
        messageBox.information(0,"结果",qstr.fromStdString(s));
        messageBox.setFixedSize(500,200);
        }
    }

}



void UsePC::on_query_state_clicked()
{
    if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
    }else{
        auto* s = admin->SearchStudent(stoi(ui->enter_id->text().toStdString()));
        if (s==nullptr){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","无法查询到所要的学号");
            messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            switch(s->status){
            case Student::status::LOGIN: //上机
                messageBox.information(0,"结果","正在上机中，让管理员点击中间按钮以下机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("下机");
                this->student = s;
                break;
            case Student::status::NORMAL: //下机
                messageBox.information(0,"结果","没有上机，请点击中间按钮上机！");
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
