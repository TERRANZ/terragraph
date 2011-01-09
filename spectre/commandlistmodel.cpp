#include "commandlistmodel.h"

CommandListModel::CommandListModel(QObject *parent)
    : QAbstractListModel()
{
}

void CommandListModel::setData(const list<AbstractCommand *> &list)
{
    m_List = list;
    reset();
}

int CommandListModel::rowCount(const QModelIndex &parent) const
{
    return m_List.size();
}

QModelIndex CommandListModel::index(int row, int column, const QModelIndex &parent) const
{
    list<AbstractCommand*>::const_iterator i = m_List.begin();
    int counter = 0;
    while(counter < row)
    {
        i++;
        counter++;
    }
    return createIndex(row, column, (void *)(*i));
}

QVariant CommandListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

     if (index.row() >= static_cast<int>(m_List.size()))
         return QVariant();

     if (role == Qt::DisplayRole)
         return QString::fromStdString(static_cast<AbstractCommand*>(index.internalPointer())->text());
     else
         return QVariant();
}
