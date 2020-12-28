#ifndef CONTROLUSERS_H
#define CONTROLUSERS_H

#include <QDialog>
#include "user.h"

namespace Ui {
class ControlUsers;
}

class ControlUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ControlUsers(QWidget *parent = nullptr);
    ~ControlUsers();

private slots:

    void on_buttonDeleteUser_clicked();
    void on_buttonAddUser_clicked();
    void on_lineFind_textChanged(const QString &arg1);

private:
    Ui::ControlUsers *mUi;
    QList<User> m_listUsers;

};

#endif // CONTROLUSERS_H
