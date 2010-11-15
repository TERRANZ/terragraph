#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    procdiagram = new ProcessDiagram();
    processdiagwnd = new WindowQt(ui->mdiArea);
    processdiagwnd->AddCompl(procdiagram);
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
    Vertex *newvert = new Vertex(processdiagwnd,L"S");
    newvert->setGId(L"1");
    //newvert->InsertGlyph(c);
    //Character *c = new Character();
    //std::wstring text(L"S");
    //c->setText(text);
    procdiagram->insert(newvert);

    processdiagwnd->reDraw();
   // processdiagwnd->drawVertex(newvert);
}
