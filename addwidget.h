#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <array>
#include <string>
#include "cpu.h"
#include "desktop.h"
#include "mobile.h"
#include "server.h"

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>

class AddWidget : public QWidget
{
    Q_OBJECT
private:
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

    QGroupBox * typeGB;
    QGroupBox * manufacturerGB;

    QHBoxLayout * typeLayout;
    QHBoxLayout * manufacturerLayout;
    QHBoxLayout * columnsLayout;
    QVBoxLayout * labelsLayout;
    QVBoxLayout * fieldsLayout;
    QHBoxLayout * actionsLayout;
    QVBoxLayout * mainLayout;

public:
    explicit AddWidget(QWidget *parent = nullptr);

signals:
    void created(CPU *);

public slots:
    void setMobileParameters(bool);
    void setDesktopParameters(bool);
    void setServerParameters(bool);
    void createCpu();
};

#endif // ADDWIDGET_H
