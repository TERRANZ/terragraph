#ifndef QFILEDIALOGEX_H
#define QFILEDIALOGEX_H

#include <QFileDialog>
#include <QComboBox>
#include <QTextCodec>
#include "qtextcodecmodel.h"

class QFileDialogEx : public QFileDialog
{
    Q_OBJECT
public:
    explicit QFileDialogEx(QWidget *parent = 0);

    QTextCodec *codec();

private:
    QComboBox *m_ComboBox;
    QTextCodecModel *m_Model;
};

#endif // QFILEDIALOGEX_H
