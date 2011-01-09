#ifndef ASSEMBLEDIALOG_H
#define ASSEMBLEDIALOG_H

#include <QDialog>
#include "data/module.h"
#include "data/assemble.h"

namespace Ui {
    class ObjectDialog;
}

class AssembleDialog : public QDialog
{
    Q_OBJECT

private:
    explicit AssembleDialog(QWidget *parent = 0);
    ~AssembleDialog();

    void setData(Assemble value);

private slots:
    void save();
    void cancel();
    void params();

public:
    static bool addAssemble(Module module, QWidget *parent = 0);
    static bool editAssemble(Assemble assemble, QWidget *parent = 0);

private:
    Ui::ObjectDialog *ui;
    Assemble m_Data;
};

#endif // ASSEMBLEDIALOG_H
