#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    procdiagram = new ProcessDiagram();
    processdiagwnd = new WindowQt(ui->mdiArea);
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
    Character *c = new Character();
    std::wstring text(L"S");
    c->SetText(text);
    newvert->InsertGlyph(c);
    procdiagram->InsertGlyph(c);
    processdiagwnd->AddCompl(procdiagram);
    processdiagwnd->ReDraw();
}
