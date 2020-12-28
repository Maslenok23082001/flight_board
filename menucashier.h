#ifndef MENUCASHIER_H
#define MENUCASHIER_H

#include <QDialog>
#include "plane.h"

namespace Ui {
class MenuCashier;
}

class MenuCashier : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCashier(QWidget *parent = nullptr);
    ~MenuCashier();

private slots:






    void on_pushButton_clicked();





signals:
    void editedRace(int, Plane);

private:
    Ui::MenuCashier *mUi;

};

#endif // MENUCASHIER_H
