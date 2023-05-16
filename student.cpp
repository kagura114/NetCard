#include "student.h"

Student::Student()
{
    start_worktime();
    finish_worktime();
    this->place = classroom;
    this->status = NORMAL;
}

string Student::GetData(){
    string result = "";
    result += to_string(id) + "\n";         //卡号
    result += name + "\n";                  //姓名
    result += password + "\n";              //密码
    result += to_string(recharge) + "\n";	//充值金额
    result += to_string(cost) + "\n";		//花费
    result += to_string(remain) + "\n";		//余额
    result += to_string(status) + "\n";		//卡账户状态
    result += to_string(place) + "\n";		//上机地点
    result += to_string(start_time.time_since_epoch().count()) + "\n";	//开始上机的时间
    result += to_string(finish_time.time_since_epoch().count()) + "\n";	//结束上机的时间
    return result;
}


Student::Student(string filename){
    auto* student = this;
    ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> student->id;
        inFile.ignore();
        getline(inFile, student->name);
        getline(inFile, student->password);
        inFile >> student->recharge;
        inFile >> student->cost;
        inFile >> student->remain;
        string status,place;
        inFile >> status;
        if (status == to_string(Student::status::FREEZE)){
            student->status = Student::status::FREEZE;
        }else         if (status == to_string(Student::status::LOST)){
            student->status = Student::status::LOST;
        }else         if (status == to_string(Student::status::NORMAL)){
            student->status = Student::status::NORMAL;
        }else         if (status == to_string(Student::status::LOGIN)){
            student->status = Student::status::LOGIN;
        }
        inFile >> place;
        if (place == to_string(Student::place::classroom)){
            student->place = Student::place::classroom;
        }else         if (place == to_string(Student::place::dormitory)){
            student->place = Student::place::dormitory;
        }else         if (place == to_string(Student::place::CS_buliding)){
            student->place = Student::place::CS_buliding;
        }else         if (place == to_string(Student::place::library)){
            student->place = Student::place::library;
        }

        time_t start_time, finish_time;
        inFile >> start_time;
        student->start_time = chrono::system_clock::time_point(chrono::system_clock::duration(start_time));
        inFile >> finish_time;
        student->finish_time = chrono::system_clock::time_point(chrono::system_clock::duration(finish_time));
        inFile.close();
    }
}

string Student::workplace()
{
    string result = "";
    switch (place)
    {
    case Student::classroom:
        result += "上机地点：南京邮电大学教室";
        break;
    case Student::CS_buliding:
        result += "上机地点：南京邮电大学计算机学科楼";
        break;
    case Student::library:
        result += "上机地点：南京邮电大学图书馆";
        break;
    case Student::dormitory:
        result += "上机地点：南京邮电大学桂苑";
        break;
    default:
        result += "上机地点：南京邮电大学校外";
        break;
    }
    return result;

}
void Student::start_worktime(enum place where)
{
    auto now = std::chrono::system_clock::now();
    place = where;
    start_time = now;
}
void Student::finish_worktime()
{
    auto now = chrono::system_clock::now();
    finish_time = now;
    //计算上机时间
    auto duration = chrono::duration_cast<std::chrono::seconds>(finish_time - start_time);
    cost += duration.count() * 0.1;
    last_cost = duration.count() * 0.1;
    remain = recharge - cost;
}
string Student::GetStatus()
{//卡账户状态
    string result = "";
    switch (status)
    {
    case Student::NORMAL:
        result += "正常";
        break;
    case
        Student::LOST:result += "挂失";
        break;
    case
        Student::FREEZE:result += "冻结";
        break;
    case
        Student::LOGIN:result += "上机";
        break;
    default:
        result += "未知";
        break;
   }
    return result;

}

string Student::GetInfo()
{
    string result = "";
    result += "学生卡号：" + to_string(id) + "\n";	//卡号
    result += "学生姓名：" + name + "\n";			//姓名
    result += "学生充值金额：" + to_string(recharge) + "\n";	//充值金额
    result += "学生花费：" + to_string(cost) + "\n";		//花费
    result += "学生余额：" + to_string(remain) + "\n";		//余额
    result += "学生卡账户状态："  + GetStatus() + "\n";		//卡账户状态
    result += "学生" + workplace() + "\n";		//上机地点
    result += "学生开始上机的时间：" + toNormalTime(start_time) + "\n";		//开始上机的时间
    result += "学生结束上机的时间：" + toNormalTime(finish_time) + "\n";	//结束上机的时间
    return result;
}

string Student::toNormalTime(chrono::system_clock::time_point t){//timepoint转化为人类可读的形式
    using time_point = std::chrono::system_clock::time_point;
    const string format = "%Y-%m-%d %H:%M:%S";
    std::time_t tt = std::chrono::system_clock::to_time_t(t);
    std::tm tm = *std::localtime(&tt); //GMT+8
    std::stringstream ss;
    ss << std::put_time(&tm, format.c_str());
    return ss.str();
}
