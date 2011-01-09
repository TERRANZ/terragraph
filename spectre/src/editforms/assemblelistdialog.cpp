#include "assemblelistdialog.h"
#include "ui_objectlistdialog.h"

#include <QMessageBox>
#include "editforms/assembledialog.h"

AssembleListDialog::AssembleListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObjectListDialog)
{
    ui->setupUi(this);

    m_Model = new AssembleListModel(this);
    ui->tableView->setModel(m_Model);

    setWindowTitle("Процессы");

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->edit, SIGNAL(clicked()), this, SLOT(edit()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));
}

AssembleListDialog::~AssembleListDialog()
{
    delete ui;
}

void AssembleListDialog::setData(Module value)
{
    m_Data = value;
    updateData();
}

void AssembleListDialog::create()
{
    if(AssembleDialog::addAssemble(m_Data, this))
    {
        updateData();
    }
}

void AssembleListDialog::edit()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Assemble value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), AssembleListModel::DataRole).value<Assemble>();
    if(value.isNull())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при редактировании.");
    }
    else
    {
        if(AssembleDialog::editAssemble(value, this))
        {
            updateData();
        }
    }
}

void AssembleListDialog::remove()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Assemble value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), AssembleListModel::DataRole).value<Assemble>();
    if(!value.removeFromParent())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при удалении.");
    }
    else
    {
        updateData();
    }
}

void AssembleListDialog::updateData()
{
    m_Model->setAssembleList(m_Data.assembleList());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}
