#include "mainwindow.h"

MainWindow::MainWindow (QWidget * parent) : QMainWindow(parent)
{
    addItemButton = new QPushButton("Add a new CPU model");
    editButton = new QPushButton("Edit");
    removeButton = new QPushButton("Delete");

    topButtonsLayout = new QHBoxLayout();
    topButtonsLayout->addWidget(addItemButton);
    topButtonsLayout->addWidget(editButton);
    topButtonsLayout->addWidget(removeButton);

    cpuList = new QListWidget();

    mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(topButtonsLayout);
    mainLayout->addWidget(cpuList);
    
    setWindowTitle("CPU Qatalog");
    mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{

}
