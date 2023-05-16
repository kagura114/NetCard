#include "addstudent.h"
#include "ui_addstudent.h"

AddStudent::AddStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_Submit_clicked()
{

}

