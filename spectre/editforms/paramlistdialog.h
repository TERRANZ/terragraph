#ifndef PARAMLISTDIALOG_H
#define PARAMLISTDIALOG_H

#include <QDialog>
#include "paramlistmodel.h"
#include "data/basewithparamlist.h"


namespace Ui {
    class ValueListDialog;
}

class ParamListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ParamListDialog(QWidget *parent = 0);
    ~ParamListDialog();

    void setData(BaseWithParamList value);

private slots:
    void create();
    void edit();
    void remove();
    void updateData();
    void setDataValues(QModelIndexList indexList);

public:
    static bool editParamList(BaseWithParamList baseWithParamlist, QWidget *parent = 0);

private:
    Ui::ValueListDialog *ui;
    BaseWithParamList m_Data;
    ParamListModel *m_Model;
};

#endif // PARAMLISTDIALOG_H
