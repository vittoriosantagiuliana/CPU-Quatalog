#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adddialog.h"
#include "tableadapter.h"

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QTableView>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QMenuBar * menuBar;
    QMenu * fileMenu;
    QAction * openAction, * saveAction, * exitAction;

    QWidget * mainWidget;

    QVBoxLayout * mainLayout;
    QHBoxLayout * topButtonsLayout;

    QPushButton * addItemButton;
    QPushButton * editButton;
    QPushButton * removeButton;

    QTableView * cpuList;

    TableAdapter * cpuModel;

public:
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private slots:
    void addCpu(CPU *);
    void editCpu();
    void removeCpu();

public slots:
    void openFile();
    void saveFile();
    void addDialog();
};

#endif // MAINWINDOW_H
