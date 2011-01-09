#include "qfiledialogex.h"
#include <QLayout>
#include <QLabel>

QFileDialogEx::QFileDialogEx(QWidget *parent) :
    QFileDialog(parent)
{
    m_ComboBox = new QComboBox(this);
    m_Model = new QTextCodecModel(this);
    m_ComboBox->setModel(m_Model);

    m_ComboBox->setCurrentIndex(m_Model->indexOfMib(QTextCodec::codecForName("UTF-8")->mibEnum()));

    this->layout()->addWidget(new QLabel("Code Page"));
    this->layout()->addWidget(m_ComboBox);
}

QTextCodec *QFileDialogEx::codec()
{
    return m_ComboBox->itemData(m_ComboBox->currentIndex(), QTextCodecModel::DataRole).value<QTextCodec*>();
}
