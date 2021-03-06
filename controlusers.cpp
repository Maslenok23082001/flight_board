#include "controlusers.h"
#include "ui_dialog_controlusers.h"

#include "config.h"
#include "adduser.h"

#include <QFile>
#include <QDataStream>
#include <QMessageBox>

#include <QDebug>

ControlUsers::ControlUsers(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::ControlUsers)
{
    mUi->setupUi(this);
    this->setStyleSheet("background-color: #a8faff;");

    QFile file(Config::fileUsers);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);

        int row = 0;
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            m_listUsers.append(user);

            QTableWidgetItem *item_login = new QTableWidgetItem(user.login());
            QTableWidgetItem *item_password = new QTableWidgetItem(user.password());
            QTableWidgetItem *item_status = new QTableWidgetItem(user.statusString());

            mUi->tableUsers->insertRow(row);
            mUi->tableUsers->setItem(row, 0, item_login);
            mUi->tableUsers->setItem(row, 1, item_password);
            mUi->tableUsers->setItem(row, 2, item_status);
            row++;
        }
    }
}

ControlUsers::~ControlUsers()
{
    delete mUi;
}


void ControlUsers::on_buttonDeleteUser_clicked()
{
    int currentRow = mUi->tableUsers->currentRow();
    if (currentRow != -1)
    {
        const QString login = mUi->tableUsers->item(currentRow, 0)->text();
        const QString password = mUi->tableUsers->item(currentRow, 1)->text();
        const QString status = mUi->tableUsers->item(currentRow, 2)->text();


        mUi->tableUsers->removeRow(currentRow);

        QFile read_file(Config::fileUsers);
        if (read_file.open(QIODevice::ReadOnly)) {
            QFile write_file("buf_file_users");
            write_file.open(QIODevice::WriteOnly);

            QDataStream read_ist(&read_file);
            QDataStream write_ist(&write_file);

            while (!read_ist.atEnd()) {
                User user;
                read_ist >> user;

                if (user.login() != login) {
                    write_ist << user;
                }
            }

            read_file.close();
            read_file.remove();
            write_file.close();
            write_file.rename(Config::fileUsers);
        }
    }
    else {
        QMessageBox::warning(this, windowTitle(),
                             "Ошибка: не удалось удалить пользователя!");
    }
}

void ControlUsers::on_buttonAddUser_clicked()
{
    AddUser dialog(this);
    dialog.setWindowTitle(windowTitle());

    if (dialog.exec() == QDialog::Accepted) {
        const User &user = dialog.getUser();

        QFile file(Config::fileUsers);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << user;

        QTableWidgetItem *item_login = new QTableWidgetItem(user.login());
        QTableWidgetItem *item_password = new QTableWidgetItem(user.password());
        QTableWidgetItem *item_status = new QTableWidgetItem(user.statusString());

        int row = mUi->tableUsers->rowCount();
        mUi->tableUsers->insertRow(row);
        mUi->tableUsers->setItem(row, 0, item_login);
        mUi->tableUsers->setItem(row, 1, item_password);
        mUi->tableUsers->setItem(row, 2, item_status);
    }
}


void ControlUsers::on_lineFind_textChanged(const QString &text)
{
    QStringList listStr = text.split(" ");
    listStr.removeAll(QString());

    for (int i = 0; i < m_listUsers.size(); i++) {
        mUi->tableUsers->showRow(i);
    }

    int row = 0;
    foreach (const User &user, m_listUsers) {
        int count = 0;
        foreach (const QString &str, listStr) {
            if (user.login().contains(str) ||
                    user.statusString().contains(str)) {
                count++;
            }
        }
        if (count != listStr.size()) {
            mUi->tableUsers->hideRow(row);
        }
        row++;
    }
}
