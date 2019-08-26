#include "editdialog.h"

void EditDialog::editCpu()
{
    cpu->setManufacturer(manufacturerCB->currentIndex());
    cpu->setModelName(modelLE->text().toStdString());
    cpu->setSocket(socketCB->currentIndex());
    cpu->setReleaseYear(yearSB->value());
    cpu->setCoreCount(coreSB->value());
    cpu->setThreadCount(threadSB->value());
    cpu->setManufacturingProcess(processSB->value());
    cpu->setTdpRating(tdpSB->value());
    cpu->setArchitecture(bitsCB->isChecked());
    if (eccCB->isEnabled())
        cpu->setEccMemorySupport(eccCB->isChecked());
}

EditDialog::EditDialog(CPU *c, QWidget *parent) : QDialog(parent),
                                                  manufacturerCB(new QComboBox()),
                                                  modelLE(new QLineEdit()),
                                                  socketCB(new QComboBox()),
                                                  yearSB(new QSpinBox()),
                                                  coreSB(new QSpinBox()),
                                                  threadSB(new QSpinBox()),
                                                  processSB(new QSpinBox()),
                                                  tdpSB(new QSpinBox()),
                                                  bitsCB(new QCheckBox("64 bit")),
                                                  eccCB(new QCheckBox("ECC memory support")),
                                                  manufacturerLabel(new QLabel("Manufacturer")),
                                                  modelLabel(new QLabel("Model")),
                                                  socketLabel(new QLabel("Socket")),
                                                  yearLabel(new QLabel("Release year")),
                                                  coreLabel(new QLabel("Number of cores")),
                                                  threadLabel(new QLabel("Threads per core")),
                                                  processLabel(new QLabel("Manufacturing process")),
                                                  tdpLabel(new QLabel("Rated TDP")),
                                                  editBtn(new QPushButton("Edit", this)),
                                                  cancelBtn(new QPushButton("Calcel", this)),
                                                  columnsLayout(new QHBoxLayout()),
                                                  labelsLayout(new QVBoxLayout()),
                                                  fieldsLayout(new QVBoxLayout()),
                                                  actionsLayout(new QHBoxLayout()),
                                                  mainLayout(new QVBoxLayout(this)),
                                                  cpu(c)
{
    for (auto pair : CPU::manufacturers)
        manufacturerCB->addItem(QString::fromStdString(pair.second));

    modelLE->setText(QString::fromStdString(cpu->getModelName()));

    if (dynamic_cast<Mobile *>(c) != nullptr)
    {
        coreSB->setMaximum(Mobile::maxCores);
        tdpSB->setMaximum(Mobile::maxTdp);
        eccCB->setChecked(false);
        eccCB->setEnabled(false);
        for (auto pair : Mobile::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    if (dynamic_cast<Desktop *>(c) != nullptr)
    {
        coreSB->setMaximum(Desktop::maxCores);
        tdpSB->setMaximum(Desktop::maxTdp);
        for (auto pair : Desktop::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }
    if (dynamic_cast<Server *>(c) != nullptr)
    {
        coreSB->setMaximum(Server::maxCores);
        tdpSB->setMaximum(Server::maxTdp);
        eccCB->setChecked(true);
        eccCB->setEnabled(false);
        for (auto pair : Server::sockets)
            socketCB->addItem(QString::fromStdString(pair.second));
    }

    yearSB->setValue(cpu->getReleaseYear());
    yearSB->setRange(1985, 2020);

    coreSB->setValue(cpu->getCoreCount());
    threadSB->setValue(cpu->getThreadCount());

    processSB->setValue(cpu->getManufacturingProcess());
    processSB->setRange(5, 1000);

    tdpSB->setValue(cpu->getTdpRating());

    eccCB->setChecked(cpu->getEccMemorySupport());

    labelsLayout->addWidget(manufacturerLabel);
    labelsLayout->addWidget(modelLabel);
    labelsLayout->addWidget(socketLabel);
    labelsLayout->addWidget(yearLabel);
    labelsLayout->addWidget(coreLabel);
    labelsLayout->addWidget(threadLabel);
    labelsLayout->addWidget(processLabel);
    labelsLayout->addWidget(tdpLabel);

    fieldsLayout->addWidget(manufacturerCB);
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

    mainLayout->addLayout(columnsLayout);
    mainLayout->addWidget(bitsCB);
    mainLayout->addWidget(eccCB);
    mainLayout->addLayout(actionsLayout);

    setWindowTitle("Edit CPU");

    connect(this, SIGNAL(accepted()), this, SLOT(editCpu()));
    connect(editBtn, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}
