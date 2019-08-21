#include "addwidget.h"

void AddWidget::setMobileParameters(bool checked) {
    if (checked) {
        coreSB->setMaximum(Mobile::maxCores);
        tdpSB->setMaximum(Mobile::maxTdp);
        //eccCB->setChecked(false);
        eccCB->setEnabled(false);
        for (auto pair : Mobile::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    else {
        eccCB->setEnabled(true);
        socketCB->clear();
    }
}

void AddWidget::setDesktopParameters(bool checked) {
    if (checked) {
        coreSB->setMaximum(Desktop::maxCores);
        tdpSB->setMaximum(Desktop::maxTdp);
        for (auto pair : Desktop::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    else
        socketCB->clear();
}

void AddWidget::setServerParameters(bool checked) {
    if (checked) {
        coreSB->setMaximum(Server::maxCores);
        tdpSB->setMaximum(Server::maxTdp);
        eccCB->setChecked(true);
        eccCB->setEnabled(false);
        for (auto pair : Server::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    else {
        eccCB->setEnabled(true);
        socketCB->clear();
    }
}

void AddWidget::createCpu() {
    CPU * c;

    int manufacturer;
    for (int i = 0; i < CPU::manufacturers.size(); ++i)
        if (manufacturerRBtn[i].isChecked())
            manufacturer = i;

    if (mobileRBtn->isChecked())
        c = new Mobile(
                    manufacturer,
                    modelLE->text().toStdString(),
                    socketCB->currentIndex(),
                    yearSB->value(),
                    coreSB->value(),
                    threadSB->value(),
                    processSB->value(),
                    tdpSB->value(),
                    bitsCB->isChecked()
                    );
    else if (desktopRBtn->isChecked())
        c = new Desktop(
                    manufacturer,
                    modelLE->text().toStdString(),
                    socketCB->currentIndex(),
                    yearSB->value(),
                    coreSB->value(),
                    threadSB->value(),
                    processSB->value(),
                    tdpSB->value(),
                    bitsCB->isChecked(),
                    eccCB->isChecked()
                    );
    else if (serverRBtn->isChecked())
        c = new Server(
                    manufacturer,
                    modelLE->text().toStdString(),
                    socketCB->currentIndex(),
                    yearSB->value(),
                    coreSB->value(),
                    threadSB->value(),
                    processSB->value(),
                    tdpSB->value(),
                    bitsCB->isChecked()
                    );
}


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

    modelLE = new QLineEdit();
    modelLabel = new QLabel("Model");

    socketCB = new QComboBox();
    //fillSocket() con connect

    yearSB = new QSpinBox();
    yearSB->setRange(1985, 2020);
    yearLabel = new QLabel("Release year");

    coreSB = new QSpinBox();
    coreLabel = new QLabel("Number of cores");

    threadSB = new QSpinBox();
    threadSB->setMaximum(4);
    threadLabel = new QLabel("Threads per core");

    processSB = new QSpinBox();
    processSB->setMaximum(1000);
    processLabel = new QLabel("Manufacturing process");

    tdpSB = new QSpinBox();
    //setTdpSB()
    tdpLabel = new QLabel("Rated TDP");

    bitsCB = new QCheckBox("64 bit");

    eccCB = new QCheckBox("ECC memory support");

    labelsLayout = new QVBoxLayout();
    labelsLayout->addWidget(modelLabel);
    labelsLayout->addWidget(socketLabel);
    labelsLayout->addWidget(yearLabel);
    labelsLayout->addWidget(coreLabel);
    labelsLayout->addWidget(threadLabel);
    labelsLayout->addWidget(processLabel);
    labelsLayout->addWidget(tdpLabel);

    fieldsLayout = new QVBoxLayout();
    fieldsLayout->addWidget(modelLE);
    fieldsLayout->addWidget(socketCB);
    fieldsLayout->addWidget(yearSB);
    fieldsLayout->addWidget(coreSB);
    fieldsLayout->addWidget(threadSB);
    fieldsLayout->addWidget(processSB);
    fieldsLayout->addWidget(tdpSB);

    columnsLayout = new QHBoxLayout();
    columnsLayout->addLayout(labelsLayout);
    columnsLayout->addLayout(fieldsLayout);

    addBtn = new QPushButton("Add");
    cancelBtn = new QPushButton("Calcel");
    actionsLayout = new QHBoxLayout();
    actionsLayout->addWidget(cancelBtn);
    actionsLayout->addWidget(addBtn);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(typeGB);
    mainLayout->addWidget(manufacturerGB);
    mainLayout->addWidget(bitsCB);
    mainLayout->addWidget(eccCB);
    mainLayout->addLayout(actionsLayout);

    connect(this, SIGNAL(created(CPU *)), parent, SLOT(addCpu(CPU *)));
    connect(this, SIGNAL(accepted()), this, SLOT(createCpu()));
    connect(addBtn, SIGNAL(clicked()), this, SLOT(accepted()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(rejected()));
}
