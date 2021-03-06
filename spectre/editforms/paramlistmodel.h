#ifndef PARAMLISTMODEL_H
#define PARAMLISTMODEL_H

#include <QAbstractItemModel>

#include <list>
#include "data/param.h"

Q_DECLARE_METATYPE(Param)

class ParamListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit ParamListModel(QObject *parent = 0);

    void setParamList(list<Param> list);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    list<Param> m_Data;
};

#endif // BASEWITHPARAMLISTMODEL_H
