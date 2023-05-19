#include "enterpassword.h"
#include "ui_enterpassword.h"
EnterPassword::EnterPassword(Admin* ad,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EnterPassword)
{
    this->inOperation = true;
    this->admin = ad;
    this->State = false;
    ui->setupUi(this);
    ui->Clean->setStyleSheet("QPushButton{"
                             "font: 25 14pt '微软雅黑 regular';"                          //字体大小，形状
                             "color: rgb(0,0,0);"                                        //字体颜色
                             "background-color: rgb(255,248,220);"                       //背景颜色
                             "border: 2px groove gray;"                                  //设置控件边属性为2像素，凹槽形式为灰色
                             "border-radius:15px;"                                       //元素边框产生圆角，且四个角的水平和垂直半径为15px
                             "padding:2px 4px;"                                          //控制内边距像素
                             "border-style: outset;}"                                    //边框的凸边部分的样式
                             "QPushButton:hover{background-color: rgb(22,218,208);}"     //鼠标悬停在边框时的边框颜色
                             "QPushButton:pressed{background-color: rgb(17,171,164);}"   //鼠标点击边框时的边框颜色
                             "border:2px solid rgb(20,196,188);");                       //边框粗细-颜色-圆角设置
    ui->Submit->setStyleSheet("QPushButton{"
                              "font: 25 14pt '微软雅黑 regular';"                          //字体大小，形状
                              "color: rgb(0,0,0);"                                        //字体颜色
                              "background-color: rgb(255,248,220);"                       //背景颜色
                              "border: 2px groove gray;"                                  //设置控件边属性为2像素，凹槽形式为灰色
                              "border-radius:15px;"                                       //元素边框产生圆角，且四个角的水平和垂直半径为15px
                              "padding:2px 4px;"                                          //控制内边距像素
                              "border-style: outset;}"                                    //边框的凸边部分的样式
                              "QPushButton:hover{background-color: rgb(22,218,208);}"     //鼠标悬停在边框时的边框颜色
                              "QPushButton:pressed{background-color: rgb(17,171,164);}"   //鼠标点击边框时的边框颜色
                              "border:2px solid rgb(20,196,188);");                       //边框粗细-颜色-圆角设置
    ui->enter_pass->setEchoMode(QLineEdit::Password);//输入密码为黑点
    ui->enter_pass->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                       //字体
                                  "color: rgb(31,31,31);"                                  //字体颜色
                                  "padding-left:20px;"                                     //内边距-字体缩进
                                  "background-color: rgb(255, 255, 255);"                  //背景颜色
                                  "border:2px solid rgb(20,196,188);"                      //2像素宽度和2像素高度的实线边框
                                  "border-radius:15px;");                                  //边框粗细-颜色-圆角设置"
    this->setStyleSheet("background-color: qlineargradient"                                //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,248,255, 255), stop:1 rgba(240,248,255, 255));");
    this->show();                                                                          //展示页面
}
EnterPassword::~EnterPassword()
{
    delete ui;
}
void EnterPassword::on_Submit_clicked()                                                    //管理员已登录可以直接完成
{
    if(admin->status == Admin::LOGIN){
        this->State = true;
        this->close();
    }
    QString Pa = ui->enter_pass->text();                                                   //获取输入的内容
    std::string pass = Pa.toStdString();
    this->State = admin->VerifyPass(pass);                                                 //检查密码
    if (this->State == false){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","密码错误或被锁定！");                                  //提示密码输入对错
        messageBox.setFixedSize(500,200);
    }else{
        QMessageBox messageBox;
        messageBox.information(nullptr,"信息","登陆成功！");
        messageBox.setFixedSize(500,200);
    }
    this->inOperation = false;
    this->close();                                                                         //关闭当前页面
}
bool EnterPassword::GetState(){
    return State;
}
