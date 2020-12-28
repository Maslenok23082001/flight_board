#include "menucashier.h"
#include "ui_dialog_menucashier.h"
#include "controlraces.h"
#include "config.h"
#include "workwidget.h"
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QTextStream>

MenuCashier::MenuCashier(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::MenuCashier)

{
    mUi->setupUi(this);
    this->setStyleSheet("background-color: #a8faff;");



//


}

MenuCashier::~MenuCashier()
{
    delete mUi;
}




void MenuCashier::on_pushButton_clicked()
{
    this->close();
    const QList<Plane> &listPlanes = qobject_cast<WorkWidget*>(parent())->listPlanes();
    ControlRaces dialog(listPlanes, this);
    dialog.setWindowTitle(windowTitle());

    connect(&dialog, SIGNAL(addedRace(Plane)),
            parent(), SLOT(addRace(Plane)));
    connect(&dialog, SIGNAL(editedRace(int, Plane)),
            parent(), SLOT(editRace(int, Plane)));
    connect(&dialog, SIGNAL(deletedRace(int)),
            parent(), SLOT(deleteRace(int)));
    dialog.exec();

}




