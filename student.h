#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
class Student
{
public:
    uint32_t	id;						//卡号
    string		name;					//姓名
    string		SchoolID;				//学号
    double		recharge	=10.0;		//充值金额
    double		remain		=0.0;		//余额
    double		cost		=0.0;		//花费
    string		password	= "";		//密码
    bool		states		=false;		//上机状态
    bool		inmenu		=false;
    enum place{
        classroom,
        dormitory,
        CS_buliding,
        library}		place;
    enum status{
        NORMAL = 0x000,
        LOST = 0x001,
        FREEZE = 0x010,
        LOGIN = 0x100} status; //状态:正常，挂失，冻结。

    chrono::system_clock::time_point start_time;//开始上机的时间
    chrono::system_clock::time_point finish_time;//结束上机的时间

    void Verify(int level = LOGIN);
    Student();
    Student(string path);
    ~Student();
    Student(uint32_t ID, string schoolid,string name);
    void Normal();
    void Login();                                       //登录
    void Balance();                                     //查询余额
    void start_worktime(enum place where = CS_buliding);//开始上机的时间
    void finish_worktime();                             //结束上机的时间
    string workplace();                                 //上机地点

    void StudentMenu();     //学生菜单
    void whether_working();//是否上机
    void ChangePassword();	//学生修改自己密码
    void ReportLoss();    //学生挂失
    void ChangeName();	//学生修改自己姓名

    //SL
    string GetData();
};



#endif // STUDENT_H
