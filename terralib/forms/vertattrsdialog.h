#ifndef VERTATTRSDIALOG_H
#define VERTATTRSDIALOG_H

#include <QDialog>

namespace Ui {
    class vertattrsdialog;
}

class VertAttrsDialog : public QDialog {
    Q_OBJECT
public:
    VertAttrsDialog(QWidget *parent = 0);
    ~VertAttrsDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::vertattrsdialog *ui;
};

#endif // VERTATTRSDIALOG_H
