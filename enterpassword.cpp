#include "enterpassword.h"
#include "ui_enterpassword.h"

EnterPassword::EnterPassword(Admin* ad,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPassword)
{
    this->admin = ad;
    this->State = false;
    ui->setupUi(this);
}

EnterPassword::~EnterPassword()
{
    delete ui;
}

void EnterPassword::on_Submit_clicked()
{
    //管理员已登录可以直接完成
    if(admin->status == Admin::LOGIN){
        this->State = true;
    }
    //获取输入的内容
    QString Pa = ui->enter_pass->text();
    std::string pass = Pa.toStdString();
    //检查密码
    this->State = admin->VerifyPass(pass);

    if (State){
        this->close();
    }
    else{
        throw "Wrong Password";
        this->close();
    }
}

bool EnterPassword::GetState(){
    return State;
}
