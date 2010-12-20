#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "../terralib/facadewidget.h"
#include "logger.h"

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
    Logger *logger;
    FacadeWidget *facade;

private slots:
    void AddNewV();
    void AddNewArrow();
};

#endif // MAINWINDOW_H
