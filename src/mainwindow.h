#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "../terralib/windowqt.h"
#include "../terralib/processdiagram.h"
#include "../terralib/vertex.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    ProcessDiagram *procdiagram;
    WindowQt *processdiagwnd;

private slots:
    void AddNewV();
};

#endif // MAINWINDOW_H
