#ifndef TABLEADAPTER_H
#define TABLEADAPTER_H

#include "model.h"
#include "serializexml.h"
#include "editdialog.h"

#include <QAbstractTableModel>

class TableAdapter : public QAbstractTableModel
{
private:
    Model * model;
public:
    TableAdapter(QObject * = nullptr);
    ~TableAdapter() override;
    virtual int rowCount(const QModelIndex & = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex & = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const override;

    void saveFile(const std::string &) const;
    void loadFile(const std::string &);
    void addCpu(CPU *);
    void editCpu(QModelIndex &);
    void removeCpu(int);
};

#endif // TABLEADAPTER_H
