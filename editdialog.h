#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <array>
#include <string>
#include "cpu.h"
#include "desktop.h"
#include "mobile.h"
#include "server.h"

#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>

class EditDialog : public QDialog
{
    Q_OBJECT
private:
    QGroupBox * manufacturerGB;

    QRadioButton * manufacturerRBtn;
    QLineEdit * modelLE;
    QComboBox * socketCB;
    QSpinBox * yearSB;
    QSpinBox * coreSB;
    QSpinBox * threadSB;
    QSpinBox * processSB;
    QSpinBox * tdpSB;
    QCheckBox * bitsCB;
    QCheckBox * eccCB;

    QLabel * modelLabel;
    QLabel * socketLabel;
    QLabel * yearLabel;
    QLabel * coreLabel;
    QLabel * threadLabel;
    QLabel * processLabel;
    QLabel * tdpLabel;

    QPushButton * editBtn;
    QPushButton * cancelBtn;

    QHBoxLayout * manufacturerLayout;
    QHBoxLayout * columnsLayout;
    QVBoxLayout * labelsLayout;
    QVBoxLayout * fieldsLayout;
    QHBoxLayout * actionsLayout;
    QVBoxLayout * mainLayout;

    CPU * cpu;

public:
    EditDialog(CPU *, QWidget * parent = nullptr);
    ~EditDialog();
signals:
private slots:
    void editCpu();
public slots:
};

#endif // EDITDIALOG_H
