#ifndef CHANNELLISTMODEL_H
#define CHANNELLISTMODEL_H

#include <QAbstractItemModel>
#include <list>
#include "data/channel.h"

using namespace std;

Q_DECLARE_METATYPE(Channel)

class ChannelListModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit ChannelListModel(QObject *parent = 0);

    void setChannelList(list<Channel> list);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    list<Channel> m_Data;

};

#endif // CHANNELLISTMODEL_H
