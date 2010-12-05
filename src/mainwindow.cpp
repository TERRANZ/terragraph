#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
//    processdiagwnd = new WindowQt(ui->mdiArea);
//    gm = new GraphicManager(processdiagwnd);
//    procdiag  = gm->createProcDiagram();
//    processdiagwnd->AddCompl(procdiag);
    logger = new Logger();
}

MainWindow::~MainWindow()
{
//    delete processdiagwnd;
    delete logger;
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
//    gm->addVertToProcDiag(1);
//    processdiagwnd->reDraw();
    logger->addToLog("MainWindow::AddNewV()");
}
