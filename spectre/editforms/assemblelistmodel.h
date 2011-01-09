#ifndef ASSEMBLELISTMODEL_H
#define ASSEMBLELISTMODEL_H

#include <QAbstractItemModel>
#include <list>
#include "data/assemble.h"

using namespace std;

Q_DECLARE_METATYPE(Assemble)

class AssembleListModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit AssembleListModel(QObject *parent = 0);

    void setAssembleList(list<Assemble> list);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    list<Assemble> m_Data;

};

#endif // ASSEMBLELISTMODEL_H
