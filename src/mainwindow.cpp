#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
    processdiagwnd = new WindowQt(ui->mdiArea);
    gm = new GraphicManager(processdiagwnd);
    gm->createProcDiagram();
    
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
    gm->addVertToProcDiag(1);
    processdiagwnd->reDraw();
}
