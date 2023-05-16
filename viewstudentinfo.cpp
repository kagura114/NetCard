#include "viewstudentinfo.h"
#include "ui_viewstudentinfo.h"

ViewStudentInfo::ViewStudentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewStudentInfo)
{
    ui->setupUi(this);
}

ViewStudentInfo::~ViewStudentInfo()
{
    delete ui;
}

void ViewStudentInfo::on_QID_clicked()
{

}


void ViewStudentInfo::on_QSchoolID_clicked()
{

}


void ViewStudentInfo::on_Qname_clicked()
{

}

