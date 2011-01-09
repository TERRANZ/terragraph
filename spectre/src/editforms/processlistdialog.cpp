#include "processlistdialog.h"
#include "ui_objectlistdialog.h"

#include <QMessageBox>
#include "editforms/processdialog.h"

ProcessListDialog::ProcessListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectListDialog)
{
    ui->setupUi(this);

    m_Model = new ProcessListModel(this);
    ui->tableView->setModel(m_Model);

    setWindowTitle("Процессы");

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->edit, SIGNAL(clicked()), this, SLOT(edit()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));
}

ProcessListDialog::~ProcessListDialog()
{
    delete ui;
}

void ProcessListDialog::setData(Module value)
{
    m_Data = value;
    updateData();
}

void ProcessListDialog::create()
{
    if(ProcessDialog::addProcess(m_Data, this))
    {
        updateData();
    }
}

void ProcessListDialog::edit()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Process value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ProcessListModel::DataRole).value<Process>();
    if(value.isNull())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при редактировании.");
    }
    else
    {
        if(ProcessDialog::editProcess(value, this))
        {
            updateData();
        }
    }
}

void ProcessListDialog::remove()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Process value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ProcessListModel::DataRole).value<Process>();
    if(!value.removeFromParent())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при удалении.");
    }
    else
    {
        updateData();
    }
}

void ProcessListDialog::updateData()
{
    m_Model->setProcessList(m_Data.processList());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}
