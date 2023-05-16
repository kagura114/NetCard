#ifndef FREEZE_H
#define FREEZE_H

#include <QWidget>
#include "admin.h"
namespace Ui {
class Freeze;
}

class Freeze : public QWidget
{
    Q_OBJECT

public:
    explicit Freeze(Admin* a,QWidget *parent = nullptr);
    ~Freeze();

private slots:
    void on_change_mode_clicked();

private:
    Ui::Freeze *ui;
    Admin* admin;
};

#endif // FREEZE_H
