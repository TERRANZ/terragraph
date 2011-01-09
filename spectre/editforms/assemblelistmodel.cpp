#include "assemblelistmodel.h"

AssembleListModel::AssembleListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void AssembleListModel::setAssembleList(list<Assemble> list)
{
    m_Data = list;
    reset();
}

QVariant AssembleListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_Data.size()))
        return QVariant();

    Assemble *i = static_cast<Assemble *>(index.internalPointer());

    switch(role)
    {
    case Qt::DisplayRole:
        switch(index.column())
        {
        case 0:
            return QString::fromStdString(i->id());
        case 1:
            return QString::fromStdString(i->templet());
        case 2:
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

QModelIndex AssembleListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<Assemble>::const_iterator i = m_Data.begin();
    int counter = 0;
    while(counter < row)
    {
        i++;
        counter++;
    }
    return createIndex(row, column, (void *)&(*i));
}

QModelIndex AssembleListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int AssembleListModel::rowCount(const QModelIndex &parent) const
{
    return m_Data.size();
}

int AssembleListModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant AssembleListModel::headerData(int section, Qt::Orientation orientation, int role) const
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
           return QString("Схема генерации");
        case 2:
           return QString("Комментарий");
       }
    }
    return QVariant();
}
