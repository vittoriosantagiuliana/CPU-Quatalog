#include "editdialog.h"

void EditDialog::editCpu() {

    int manufacturer(0);
    for (unsigned int i = 0; i < CPU::manufacturers.size(); ++i)
        if (manufacturerRBtn[i].isChecked())
            manufacturer = static_cast<int>(i);

    cpu->setManufacturer(manufacturer);
    cpu->setModelName(modelLE->text().toStdString());
    cpu->setSocket(socketCB->currentIndex());
    cpu->setReleaseYear(yearSB->value());
    cpu->setCoreCount(coreSB->value());
    cpu->setThreadCount(threadSB->value());
    cpu->setManufacturer(processSB->value());
    cpu->setTdpRating(tdpSB->value());
    cpu->setArchitecture(bitsCB->isChecked());
    if (eccCB->isEnabled())
        cpu->setEccMemorySupport(eccCB->isChecked());
}

EditDialog::EditDialog(CPU * c, QWidget * parent) :
    QDialog(parent),
    manufacturerGB(new QGroupBox("Manufacturer")),
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
    editBtn(new QPushButton("Edit", this)),
    cancelBtn(new QPushButton("Calcel", this)),
    manufacturerLayout(new QHBoxLayout()),
    columnsLayout(new QHBoxLayout()),
    labelsLayout(new QVBoxLayout()),
    fieldsLayout(new QVBoxLayout()),
    actionsLayout(new QHBoxLayout()),
    mainLayout(new QVBoxLayout(this)),
    cpu(c)
{
    if (dynamic_cast<Mobile *>(c) != nullptr) {
        coreSB->setMaximum(Mobile::maxCores);
        tdpSB->setMaximum(Mobile::maxTdp);
        eccCB->setChecked(false);
        eccCB->setEnabled(false);
        for (auto pair : Mobile::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    if (dynamic_cast<Desktop *>(c) != nullptr) {
        coreSB->setMaximum(Desktop::maxCores);
        tdpSB->setMaximum(Desktop::maxTdp);
        for (auto pair : Desktop::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    if (dynamic_cast<Server *>(c) != nullptr) {
        coreSB->setMaximum(Server::maxCores);
        tdpSB->setMaximum(Server::maxTdp);
        eccCB->setChecked(true);
        eccCB->setEnabled(false);
        for (auto pair : Server::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }


    for (unsigned int i = 0; i < CPU::manufacturers.size(); i++) {
        manufacturerRBtn[i].setText(QString::fromStdString(CPU::manufacturers.at(static_cast<int>(i))));
        manufacturerLayout->addWidget(manufacturerRBtn + i);
    }

    manufacturerGB->setLayout(manufacturerLayout);
    yearSB->setRange(1985, 2020);

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
    actionsLayout->addWidget(editBtn);

    mainLayout->addWidget(manufacturerGB);
    mainLayout->addLayout(columnsLayout);
    mainLayout->addWidget(bitsCB);
    mainLayout->addWidget(eccCB);
    mainLayout->addLayout(actionsLayout);
    //connect(this, SIGNAL(edited(CPU *)), parent, SLOT(editCpu(CPU *)));
    connect(this, SIGNAL(accepted()), this, SLOT(editCpu()));
    connect(editBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}

EditDialog::~EditDialog() { delete [] manufacturerRBtn; }
