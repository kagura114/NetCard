#include "enterpassword.h"
#include "ui_enterpassword.h"

EnterPassword::EnterPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPassword)
{
    ui->setupUi(this);
}

EnterPassword::~EnterPassword()
{
    delete ui;
}
