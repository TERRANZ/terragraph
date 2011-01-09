#ifndef COMMANDLISTMODEL_H
#define COMMANDLISTMODEL_H

#include <QAbstractListModel>
#include "commandlist/abstractcommand.h"

class CommandListModel: public QAbstractListModel
{
public:
    CommandListModel(QObject *parent = 0);

    void setData(const list<AbstractCommand *> &list);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    list<AbstractCommand *> m_List;
};

#endif // COMMANDLISTMODEL_H
