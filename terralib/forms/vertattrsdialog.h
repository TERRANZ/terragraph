#ifndef VERTATTRSDIALOG_H
#define VERTATTRSDIALOG_H

#include <QDialog>
#include "../glyph.h"

namespace Ui {
    class vertattrsdialog;
}

class VertAttrsDialog : public QDialog {
    Q_OBJECT
public:
    VertAttrsDialog(QWidget *parent = 0);
    ~VertAttrsDialog();
    void load(Glyph *g);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::vertattrsdialog *ui;

signals:
    void signalOk(int ntype,QString id, QString comment, int type,QString chan, QString method, int count);

private slots:
    void on_save_2_clicked();
};

#endif // VERTATTRSDIALOG_H
