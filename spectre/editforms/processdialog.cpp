#include "processdialog.h"
#include "ui_objectdialog.h"

#include "paramlistdialog.h"
#include <QMessageBox>

ProcessDialog::ProcessDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ObjectDialog)
{
    m_EntryModel = new QStringListModel(this);

    ui->setupUi(this);
    ui->label_id->setText(tr("Имя процесса"));
    ui->label_templet->setText(tr("Схема генерации процесса"));
    ui->entry->setModel(m_EntryModel);

    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->params, SIGNAL(clicked()), this, SLOT(params()));
}

ProcessDialog::~ProcessDialog()
{
    delete ui;
}

void ProcessDialog::setData(Process value)
{
    m_Data = value;
    ui->id->setText(QString::fromStdString(m_Data.id()));
    ui->templet->setText(QString::fromStdString(m_Data.templet()));
    ui->rem->setText(QString::fromStdString(m_Data.rem()));
    ui->entry->setEditText(QString::fromStdString(m_Data.entry()));

    QStringList entrys;

    list<Port> ports = m_Data.portList();
    {
        for(list<Port>::iterator i = ports.begin(); i != ports.end(); i++)
        {
            entrys<<QString::fromStdString(i->id());
        }
    }
    list<Method> methods = m_Data.methodList();
    {
        for(list<Method>::iterator i = methods.begin(); i != methods.end(); i++)
        {
            entrys<<QString::fromStdString(i->id());
        }
    }
    m_EntryModel->setStringList(entrys);
    ui->entry->setCurrentIndex(ui->entry->findText(QString::fromStdString(m_Data.entry())));
}

void ProcessDialog::save()
{
    m_Data.setId(ui->id->text().toStdString());
    m_Data.setTemplet(ui->templet->text().toStdString());
    m_Data.setRem(ui->rem->text().toStdString());
    m_Data.setEntry(ui->entry->currentText().toStdString());

    accept();
}

void ProcessDialog::params()
{
    ParamListDialog dialog(this);
    dialog.setData(m_Data);
    dialog.exec();
}

void ProcessDialog::cancel()
{
    reject();
}

bool ProcessDialog::addProcess(Module module, QWidget *parent)
{
//    Process value = module.createProcess();
//    ProcessDialog dialog(parent);
//    dialog.setData(value);
//    while(true)
//    {
//        if(dialog.exec() == QDialog::Accepted)
//        {
//            Process result = module.addProcess(value);
//            if(result.isNull())
//            {
//                QMessageBox::information(parent, "Ошибка!", "Имя должно быть уникалльно.");
//            }
//            else
//            {
//               return true;
//            }
//        }
//        else
//        {
//            return false;
//        }
//    }
    return true;
}

bool ProcessDialog::editProcess(Process process, QWidget *parent)
{
//    Process newProcess = process.clone().toProcess();
//    ProcessDialog dialog(parent);
//    dialog.setData(newProcess);
//    while(true)
//    {
//        if(dialog.exec() == QDialog::Accepted)
//        {
//            Base result = process.replace(newProcess);
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
