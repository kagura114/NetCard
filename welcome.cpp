#include "welcome.h"
#include "./ui_welcome.h"

Welcome::Welcome(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Welcome)
{
    ui->setupUi(this);
}

Welcome::~Welcome()
{
    delete ui;
}


void Welcome::on_NewFile_clicked()
{
    this->close();//关闭当前界面
    auto* c = new CreateProject(nullptr,true);
    c->show();
}


void Welcome::on_ReadFile_clicked()
{
    this->close();//关闭当前界面
    auto* c = new CreateProject(nullptr,false);
    c->show();
}

