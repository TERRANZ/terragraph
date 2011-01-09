#include "arcdialog.h"
#include "ui_arcdialog.h"

ArcDialog::ArcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcDialog)
{
    ui->setupUi(this);
}

ArcDialog::~ArcDialog()
{
    delete ui;
}
