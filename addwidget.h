#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QLineEdit>

class AddWidget : public QWidget
{
    Q_OBJECT
private:

    QLineEdit year;
public:
    explicit AddWidget(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // ADDWIDGET_H
