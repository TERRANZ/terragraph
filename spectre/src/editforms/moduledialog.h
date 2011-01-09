#ifndef MODULEDIALOG_H
#define MODULEDIALOG_H

#include <QDialog>
#include <data/module.h>

namespace Ui {
    class ModuleDialog;
}

class ModuleDialog : public QDialog
{
    Q_OBJECT

    enum TypeEx
    {
        Normal,
        Lite
    };

private:
    explicit ModuleDialog(QWidget *parent = 0);
    ~ModuleDialog();

    void setType(TypeEx typeEx);
    void setData(Module value);

private slots:
    void save();
    void cancel();
    void params();
    void includes();

public:
    static bool editModule(Module module, QWidget *parent = 0);

private:
    Ui::ModuleDialog *ui;

    Module m_Data;
};

#endif // ATTRIBUTESMODULEDIALOG_H
