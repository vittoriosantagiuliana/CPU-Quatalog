#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          menuBar(new QMenuBar(this)),
                                          fileMenu(new QMenu("&File", menuBar)),
                                          openAction(new QAction("&Open", this)),
                                          saveAction(new QAction("&Save", this)),
                                          exitAction(new QAction("E&xit", this)),
                                          mainWidget(new QWidget(this)),
                                          mainLayout(new QVBoxLayout(mainWidget)),
                                          topButtonsLayout(new QHBoxLayout(mainWidget)),
                                          addItemButton(new QPushButton("Add a new CPU model", mainWidget)),
                                          editButton(new QPushButton("Edit", mainWidget)),
                                          removeButton(new QPushButton("Delete", mainWidget)),
                                          cpuList(new QTableView(mainWidget)),
                                          cpuModel(new TableAdapter(this))
{
    openAction->setShortcut(QKeySequence::Open);
    saveAction->setShortcut(QKeySequence::Save);
    exitAction->setShortcut(QKeySequence::Quit);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(exitAction);
    menuBar->addMenu(fileMenu);

    topButtonsLayout->addWidget(addItemButton);
    topButtonsLayout->addWidget(editButton);
    topButtonsLayout->addWidget(removeButton);

    cpuList->setModel(cpuModel);
    cpuList->setSelectionBehavior(QAbstractItemView::SelectRows);

    mainLayout->addWidget(menuBar);
    mainLayout->addLayout(topButtonsLayout);
    mainLayout->addWidget(cpuList);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    setWindowTitle("CPU Qatalog");
    resize(1000, 600);

    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(addItemButton, SIGNAL(clicked()), this, SLOT(addDialog()));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editCpu()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeCpu()));
}

void MainWindow::addDialog()
{
    AddDialog add(this);
    add.exec();
}

void MainWindow::openFile()
{
    cpuModel->loadFile(QFileDialog::getOpenFileName(this, "Open file", "", "XML Files (*.xml)").toStdString());
}
void MainWindow::saveFile()
{
    cpuModel->saveFile(QFileDialog::getSaveFileName(this, "Save as...", "", "XML Files (*.xml)").toStdString());
}

void MainWindow::addCpu(CPU *c) { cpuModel->addCpu(c); }

void MainWindow::editCpu()
{
    QModelIndexList l = cpuList->selectionModel()->selectedIndexes();
    if (!l.empty())
    {
        QModelIndex i = l.at(0);
        if (i.isValid())
            cpuModel->editCpu(i);
    }
}

void MainWindow::removeCpu()
{
    QModelIndexList l = cpuList->selectionModel()->selectedIndexes();
    if (!l.empty())
    {
        QModelIndex i = l.at(0);
        if (i.isValid())
            cpuModel->removeCpu(i.row());
    }
}
