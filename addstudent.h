#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H
#include <QWidget>
#include "admin.h"
#include "enterpassword.h"
namespace Ui {
class AddStudent;
}
class AddStudent : public QWidget
{
    Q_OBJECT
public:
    AddStudent(Admin* a,QWidget *parent = nullptr);
    ~AddStudent();
private slots:
    void on_Submit_clicked();
private:
    Ui::AddStudent *ui;
    Admin* admin;
};

#endif // ADDSTUDENT_H
