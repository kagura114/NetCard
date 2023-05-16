#include "createproject.h"
#include "ui_createproject.h"

CreateProject::CreateProject(QWidget *parent,bool createN) :
    QWidget(parent),
    ui(new Ui::CreateProject)
{
    this->createnew = createN;
    ui->setupUi(this);
}

CreateProject::~CreateProject()
{
    delete ui;
}

void CreateProject::on_Enter_clicked()
{
    //获取输入的内容
    QString Pa = ui->Path->text();
    std::string file = Pa.toStdString();
    bool success = true;

    if (createnew){
        try {
            std::filesystem::create_directory(file);
        } catch (...) {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","输入的路径无法访问！");
            messageBox.setFixedSize(500,200);
            success = false;
        }
    }
    //检查路径存在和创建成功
    if (!std::filesystem::exists(file)) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","输入的路径不存在！");
        messageBox.setFixedSize(500,200);
        success = false;
    }
    //进入创建管理员界面
    if (success && createnew){
        this->close();//关闭当前界面
        auto* c = new CreateAdmin(file);
        c->show();
    }
    //读取文件
    else if(success && !createnew){
        bool readSuccess = true;
        try {
            Admin *a = Admin::AddAdmin(file);
            //读取所有学生
            std::vector<std::string> file_paths;
            // 获取文件目录列表
            for (const auto& entry : std::filesystem::recursive_directory_iterator(file+"/Students/")) {
                //不包含非文件
                if (entry.is_regular_file()) {
                    file_paths.push_back(entry.path().string());
                }
            }
            //加载学生
            for (const string &path : file_paths) {
                Student* stu = new Student(path);
                a->AddStudent(stu);
            }

            //打开管理员管理页面
        } catch (...) {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","读取路径时出现了问题！");
            messageBox.setFixedSize(500,200);
        }



    }

}

