#ifndef GENERATORDIALOG_H
#define GENERATORDIALOG_H

#include <QDialog>
#include "generator.h"
#include "qtextcodecmodel.h"

namespace Ui {
    class GeneratorDialog;
}

class GeneratorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratorDialog(QWidget *parent = 0);
    ~GeneratorDialog();

    void setGenerator(Generator *generator);

private slots:
    void selectFile();
    void save();
    void cancel();

private:
    Ui::GeneratorDialog *ui;
    Generator *m_Generator;
    QTextCodecModel *m_Model;
};

#endif // GENERATORDIALOG_H
