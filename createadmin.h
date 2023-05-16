#ifndef CREATEADMIN_H
#define CREATEADMIN_H

#include <QWidget>
#include "admin.h"
#include "menu.h"
namespace Ui {
class CreateAdmin;
}

class CreateAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAdmin(string Path,QWidget *parent = nullptr);
    ~CreateAdmin();
    string path;
    Admin* admin;
private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateAdmin *ui;
};

#endif // CREATEADMIN_H
