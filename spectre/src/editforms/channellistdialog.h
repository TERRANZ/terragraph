#ifndef CHANNELLISTDIALOG_H
#define CHANNELLISTDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "channellistmodel.h"

namespace Ui {
    class ObjectListDialog;
}

class ChannelListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChannelListDialog(QWidget *parent = 0);
    ~ChannelListDialog();

    void setData(Module value);

private slots:
    void create();
    void edit();
    void remove();
    void updateData();

private:
    Ui::ObjectListDialog *ui;
    Module m_Data;
    ChannelListModel *m_Model;
};

#endif // CHANNELLISTDIALOG_H
