#include "adddialog.h"

void AddDialog::setMobileParameters(bool checked) {
    if (checked) {
        coreSB->setMaximum(Mobile::maxCores);
        tdpSB->setMaximum(Mobile::maxTdp);
        eccCB->setChecked(false);
        eccCB->setEnabled(false);
        for (auto pair : Mobile::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    else {
        eccCB->setEnabled(true);
        socketCB->clear();
    }
}

void AddDialog::setDesktopParameters(bool checked) {
    if (checked) {
        coreSB->setMaximum(Desktop::maxCores);
        tdpSB->setMaximum(Desktop::maxTdp);
        for (auto pair : Desktop::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    else
        socketCB->clear();
}

void AddDialog::setServerParameters(bool checked) {
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

void AddDialog::createCpu() {
    CPU * c;

    int manufacturer(0);
    for (unsigned int i = 0; i < CPU::manufacturers.size(); ++i)
        if (manufacturerRBtn[i].isChecked())
            manufacturer = static_cast<int>(i);

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
    else //if (serverRBtn->isChecked())
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
    emit created(c);
}


AddDialog::AddDialog(QWidget * parent) :
    QDialog(parent),
    typeGB(new QGroupBox()),
    manufacturerGB(new QGroupBox("Manufacturer")),
    mobileRBtn(new QRadioButton("Mobile")),
    desktopRBtn(new QRadioButton("Desktop")),
    serverRBtn(new QRadioButton("Server")),
    manufacturerRBtn(new QRadioButton[CPU::manufacturers.size()]),
    modelLE(new QLineEdit()),
    socketCB(new QComboBox()),
    yearSB(new QSpinBox()),
    coreSB(new QSpinBox()),
    threadSB(new QSpinBox()),
    processSB(new QSpinBox()),
    tdpSB(new QSpinBox()),
    bitsCB(new QCheckBox("64 bit")),
    eccCB(new QCheckBox("ECC memory support")),
    modelLabel(new QLabel("Model")),
    socketLabel(new QLabel("Socket")),
    yearLabel(new QLabel("Release year")),
    coreLabel(new QLabel("Number of cores")),
    threadLabel(new QLabel("Threads per core")),
    processLabel(new QLabel("Manufacturing process")),
    tdpLabel(new QLabel("Rated TDP")),
    addBtn(new QPushButton("Add", this)),
    cancelBtn(new QPushButton("Calcel", this)),
    typeLayout(new QHBoxLayout()),
    manufacturerLayout(new QHBoxLayout()),
    columnsLayout(new QHBoxLayout()),
    labelsLayout(new QVBoxLayout()),
    fieldsLayout(new QVBoxLayout()),
    actionsLayout(new QHBoxLayout()),
    mainLayout(new QVBoxLayout(this))
{
    typeLayout->addWidget(mobileRBtn);
    typeLayout->addWidget(desktopRBtn);
    typeLayout->addWidget(serverRBtn);
    
    typeGB->setLayout(typeLayout);

    for (unsigned int i = 0; i < CPU::manufacturers.size(); i++) {
        manufacturerRBtn[i].setText(QString::fromStdString(CPU::manufacturers.at(static_cast<int>(i))));
        manufacturerLayout->addWidget(manufacturerRBtn + i);
    }

    manufacturerGB->setLayout(manufacturerLayout);
    yearSB->setRange(1985, 2020);

    //threadSB->setMaximum(4);

    processSB->setMaximum(1000);
    
    labelsLayout->addWidget(modelLabel);
    labelsLayout->addWidget(socketLabel);
    labelsLayout->addWidget(yearLabel);
    labelsLayout->addWidget(coreLabel);
    labelsLayout->addWidget(threadLabel);
    labelsLayout->addWidget(processLabel);
    labelsLayout->addWidget(tdpLabel);

    fieldsLayout->addWidget(modelLE);
    fieldsLayout->addWidget(socketCB);
    fieldsLayout->addWidget(yearSB);
    fieldsLayout->addWidget(coreSB);
    fieldsLayout->addWidget(threadSB);
    fieldsLayout->addWidget(processSB);
    fieldsLayout->addWidget(tdpSB);

    columnsLayout->addLayout(labelsLayout);
    columnsLayout->addLayout(fieldsLayout);

    actionsLayout->addWidget(cancelBtn);
    actionsLayout->addWidget(addBtn);

    mainLayout->addWidget(typeGB);
    mainLayout->addWidget(manufacturerGB);
    mainLayout->addLayout(columnsLayout);
    mainLayout->addWidget(bitsCB);
    mainLayout->addWidget(eccCB);
    mainLayout->addLayout(actionsLayout);
    connect(mobileRBtn, SIGNAL(toggled(bool)), this, SLOT(setMobileParameters(bool)));
    connect(desktopRBtn, SIGNAL(toggled(bool)), this, SLOT(setDesktopParameters(bool)));
    connect(serverRBtn, SIGNAL(toggled(bool)), this, SLOT(setServerParameters(bool)));
    connect(this, SIGNAL(created(CPU *)), parent, SLOT(addCpu(CPU *)));
    connect(this, SIGNAL(accepted()), this, SLOT(createCpu()));
    connect(addBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}

AddDialog::~AddDialog() { delete [] manufacturerRBtn; }
