#ifndef INCLUDELISTMODEL_H
#define INCLUDELISTMODEL_H

#include <QAbstractItemModel>

#include <list>
#include "data/include.h"

Q_DECLARE_METATYPE(Include)

class IncludeListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit IncludeListModel(QObject *parent = 0);

    void setIncludeList(list<Include> list);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    list<Include> m_Data;

};

#endif // INCLUDELISTMODEL_H
