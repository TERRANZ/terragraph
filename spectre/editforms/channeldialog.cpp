#include "channeldialog.h"
#include "ui_objectdialog.h"

#include "paramlistdialog.h"
#include <QMessageBox>

#include "data/xmldata.h"

ChannelDialog::ChannelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectDialog)
{
    ui->setupUi(this);

    m_EntrysModel = new QStringListModel(this);

    ui->label_id->setText(tr("Имя канала"));
    ui->label_templet->setText(tr("Схема генерации канала"));
    ui->entry->setModel(m_EntrysModel);

    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->params, SIGNAL(clicked()), this, SLOT(params()));
}

ChannelDialog::~ChannelDialog()
{
    delete ui;
}

void ChannelDialog::setData(Channel value)
{
    m_Data = value;
    ui->id->setText(QString::fromStdString(m_Data.id()));
    ui->templet->setText(QString::fromStdString(m_Data.templet()));
    ui->rem->setText(QString::fromStdString(m_Data.rem()));

    QStringList entrys;
    list<State> states = m_Data.stateList();
    for(list<State>::iterator i = states.begin(); i != states.end(); i++)
    {
        entrys<<QString::fromStdString(i->id());
    }
    m_EntrysModel->setStringList(entrys);
    ui->entry->setCurrentIndex(ui->entry->findText(QString::fromStdString(m_Data.entry())));
}

void ChannelDialog::save()
{
    m_Data.toChannel().setId(ui->id->text().toStdString());
    m_Data.toChannel().setTemplet(ui->templet->text().toStdString());
    m_Data.toChannel().setRem(ui->rem->text().toStdString());
    m_Data.toChannel().setEntry(ui->entry->currentText().toStdString());

    accept();
}

void ChannelDialog::params()
{
    ParamListDialog dialog(this);
    dialog.setData(m_Data);
    dialog.exec();
}

void ChannelDialog::cancel()
{
    reject();
}

bool ChannelDialog::addChannel(Module module, QWidget *parent)
{
    CommandList::State savePoint;
    module.xmlData()->commandList()->saveState(savePoint);
    Channel value = module.addChannel();
    ChannelDialog dialog(parent);
    dialog.setData(value);
    if(dialog.exec() == QDialog::Accepted)
    {
        return true;
    }
    else
    {
        module.xmlData()->commandList()->rollback(savePoint);
        return false;
    }
}

bool ChannelDialog::editChannel(Channel channel, QWidget *parent)
{
//    Channel newChannel = channel.clone().toChannel();
//    ChannelDialog dialog(parent);
//    dialog.setData(newChannel);
//    while(true)
//    {
//        if(dialog.exec() == QDialog::Accepted)
//        {
//            Base result = channel.replace(newChannel);
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
