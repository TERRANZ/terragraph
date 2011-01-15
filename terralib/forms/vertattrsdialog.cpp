#include "vertattrsdialog.h"
#include "ui_vertattrsdialog.h"

VertAttrsDialog::VertAttrsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vertattrsdialog)
{
    ui->setupUi(this);
}

VertAttrsDialog::~VertAttrsDialog()
{
    delete ui;
}

void VertAttrsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
