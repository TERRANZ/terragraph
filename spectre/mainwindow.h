#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QActionGroup>
#include "xmlview/xmlview.h"
#include "generator.h"
#include "xmlview/stdstringlistmodel.h"
#include "editforms/moduledialog.h"
#include "editforms/channeldialog.h"
#include "editforms/processdialog.h"
#include "editforms/assembledialog.h"
#include "editforms/channellistdialog.h"
#include "editforms/processlistdialog.h"
#include "editforms/assemblelistdialog.h"
#include "generatordialog.h"
#include "../terralib/facadewidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Tool
    {
        ToolCreateNode,
        ToolCreateArc,
        ToolDeleteObject,
        ToolSelectMove,
        Properties
    };

    enum GraphicMode
    {
        GMText,
        GMGraph
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createActions();
    void createToolBars();
    void createMenu();
    void createWidgets();
    void updateTools();

private slots:
    void create();
    void open();
    bool save();
    bool saveAs();
    void generateStart();
    void generateStop();
    void exit();

    void undo();
    void redo();

    void zoomIn();
    void zoomOriginal();
    void zoomOut();
    void showGraphic();

    void showAttributesModules();
    void newChannel();
    void newProcess();
    void newAssemble();
    void showListChannels();
    void showListProcess();
    void showListAssembles();

    void selectToolCreateNode();
    void selectToolCreateArc();
    void selectToolDeleteObject();
    void selectToolSelectMove();
    void showProperties();

    void showSettings();
    void openTemplate();

    void showHelp();
    void showAbout();

    void generatorFinished(int code, QProcess::ExitStatus exitStatus);
    void generatorConsole(QString text);
    void setCurrentFileName(QString value);

    void updateData();

private:
    void removeTool(Base element);

private:
    Ui::MainWindow *ui;

    QAction *m_CreateAction;
    QAction *m_OpenAction;
    QAction *m_SaveAction;
    QAction *m_SaveAsAction;
    QAction *m_GenerateStartAction;
    QAction *m_GenerateStopAction;
    QAction *m_ExitAction;

    QAction *m_UndoAction;
    QAction *m_RedoAction;

    QAction *m_ZoomInAction;
    QAction *m_ZoomOriginalAction;
    QAction *m_ZoomOutAction;
    QAction *m_ShowGraphic;

    QAction *m_AttributesModuleAction;
    QAction *m_NewChannelAction;
    QAction *m_NewProcessAction;
    QAction *m_NewAssembleAction;
    QAction *m_ListChannelsAction;
    QAction *m_ListProcessAction;
    QAction *m_ListAssemblesAction;

    QActionGroup *m_ToolsActionGroup;
    QAction *m_ToolCreateNodeAction;
    QAction *m_ToolCreateArcAction;
    QAction *m_ToolDeleteObjectAction;
    QAction *m_ToolSelectMoveAction;
    QAction *m_PropertiesAction;

    QAction *m_GenerateOptionsAction;
    QAction *m_OpenTemplateAction;

    QAction *m_HelpAction;
    QAction *m_AboutAction;
    QAction *m_AboutQtAction;

    QMenu *m_FileMenu;
    QMenu *m_ViewMenu;
    QMenu *m_ModuleMenu;
    QMenu *m_EditMenu;
    QMenu *m_OptionsMenu;
    QMenu *m_HelpMenu;

    QToolBar *m_FileToolBar;
    QToolBar *m_GenerateToolBar;
    QToolBar *m_ZoomToolBar;
    QToolBar *m_ToolToolBar;

    QFileDialog *m_OpenDialog;
    QFileDialog *m_SaveDialog;
    QFileDialog *m_TemplateOpenDialog;

    QString m_CurrentFileName;
    XmlView *m_XmlView;
    XmlData *m_Data;
    FacadeWidget *m_GraphicView;

    Generator *m_Generator;
    Tool m_CurrentTool;

    StdStringListModel *m_CommandListModel;

    static const qreal ZoomFactorStep;
    GraphicMode m_mode;
};

#endif // MAINWINDOW_H
