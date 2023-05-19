#ifndef VIEWSTUDENTINFO_H
#define VIEWSTUDENTINFO_H
#include <QWidget>
#include "admin.h"
namespace Ui {
class ViewStudentInfo;
}
class ViewStudentInfo : public QWidget
{
    Q_OBJECT
public:
    explicit ViewStudentInfo(Admin*,QWidget *parent = nullptr);
    ~ViewStudentInfo();
private slots:
    void on_QID_clicked();
    void on_QSchoolID_clicked();
    void on_Qname_clicked();
private:
    Ui::ViewStudentInfo *ui;
    Admin* admin;
};
#endif // VIEWSTUDENTINFO_H
