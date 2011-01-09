#include "qtableviewex.h"

QTableViewEx::QTableViewEx(QWidget *parent) :
    QTableView(parent)
{
}

void QTableViewEx::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QTableView::selectionChanged(selected, deselected);
    emit changeCells(selected.indexes());
}
