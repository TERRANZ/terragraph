#ifndef PROCESSLISTDIALOG_H
#define PROCESSLISTDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "processlistmodel.h"

namespace Ui {
    class ObjectListDialog;
}

class ProcessListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProcessListDialog(QWidget *parent = 0);
    ~ProcessListDialog();

    void setData(Module value);

private slots:
    void create();
    void edit();
    void remove();
    void updateData();

private:
    Ui::ObjectListDialog *ui;
    Module m_Data;
    ProcessListModel *m_Model;
};

#endif // PROCESSLISTDIALOG_H
