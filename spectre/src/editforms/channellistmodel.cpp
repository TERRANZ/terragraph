#include "channellistmodel.h"

ChannelListModel::ChannelListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void ChannelListModel::setChannelList(list<Channel> list)
{
    m_Data = list;
    reset();
}

QVariant ChannelListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_Data.size()))
        return QVariant();

    Channel *i = static_cast<Channel *>(index.internalPointer());

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

QModelIndex ChannelListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<Channel>::const_iterator i = m_Data.begin();
    int counter = 0;
    while(counter < row)
    {
        i++;
        counter++;
    }
    return createIndex(row, column, (void *)&(*i));
}

QModelIndex ChannelListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ChannelListModel::rowCount(const QModelIndex &parent) const
{
    return m_Data.size();
}

int ChannelListModel::columnCount(const QModelIndex &parent) const
{
    return 4;
}

QVariant ChannelListModel::headerData(int section, Qt::Orientation orientation, int role) const
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
