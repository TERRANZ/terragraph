#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "data/process.h"
#include <QStringListModel>

namespace Ui {
    class ObjectDialog;
}

class ProcessDialog : public QDialog
{
    Q_OBJECT

private:
    explicit ProcessDialog(QWidget *parent = 0);
    ~ProcessDialog();

    void setData(Process value);

private slots:
    void save();
    void cancel();
    void params();

public:
    static bool addProcess(Module module, QWidget *parent = 0);
    static bool editProcess(Process process, QWidget *parent = 0);

private:
    Ui::ObjectDialog *ui;
    Process m_Data;
    QStringListModel *m_EntryModel;
};

#endif // PROCESSDIALOG_H
