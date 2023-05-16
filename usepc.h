#ifndef USEPC_H
#define USEPC_H

#include <QWidget>
#include "admin.h"
namespace Ui {
class UsePC;
}

class UsePC : public QWidget
{
    Q_OBJECT

public:
    explicit UsePC(Admin* a,QWidget *parent = nullptr);
    ~UsePC();

private slots:
    void on_change_mode_clicked();

    void on_exit_btn_clicked();

    void on_query_state_clicked();

private:
    Ui::UsePC *ui;
    Admin* admin;
};

#endif // USEPC_H
