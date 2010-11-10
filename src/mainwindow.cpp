#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    procdiagram = new ProcessDiagram();
    processdiagwnd = new WindowQt(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete procdiagram;
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
    Vertex *newvert = new Vertex();
    procdiagram->Insert(newvert);
}
