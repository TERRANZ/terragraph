#ifndef ASSEMBLELISTDIALOG_H
#define ASSEMBLELISTDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "assemblelistmodel.h"

namespace Ui {
    class ObjectListDialog;
}

class AssembleListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AssembleListDialog(QWidget *parent = 0);
    ~AssembleListDialog();


    void setData(Module value);

private slots:
    void create();
    void edit();
    void remove();
    void updateData();

private:
    Ui::ObjectListDialog *ui;
    Module m_Data;
    AssembleListModel *m_Model;
};

#endif // ASSEMBLELISTDIALOG_H
