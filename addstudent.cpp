#include "addstudent.h"
#include "ui_addstudent.h"

AddStudent::AddStudent(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    this->admin = a;
    this->show();
    //叠在上个窗口上面
    if(admin->status!=Admin::LOGIN){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请先登录");
        messageBox.setFixedSize(500,200);
        auto *c = new EnterPassword(admin);
    }
    ui->ClearID->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->ClearName->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->ClearSchoolID->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                  "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                  "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                  "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                  "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->ID->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                                  "color: rgb(31,31,31);"  //字体颜色
                                  "padding-left:20px;"       //内边距-字体缩进
                                  "background-color: rgb(255, 255, 255);" //背景颜色
                                  "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    ui->SchoolID->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                                  "color: rgb(31,31,31);"  //字体颜色
                                  "padding-left:20px;"       //内边距-字体缩进
                                  "background-color: rgb(255, 255, 255);" //背景颜色
                                  "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    ui->Name->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                                  "color: rgb(31,31,31);"  //字体颜色
                                  "padding-left:20px;"       //内边距-字体缩进
                                  "background-color: rgb(255, 255, 255);" //背景颜色
                                  "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    ui->Submit->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                               "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                               "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                               "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                               "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,255,255, 255), stop:1 rgba(240,255,255, 255));");
}

AddStudent::~AddStudent()
{
    delete ui;
}

void AddStudent::on_Submit_clicked()
{
    try {
        //读取数据
        auto *s = new Student();
        s->name = ui->Name->text().toStdString();
        s->id = stoi(ui->ID->text().toStdString());
        s->SchoolID = ui->SchoolID->text().toStdString();

        //检查数据
        if(!admin->verifyStudent(s)){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","ID已存在，不允许重复添加");
            messageBox.setFixedSize(500,200);
            this->close();
        }
        //验证登陆状态
        else if(admin->status==Admin::LOGIN)
        {
            admin->AddStudent(s);
            QMessageBox messageBox;
            messageBox.information(nullptr,"信息","创建成功！");
            messageBox.setFixedSize(500,200);
        }
        else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","未登录！");
            messageBox.setFixedSize(500,200);
            this->close();
        }

    }
    catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","添加学生失败！");
        messageBox.setFixedSize(500,200);
    }

    this->close();//关闭当前界面
}

