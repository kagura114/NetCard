#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <qprocess.h>

#include "createproject.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Welcome; }
QT_END_NAMESPACE

class Welcome : public QWidget
{
    Q_OBJECT

public:
    Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_NewFile_clicked();

    void on_ReadFile_clicked();

private:
    Ui::Welcome *ui;
};
#endif // WELCOME_H
