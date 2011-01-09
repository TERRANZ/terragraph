#-------------------------------------------------
#
# Project created by QtCreator 2010-11-08T06:09:32
#
#-------------------------------------------------

QT       += core gui xml webkit

TARGET = diplom
TEMPLATE = app

SOURCES += \
    dom/domnode.cpp \
    dom/domelement.cpp \
    dom/domdocument.cpp \
    data/base.cpp \
    data/basemove.cpp \
    data/param.cpp \
    data/basewithparamlist.cpp \
    data/include.cpp \
    data/message.cpp \
    data/receive.cpp \
    data/condition.cpp \
    data/send.cpp \
    data/activate.cpp \
    data/methoditem.cpp \
    data/assembleprocess.cpp \
    data/assemblechannel.cpp \
    data/state.cpp \
    data/port.cpp \
    data/method.cpp \
    data/channel.cpp \
    data/process.cpp \
    data/assemble.cpp \
    data/module.cpp \
    data/xmldata.cpp \
    commandlist/abstractcommand.cpp \
    commandlist/commandlist.cpp \
    xmlview/htmltemplates.cpp \
    xmlview/xmlview.cpp \
    xmlview/htmltagsinfo.cpp \
    xmlview/stdstringlistmodel.cpp \
    xmlview/htmlgenerator.cpp \
    editforms/moduledialog.cpp \
    editforms/processdialog.cpp \
    editforms/channeldialog.cpp \
    editforms/assembledialog.cpp \
    editforms/channellistmodel.cpp \
    editforms/channellistdialog.cpp \
    editforms/processlistmodel.cpp \
    editforms/processlistdialog.cpp \
    editforms/assemblelistmodel.cpp \
    editforms/assemblelistdialog.cpp \
    editforms/paramlistdialog.cpp \
    editforms/paramlistmodel.cpp \
    editforms/includelistmodel.cpp \
    editforms/includelistdialog.cpp \
    main.cpp\
    mainwindow.cpp \
    arcdialog.cpp \
    nodepropertiesdialog.cpp \
    generatordialog.cpp \
    generator.cpp \
    qtableviewex.cpp \
    qtextcodecmodel.cpp \
    qfiledialogex.cpp \
    data/commands/editattributecommand.cpp \
    data/commands/addelementcommand.cpp \

HEADERS  += \
    dom/domnode.h \
    dom/domdocument.h \
    dom/domelement.h \
    data/base.h \
    data/basemove.h \
    data/param.h \
    data/basewithparamlist.h \
    data/include.h \
    data/message.h \
    data/receive.h \
    data/condition.h \
    data/send.h \
    data/activate.h \
    data/methoditem.h \
    data/assembleprocess.h \
    data/assemblechannel.h \
    data/state.h \
    data/port.h \
    data/method.h \
    data/channel.h \
    data/process.h \
    data/assemble.h \
    data/module.h \
    data/xmldata.h \
    commandlist/abstractcommand.h \
    commandlist/commandlist.h \
    xmlview/htmltemplates.h \
    xmlview/xmlview.h \
    xmlview/htmltagsinfo.h \
    xmlview/stdstringlistmodel.h \
    xmlview/htmlgenerator.h \
    editforms/moduledialog.h \
    editforms/processdialog.h \
    editforms/channeldialog.h \
    editforms/assembledialog.h \
    editforms/channellistmodel.h \
    editforms/channellistdialog.h \
    editforms/processlistmodel.h \
    editforms/processlistdialog.h \
    editforms/assemblelistmodel.h \
    editforms/assemblelistdialog.h \
    editforms/paramlistdialog.h \
    editforms/paramlistmodel.h \
    editforms/includelistmodel.h \
    editforms/includelistdialog.h \
    mainwindow.h \
    arcdialog.h \
    nodepropertiesdialog.h \
    generatordialog.h \
    generator.h \
    qtableviewex.h \
    qtextcodecmodel.h \
    qfiledialogex.h \
    data/commands/editattributecommand.h \
    data/commands/addelementcommand.h \

FORMS    += \
    editforms/moduledialog.ui \
    editforms/objectdialog.ui \
    editforms/objectlistdialog.ui \
    editforms/valuelistdialog.ui \
    mainwindow.ui \
    nodepropertiesdialog.ui \
    generatordialog.ui \
    arcdialog.ui

OTHER_FILES += \
    data/readme.txt

RESOURCES += \
    resources.qrc
