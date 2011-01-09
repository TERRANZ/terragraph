#include "mainwindow.h"
#include "ui_mainwindow.h"

const qreal MainWindow::ZoomFactorStep = 0.1;

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_Data = new XmlData();
    m_Data->create();

    createActions();
    createToolBars();
    createMenu();
    createWidgets();

    m_Generator = new Generator(this);
    m_Generator->setPath("gpt.exe");
    m_Generator->setParams("-m $f");
    m_Generator->setWorkingDirectory("$d");

    m_CurrentTool = ToolSelectMove;

    setCurrentFileName(QString());

    connect(m_Generator, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(generatorFinished(int,QProcess::ExitStatus)));
    connect(m_Generator, SIGNAL(writeResult(QString)), this, SLOT(generatorConsole(QString)));
    m_mode = GMText;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_Data;
}

void MainWindow::createActions()
{
    m_CreateAction = new QAction(this);
    m_OpenAction = new QAction(this);
    m_SaveAction = new QAction(this);
    m_SaveAsAction = new QAction(this);
    m_GenerateStartAction = new QAction(this);
    m_GenerateStopAction = new QAction(this);
    m_ExitAction = new QAction(this);

    m_UndoAction = new QAction(this);
    m_RedoAction = new QAction(this);

    m_ZoomInAction = new QAction(this);
    m_ZoomOriginalAction = new QAction(this);
    m_ZoomOutAction = new QAction(this);
    m_ShowGraphic = new QAction(this);

    m_AttributesModuleAction = new QAction(this);
    m_NewChannelAction = new QAction(this);
    m_NewProcessAction = new QAction(this);
    m_NewAssembleAction = new QAction(this);
    m_ListChannelsAction = new QAction(this);
    m_ListProcessAction = new QAction(this);
    m_ListAssemblesAction = new QAction(this);

    m_ToolsActionGroup = new QActionGroup(this);
    m_ToolCreateNodeAction = new QAction(this);
    m_ToolCreateArcAction = new QAction(this);
    m_ToolDeleteObjectAction = new QAction(this);
    m_ToolSelectMoveAction = new QAction(this);
    m_PropertiesAction = new QAction(this);

    m_GenerateOptionsAction = new QAction(this);
    m_OpenTemplateAction = new QAction(this);

    m_HelpAction = new QAction(this);
    m_AboutAction = new QAction(this);
    m_AboutQtAction = new QAction(this);

    m_CreateAction->setText(tr("Создать"));
    m_CreateAction->setIcon(QIcon(":/images/new"));
    m_OpenAction->setText(tr("Открыть"));
    m_OpenAction->setIcon(QIcon(":/images/open"));
    m_SaveAction->setText(tr("Сохранить"));
    m_SaveAction->setIcon(QIcon(":/images/save"));
    m_SaveAsAction->setText(tr("Сохранить как..."));
    m_GenerateStartAction->setText(tr("Сгенерировать код модуля"));
    m_GenerateStartAction->setIcon(QIcon(":/images/generate-start"));
    m_GenerateStopAction->setText(tr("Остановить генерацию"));
    m_GenerateStopAction->setIcon(QIcon(":/images/generate-stop"));
    m_GenerateStopAction->setEnabled(false);
    m_ExitAction->setText(tr("Выход"));
    m_ExitAction->setIcon(QIcon(":/images/exit"));

    m_UndoAction->setText(tr("Отменить"));
    m_UndoAction->setShortcut(QKeySequence("Ctrl+Z"));
    m_RedoAction->setText(tr("Повторить"));
    m_RedoAction->setShortcut(QKeySequence("Ctrl+Y"));

    m_ZoomInAction->setText(tr("Приблизить"));
    m_ZoomInAction->setIcon(QIcon(":/images/zoom-in"));
    m_ZoomOriginalAction->setText(tr("Оригинал"));
    m_ZoomOriginalAction->setIcon(QIcon(":/images/zoom-original"));
    m_ZoomOutAction->setText(tr("Отдалить"));
    m_ZoomOutAction->setIcon(QIcon(":/images/zoom-out"));
    m_ShowGraphic->setText(tr("Графический режим"));

    m_AttributesModuleAction->setText(tr("Атрибуты модуля..."));
    m_NewChannelAction->setText(tr("Новый Канал..."));
    m_NewProcessAction->setText(tr("Новый Процесс..."));
    m_NewAssembleAction->setText(tr("Новая Сборка..."));
    m_ListChannelsAction->setText(tr("Список Каналов..."));
    m_ListProcessAction->setText(tr("Список Процессов..."));
    m_ListAssemblesAction->setText(tr("Список Сборок..."));

    m_ToolsActionGroup->addAction(m_ToolCreateNodeAction);
    m_ToolsActionGroup->addAction(m_ToolCreateArcAction);
    m_ToolsActionGroup->addAction(m_ToolDeleteObjectAction);
    m_ToolsActionGroup->addAction(m_ToolSelectMoveAction);
//---------
    m_ToolCreateNodeAction->setText(tr("Инструмент создания Вершин"));
    m_ToolCreateNodeAction->setIcon(QIcon(":/images/addnode"));
    m_ToolCreateNodeAction->setIconVisibleInMenu(false);
    m_ToolCreateNodeAction->setCheckable(true);

    m_ToolCreateArcAction->setText(tr("Инструмент создания Дуги"));
    m_ToolCreateArcAction->setIcon(QIcon(":/images/addarc"));
    m_ToolCreateArcAction->setIconVisibleInMenu(false);
    m_ToolCreateArcAction->setCheckable(true);

    m_ToolDeleteObjectAction->setText(tr("Инструмент удаления Объекта"));
    m_ToolDeleteObjectAction->setIcon(QIcon(":/images/delete"));
    m_ToolDeleteObjectAction->setIconVisibleInMenu(false);
    m_ToolDeleteObjectAction->setCheckable(true);
    m_ToolSelectMoveAction->setText(tr("Инструмент выбора/перетаскивания"));

    m_ToolSelectMoveAction->setIcon(QIcon(":/images/select"));
    m_ToolSelectMoveAction->setIconVisibleInMenu(false);
    m_ToolSelectMoveAction->setCheckable(true);
    m_ToolSelectMoveAction->setChecked(true);

    m_PropertiesAction->setText(tr("Свойства..."));
    m_PropertiesAction->setIcon(QIcon(":/images/edit"));
    m_PropertiesAction->setIconVisibleInMenu(false);
    m_PropertiesAction->setEnabled(false);
//---------
    m_GenerateOptionsAction->setText(tr("Настройки генератора..."));
    m_GenerateOptionsAction->setIcon(QIcon(":/images/generate-options"));
    m_OpenTemplateAction->setText(tr("Выбрать шаблон отображения..."));

    m_HelpAction->setText(tr("Справка"));
    m_AboutAction->setText(tr("О программе"));
    m_AboutQtAction->setText(tr("About Qt"));

    connect(m_CreateAction, SIGNAL(triggered()), this, SLOT(create()));
    connect(m_OpenAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(m_SaveAction, SIGNAL(triggered()), this, SLOT(save()));
    connect(m_SaveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
    connect(m_GenerateStartAction, SIGNAL(triggered()), this, SLOT(generateStart()));
    connect(m_GenerateStopAction, SIGNAL(triggered()), this, SLOT(generateStop()));
    connect(m_ExitAction, SIGNAL(triggered()), this, SLOT(exit()));

    connect(m_UndoAction, SIGNAL(triggered()), this, SLOT(undo()));
    connect(m_RedoAction, SIGNAL(triggered()), this, SLOT(redo()));

    connect(m_ZoomInAction, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(m_ZoomOriginalAction, SIGNAL(triggered()), this, SLOT(zoomOriginal()));
    connect(m_ZoomOutAction, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(m_ShowGraphic, SIGNAL(triggered()), this, SLOT(showGraphic()));

    connect(m_AttributesModuleAction, SIGNAL(triggered()), this, SLOT(showAttributesModules()));
    connect(m_NewChannelAction, SIGNAL(triggered()), this, SLOT(newChannel()));
    connect(m_NewProcessAction, SIGNAL(triggered()), this, SLOT(newProcess()));
    connect(m_NewAssembleAction, SIGNAL(triggered()), this, SLOT(newAssemble()));
    connect(m_ListChannelsAction, SIGNAL(triggered()), this, SLOT(showListChannels()));
    connect(m_ListProcessAction, SIGNAL(triggered()), this, SLOT(showListProcess()));
    connect(m_ListAssemblesAction, SIGNAL(triggered()), this, SLOT(showListAssembles()));
    connect(m_PropertiesAction, SIGNAL(triggered()), this, SLOT(showProperties()));

    connect(m_ToolCreateNodeAction, SIGNAL(triggered()), this, SLOT(selectToolCreateNode()));
    connect(m_ToolCreateArcAction, SIGNAL(triggered()), this, SLOT(selectToolCreateArc()));
    connect(m_ToolDeleteObjectAction, SIGNAL(triggered()), this, SLOT(selectToolDeleteObject()));
    connect(m_ToolSelectMoveAction, SIGNAL(triggered()), this, SLOT(selectToolSelectMove()));

    connect(m_GenerateOptionsAction, SIGNAL(triggered()), this, SLOT(showSettings()));
    connect(m_OpenTemplateAction, SIGNAL(triggered()), this, SLOT(openTemplate()));

    connect(m_AboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createToolBars()
{
    m_FileToolBar = this->addToolBar("Главная");
    m_GenerateToolBar = this->addToolBar("Генератор");
    m_ZoomToolBar = this->addToolBar("Масштаб");
    m_ToolToolBar = this->addToolBar("Редактирование");

    m_FileToolBar->addAction(m_CreateAction);
    m_FileToolBar->addAction(m_OpenAction);
    m_FileToolBar->addAction(m_SaveAction);

    m_GenerateToolBar->addAction(m_GenerateStartAction);
    m_GenerateToolBar->addAction(m_GenerateStopAction);
    m_GenerateToolBar->addAction(m_GenerateOptionsAction);

    m_ZoomToolBar->addAction(m_ZoomInAction);
    m_ZoomToolBar->addAction(m_ZoomOriginalAction);
    m_ZoomToolBar->addAction(m_ZoomOutAction);

    m_ToolToolBar->addAction(m_ToolCreateNodeAction);
    m_ToolToolBar->addAction(m_ToolCreateArcAction);
    m_ToolToolBar->addAction(m_ToolDeleteObjectAction);
    m_ToolToolBar->addAction(m_ToolSelectMoveAction);
    m_ToolToolBar->addAction(m_PropertiesAction);
}

void MainWindow::createMenu()
{
    QMenu *menu;

    m_FileMenu = menuBar()->addMenu(tr("Файл"));
    m_FileMenu->addAction(m_CreateAction);
    m_FileMenu->addAction(m_OpenAction);
    m_FileMenu->addAction(m_SaveAction);
    m_FileMenu->addAction(m_SaveAsAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_GenerateStartAction);
    m_FileMenu->addAction(m_GenerateStopAction);
    m_FileMenu->addSeparator();
    m_FileMenu->addAction(m_ExitAction);

    menu = menuBar()->addMenu(tr("Правка"));
    menu->addAction(m_UndoAction);
    menu->addAction(m_RedoAction);

    m_ViewMenu = menuBar()->addMenu(tr("Вид"));
    m_ViewMenu->addAction(m_ShowGraphic);
    menu = m_ViewMenu->addMenu("Масштаб");
    menu->addAction(m_ZoomInAction);
    menu->addAction(m_ZoomOriginalAction);
    menu->addAction(m_ZoomOutAction);
    menu = m_ViewMenu->addMenu("Панели инструментов");
    menu->addAction(m_FileToolBar->toggleViewAction());
    menu->addAction(m_GenerateToolBar->toggleViewAction());
    menu->addAction(m_ZoomToolBar->toggleViewAction());
    menu->addAction(m_ToolToolBar->toggleViewAction());
    menu = m_ViewMenu->addMenu("Окна");
    menu->addAction(ui->dockWidget->toggleViewAction());
    menu->addAction(ui->dockWidget_2->toggleViewAction());

    m_ModuleMenu = menuBar()->addMenu(tr("Модуль"));
    m_ModuleMenu->addAction(m_AttributesModuleAction);
    m_ModuleMenu->addSeparator();
    m_ModuleMenu->addAction(m_NewChannelAction);
    m_ModuleMenu->addAction(m_NewProcessAction);
    m_ModuleMenu->addAction(m_NewAssembleAction);
    m_ModuleMenu->addSeparator();
    m_ModuleMenu->addAction(m_ListChannelsAction);
    m_ModuleMenu->addAction(m_ListProcessAction);
    m_ModuleMenu->addAction(m_ListAssemblesAction);

    m_EditMenu = menuBar()->addMenu(tr("Редактирование"));
    m_EditMenu->addAction(m_ToolCreateNodeAction);
    m_EditMenu->addAction(m_ToolCreateArcAction);
    m_EditMenu->addAction(m_ToolDeleteObjectAction);
    m_EditMenu->addAction(m_ToolSelectMoveAction);
    m_EditMenu->addSeparator();
    m_EditMenu->addAction(m_PropertiesAction);

    m_OptionsMenu = menuBar()->addMenu(tr("Настройка"));
    m_OptionsMenu->addAction(m_GenerateOptionsAction);
    m_OptionsMenu->addAction(m_OpenTemplateAction);

    m_HelpMenu = menuBar()->addMenu(tr("Справка"));
    m_HelpMenu->addAction(m_HelpAction);
    m_HelpMenu->addSeparator();
    m_HelpMenu->addAction(m_AboutAction);
    m_HelpMenu->addAction(m_AboutQtAction);
}

void MainWindow::createWidgets()
{
    m_OpenDialog = new QFileDialog(this);
    m_SaveDialog = new QFileDialog(this);
    m_TemplateOpenDialog = new QFileDialog(this);
    m_XmlView = new XmlView();
    m_GraphicView = new FacadeWidget(ui->stackedWidget);
    m_GraphicView->createProcDiag();

    m_OpenDialog->setAcceptMode(QFileDialog::AcceptOpen);
    m_OpenDialog->setWindowTitle(tr("Открыть"));
    m_SaveDialog->setAcceptMode(QFileDialog::AcceptSave);
    m_SaveDialog->setWindowTitle(tr("Сохранить как..."));
    m_TemplateOpenDialog->setAcceptMode(QFileDialog::AcceptOpen);

    QDir dir(qApp->applicationDirPath());
    dir.cdUp();
    dir.cdUp();

    m_XmlView->loadTemplates(dir.currentPath() + "/" + "templates/default/default.cfg");
    m_XmlView->setData(m_Data);

    ui->stackedWidget->addWidget(m_XmlView);
    ui->dockWidget->hide();

    m_CommandListModel = new StdStringListModel(this);
    ui->log->setModel(m_CommandListModel);

    updateData();
}

void MainWindow::updateTools()
{
}

void MainWindow::create()
{
    m_Data->create();
    updateData();
    setCurrentFileName(QString());

}

void MainWindow::open()
{
    if(m_OpenDialog->exec() == QDialog::Accepted)
    {
        QString fn = m_OpenDialog->selectedFiles().at(0);
        XmlData::LoadError error = m_Data->load(fn.toStdString());
        if(!error.isError())
        {
            setCurrentFileName(fn);
            updateData();
        }
        else
        {
            QString message = QString("%1\nстрока: %2\n позиция: %3").arg(QString::fromStdString(error.message())).arg(error.row()).arg(error.column());
            QMessageBox::critical(this, "Ошибка", message);
        }
    }
}

bool MainWindow::save()
{
    if(m_CurrentFileName.isEmpty())
    {
        return saveAs();
    }
    if(!m_Data->save(m_CurrentFileName.toStdString()))
    {
        QMessageBox::critical(this, "Ошибка", "Ошибка при сохранении файла");
    }
    return true;
}

bool MainWindow::saveAs()
{
    if(m_SaveDialog->exec() == QDialog::Accepted)
    {
        QString fn = m_SaveDialog->selectedFiles().at(0);
        if(m_Data->save(fn.toStdString()))
        {
            setCurrentFileName(fn);
        }
        else
        {
            QMessageBox::critical(this, "Ошибка", "Ошибка при открытии файла");
        }
        return true;
    }
    return false;
}

void MainWindow::generateStart()
{
    ui->console->clear();
    if(save())
    {
        ui->dockWidget->show();
        if(!m_Generator->isRunning())
        {
            if(m_Generator->start(m_CurrentFileName))
            {
                m_GenerateStartAction->setEnabled(false);
                m_GenerateStopAction->setEnabled(true);
            }
        }
    }
}

void MainWindow::generateStop()
{
    if(m_Generator->isRunning())
    {
        m_Generator->stop();
    }
}

void MainWindow::exit()
{
    close();
}

void MainWindow::undo()
{
    m_Data->commandList()->undo();
    updateData();
}

void MainWindow::redo()
{
    m_Data->commandList()->redo();
    updateData();
}

void MainWindow::zoomIn()
{
    m_XmlView->setZoomFactor(m_XmlView->zoomFactor() + ZoomFactorStep);
}

void MainWindow::zoomOriginal()
{
    m_XmlView->setZoomFactor(1.0);
}

void MainWindow::zoomOut()
{
    m_XmlView->setZoomFactor(m_XmlView->zoomFactor() - ZoomFactorStep);
}

void MainWindow::showGraphic()
{
    if (m_mode == GMText)
    {
        m_mode = GMGraph;
        ui->stackedWidget->removeWidget(m_XmlView);
        ui->stackedWidget->addWidget(m_GraphicView);
    }else
    {
        m_mode = GMText;
        ui->stackedWidget->removeWidget(m_GraphicView);
        ui->stackedWidget->addWidget(m_XmlView);
    }
}

void MainWindow::showAttributesModules()
{
    if(ModuleDialog::editModule(m_Data->module(), this))
    {
        updateData();
    }
}

void MainWindow::newChannel()
{
    if(ChannelDialog::addChannel(m_Data->module(), this))
    {
        updateData();
    }
}

void MainWindow::newProcess()
{
    if(ProcessDialog::addProcess(m_Data->module(), this))
    {
        updateData();
    }
}

void MainWindow::newAssemble()
{
    if(AssembleDialog::addAssemble(m_Data->module(), this))
    {
        updateData();
    }
}

void MainWindow::showListChannels()
{
    ChannelListDialog dialog(this);
    dialog.setData(m_Data->module());
    dialog.exec();
    updateData();
}

void MainWindow::showListProcess()
{
    ProcessListDialog dialog(this);
    dialog.setData(m_Data->module());
    dialog.exec();
    updateData();
}

void MainWindow::showListAssembles()
{
    AssembleListDialog dialog(this);
    dialog.setData(m_Data->module());
    dialog.exec();
    updateData();
}

void MainWindow::selectToolCreateNode()
{
    m_CurrentTool = ToolCreateNode;
    m_XmlView->setTool(XmlView::ToolAddNode);
    m_GraphicView->addNewV();
}

void MainWindow::selectToolCreateArc()
{
    m_CurrentTool = ToolCreateArc;
    m_XmlView->setTool(XmlView::ToolAddArc);
    m_GraphicView->addArrow();
}

void MainWindow::selectToolDeleteObject()
{
    m_CurrentTool = ToolDeleteObject;
    m_XmlView->setTool(XmlView::ToolRemove);
}

void MainWindow::selectToolSelectMove()
{
    m_CurrentTool = ToolSelectMove;
    m_XmlView->setTool(XmlView::ToolProperties);
}

void MainWindow::showProperties()
{
//    ArcPropertiesDialog dialog(this);
//    dialog.exec();
//    NodePropertiesDialog dialog2(this);
//    dialog2.exec();
}

void MainWindow::showSettings()
{
    GeneratorDialog dialog(this);
    dialog.setGenerator(m_Generator);
    dialog.exec();
}

void MainWindow::openTemplate()
{
    if(m_TemplateOpenDialog->exec() == QFileDialog::Accepted)
    {
        m_XmlView->loadTemplates(m_TemplateOpenDialog->selectedFiles().at(0));
    }
}

void MainWindow::showHelp()
{
}

void MainWindow::showAbout()
{
}

void MainWindow::generatorFinished(int code, QProcess::ExitStatus exitStatus)
{
    m_GenerateStartAction->setEnabled(true);
    m_GenerateStopAction->setEnabled(false);

    QString status;
    switch(exitStatus)
    {
    case QProcess::NormalExit:
        status = "normal";
        break;
    case QProcess::CrashExit:
        status = "crash";
        break;
    }
    QString mes = QString("status: %1\nreturn code: %2").arg(status).arg(code);
    ui->console->append(mes);
}

void MainWindow::generatorConsole(QString text)
{
    ui->console->append(text);
}

void MainWindow::setCurrentFileName(QString value)
{
    m_CurrentFileName = value;
    if(m_CurrentFileName.isEmpty())
    {
        setWindowTitle(tr("[Новый]"));
    }
    else
    {
        setWindowTitle(tr("[%1]").arg(m_CurrentFileName));
    }
}

void MainWindow::updateData()
{
    m_XmlView->updateData();

    m_CommandListModel->setList(m_Data->commandList()->commandStringList());
    ui->log->scrollToBottom();
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    emit m_GraphicView->onResize();
}
