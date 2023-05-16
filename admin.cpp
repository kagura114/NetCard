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
    auto *s = new Student;
    s->name = "学校公用账号";
    s->id = 0;
    s->SchoolID = "0";
    s->status = Student::NORMAL;
    s->start_worktime();
    s->finish_worktime();
    students->push_back(s);
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
    //检查目录存在
    if (!std::filesystem::exists(path + "/Students/"))
        filesystem::create_directories(path + "/Students/");
    for (auto& i : *students)
    {
        string new_path = path + "/Students/" + to_string(i->id) + ".txt";
        ofstream saver = ofstream(new_path);
        string data = i->GetData();
        saver << data;
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

    return nullptr;
}
Student* Admin::SearchStudent(string n)
{
    for (auto& i : *students)
    {
        if (i->name == n)
            return i;
    }
    return nullptr;
}

Student* Admin::SearchStudent(string schoolid, bool i)
{
    for (auto& i : *students)
    {
        if (i->SchoolID == schoolid)
            return i;
    }
    return nullptr;
}
bool Admin::VerifyPass(string pass){

    if(attempts==5){
        this->status = LOCK;
    }
    if(this->status==LOCK){
        return false;
    }
    if (pass==this->password){
        this->status = LOGIN;
        attempts = 0;
        return true;
    }
    else {
        attempts++;
        return false;}

}
bool Admin::verifyStudent(Student* s){
    for(auto i : *students){
        if(i->id==s->id)
            return false;
    }
    return true;
}

bool Admin::isLogin(){
    if (status==LOGIN)
        return true;
    else
        return false;
}
