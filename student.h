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
#include <iomanip>
using namespace std;
class Student
{
public:
    uint32_t	id          =0;                                 //卡号
    string		name        ="no name";                         //姓名
    string		SchoolID    ="0";		                        //学号
    double		recharge	=10.0;		                        //充值金额
    double		balance		=10.0;		                        //余额
    double		cost		=0.0;		                        //花费
    double      last_cost   =0;                                 //上次消费
    enum place{
        classroom,
        dormitory,
        CS_buliding,
        library}		place;                                  //上次上机地点
    enum status{                                                //每个状态都由一个十六进制数字表示
        NORMAL = 0x000,
        LOST = 0x001,
        FREEZE = 0x010,
        LOGIN = 0x100} status;                                  //状态:正常，挂失，冻结。
    chrono::system_clock::time_point start_time;                //开始上机的时间
    chrono::system_clock::time_point finish_time;               //结束上机的时间
    Student();
    Student(string path);                                       //从文件读取
    ~Student() = default;
    void start_worktime(enum place where = CS_buliding);        //开始上机
    void finish_worktime();                                     //结束上机
    string toNormalTime(chrono::system_clock::time_point t);    //转换时间戳
    string workplace();                                         //获取上机地点
                                                                //SL
    string GetData();                                           //获取纯数据
    string GetInfo();                                           //获取有提示的信息
    string GetStatus();                                         //获取当前状态
};
#endif                                                          // STUDENT_H
