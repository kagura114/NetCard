#ifndef ENTERPASSWORD_H
#define ENTERPASSWORD_H

#include <QWidget>

namespace Ui {
class EnterPassword;
}

class EnterPassword : public QWidget
{
    Q_OBJECT

public:
    explicit EnterPassword(QWidget *parent = nullptr);
    ~EnterPassword();

private:
    Ui::EnterPassword *ui;
};

#endif // ENTERPASSWORD_H
