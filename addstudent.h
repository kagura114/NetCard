#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>

namespace Ui {
class AddStudent;
}

class AddStudent : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

private slots:
    void on_Submit_clicked();

private:
    Ui::AddStudent *ui;
};

#endif // ADDSTUDENT_H
