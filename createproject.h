/*
    CreateProject .{h/cpp/ui}
    创建/读取项目文件夹
    ~~~~~~~~ <--取决于 bool createnew
*/


#ifndef CREATEPROJECT_H
#define CREATEPROJECT_H

#include <QWidget>
#include <string>
#include <filesystem>
#include <QMessageBox>

#include "createadmin.h"
#include "admin.h"
#include "student.h"
#include "menu.h"
namespace Ui {
class CreateProject;
}

class CreateProject : public QWidget
{
    Q_OBJECT


public:
    CreateProject(QWidget *parent = nullptr,bool createN = true);
    ~CreateProject();
    bool createnew;

private slots:
    void on_Enter_clicked();

    void on_Restart_clicked();

private:
    Ui::CreateProject *ui;
};

#endif // CREATEPROJECT_H
