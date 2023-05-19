#include "student.h"
Student::Student()
{
    start_worktime();
    finish_worktime();
    this->place = classroom;
    this->status = NORMAL;
}
string Student::GetData(){
    string result = "";               //初始化一个空字符串 result，用于存储生成的数据
    result += to_string(id) + "\n";                                     //卡号
    result += name + "\n";                                              //姓名
    result += to_string(recharge) + "\n";	                            //充值金额
    result += to_string(cost) + "\n";		                            //花费
    result += to_string(balance) + "\n";	                            //余额
    result += to_string(status) + "\n";		                            //卡账户状态
    result += to_string(place) + "\n";		                            //上机地点
    result += to_string(start_time.time_since_epoch().count()) + "\n";	//开始上机的时间
    result += to_string(finish_time.time_since_epoch().count()) + "\n";	//结束上机的时间
    return result;
}
Student::Student(string filename)
{
    auto* student = this;//声明一个指向当前对象的指针，将其赋值给名为 student 的成员变量
    ifstream inFile(filename);
    if (inFile.is_open()) {//检查文件是否成功打开
        inFile >> student->id;//从文件中读取学生 ID 并将其附加到 student 对象的 id 成员变量
        inFile.ignore();//忽略文件中的下一个字符
        getline(inFile, student->name);
        inFile >> student->recharge;                                     //充值
        inFile >> student->cost;                                         //花费
        inFile >> student->balance;                                      //余额
        string status,place;
        inFile >> status;
        if (status == to_string(Student::status::FREEZE)){
            student->status = Student::status::FREEZE;                   //冻结状态
        }else         if (status == to_string(Student::status::LOST)){
            student->status = Student::status::LOST;                     //挂失状态
        }else         if (status == to_string(Student::status::NORMAL)){
            student->status = Student::status::NORMAL;                   //正常状态
        }else         if (status == to_string(Student::status::LOGIN)){
            student->status = Student::status::LOGIN;                    //登录状态
        }
        inFile >> place;                                                 //上机地点
        if (place == to_string(Student::place::classroom)){
            student->place = Student::place::classroom;//
        }else         if (place == to_string(Student::place::dormitory)){
            student->place = Student::place::dormitory;
        }else         if (place == to_string(Student::place::CS_buliding)){
            student->place = Student::place::CS_buliding;
        }else         if (place == to_string(Student::place::library)){
            student->place = Student::place::library;
        }
        time_t start_time, finish_time;                                   //开始/结束上机时间
        inFile >> start_time;
        student->start_time = chrono::system_clock::time_point(chrono::system_clock::duration(start_time));
        inFile >> finish_time;
        student->finish_time = chrono::system_clock::time_point(chrono::system_clock::duration(finish_time));
        inFile.close();
    }
}
string Student::workplace()//解析上机地点
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
    auto now = std::chrono::system_clock::now();                                              //利用时间戳计算当前上机的时间
    place = where;
    start_time = now;
}
void Student::finish_worktime()
{
    auto now = chrono::system_clock::now();                                                   //利用时间戳计算结束上机的时间
    finish_time = now;
    auto duration = chrono::duration_cast<std::chrono::seconds>(finish_time - start_time);    //计算上机时间
    cost += duration.count() * 0.1;
    last_cost = duration.count() * 0.1;
    balance = recharge - cost;
}
string Student::GetStatus()//卡账户状态
{
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
    result += "学生卡号：" + to_string(id) + "\n";	                                      //卡号
    result += "学生姓名：" + name + "\n";			                                          //姓名
    result += "学生学号：" + SchoolID + "\n";			                                      //学号
    result += "学生充值金额：" + to_string(recharge) + "\n";	                              //充值金额
    result += "学生花费：" + to_string(cost) + "\n";		                                  //花费
    result += "学生余额：" + to_string(balance) + "\n";		                              //余额
    result += "学生卡账户状态："  + GetStatus() + "\n";		                              //卡账户状态
    result += "学生" + workplace() + "\n";		                                          //上机地点
    if (start_time.time_since_epoch().count()-finish_time.time_since_epoch().count()<=60) //没上过机的两个时间差别极小(创建时两个时间实际差值小于50纳秒)
    {
        result += "账户创建的时间：" + toNormalTime(start_time) + "\n";	                  //账户创建的时间
    }
    else
    {
    result += "学生开始上机的时间：" + toNormalTime(start_time) + "\n";		                  //开始上机的时间
    result += "学生结束上机的时间：" + toNormalTime(finish_time) + "\n";	                  //结束上机的时间
    }
    return result;
}
string Student::toNormalTime(chrono::system_clock::time_point t)                          //将timepoint转化为人类可读的形式
{
    using time_point = std::chrono::system_clock::time_point;
    const string format = "%Y-%m-%d %H:%M:%S";
    std::time_t tt = std::chrono::system_clock::to_time_t(t);
    std::tm tm = *std::localtime(&tt);                                                    //使用系统提供的时区
    std::stringstream ss;
    ss << std::put_time(&tm, format.c_str());
    return ss.str();
}
