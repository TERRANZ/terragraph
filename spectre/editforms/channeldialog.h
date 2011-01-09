#ifndef CHANNELDIALOG_H
#define CHANNELDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "data/channel.h"
#include <QStringListModel>

namespace Ui {
    class ObjectDialog;
}


class ChannelDialog : public QDialog
{
    Q_OBJECT

private:
    explicit ChannelDialog(QWidget *parent = 0);
    ~ChannelDialog();

    void setData(Channel value);

private slots:
    void save();
    void cancel();
    void params();

public:
    static bool addChannel(Module module, QWidget *parent = 0);
    static bool editChannel(Channel channel, QWidget *parent = 0);

private:
    Ui::ObjectDialog *ui;
    Channel m_Data;
    QStringListModel *m_EntrysModel;
};

#endif // CHANNELDIALOG_H
