#-------------------------------------------------
#
# Project created by QtCreator 2013-04-18T10:54:18
#
#-------------------------------------------------



QT += core gui xmlpatterns
QT += network widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += xml
TARGET = XemlDesigner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    storyview.cpp \
    filemanager.cpp \
    storysplitdialog.cpp \
    storydialog.cpp \
    observationpointdialog.cpp \
    parameteritem.cpp \
    aboutparameter.cpp \
    aboutstory.cpp \
    storyitem.cpp \
    parametertreeview.cpp \
    experimentdialog.cpp \
    aboutexperiment.cpp \
    experimenterdialog.cpp \
    experimentitem.cpp \
    abstractexperimentitem.cpp \
    parameterview.cpp \
    storypanel.cpp \
    poolpanel.cpp \
    parameterpanel.cpp \
    eventpanel.cpp \
    observationpointpanel.cpp \
    qualitativeparameter.cpp \
    responserangeparameter.cpp \
    freetextparameter.cpp \
    quantitativeparameter.cpp \
    genotypeview.cpp \
    germplasmpanel.cpp \
    genotypedialog.cpp \
    observationwizard.cpp \
    loaderwizard.cpp \
    loaderconclusionpage.cpp \
    loaderdatafilepage.cpp \
    loaderparamsettingpage.cpp \
    loadervalidationpage.cpp \
    loaderintropage.cpp \
    observationpanel.cpp \
    observationintropage.cpp \
    observationgenotypepage.cpp \
    observationdetailspage.cpp \
    observationmaterialpage.cpp \
    validationwindow.cpp \
    xmlsyntaxhighlighter.cpp \
    loaderontologypage.cpp \
    loadertermpage.cpp \
    loaderstorypage.cpp \
    loaderdatetimepage.cpp \
    dragtimelabel.cpp \
    timedialog.cpp \
    windowtitlebar.cpp \
    genotypeitem.cpp \
    xemlcodeeditor.cpp \
    ontologypanel.cpp \
    eventdialog.cpp \
    graphicstoryview.cpp \
    graphicstoryitem.cpp \
    graphicstoryscene.cpp \
    graphiceventitem.cpp \
    graphicobservationpointitem.cpp

HEADERS  += mainwindow.h \
    storyview.h \
    filemanager.h \
    storysplitdialog.h \
    storydialog.h \
    observationpointdialog.h \
    parameteritem.h \
    aboutparameter.h \
    aboutstory.h \
    storyitem.h \
    parametertreeview.h \
    experimentdialog.h \
    aboutexperiment.h \
    experimenterdialog.h \
    experimentitem.h \
    abstractexperimentitem.h \
    parameterview.h \
    storypanel.h \
    poolpanel.h \
    parameterpanel.h \
    eventpanel.h \
    observationpointpanel.h \
    qualitativeparameter.h \
    responserangeparameter.h \
    freetextparameter.h \
    quantitativeparameter.h \
    genotypeview.h \
    germplasmpanel.h \
    genotypedialog.h \
    observationwizard.h \
    loaderwizard.h \
    loaderintropage.h \
    loaderdatafilepage.h \
    loaderparamsettingpage.h \
    loadervalidationpage.h \
    loaderconclusionpage.h \
    loaderintropage.h \
    observationpanel.h \
    observationintropage.h \
    observationgenotypepage.h \
    observationdetailspage.h \
    observationmaterialpage.h \
    validationwindow.h \
    xmlsyntaxhighlighter.h \
    loaderontologypage.h \
    loadertermpage.h \
    loaderstorypage.h \
    loaderdatetimepage.h \
    dragtimelabel.h \
    timedialog.h \
    windowtitlebar.h \
    genotypeitem.h \
    xemlcodeeditor.h \
    ontologypanel.h \
    eventdialog.h \
    graphicstoryview.h \
    graphicstoryitem.h \
    graphicstoryscene.h \
    graphiceventitem.h \
    graphicobservationpointitem.h

FORMS    += mainwindow.ui \
    schema.ui \
    schema_mobiles.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Ontologies/release/ -lOntologies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Ontologies/debug/ -lOntologies
else:unix: LIBS += -L$$OUT_PWD/../Ontologies/ -lOntologies

INCLUDEPATH += $$PWD/../Ontologies
DEPENDPATH += $$PWD/../Ontologies

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Ontologies/release/libOntologies.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Ontologies/debug/libOntologies.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Ontologies/libOntologies.a

RESOURCES += \
    Divers.qrc
