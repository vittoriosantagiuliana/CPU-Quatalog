#include "mainwindow.h"

MainWindow::MainWindow (QWidget * parent) :
    QMainWindow(parent),
    mainWidget(new QWidget(this)),
    mainLayout(new QVBoxLayout(mainWidget)),
    topButtonsLayout(new QHBoxLayout(mainWidget)),
    addItemButton(new QPushButton("Add a new CPU model", mainWidget)),
    editButton(new QPushButton("Edit", mainWidget)),
    removeButton(new QPushButton("Delete", mainWidget)),
    cpuList(new QTableView(mainWidget)),
    cpuModel(new TableAdapter(this))
{
    topButtonsLayout->addWidget(addItemButton);
    topButtonsLayout->addWidget(editButton);
    topButtonsLayout->addWidget(removeButton);

    cpuList->setModel(cpuModel);
    cpuList->setSelectionBehavior(QAbstractItemView::SelectRows);

    mainLayout->addLayout(topButtonsLayout);
    mainLayout->addWidget(cpuList);
    
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    setWindowTitle("CPU Qatalog");
}

MainWindow::~MainWindow() { }
