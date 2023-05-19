#include "createproject.h"
#include "ui_createproject.h"
CreateProject::CreateProject(QWidget *parent,bool createN) :
    QWidget(parent),
    ui(new Ui::CreateProject)
{
    this->createnew = createN;
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet("QPushButton{"
                                    "font: 25 14pt '微软雅黑 regular';"                                //字体大小，形状
                                    "color: rgb(0,0,0);"                                              //字体颜色
                                    "background-color: rgb(255,248,220);"                             //背景颜色
                                    "border: 2px groove gray;"                                        //设置控件边属性为2像素，凹槽形式为灰色
                                    "border-radius:15px;"                                             //元素边框产生圆角，且四个角的水平和垂直半径为15px
                                    "padding:2px 4px;"                                                //控制内边距像素
                                    "border-style: outset;}"                                          //边框的凸边部分的样式
                                    "QPushButton:hover{background-color: rgb(22,218,208);}"           //鼠标悬停在边框时的边框颜色
                                    "QPushButton:pressed{background-color: rgb(17,171,164);}"         //鼠标点击边框时的边框颜色
                                    "border:2px solid rgb(20,196,188);");                             //边框粗细-颜色-圆角设置
    ui->Enter->setStyleSheet("QPushButton{"
                             "font: 25 14pt '微软雅黑 regular';"                                       //字体大小，形状
                             "color: rgb(0,0,0);"                                                     //字体颜色
                             "background-color: rgb(255,248,220);"                                    //背景颜色
                             "border: 2px groove gray;"                                               //设置控件边属性为2像素，凹槽形式为灰色
                             "border-radius:15px;"                                                    //元素边框产生圆角，且四个角的水平和垂直半径为15px
                             "padding:2px 4px;"                                                       //控制内边距像素
                             "border-style: outset;}"                                                 //边框的凸边部分的样式
                             "QPushButton:hover{background-color: rgb(22,218,208);}"                  //鼠标悬停在边框时的边框颜色
                             "QPushButton:pressed{background-color: rgb(17,171,164);}"                //鼠标点击边框时的边框颜色
                             "border:2px solid rgb(20,196,188);");                                    //边框粗细-颜色-圆角设置
    ui->Restart->setStyleSheet("QPushButton{"
                               "font: 25 14pt '微软雅黑 regular';"                                     //字体大小，形状
                               "color: rgb(0,0,0);"                                                   //字体颜色
                               "background-color: rgb(255,248,220);"                                  //背景颜色
                               "border: 2px groove gray;"                                             //设置控件边属性为2像素，凹槽形式为灰色
                               "border-radius:15px;"                                                  //元素边框产生圆角，且四个角的水平和垂直半径为15px
                               "padding:2px 4px;"                                                     //控制内边距像素
                               "border-style: outset;}"                                               //边框的凸边部分的样式
                               "QPushButton:hover{background-color: rgb(22,218,208);}"                //鼠标悬停在边框时的边框颜色
                               "QPushButton:pressed{background-color: rgb(17,171,164);}"              //鼠标点击边框时的边框颜色
                               "border:2px solid rgb(20,196,188);");                                  //边框粗细-颜色-圆角设置
    ui->Path->setStyleSheet("font: 20 20pt '微软雅黑 regular';"                                        //字体
                            "color: rgb(31,31,31);"                                                   //字体颜色
                            "padding-left:20px;"                                                      //内边距-字体缩进
                            "background-color: rgb(255, 255, 255);"                                   //背景颜色
                            "border:2px solid rgb(20,196,188);"                                       //2像素宽度和2像素高度的实线边框
                            "border-radius:15px;");                                                   //边框粗细-颜色-圆角设置"
    this->setStyleSheet("background-color: qlineargradient"                                           //界面背景颜色
                      "(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255,250,205, 255), stop:1 rgba(255,250,205, 255));");
    if (createN)                                                                                      //动态渲染头部的文字
        this->ui->CurrentState->setText("请输入要创建的工作目录");
    else
        this->ui->CurrentState->setText("请输入已存在的工作目录");
}
CreateProject::~CreateProject()
{
    delete ui;
}
void CreateProject::on_Enter_clicked()                                                                 //获取输入的内容
{
    QString Pa = ui->Path->text();
    std::string file = Pa.toStdString();
    bool success = true;
    if (createnew)                                                                                     //只有新建才会尝试创建文件夹
    {
        try {
            std::filesystem::create_directory(file);
        } catch (...) {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","输入的路径无法访问！");
            messageBox.setFixedSize(500,200);
            success = false;
        }
    }
    if (!std::filesystem::exists(file))                                                                //检查路径存在和创建成功
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","输入的路径不存在！");
        messageBox.setFixedSize(500,200);
        success = false;
    }
    if (success && createnew)                                                                          //进入创建管理员界面
    {
        this->close();                                                                                 //关闭当前界面
        auto* c = new CreateAdmin(file);
        c->show();
    }
    else if(success && !createnew)                                                                     //读取文件
    {
        bool readSuccess = true;
        try {
            Admin *a = Admin::AddAdmin(file);                                                          //读取所有学生
            std::vector<std::string> file_paths;                                                       // 获取文件目录列表
            for (const auto& entry : std::filesystem::recursive_directory_iterator(file+"/Students/")) //不包含非文件
            {
                if (entry.is_regular_file()) {
                    file_paths.push_back(entry.path().string());
                }
            }
            for (const string &path : file_paths)                                                      //加载学生
            {
                Student* stu = new Student(path);
                a->AddStudent(stu);
            }

            this->close();                                                                             //关闭当前界面
            auto* c = new Menu(a);
            c->show();                                                                                 //打开管理员管理页面
        } catch (...) {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","读取路径时出现了问题！");
            messageBox.setFixedSize(500,200);
        }
    }
}
void CreateProject::on_Restart_clicked()
{
    //切换模式
    this->close();                                                                                     //关闭当前界面
    auto* c = new CreateProject(nullptr,!this->createnew);                                             //反转创建控制位
    c->show();
}
