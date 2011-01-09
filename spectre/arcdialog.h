#ifndef ARCDIALOG_H
#define ARCDIALOG_H

#include <QDialog>

namespace Ui {
    class ArcDialog;
}

class ArcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArcDialog(QWidget *parent = 0);
    ~ArcDialog();

private:
    Ui::ArcDialog *ui;
};

#endif // ARCPROPERTIESDIALOG_H
