#include "createadmin.h"
#include "ui_createadmin.h"

CreateAdmin::CreateAdmin(string Path,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateAdmin)
{
    this->path = Path;
    ui->setupUi(this);
    admin = nullptr;
    ui->pushButton->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->pushButton_2->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                    "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                    "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
     ui->Passwd->setEchoMode(QLineEdit::Password);//输入密码为黑点
     ui->Passwd->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                               "color: rgb(31,31,31);"  //字体颜色
                               "padding-left:20px;"       //内边距-字体缩进
                               "background-color: rgb(255, 255, 255);" //背景颜色
                               "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    this->setStyleSheet("background-color: qlineargradient"
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(250,240,230, 255), stop:1 rgba(250,240,230, 255));");
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

        QMessageBox messageBox;
        messageBox.information(nullptr,"信息","创建成功！");
        messageBox.setFixedSize(500,200);

        this->close();//关闭当前界面
        auto* c = new Menu(admin);
        c->show();
    }
}
