#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    logger = new Logger();
    facade = new FacadeWidget(ui->mdiArea);
    facade->createProcDiag();
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
    facade->addNewV();
    logger->addToLog("MainWindow::AddNewV()");
}
void MainWindow::AddNewArrow()
{
    facade->addArrow();
}
