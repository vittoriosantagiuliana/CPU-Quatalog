#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adddialog.h"
#include "tableadapter.h"

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QTableView>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
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
signals:
    void addCpu(CPU *);
public slots:
    void addDialog();
};

#endif // MAINWINDOW_H
