#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QListWidget>
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVBoxLayout * mainLayout;
    QHBoxLayout * topButtonsLayout;

    QWidget * mainWidget;

    QPushButton * addItemButton;
    QPushButton * removeButton;
    QPushButton * editButton;

    QListView * cpuList;

public:
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
