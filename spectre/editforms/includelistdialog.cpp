#include "includelistdialog.h"
#include "ui_valuelistdialog.h"
#include <QMessageBox>

IncludeListDialog::IncludeListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ValueListDialog)
{
    ui->setupUi(this);

    m_Model = new IncludeListModel(this);
    ui->tableView->setModel(m_Model);

    setWindowTitle("Подключаемые модули");

    ui->label_1->setText("Подключаемый файл");
    ui->label_2->setText("Имя модуля");

    connect(ui->tableView, SIGNAL(changeCells(QModelIndexList)), this, SLOT(setDataValues(QModelIndexList)));

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->edit, SIGNAL(clicked()), this, SLOT(edit()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));
}

IncludeListDialog::~IncludeListDialog()
{
    delete ui;
}

void IncludeListDialog::setData(Module value)
{
    m_Data = value;
    updateData();
}

void IncludeListDialog::create()
{
    Include value = m_Data.addInclude();
    value.setFile(ui->value_1->text().toStdString());
    value.setModule(ui->value_2->text().toStdString());
    updateData();
}

void IncludeListDialog::edit()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Include value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), IncludeListModel::DataRole).value<Include>();
    if(value.isNull())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при редактировании.");
    }
    else
    {
        value.setFile(ui->value_1->text().toStdString());
        value.setModule(ui->value_2->text().toStdString());
        updateData();
    }
}

void IncludeListDialog::remove()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Include value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), IncludeListModel::DataRole).value<Include>();
    if(!value.removeFromParent())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при удалении.");
    }
    else
    {
        updateData();
    }
}

void IncludeListDialog::updateData()
{
    m_Model->setIncludeList(m_Data.includeList());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}


void IncludeListDialog::setDataValues(QModelIndexList indexList)
{
    if(indexList.isEmpty())
    {
        ui->value_1->setText(QString());
        ui->value_2->setText(QString());
    }
    else
    {
        Include *include = static_cast<Include *>(indexList.at(0).internalPointer());
        ui->value_1->setText(QString::fromStdString(include->file()));
        ui->value_2->setText(QString::fromStdString(include->module()));
    }
}

