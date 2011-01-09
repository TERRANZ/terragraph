#ifndef PROCESSLISTMODEL_H
#define PROCESSLISTMODEL_H

#include <QAbstractItemModel>
#include <list>
#include "data/process.h"

using namespace std;

Q_DECLARE_METATYPE(Process)

class ProcessListModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit ProcessListModel(QObject *parent = 0);

    void setProcessList(list<Process> list);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    list<Process> m_Data;

};

#endif // PROCESSLISTMODEL_H
