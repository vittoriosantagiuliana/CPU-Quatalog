#ifndef TABLEADAPTER_H
#define TABLEADAPTER_H

#include "model.h"

#include <QAbstractTableModel>

class TableAdapter : public QAbstractTableModel
{
    //Q_OBJECT
private:
    Model * model;
public:
    TableAdapter(QObject * = nullptr);
    ~TableAdapter() override;
    virtual int rowCount(const QModelIndex & = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex & = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const override;

signals:

public slots:
    void addCpu(CPU * c);
};

#endif // TABLEADAPTER_H
