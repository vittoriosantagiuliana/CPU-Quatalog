#include "tableadapter.h"

TableAdapter::TableAdapter(QObject *parent) : QAbstractTableModel(parent), model(new Model()) { connect(parent, SIGNAL(addCpu(CPU *)), this, SLOT(addCpu(CPU *))); }

TableAdapter::~TableAdapter() {}

int TableAdapter::rowCount(const QModelIndex &) const { return static_cast<int>(model->size()); }

int TableAdapter::columnCount(const QModelIndex &) const { return static_cast<int>(model->width()); }

QVariant TableAdapter::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.isValid())
    {
        const CPU *c = (*model)[static_cast<unsigned int>(index.row())];
        switch (index.column())
        {
        case 0:
            return QString::fromStdString(c->getChipManufacturer());
        case 1:
            return QString::fromStdString(c->getModelName());
        case 2:
            return QString::fromStdString(c->getSocket());
        case 3:
            return c->getReleaseYear();
        case 4:
            return c->getCoreCount();
        case 5:
            return c->getThreadCount();
        case 6:
            return c->getManufacturingProcess();
        case 7:
            return c->getTdpRating();
        case 8:
            return QString(c->is64bit() ? "64 bit" : "32 bit");
        case 9:
            return QString(c->getEccMemorySupport() ? "Yes" : "No");
        default:
            break;
        }
    }
    return QVariant();
}

QVariant TableAdapter::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section)
        {
        case 0:
            return QString("Manufacturer");
        case 1:
            return QString("Model");
        case 2:
            return QString("Socket");
        case 3:
            return QString("Release year");
        case 4:
            return QString("# of cores");
        case 5:
            return QString("# of threads");
        case 6:
            return QString("Manufacturing process (nm)");
        case 7:
            return QString("TDP rating");
        case 8:
            return QString("Architecture");
        case 9:
            return QString("ECC memory support");
        default:
            return QString(section);
        }
    return QVariant();
}

void TableAdapter::loadFile(const std::string &path)
{
    try
    {
        beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
        model->clear();
        endRemoveRows();
        model->unserialize(path);
        beginInsertRows(QModelIndex(), 0, rowCount() - 1);
        endInsertRows();
    }
    catch (FileException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
    catch (ManufacturerException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
    catch (SocketException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
    catch (CoresException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
    catch (TDPException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
}

void TableAdapter::saveFile(const std::string &path) const
{
    try
    {
        model->serialize(path);
    }
    catch (FileException &e)
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(e.what()));
        msgBox.exec();
    }
}

void TableAdapter::addCpu(CPU *c)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    model->pushBack(*c);
    endInsertRows();
}

void TableAdapter::editCpu(QModelIndex &i)
{
    int j = i.row();
    EditDialog edit((*model)[static_cast<unsigned int>(j)]);
    edit.exec();
    emit dataChanged(i, i);
}

void TableAdapter::removeCpu(int i)
{
    beginRemoveRows(QModelIndex(), i, i);
    if (static_cast<unsigned int>(i) < model->size())
        model->remove(static_cast<unsigned int>(i));
    endRemoveRows();
}
