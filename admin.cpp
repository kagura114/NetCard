#include "admin.h"

Admin::Admin(string pas,string pa)
{

    //初始化数据
    attempts = 0;
    status   = LOGOUT;
    students = new vector<Student*>;
    path	 = pa;
    password = pas;
    //强制创建默认学生

}

Admin::~Admin()= default;

Admin* Admin::AddAdmin(string path){
    using namespace std::filesystem;
    //打开文件并读取
    ifstream in(path + "/Admin.txt");
    string pass = "";
    string status;
    in >> status;
    if (status == to_string(LOCK)){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","已锁定！请联系xxx解锁管理员账号！");
        messageBox.setFixedSize(500,200);
    }
    int encryptedChar;
    string psw;
    while (in >> encryptedChar)
        psw += (char)(encryptedChar - 3);
    Admin* a = new Admin(psw,path);
    return a;
}

void Admin::Save()
{
    using namespace std::filesystem;

    //检测是否存在文件夹
    if (!filesystem::exists(path)) {
        create_directories(path);
    }
    //保存自身信息
    ofstream out(path + "/Admin.txt");
    out << status << endl;
    for (auto i : password)
    {
        out << (int)i + 3;
        out << " ";
    }
    out << endl; //将密码转化为数字提高辨识难度
    out.close();
    //保存学生信息
    for (auto& i : *students)
    {
        ofstream saver = ofstream(path + "/Students/" + to_string(i->id) + ".txt");
        saver << i->GetData() << endl;
        saver.close();
    }
}
void Admin::AddStudent(Student *s){
    this->students->push_back(s);
}

Student* Admin::SearchStudent(uint32_t id)
{
    for (auto& i : *students)
    {
        if (i->id == id)
            return i;
    }
    QMessageBox messageBox;
    messageBox.critical(0,"Error","没有找到持有这个卡号的学生！");
    messageBox.setFixedSize(500,200);
    return nullptr;
}
bool Admin::VerifyPass(string pass){
    if (pass==this->password){
        this->status = LOGIN;
        return true;
    }
    else return false;
}
