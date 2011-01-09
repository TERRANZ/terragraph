#include "editlistvaluesdialog.h"
#include "ui_editlistvaluesdialog.h"

EditListValuesDialog::EditListValuesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditListValuesDialog)
{
    ui->setupUi(this);
    m_Model = new BaseWithParamListModel(this);
    ui->tableView->setModel(m_Model);

    connect(ui->create, SIGNAL(clicked()), this, SLOT(create()));
}

EditListValuesDialog::~EditListValuesDialog()
{
    delete ui;
}

void EditListValuesDialog::setData(BaseWithParamList value)
{
    m_Model->setData(value);
}

void EditListValuesDialog::create()
{
    m_Model->addParam(ui->id->text(), ui->value->text());
}
