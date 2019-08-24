#ifndef ADDWIDGET_H
#define ADDWIDGET_H

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

class AddDialog : public QDialog
{
    Q_OBJECT
private:
    QGroupBox * typeGB;
    QGroupBox * manufacturerGB;

    QRadioButton * mobileRBtn, * desktopRBtn, * serverRBtn;
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

    QPushButton * addBtn;
    QPushButton * cancelBtn;

    QHBoxLayout * typeLayout;
    QHBoxLayout * manufacturerLayout;
    QHBoxLayout * columnsLayout;
    QVBoxLayout * labelsLayout;
    QVBoxLayout * fieldsLayout;
    QHBoxLayout * actionsLayout;
    QVBoxLayout * mainLayout;

public:
    explicit AddDialog(QWidget * parent = nullptr);

signals:
    void created(CPU *);

private slots:
    void setMobileParameters(bool);
    void setDesktopParameters(bool);
    void setServerParameters(bool);

public slots:
    void createCpu();
};

#endif // ADDWIDGET_H
