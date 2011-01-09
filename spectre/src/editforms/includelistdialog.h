#ifndef INCLUDELISTDIALOG_H
#define INCLUDELISTDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "includelistmodel.h"

namespace Ui {
    class ValueListDialog;
}

class IncludeListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IncludeListDialog(QWidget *parent = 0);
    ~IncludeListDialog();

    void setData(Module value);

private slots:
    void create();
    void edit();
    void remove();
    void updateData();
    void setDataValues(QModelIndexList indexList);

private:
    Ui::ValueListDialog *ui;
    Module m_Data;
    IncludeListModel *m_Model;
};

#endif // INCLUDELISTDIALOG_H
