#include "user.h"

User::User()
{
}

User::User(const QString &login, const QString &password, const User::Status &status)
{
	m_login = login;
	m_password = password;
	m_status = status;
}

const QString &User::login() const
{
	return m_login;
}

const QString &User::password() const
{
	return m_password;
}

const User::Status &User::status() const
{
	return m_status;
}

const QString User::statusString() const
{
	return getListStatus()[m_status];
}

void User::setData(const QString &login, const QString &password, const User::Status &status)
{
	m_login = login;
	m_password = password;
	m_status = status;
}

void User::setLogin(const QString &login)
{
	m_login = login;
}

void User::setPassword(const QString &password)
{
	m_password = password;
}

void User::setStatus(const Status &status)
{
	m_status = status;
}



QMap<User::Status, QString> User::getListStatus()
{
	return QMap<Status, QString>({ { Passenger, "Пассажир" },
                                   { Cashier, "Диспетчер"} ,
								   { Admin, "Администратор" }
								 });
}
