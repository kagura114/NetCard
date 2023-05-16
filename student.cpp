#include "student.h"

Student::Student()
{

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

static Student* ReadData(string filename){
    auto* student = new Student;
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
    return student;
}
