#include "usepc.h"
#include "ui_usepc.h"
UsePC::UsePC(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UsePC)
{
    ui->setupUi(this);
    this->admin = a;
    ui->change_mode->setStyleSheet("QPushButton{"
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
    ui->query_state->setStyleSheet("QPushButton{"
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
    ui->exit_btn->setStyleSheet("QPushButton{"
                                "font: 25 14pt '微软雅黑 regular';"                             //字体大小，形状
                                "color: rgb(0,0,0);"                                           //字体颜色
                                "background-color: rgb(255,248,220);"                          //背景颜色
                                "border: 2px groove gray;"                                     //设置控件边属性为2像素，凹槽形式为灰色
                                "border-radius:15px;"                                          //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                "padding:2px 4px;"                                             //控制内边距像素
                                "border-style: outset;}"                                       //边框的凸边部分的样式
                                "QPushButton:hover{background-color: rgb(22,218,208);}"        //鼠标悬停在边框时的边框颜色
                                "QPushButton:pressed{background-color: rgb(17,171,164);}"      //鼠标点击边框时的边框颜色
                                "border:2px solid rgb(20,196,188);");                          //边框粗细-颜色-圆角设置
    ui->enter_id->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                             //字体
                                "color: rgb(31,31,31);"                                        //字体颜色
                                "padding-left:20px;"                                           //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);"                        //背景颜色
                                "border:2px solid rgb(20,196,188);"                            //2像素宽度和2像素高度的实线边框
                                "border-radius:15px;");                                        //边框粗细-颜色-圆角设置"
    this->setStyleSheet("background-color: qlineargradient"                                    //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255,250,250, 255), stop:1 rgba(255,250,250, 255));");
    this->student = nullptr;
    this->show();                                                                              //最后显示完成的页面
}
UsePC::~UsePC()
{
    delete ui;
}
void UsePC::on_change_mode_clicked()                                                           //决定功能
{
    if(ui->change_mode->text()=="功能"){                                                        //查询状态
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请先查询状态！");
        messageBox.setFixedSize(500,200);
    }else if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;                                                                //输入学号
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
    }else if(ui->change_mode->text()=="--"){
        QMessageBox messageBox;                                                                //提示错误操作
        messageBox.critical(0,"Error","该状态下不允许操作");
        messageBox.setFixedSize(500,200);
    }else if(this->student==nullptr){                                                          //防止空指针
        QMessageBox messageBox;                                                                //提示重新查询
        messageBox.critical(0,"Error","请重新查询");
        messageBox.setFixedSize(500,200);
        ui->change_mode->setText("功能");
    }else if(ui->change_mode->text()=="上机"){                                                  //提示上机
        student->start_worktime();
        student->status = Student::status::LOGIN;
        string s = student->name + "在" + student->toNormalTime(student->start_time) + " 开始上机！";
        QMessageBox messageBox;
        QString qstr = QString::fromStdString(s);                                               //提示下机
        messageBox.information(0,"结果",qstr.fromStdString(s));
        messageBox.setFixedSize(500,200);
    }else if(ui->change_mode->text()=="下机"){
        if(!admin->isLogin()){                                                                  //需要登录
            QMessageBox messageBox;
            messageBox.critical(0,"Error","请先登录");
            messageBox.setFixedSize(500,200);
            auto *c = new EnterPassword(admin);
        }else{
        student->finish_worktime();                                                             //显示结束上机时间
        student->status = Student::status::NORMAL;                                              //上机状态
        string s = student->name + "在" + student->toNormalTime(student->finish_time) + " 结束上机！";
        s+= "\n共消费" + to_string(student->last_cost) + "元";                                   //上机消费金额
             s+= "\n可用余额为" + to_string(student->balance) + "元。";
                                        if(student->balance<=0)
            s+="\n余额不足请联系管理员充值！";
        QMessageBox messageBox;
        QString qstr = QString::fromStdString(s);
        messageBox.information(0,"结果",qstr.fromStdString(s));
        messageBox.setFixedSize(500,200);
        }
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","出错了");
        messageBox.setFixedSize(500,200);
        this->close();                                                                            //关闭此前页面
    }
    //重置清空
    this->student = nullptr;
    ui->enter_id->clear();
    ui->change_mode->setText("功能");
}
void UsePC::on_query_state_clicked()
{
    if(ui->enter_id->text().isNull()){                                                            //输入学号操作
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
        return;
    }else{
        uint32_t id;
        try {
        id = stoi(ui->enter_id->text().toStdString());
        } catch (...) {
        QMessageBox messageBox;                                                                   //输入卡号操作
        messageBox.critical(0,"Error","请输入仅数字学号！");
        messageBox.setFixedSize(500,200);
        }
        auto* s = admin->SearchStudent(id);
        if (s==nullptr){
            QMessageBox messageBox;                                                               //查找目标学号
            messageBox.critical(0,"Error","无法查询到所要的学号");
            messageBox.setFixedSize(500,200);
            return;
        }else{
            QMessageBox messageBox;
            switch(s->status){
            case Student::status::LOGIN:                                                          //上机，即登录状态
                messageBox.information(0,"结果","正在上机中，让管理员点击中间按钮以下机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("下机");
                this->student = s;
                break;
            case Student::status::NORMAL:                                                         //下机，即正常状态
                messageBox.information(0,"结果","没有上机，请点击中间按钮上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("上机");
                this->student = s;
                break;
            case Student::status::LOST:                                                           //挂失，即挂失状态
                messageBox.critical(0,"结果","已挂失，不可上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("--");
                break;
            case Student::status::FREEZE:                                                         //冻结，即冻结状态
                messageBox.critical(0,"结果","已冻结，不可上机！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("--");
                break;
            }
            return;
        }
        this->student = nullptr;                                                                  //重置清空
        ui->enter_id->clear();
        ui->change_mode->setText("功能");
    }
}
void UsePC::on_exit_btn_clicked()
{
    this->close();                                                                                //关闭此前页面
}
