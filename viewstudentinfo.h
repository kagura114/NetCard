#ifndef VIEWSTUDENTINFO_H
#define VIEWSTUDENTINFO_H

#include <QWidget>

namespace Ui {
class ViewStudentInfo;
}

class ViewStudentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ViewStudentInfo(QWidget *parent = nullptr);
    ~ViewStudentInfo();

private slots:
    void on_QID_clicked();

    void on_QSchoolID_clicked();

    void on_Qname_clicked();

private:
    Ui::ViewStudentInfo *ui;
};

#endif // VIEWSTUDENTINFO_H
