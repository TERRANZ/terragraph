#include "generatordialog.h"
#include "ui_generatordialog.h"
#include <QFileDialog>

GeneratorDialog::GeneratorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratorDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Настройки генератора"));
    m_Generator = 0;

    m_Model = new QTextCodecModel(this);
    ui->comboBox->setModel(m_Model);

    connect(ui->btnPath, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui->save, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancel()));
}

GeneratorDialog::~GeneratorDialog()
{
    delete ui;
}

void GeneratorDialog::setGenerator(Generator *generator)
{
    m_Generator = generator;
    ui->command->setText(m_Generator->command());
    ui->params->setText(m_Generator->params());
    ui->workingDirectory->setText(m_Generator->workingDirectory());
    ui->comboBox->setCurrentIndex(m_Model->indexOfMib(m_Generator->codec()->mibEnum()));
}

void GeneratorDialog::selectFile()
{
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::ExistingFile);
    if(dialog.exec() == QDialog::Accepted)
    {
        ui->command->setText(dialog.selectedFiles().at(0));
    }
}

void GeneratorDialog::save()
{
    m_Generator->setPath(ui->command->text());
    m_Generator->setParams(ui->params->text());
    m_Generator->setWorkingDirectory(ui->workingDirectory->text());
    m_Generator->setCodec(ui->comboBox->itemData(ui->comboBox->currentIndex(), QTextCodecModel::DataRole).value<QTextCodec*>());
    accept();
}

void GeneratorDialog::cancel()
{
    reject();
}
