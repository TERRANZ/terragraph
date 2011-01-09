#ifndef NODEPROPERTIESDIALOG_H
#define NODEPROPERTIESDIALOG_H

#include <QDialog>

namespace Ui {
    class NodePropertiesDialog;
}

class NodePropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NodePropertiesDialog(QWidget *parent = 0);
    ~NodePropertiesDialog();

private:
    Ui::NodePropertiesDialog *ui;
};

#endif // NODEPROPERTIESDIALOG_H
