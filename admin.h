#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <QMessageBox>

#include "student.h"

using namespace std;
class Admin
{
public:
    //构造函数和析构函数
    Admin(string pas,string path);
    ~Admin();

    //辅助函数
    bool VerifyPass(string pass);   //验证密码
    bool verifyStudent(Student* s); //验证创建的学生是否合理

    void Save();			//保存

    Student* SearchStudent(uint32_t id);            //搜索学生(id)
    Student* SearchStudent(string n);               //搜索学生(姓名)
    Student* SearchStudent(string schoolid,bool i);	//搜索学生(学号)
    void AddStudent(Student *);     //添加学生
    void DeleteStudent();			//删除学生

    //从文件读取
    static Admin* AddAdmin(string path);

    enum Status { LOGOUT = 0x001, LOGIN = 0x010 , LOCK = 0x100 } status;	//登录状态
private:
    string	password;	//密码
    char	attempts;	//尝试登录次数
    string  path;		//保存文件路径
    vector<Student*>* students;	//学生列表

};



#endif // ADMIN_H
