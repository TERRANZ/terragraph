#include "processlistmodel.h"

ProcessListModel::ProcessListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void ProcessListModel::setProcessList(list<Process> list)
{
    m_Data = list;
    reset();
}

QVariant ProcessListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_Data.size()))
        return QVariant();

    Process *i = static_cast<Process *>(index.internalPointer());

    switch(role)
    {
    case Qt::DisplayRole:
        switch(index.column())
        {
        case 0:
            return QString::fromStdString(i->id());
        case 1:
            return QString::fromStdString(i->entry());
        case 2:
            return QString::fromStdString(i->templet());
        case 3:
            return QString::fromStdString(i->rem());
        }
        break;
    case DataRole:
        QVariant result;
        result.setValue(*i);
        return result;
    }
    return QVariant();
}

QModelIndex ProcessListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<Process>::const_iterator i = m_Data.begin();
    int counter = 0;
    while(counter < row && i != m_Data.end())
    {
        i++;
        counter++;
    }
    if(i == m_Data.end())
        return createIndex(row, column);
    return createIndex(row, column, (void *)&(*i));
}

QModelIndex ProcessListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ProcessListModel::rowCount(const QModelIndex &parent) const
{
    return m_Data.size();
}

int ProcessListModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant ProcessListModel::headerData(int section, Qt::Orientation orientation, int role) const
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
           return QString("Имя");
        case 1:
           return QString("Точка входа");
        case 2:
           return QString("Схема генерации");
        case 3:
           return QString("Комментарий");
       }
    }
    return QVariant();
}
