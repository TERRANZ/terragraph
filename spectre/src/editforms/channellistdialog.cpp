#include "channellistdialog.h"
#include "ui_objectlistdialog.h"
#include "editforms/channeldialog.h"
#include <QMessageBox>

ChannelListDialog::ChannelListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectListDialog)
{
    ui->setupUi(this);

    m_Model = new ChannelListModel(this);
    ui->tableView->setModel(m_Model);

    setWindowTitle("Каналы");

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->edit, SIGNAL(clicked()), this, SLOT(edit()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));
}

ChannelListDialog::~ChannelListDialog()
{
    delete ui;
}

void ChannelListDialog::setData(Module value)
{
    m_Data = value;
    updateData();
}

void ChannelListDialog::create()
{
    if(ChannelDialog::addChannel(m_Data, this))
    {
        updateData();
    }
}

void ChannelListDialog::edit()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Channel value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ChannelListModel::DataRole).value<Channel>();
    if(value.isNull())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при редактировании.");
    }
    else
    {
        if(ChannelDialog::editChannel(value, this))
        {
            updateData();
        }
    }
}

void ChannelListDialog::remove()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Channel value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ChannelListModel::DataRole).value<Channel>();
    if(!value.removeFromParent())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при удалении.");
    }
    else
    {
        updateData();
    }
}

void ChannelListDialog::updateData()
{
    m_Model->setChannelList(m_Data.channelList());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}


