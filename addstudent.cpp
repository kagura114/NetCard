#include "addstudent.h"
#include "ui_addstudent.h"
AddStudent::AddStudent(Admin* a,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    this->admin = a;
    this->show();
    ui->ClearID->setStyleSheet("QPushButton{"
                               "font: 25 14pt '微软雅黑 regular';"                                 //字体大小，形状
                               "color: rgb(0,0,0);"                                              //字体颜色
                               "background-color: rgb(255,248,220);"                             //背景颜色
                               "border: 2px groove gray;"                                        //设置控件边属性为2像素，凹槽形式为灰色
                               "border-radius:15px;"                                             //元素边框产生圆角，且四个角的水平和垂直半径为15px
                               "padding:2px 4px;"                                                //控制内边距像素
                               "border-style: outset;}"                                          //边框的凸边部分的样式
                               "QPushButton:hover{background-color: rgb(22,218,208);}"           //鼠标悬停在边框时的边框颜色
                               "QPushButton:pressed{background-color: rgb(17,171,164);}"         //鼠标点击边框时的边框颜色
                               "border:2px solid rgb(20,196,188);");                             //边框粗细-颜色-圆角设置
    ui->ClearName->setStyleSheet("QPushButton{"
                                 "font: 25 14pt '微软雅黑 regular';"                              //字体大小，形状
                                 "color: rgb(0,0,0);"                                            //字体颜色
                                 "background-color: rgb(255,248,220);"                           //背景颜色
                                 "border: 2px groove gray;"                                      //设置控件边属性为2像素，凹槽形式为灰色
                                 "border-radius:15px;"                                           //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                 "padding:2px 4px;"                                              //控制内边距像素
                                 "border-style: outset;}"                                        //边框的凸边部分的样式
                                 "QPushButton:hover{background-color: rgb(22,218,208);}"         //鼠标悬停在边框时的边框颜色
                                 "QPushButton:pressed{background-color: rgb(17,171,164);}"       //鼠标点击边框时的边框颜色
                                 "border:2px solid rgb(20,196,188);");                           //边框粗细-颜色-圆角设置
    ui->ClearSchoolID->setStyleSheet("QPushButton{"
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
    ui->ID->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                                     //字体
                          "color: rgb(31,31,31);"                                                //字体颜色
                          "padding-left:20px;"                                                   //内边距-字体缩进
                          "background-color: rgb(255, 255, 255);"                                //背景颜色
                          "border:2px solid rgb(20,196,188);"                                    //2像素宽度和2像素高度的实线边框
                          "border-radius:15px;");                                                //边框粗细-颜色-圆角设置"
    ui->SchoolID->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                               //字体
                                "color: rgb(31,31,31);"                                          //字体颜色
                                "padding-left:20px;"                                             //内边距-字体缩进
                                "background-color: rgb(255, 255, 255);"                          //背景颜色
                                "border:2px solid rgb(20,196,188);"                              //2像素宽度和2像素高度的实线边框
                                "border-radius:15px;");                                          //边框粗细-颜色-圆角设置"
    ui->Name->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                                   //字体
                            "color: rgb(31,31,31);"                                              //字体颜色
                            "padding-left:20px;"                                                 //内边距-字体缩进
                            "background-color: rgb(255, 255, 255);"                              //背景颜色
                            "border:2px solid rgb(20,196,188);"                                  //2像素宽度和2像素高度的实线边框
                            "border-radius:15px;");                                              //边框粗细-颜色-圆角设置"
    ui->Submit->setStyleSheet("QPushButton{"
                              "font: 25 14pt '微软雅黑 regular';"                                  //字体大小，形状
                              "color: rgb(0,0,0);"                                                //字体颜色
                              "background-color: rgb(255,248,220);"                               //背景颜色
                              "border: 2px groove gray;"                                          //设置控件边属性为2像素，凹槽形式为灰色
                              "border-radius:15px;"                                               //元素边框产生圆角，且四个角的水平和垂直半径为15px
                              "padding:2px 4px;"                                                  //控制内边距像素
                              "border-style: outset;}"                                            //边框的凸边部分的样式
                              "QPushButton:hover{background-color: rgb(22,218,208);}"             //鼠标悬停在边框时的边框颜色
                              "QPushButton:pressed{background-color: rgb(17,171,164);}"           //鼠标点击边框时的边框颜色
                              "border:2px solid rgb(20,196,188);");                               //边框粗细-颜色-圆角设置
    this->setStyleSheet("background-color: qlineargradient"                                       //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(250,235,215, 255), stop:1 rgba(250,235,215, 255));");
    if(admin->status!=Admin::LOGIN)                                                               //叠在上个窗口上面
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","请先登录");
        messageBox.setFixedSize(500,200);
        auto *c = new EnterPassword(admin);
    }
}
AddStudent::~AddStudent()
{
    delete ui;
}
void AddStudent::on_Submit_clicked()
{
    try {
        auto *s = new Student();                                                                    //读取数据
        string name = ui->Name->text().toStdString();
        uint32_t id = stoi(ui->ID->text().toStdString());
        string SchoolID = ui->SchoolID->text().toStdString();
        if(name.empty())                                                                            //检查非空
            name="No Name";
        if(SchoolID.empty())
            SchoolID="0"; 
        s->name = name;                                                                             //赋值
        s->id   = id;
        s->SchoolID = SchoolID;
        if(!admin->verifyStudent(s))                                                                //检查ID数据
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","ID已存在，不允许重复添加");
            messageBox.setFixedSize(500,200);
            delete s;
            this->close();
        }
        else if(admin->status==Admin::LOGIN)                                                        //验证登陆状态
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
            delete s;
            this->close();                                                                          //关闭当前界面
        }
    }
    catch (...) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","添加学生失败！");
        messageBox.setFixedSize(500,200);
    }
    this->close();                                                                                  //关闭当前界面
}
