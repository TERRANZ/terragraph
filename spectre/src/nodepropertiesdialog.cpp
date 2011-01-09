#include "nodepropertiesdialog.h"
#include "ui_nodepropertiesdialog.h"

NodePropertiesDialog::NodePropertiesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NodePropertiesDialog)
{
    ui->setupUi(this);
}

NodePropertiesDialog::~NodePropertiesDialog()
{
    delete ui;
}
