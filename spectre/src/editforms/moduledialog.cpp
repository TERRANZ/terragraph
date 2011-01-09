#include "moduledialog.h"
#include "ui_moduledialog.h"

#include "paramlistdialog.h"
#include "includelistdialog.h"
#include <QMessageBox>

#include "data/xmldata.h"

ModuleDialog::ModuleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModuleDialog)
{
    ui->setupUi(this);

    setWindowTitle("Атрибуты модуля");

    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->params, SIGNAL(clicked()), this, SLOT(params()));
    connect(ui->includes, SIGNAL(clicked()), this, SLOT(includes()));
}

ModuleDialog::~ModuleDialog()
{
    delete ui;
}

void ModuleDialog::setType(TypeEx typeEx)
{
    switch(typeEx)
    {
    case Normal:
        ui->params->setVisible(true);
        ui->includes->setVisible(true);
    case Lite:
        ui->params->setVisible(false);
        ui->includes->setVisible(false);
    }
}

void ModuleDialog::setData(Module value)
{
    m_Data = value;
    ui->id->setText(QString::fromStdString(m_Data.id()));
    ui->ver->setText(QString::fromStdString(m_Data.ver()));
    ui->rem->setText(QString::fromStdString(m_Data.rem()));
}

void ModuleDialog::save()
{
    m_Data.setId(ui->id->text().toStdString());
    m_Data.setVer(ui->ver->text().toStdString());
    m_Data.setRem(ui->rem->text().toStdString());
    accept();
}

void ModuleDialog::cancel()
{
    reject();
}

void ModuleDialog::params()
{
//    ParamListDialog dialog(this);
//    dialog.setData(m_Data);
//    dialog.exec();
    ParamListDialog::editParamList(m_Data, this);
}

void ModuleDialog::includes()
{
    IncludeListDialog dialog(this);
    dialog.setData(m_Data);
    dialog.exec();
}

bool ModuleDialog::editModule(Module module, QWidget *parent)
{
//    Module value = module.clone().toModule();
//    ModuleDialog dialog(parent);
//    dialog.setData(value);
//    if(dialog.exec() == QDialog::Accepted)
//    {
//        Base result = module.replace(value);
//        if(result.isNull())
//        {
//            QMessageBox::information(parent, "Ошибка!", "Непонятно! о_О");
//            return false;
//        }
//    }
//    else
//    {
//        return false;
//    }
//    return true;

    CommandList::State savePoint;
    module.xmlData()->commandList()->saveState(savePoint);
    ModuleDialog dialog(parent);
    dialog.setData(module);
    if(dialog.exec() == QDialog::Accepted)
    {
        return true;
    }
    module.xmlData()->commandList()->rollback(savePoint);
    return false;
}
