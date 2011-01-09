#include "paramlistmodel.h"

ParamListModel::ParamListModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

void ParamListModel::setParamList(list<Param> list)
{
    m_Data = list;
    reset();
}

QVariant ParamListModel::data(const QModelIndex & index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_Data.size()))
        return QVariant();

    Param* i = static_cast<Param *>(index.internalPointer());

    switch(role)
    {
    case Qt::DisplayRole:
        switch(index.column())
        {
        case 0:
            return QString::fromStdString(i->id());
        case 1:
            return QString::fromStdString(i->value());
        }
        break;
    case DataRole:
        QVariant result;
        result.setValue(*i);
        return result;
    }
    return QVariant();
}

QModelIndex ParamListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<Param>::const_iterator i = m_Data.begin();
    int counter = 0;
    while(counter < row)
    {
        i++;
        counter++;
    }

    return createIndex(row, column, (void *)&(*i));
}

QModelIndex ParamListModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ParamListModel::rowCount(const QModelIndex &parent) const
{
    return m_Data.size();
}

int ParamListModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ParamListModel::headerData(int section, Qt::Orientation orientation, int role) const
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
           return QString("Название");
        case 1:
           return QString("Значение");
       }
    }
    return QVariant();
}
