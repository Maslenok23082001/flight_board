#include "addrace.h"
#include "ui_dialog_addrace.h"

#include "config.h"
#include "plane.h"
#include "regex"

AddRace::AddRace(Plane *plane, const QList<Plane> &listPlanes, Type type, QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddRace),
    m_plane(plane),
    m_listPlanes(listPlanes)
{
    mUi->setupUi(this);
    this->setStyleSheet("background-color: #a8faff;");

    m_startNumberPlane = plane->number();

    if (type == Edit) {
        mUi->mainLabel->setText("Редактирование рейса");
        mUi->edit_number->setText(m_plane->number());
        mUi->edit_departure->setText(m_plane->departure());
        mUi->edit_arrival->setText(m_plane->arrival());
        mUi->edit_departure_time->setText(m_plane->departure_time());
        mUi->edit_arrival_time->setText(m_plane->arrival_time());
        mUi->edit_status->setText(m_plane->status());
    }
    else {
        mUi->mainLabel->setText("Добавление рейса");
    }


}

AddRace::~AddRace()
{
    delete mUi;
}

void AddRace::accept()
{
    mUi->labelError->clear();

    QString number = mUi->edit_number->text();
    QString departure = mUi->edit_departure->text();
    QString arrival = mUi->edit_arrival->text();
    QString departure_time = mUi->edit_departure_time->text();
    QString arrival_time = mUi->edit_arrival_time->text();
    QString status = mUi->edit_status->text();


    if ((number.isEmpty() ||
        departure.isEmpty() ||
        arrival.isEmpty() ||
        departure_time.isEmpty()||
        arrival_time.isEmpty() ||
        status.isEmpty())) {
        mUi->labelError->setText("Ошибка: заполните все поля!");
    } else {
        m_plane->setData(number, departure, arrival, departure_time, arrival_time, status);
        QDialog::accept();
    }
}


