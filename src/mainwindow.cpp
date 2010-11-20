#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
    processdiagwnd = new WindowQt(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete processdiagwnd;
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::AddNewV()
{
//    Vertex *newvert = new Vertex(processdiagwnd,L"S",L"1");
//    procdiagram->insert(newvert);
//
//    processdiagwnd->reDraw();
}
