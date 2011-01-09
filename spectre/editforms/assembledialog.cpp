#include "assembledialog.h"
#include "ui_objectdialog.h"

#include "paramlistdialog.h"
#include <QMessageBox>

AssembleDialog::AssembleDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ObjectDialog)
{
    ui->setupUi(this);

    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->params, SIGNAL(clicked()), this, SLOT(params()));
}

AssembleDialog::~AssembleDialog()
{
    delete ui;
}

void AssembleDialog::setData(Assemble value)
{
    m_Data = value;
    ui->id->setText(QString::fromStdString(m_Data.id()));
    ui->templet->setText(QString::fromStdString(m_Data.templet()));
    ui->rem->setText(QString::fromStdString(m_Data.rem()));
}

void AssembleDialog::save()
{
    m_Data.toAssemble().setId(ui->id->text().toStdString());
    m_Data.toAssemble().setTemplet(ui->templet->text().toStdString());
    m_Data.toAssemble().setRem(ui->rem->text().toStdString());
    accept();
}

void AssembleDialog::params()
{
    ParamListDialog dialog(this);
    dialog.setData(m_Data);
    dialog.exec();
}

void AssembleDialog::cancel()
{
    reject();
}

bool AssembleDialog::addAssemble(Module module, QWidget *parent)
{
//    Assemble value = module.createAssemble();
//    AssembleDialog dialog(parent);
//    dialog.setWindowTitle("Новая сборка");
//    dialog.ui->entry->setEnabled(false);
//    dialog.setData(value);
//    while(true)
//    {
//        if(dialog.exec() == QDialog::Accepted)
//        {
//            Assemble result = module.addAssemble(value);
//            if(result.isNull())
//            {
//                QMessageBox::information(parent, "Ошибка!", "Имя должно быть уникалльно.");
//            }
//            else
//            {
//                return true;
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
    return true;
}

bool AssembleDialog::editAssemble(Assemble assemble, QWidget *parent)
{
//    Assemble newAssemble = assemble.clone().toAssemble();
//    AssembleDialog dialog(parent);
//    dialog.setWindowTitle("Редактирование сборки");
//    dialog.ui->entry->setEnabled(false);
//    dialog.setData(newAssemble);
//    while(true)
//    {
//        if(dialog.exec() == QDialog::Accepted)
//        {
//            Base result = assemble.replace(newAssemble);
//            if(result.isNull())
//            {
//                QMessageBox::information(parent, "Ошибка!", "Имя должно быть уникалльно.");
//            }
//            else
//            {
//                return true;
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
    return true;
}
