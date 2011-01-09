#ifndef STDLISTSTTRINGMODEL_H
#define STDLISTSTTRINGMODEL_H

#include <QAbstractItemModel>
#include <list>
#include <string>

using namespace std;

class StdStringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StdStringListModel(QObject *parent = 0);

    void setList(const list<string> &list);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    list<string> m_List;
};

#endif // STDLISTSTTRINGMODEL_H
