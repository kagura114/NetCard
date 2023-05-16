#include "usepc.h"
#include "ui_usepc.h"

UsePC::UsePC(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsePC)
{
    ui->setupUi(this);
    this->admin = a;



    //最后显示完成的页面
    this->show();
}

UsePC::~UsePC()
{
    delete ui;
}

void UsePC::on_change_mode_clicked()
{

}



void UsePC::on_query_state_clicked()
{

}




void UsePC::on_exit_btn_clicked()
{
    this->close();
}
