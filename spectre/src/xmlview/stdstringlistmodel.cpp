#include "stdstringlistmodel.h"

StdStringListModel::StdStringListModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

void StdStringListModel::setList(const list<string> &list)
{
    m_List = list;
    reset();
}

int StdStringListModel::rowCount(const QModelIndex &parent) const
{
    return m_List.size();
}

QVariant StdStringListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= static_cast<int>(m_List.size()))
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        int i = 0;
        for(list<string>::const_iterator itr = m_List.begin(); itr != m_List.end(); itr++)
        {
            if(i == index.row())
                return QString::fromStdString(*itr);
            i++;
        }
        return QVariant();
    }
    else
        return QVariant();
}

QVariant StdStringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}
