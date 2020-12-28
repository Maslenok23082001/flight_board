#ifndef PLANE_H
#define PLANE_H


#include <QString>
#include <QDate>
#include <QTime>

#include <QDataStream>
#include <QTextStream>

class Plane
{
public:
	Plane();
	
    Plane(QString number, const QString departure, const QString arrival, const QString departure_time, const QString arrival_time, const QString status);
    void setData(QString number, const QString departure, const QString arrival, const QString departure_time, const QString arrival_time, const QString status);

	QString number() const;
	void setNumber(const QString &number);

	QString departure() const;
	void setDeparture(const QString &departure);

	QString arrival() const;
	void setArrival(const QString &arrival);
    


    QString departure_time() const;
    void setDeparture_time(const QString &departure);

    QString arrival_time() const;
    void setArrival_time(const QString &arrival);
    QString status() const;
    void setStatus(const QString &status);
    

    
private:
	QString m_number;
    QString m_departure;
    QString m_arrival;
    QString m_departure_time;
    QString m_arrival_time;
    QString m_status;

};

inline QDataStream &operator<< (QDataStream &ost, const Plane &plane)
{
    ost << plane.number() << plane.departure() << plane.arrival() << plane.departure_time() << plane.arrival_time() << plane.status();

	return ost;
}

inline QDataStream &operator>> (QDataStream &ist, Plane &plane)
{
    QString number;
    QString departure;
    QString arrival;
    QString departure_time;
    QString arrival_time;
    QString status;


    ist >> number >> departure >> arrival >> departure_time >> arrival_time >> status;

    plane.setData(number, departure, arrival, departure_time, arrival_time, status);
	return ist;
}

inline QTextStream &operator<< (QTextStream &ost, const Plane &plane)
{
	ost << QString("______Начало САМОЛЕТА______")
        << QString("Номер самолета: ") << plane.number()
		<< QString("Пункт отправления: ") << plane.departure()
        << QString("Пункт прибытия: ") << plane.arrival()
        << QString("Время отправления:") << plane.departure_time()
        << QString("Время прибытия:") << plane.arrival_time()
        << QString("Статус:") << plane.status()
         << "\n";

	ost << QString("______КОНЕЦ САМОЛЕТА______");
	return ost;
}

#endif // PLANE_H
