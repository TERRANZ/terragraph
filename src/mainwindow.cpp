#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);;
    gm = new GraphicManager(ui->mdiArea);
    gm->createProcDiagram();
    logger = new Logger();
}

MainWindow::~MainWindow()
{
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
    gm->addVertToProcDiag(1);
    logger->addToLog("MainWindow::AddNewV()");
}
void MainWindow::AddNewArrow()
{
    gm->addArrow();
}
