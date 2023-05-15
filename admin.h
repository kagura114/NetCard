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

    //功能函数
    void Login();		//登录
    void Logout();		//登出
    void AdminMenu();	//管理员菜单
    //辅助函数

    void Verify(int level = LOGIN);		//验证是否登录

    //管理员菜单
    void Save();			//保存
    void ModifyStudent();	//修改
    void LoginStudent();    //登录学生账户

    Student* SearchStudent(uint32_t id);	//搜索学生(精确)

    void StudentMenu(Student *s);	//学生信息菜单
    void AddStudent();				//添加学生
    void DeleteStudent();			//删除学生
    void ListStudent();				//列出学生
    void SearchStudentR();			//搜索学生(模糊)

    //学生菜单
    void ChangeID(Student* s);			//修改学号
    void ChangePassword(Student* s);	//修改密码

    //从文件读取
    static Admin* AddAdmin(string path);
private:
    string	password;	//密码
    char	attempts;	//尝试登录次数
    enum Status { LOGOUT = 0x001, LOGIN = 0x010 , LOCK = 0x100 } status;	//登录状态
    vector<Student*>* students;	//学生列表
    string  path;		//保存文件路径
};



#endif // ADMIN_H
