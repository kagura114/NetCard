#include "menu.h"
#include "ui_menu.h"

Menu::Menu(Admin* admi,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    this->admin = admi;
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_AddStudent_clicked()
{

}


void Menu::on_FreezenUnF_clicked()
{

}


void Menu::on_SaveData_clicked()
{

}


void Menu::on_UsenUnuse_clicked()
{

}


void Menu::on_ViewData_clicked()
{

}

