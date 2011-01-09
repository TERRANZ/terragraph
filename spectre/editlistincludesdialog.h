#ifndef EDITLISTVALUESDIQLOG_H
#define EDITLISTVALUESDIQLOG_H

#include <QDialog>
#include "basewithparamlistmodel.h"
#include "data/basewithparamlist.h"


namespace Ui {
    class EditListValuesDialog;
}

class EditListValuesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditListValuesDialog(QWidget *parent = 0);
    ~EditListValuesDialog();

    void setData(BaseWithParamList value);

private slots:
    void create();

private:
    Ui::EditListValuesDialog *ui;
    BaseWithParamListModel *m_Model;
};

#endif // EDITLISTVALUESDIQLOG_H
