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
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>

class EditDialog : public QDialog
{
    Q_OBJECT
private:
    QComboBox *manufacturerCB;
    QLineEdit *modelLE;
    QComboBox *socketCB;
    QSpinBox *yearSB;
    QSpinBox *coreSB;
    QSpinBox *threadSB;
    QSpinBox *processSB;
    QSpinBox *tdpSB;
    QCheckBox *bitsCB;
    QCheckBox *eccCB;

    QLabel *manufacturerLabel;
    QLabel *modelLabel;
    QLabel *socketLabel;
    QLabel *yearLabel;
    QLabel *coreLabel;
    QLabel *threadLabel;
    QLabel *processLabel;
    QLabel *tdpLabel;

    QPushButton *editBtn;
    QPushButton *cancelBtn;

    QHBoxLayout *columnsLayout;
    QVBoxLayout *labelsLayout;
    QVBoxLayout *fieldsLayout;
    QHBoxLayout *actionsLayout;
    QVBoxLayout *mainLayout;

    CPU *cpu;

public:
    EditDialog(CPU *, QWidget *parent = nullptr);

private slots:
    void editCpu();
};

#endif // EDITDIALOG_H
