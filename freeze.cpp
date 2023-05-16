#include "freeze.h"
#include "ui_freeze.h"

Freeze::Freeze(Admin *a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Freeze)
{
    this->admin = a;
    ui->setupUi(this);
    this->student = nullptr;
    ui->need_admin_box->setCheckable(false);    //先禁止选中
    ui->change_mode->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                   "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                   "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                   "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                   "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->query_state->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                   "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                   "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                   "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                   "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->exit_btn->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 regular';color: rgb(0,0,0);background-color: rgb(255,248,220);"
                                "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置
    ui->enter_id->setStyleSheet("font: 20 20pt '微软雅黑 regular';" //字体
                                "color: rgb(31,31,31);"  //字体颜色
                                "padding-left:20px;"       //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);" //背景颜色
                                "border:2px solid rgb(20,196,188);border-radius:15px;");//边框粗细-颜色-圆角设置");
    this->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(240,255,255, 255), stop:1 rgba(240,255,255, 255));");
    //最后显示完成的页面
    this->show();
}

Freeze::~Freeze()
{
    delete ui;
}

void Freeze::on_change_mode_clicked()
{
    if(ui->change_mode->text()=="功能"){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请先查询状态！");
        messageBox.setFixedSize(500,200);
    }else if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
    }else if(this->student==nullptr){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请重新查询状态!");
        messageBox.setFixedSize(500,200);
    }else if(ui->change_mode->text()=="挂失"){
        student->status = Student::LOST;
        QMessageBox messageBox;
        messageBox.warning(0,"Error","已挂失！");
        messageBox.setFixedSize(500,200);
    }else if(ui->change_mode->text()=="解挂"){
        if(student->status != Student::FREEZE){             //解冻是管理员专有的
            QMessageBox messageBox;
            messageBox.information(0,"Error","只可以解冻！");
            messageBox.setFixedSize(500,200);
            reset();
            return;
        }
        student->status = Student::NORMAL;
        QMessageBox messageBox;
        messageBox.information(0,"Error","已解除挂失！");
        messageBox.setFixedSize(500,200);
        this->student = nullptr;
        ui->enter_id->clear();
    }else if(ui->change_mode->text()=="冻结"){
        if(admin->isLogin()){                   //冻结是管理员操作
            if(student->status==Student::LOGIN) //强制下线
                student->finish_worktime();
            student->status = Student::FREEZE;
            QMessageBox messageBox;
            messageBox.warning(0,"Error","已强制冻结！");
            messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","请先登录");
            messageBox.setFixedSize(500,200);
            auto *c = new EnterPassword(admin);
        }
    }else if(ui->change_mode->text()=="解冻"){
        if(admin->isLogin()){                   //解冻是管理员操作
            student->status = Student::NORMAL;
            QMessageBox messageBox;
            messageBox.information(0,"Error","已解除冻结！");
            messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            messageBox.critical(0,"Error","请先登录");
            messageBox.setFixedSize(500,200);
            auto *c = new EnterPassword(admin);
        }
    }else{
        QMessageBox messageBox;
        messageBox.critical(0,"Error","出错了");
        messageBox.setFixedSize(500,200);
        this->close();
    }
    reset();
}


void Freeze::on_query_state_clicked()
{
    if(ui->enter_id->text().isNull()){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请输入学号！");
        messageBox.setFixedSize(500,200);
        return;
    }else{
        uint32_t id;
        try {
            id = stoi(ui->enter_id->text().toStdString());
        } catch (...) {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","请输入仅数字学号！");
            messageBox.setFixedSize(500,200);
        }
        auto* s = admin->SearchStudent(id);
        if (s==nullptr){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","无法查询到所要的学号");
            messageBox.setFixedSize(500,200);
        }else{
            QMessageBox messageBox;
            switch(s->status){
            case Student::status::LOGIN: //上机
                messageBox.information(0,"结果","正常");
                messageBox.setFixedSize(500,200);
                if (ui->need_admin_box->isChecked())
                    ui->change_mode->setText("冻结");
                else
                    ui->change_mode->setText("挂失");
                this->student = s;
                break;
            case Student::status::NORMAL: //下机
                messageBox.information(0,"结果","正常");
                messageBox.setFixedSize(500,200);
                if (ui->need_admin_box->isChecked())
                   ui->change_mode->setText("冻结");
                else
                    ui->change_mode->setText("挂失");
                this->student = s;
                break;

            case Student::status::LOST: //挂失
                messageBox.critical(0,"结果","已挂失,如果找回请解挂！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("解挂");
                this->student = s;
                break;

            case Student::status::FREEZE: //冻结
                messageBox.critical(0,"结果","已冻结,请找管理员解冻！");
                messageBox.setFixedSize(500,200);
                ui->change_mode->setText("解冻");
                this->student = s;
                break;

            }
            ui->need_admin_box->setCheckable(true);

        }
    }
}


void Freeze::on_exit_btn_clicked()
{
    this->close();
}
void Freeze::reset(){
    this->student = nullptr;
    ui->enter_id->clear();
    ui->change_mode->setText("功能");
    ui->need_admin_box->setCheckable(false);
    ui->need_admin_box->setCheckState(Qt::CheckState::Unchecked);
}

void Freeze::on_need_admin_box_stateChanged(int arg1)
{
    //改变按钮上面的字
    if(ui->change_mode->text()=="功能"){

    }else if(ui->change_mode->text()=="挂失"&&ui->need_admin_box->isChecked()){
        ui->change_mode->setText("冻结");
    }else if(ui->change_mode->text()=="解挂"&&ui->need_admin_box->isChecked()){
        ui->change_mode->setText("解冻");
    }else if(ui->change_mode->text()=="冻结"&&!ui->need_admin_box->isChecked()){
        ui->change_mode->setText("挂失");
    }else if(ui->change_mode->text()=="解冻"&&!ui->need_admin_box->isChecked()){
        ui->change_mode->setText("解挂");
    }
}

