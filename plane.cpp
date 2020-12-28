#include "plane.h"

Plane::Plane()
{
    m_number = "";
    m_departure = "";
    m_arrival = "";
    m_departure_time = "";
    m_arrival_time = "";
    m_status = "";

}

Plane::Plane(QString number, const QString departure, const QString arrival, const QString departure_time, const QString arrival_time, const QString status)
{
    setData(number, departure, arrival, departure_time, arrival_time, status);
}

void Plane::setData(QString number, const QString departure, const QString arrival, const QString departure_time, const QString arrival_time, const QString status)
{
    m_number = number;
    m_departure = departure;
    m_arrival = arrival;
    m_departure_time = departure_time;
    m_arrival_time = arrival_time;
    m_status = status;

}

QString Plane::number() const
{
    return m_number;
}

void Plane::setNumber(const QString &number)
{
    m_number = number;
}

QString Plane::departure() const
{
    return m_departure;
}

void Plane::setDeparture(const QString &departure)
{
    m_departure = departure;
}

QString Plane::arrival() const
{
    return m_arrival;
}

void Plane::setArrival(const QString &arrival)
{
    m_arrival = arrival;
}

QString Plane::departure_time() const
{
    return m_departure_time;
}

void Plane::setDeparture_time(const QString &departure_time)
{
    m_departure_time = departure_time;
}
QString Plane::arrival_time() const
{
    return m_arrival_time;
}

void Plane::setArrival_time(const QString &arrival_time)
{
    m_arrival_time = arrival_time;
}
QString Plane::status() const
{
    return m_status;
}

void Plane::setStatus(const QString &status)
{
    m_status = status;
}
