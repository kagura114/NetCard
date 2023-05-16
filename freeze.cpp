#include "freeze.h"
#include "ui_freeze.h"

Freeze::Freeze(Admin *a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Freeze)
{
    this->admin = a;
    ui->setupUi(this);

    //最后显示完成的页面
    this->show();
}

Freeze::~Freeze()
{
    delete ui;
}

void Freeze::on_change_mode_clicked()
{

}


void Freeze::on_query_state_clicked()
{

}


void Freeze::on_exit_btn_clicked()
{
    this->close();
}

