#include "createadmin.h"
#include "ui_createadmin.h"

CreateAdmin::CreateAdmin(string Path,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAdmin)
{
    this->path = Path;
    ui->setupUi(this);
    admin = nullptr;
}

CreateAdmin::~CreateAdmin()
{
    delete ui;
}

void CreateAdmin::on_pushButton_clicked()
{
    //获取输入的密码
    QString Pas = ui->Passwd->text();
    std::string pswd = Pas.toStdString();

    //检查密码长度
    if (pswd.length() < 3 || pswd.length() > 32)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","密码长度不在3到32之间！");
        messageBox.setFixedSize(500,200);
    }
    else{
        this->admin = new Admin(pswd,path);

    }
}

