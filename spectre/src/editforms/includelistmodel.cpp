#include "includelistmodel.h"

IncludeListModel::IncludeListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void IncludeListModel::setIncludeList(list<Include> list)
{
    m_Data = list;
    reset();
}

QVariant IncludeListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_Data.size()))
        return QVariant();

    Include *i = static_cast<Include *>(index.internalPointer());

    switch(role)
    {
    case Qt::DisplayRole:
        switch(index.column())
        {
        case 0:
            return QString::fromStdString(i->file());
        case 1:
            return QString::fromStdString(i->module());
        }
        break;
    case DataRole:
        QVariant result;
        result.setValue(*i);
        return result;
    }
    return QVariant();
}

QModelIndex IncludeListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<Include>::const_iterator i = m_Data.begin();
    int counter = 0;
    while(counter < row)
    {
        i++;
        counter++;
    }
    return createIndex(row, column, (void *)&(*i));
}

QModelIndex IncludeListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int IncludeListModel::rowCount(const QModelIndex &parent) const
{
    return m_Data.size();
}

int IncludeListModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant IncludeListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation == Qt::Vertical)
    {
        return section + 1;
    }
    else
    {
        switch(section)
        {
        case 0:
           return QString("Файл");
        case 1:
           return QString("Модуль");
       }
    }
    return QVariant();
}
