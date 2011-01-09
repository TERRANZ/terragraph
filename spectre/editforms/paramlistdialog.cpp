#include "paramlistdialog.h"
#include "ui_valuelistdialog.h"

#include <QMessageBox>
#include "qtableviewex.h"


ParamListDialog::ParamListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ValueListDialog)
{
    ui->setupUi(this);
    m_Model = new ParamListModel(this);
    ui->tableView->setModel(m_Model);

    setWindowTitle("Параметры");

    ui->label_1->setText("Имя");
    ui->label_2->setText("Значение");

    connect(ui->tableView, SIGNAL(changeCells(QModelIndexList)), this, SLOT(setDataValues(QModelIndexList)));

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
    connect(ui->edit, SIGNAL(clicked()), this, SLOT(edit()));
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(remove()));
}

ParamListDialog::~ParamListDialog()
{
    delete ui;
}

void ParamListDialog::setData(BaseWithParamList value)
{
    m_Data = value;
    updateData();
}

void ParamListDialog::create()
{
//    Param value = m_Data.createParam();
//    value.setId(ui->value_1->text().toStdString());
//    value.setValue(ui->value_2->text().toStdString());
//    Param result = m_Data.addParam(value);
//    if(result.isNull())
//    {
//        QMessageBox::information(this, "Ошибка!", "Имя должно быть уникально.");
//    }
//    else
//    {
//        updateData();
//    }

    Param value = m_Data.addParam();
    value.setId(ui->value_1->text().toStdString());
    value.setValue(ui->value_2->text().toStdString());
    updateData();
}

void ParamListDialog::edit()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Param value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ParamListModel::DataRole).value<Param>();
    if(value.isNull())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при редактировании.");
    }
    else
    {
        value.setId(ui->value_1->text().toStdString());
        value.setValue(ui->value_2->text().toStdString());
        updateData();
    }
}

void ParamListDialog::remove()
{
    if(!ui->tableView->selectionModel()->hasSelection())
        return;
    Param value = m_Model->data(ui->tableView->selectionModel()->selectedRows(0).at(0), ParamListModel::DataRole).value<Param>();
    if(!value.removeFromParent())
    {
        QMessageBox::information(this, "Ошибка!", "Ошибка при удалении.");
    }
    else
    {
        updateData();
    }
}

void ParamListDialog::updateData()
{
    m_Model->setParamList(m_Data.paramList());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void ParamListDialog::setDataValues(QModelIndexList indexList)
{
    if(indexList.isEmpty())
    {
        ui->value_1->setText(QString());
        ui->value_2->setText(QString());
    }
    else
    {
        Param *param = static_cast<Param *>(indexList.at(0).internalPointer());
        ui->value_1->setText(QString::fromStdString(param->id()));
        ui->value_2->setText(QString::fromStdString(param->value()));
    }
}

bool ParamListDialog::editParamList(BaseWithParamList baseWithParamlist, QWidget *parent)
{
    ParamListDialog dialog(parent);
    dialog.setData(baseWithParamlist);
    dialog.exec();
    return true;
}
