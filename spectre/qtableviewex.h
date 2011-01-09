#ifndef QTABLEVIEWEX_H
#define QTABLEVIEWEX_H

#include <QTableView>

class QTableViewEx : public QTableView
{
    Q_OBJECT
public:
    explicit QTableViewEx(QWidget *parent = 0);

protected:
    virtual void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

signals:
    void changeCells(QModelIndexList indexList);

public slots:

};

#endif // QTABLEVIEWEX_H
