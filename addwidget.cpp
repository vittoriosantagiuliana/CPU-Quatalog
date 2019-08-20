#include "addwidget.h"

AddWidget::AddWidget(QWidget *parent) : QWidget(parent)
{
    mobileRBtn = new QRadioButton("Mobile");
    desktopRBtn = new QRadioButton("Desktop");
    serverRBtn = new QRadioButton("Server");
    typeLayout = new QHBoxLayout();
    typeLayout->addWidget(mobileRBtn);
    typeLayout->addWidget(desktopRBtn);
    typeLayout->addWidget(serverRBtn);
    typeGB = new QGroupBox();
    typeGB->setLayout(typeLayout);


    manufacturerRBtn = new QRadioButton[CPU::manufacturers.size()];

    for (int i = 0; i < CPU::manufacturers.size(); i++) {
        manufacturerRBtn[i].setText(QString::fromStdString(CPU::manufacturers.at(i)));
        manufacturerLayout->addWidget(manufacturerRBtn + i);
    }

    manufacturerGB = new QGroupBox("Manufacturer");
    manufacturerGB->setLayout(manufacturerLayout);

    // layout
    modelLE = new QLineEdit();
    modelLabel = new QLabel("Model: ");

    socketCB = new QComboBox();
    //fillSocket() con connect









    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(typeGB);
    mainLayout->addWidget(manufacturerGB);


}
