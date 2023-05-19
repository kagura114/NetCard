#ifndef USEPC_H
#define USEPC_H
#include <QWidget>
#include <qstring.h>
#include "admin.h"
#include "enterpassword.h"
namespace Ui {
class UsePC;
}
class UsePC : public QWidget
{
    Q_OBJECT
public:
    UsePC(Admin* a,QWidget *parent = nullptr);
    ~UsePC();
private slots:
    void on_change_mode_clicked();
    void on_exit_btn_clicked();
    void on_query_state_clicked();
private:
    Ui::UsePC *ui;
    Admin* admin;
    Student *student;
};
#endif // USEPC_H
