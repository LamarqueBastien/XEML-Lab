
QT += core gui xml xmlpatterns network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += printsupport
TARGET = XemlDesigner
TEMPLATE = app
QTPLUGIN     += qsqlodbc qmysql


SOURCES += \
    AboutWindows/aboutstory.cpp \
    AboutWindows/aboutparameter.cpp \
    AboutWindows/aboutexperiment.cpp \
	mainwindow.cpp \
	main.cpp \
    filemanager.cpp \
    DialogWindows/timedialog.cpp \
    DialogWindows/storysplitdialog.cpp \
    DialogWindows/storydialog.cpp \
    DialogWindows/responserangeparameter.cpp \
    DialogWindows/quantitativeparameter.cpp \
    DialogWindows/qualitativeparameter.cpp \
    DialogWindows/observationpointdialog.cpp \
    DialogWindows/genotypedialog.cpp \
    DialogWindows/freetextparameter.cpp \
    DialogWindows/experimenterdialog.cpp \
    DialogWindows/experimentdialog.cpp \
    DialogWindows/eventdialog.cpp \
    Div/windowtitlebar.cpp \
    Div/dragtimelabel.cpp \
    PanelWindows/storypanel.cpp \
    PanelWindows/poolpanel.cpp \
    PanelWindows/parameterpanel.cpp \
    PanelWindows/ontologypanel.cpp \
    PanelWindows/observationpanel.cpp \
    PanelWindows/germplasmpanel.cpp \
    PanelWindows/eventpanel.cpp \
    SampleLoader/observationwizard.cpp \
    SampleLoader/observationpointpanel.cpp \
    SampleLoader/observationmaterialpage.cpp \
    SampleLoader/observationintropage.cpp \
    SampleLoader/observationgenotypepage.cpp \
    SampleLoader/observationdetailspage.cpp \
    Views/GraphicStoryView/Items/graphicstoryitem.cpp \
    Views/GraphicStoryView/Items/graphicobservationpointitem.cpp \
    Views/GraphicStoryView/Items/graphiceventitem.cpp \
    Views/GraphicStoryView/graphicstoryview.cpp \
    Views/GraphicStoryView/graphicstoryscene.cpp \
    Views/Items/storyitem.cpp \
    Views/Items/parameteritem.cpp \
    Views/Items/genotypeitem.cpp \
    Views/Items/experimentitem.cpp \
    Views/Items/anchorstoryitem.cpp \
    Views/Items/abstractexperimentitem.cpp \
    Views/xemlcodeeditor.cpp \
    Views/storyview.cpp \
    Views/parameterview.cpp \
    Views/parametertreeview.cpp \
    Views/genotypeview.cpp \
    XemlCSVLoader/loaderwizard.cpp \
    XemlCSVLoader/loadervalidationpage.cpp \
    XemlCSVLoader/loadertermpage.cpp \
    XemlCSVLoader/loaderstorypage.cpp \
    XemlCSVLoader/loaderparamsettingpage.cpp \
    XemlCSVLoader/loaderontologypage.cpp \
    XemlCSVLoader/loaderintropage.cpp \
    XemlCSVLoader/loaderdatetimepage.cpp \
    XemlCSVLoader/loaderdatafilepage.cpp \
    XemlCSVLoader/loaderconclusionpage.cpp \
    XMLValidation/xmlsyntaxhighlighter.cpp \
    XMLValidation/validationwindow.cpp \
    Views/plotparameterview.cpp \
    Views/GraphicStoryView/graphicplotscene.cpp \
    Div/qcustomplot.cpp \
    Views/HTMLReportView/htmlreportview.cpp \
    DialogWindows/annotationdialog.cpp \
    Views/xemlobjectinfoview.cpp \
    Views/Items/infoballoontip.cpp \
    DialogWindows/sqlconnectiondialog.cpp \
    DialogWindows/uuiddialog.cpp \
    Views/experimenttableview.cpp \
    Views/Items/abstracttableitem.cpp \
    Views/tableview.cpp \
    PopulationLoader/individualwizard.cpp \
    PopulationLoader/individualintropage.cpp \
    PopulationLoader/individualimportfilepage.cpp \
    PopulationLoader/individualconclusionpage.cpp \
    PopulationLoader/individualcreationpage.cpp

HEADERS += \
    AboutWindows/aboutstory.h \
    AboutWindows/aboutparameter.h \
    AboutWindows/aboutexperiment.h \
    mainwindow.h \
    filemanager.h \
    DialogWindows/timedialog.h \
    DialogWindows/storysplitdialog.h \
    DialogWindows/storydialog.h \
    DialogWindows/responserangeparameter.h \
    DialogWindows/quantitativeparameter.h \
    DialogWindows/qualitativeparameter.h \
    DialogWindows/observationpointdialog.h \
    DialogWindows/genotypedialog.h \
    DialogWindows/freetextparameter.h \
    DialogWindows/experimenterdialog.h \
    DialogWindows/experimentdialog.h \
    DialogWindows/eventdialog.h \
    Div/windowtitlebar.h \
    Div/dragtimelabel.h \
    PanelWindows/storypanel.h \
    PanelWindows/poolpanel.h \
    PanelWindows/parameterpanel.h \
    PanelWindows/ontologypanel.h \
    PanelWindows/observationpointpanel.h \
    PanelWindows/observationpanel.h \
    PanelWindows/germplasmpanel.h \
    PanelWindows/eventpanel.h \
    SampleLoader/observationwizard.h \
    SampleLoader/observationmaterialpage.h \
    SampleLoader/observationintropage.h \
    SampleLoader/observationgenotypepage.h \
    SampleLoader/observationdetailspage.h \
    Views/GraphicStoryView/Items/graphicstoryitem.h \
    Views/GraphicStoryView/Items/graphicobservationpointitem.h \
    Views/GraphicStoryView/Items/graphiceventitem.h \
    Views/GraphicStoryView/graphicstoryview.h \
    Views/GraphicStoryView/graphicstoryscene.h \
    Views/Items/storyitem.h \
    Views/Items/parameteritem.h \
    Views/Items/genotypeitem.h \
    Views/Items/experimentitem.h \
    Views/Items/anchorstoryitem.h \
    Views/Items/abstractexperimentitem.h \
    Views/xemlcodeeditor.h \
    Views/storyview.h \
    Views/parameterview.h \
    Views/parametertreeview.h \
    Views/genotypeview.h \
    XemlCSVLoader/loaderwizard.h \
    XemlCSVLoader/loadervalidationpage.h \
    XemlCSVLoader/loadertermpage.h \
    XemlCSVLoader/loaderstorypage.h \
    XemlCSVLoader/loaderparamsettingpage.h \
    XemlCSVLoader/loaderontologypage.h \
    XemlCSVLoader/loaderintropage.h \
    XemlCSVLoader/loaderdatetimepage.h \
    XemlCSVLoader/loaderdatafilepage.h \
    XemlCSVLoader/loaderconclusionpage.h \
    XMLValidation/xmlsyntaxhighlighter.h \
    XMLValidation/validationwindow.h \
    Views/plotparameterview.h \
    Views/GraphicStoryView/graphicplotscene.h \
    Div/qcustomplot.h \
    Views/HTMLReportView/htmlreportview.h \
    DialogWindows/annotationdialog.h \
    Views/xemlobjectinfoview.h \
    Views/Items/infotipbutton.h \
    Views/Items/infoballoontip.h \
    DialogWindows/sqlconnectiondialog.h \
    DialogWindows/uuiddialog.h \
    Views/experimenttableview.h \
    Views/Items/abstracttableitem.h \
    Views/tableview.h \
    PopulationLoader/individualwizard.h \
    PopulationLoader/individualintropage.h \
    PopulationLoader/individualimportfilepage.h \
    PopulationLoader/individualconclusionpage.h \
    PopulationLoader/individualcreationpage.h

RESOURCES += \
    Divers.qrc

FORMS +=\
    schema.ui \
	schema_mobiles.ui \
    mainwindow.ui

OTHER_FILES += \
    XEMLSchema_V1.1.xsd \
    test11.xeml \
    Template_Xeml.xml \
    default.xeml \
    Images/zoomout.png \
    Images/zoomin.png \
    Images/XemlLogo.png \
    Images/SilverMetal.png \
    Images/save.png \
    Images/paste.png \
    Images/open.png \
    Images/new.png \
    Images/GreenMetal.png \
    Images/exit2.jpg \
    Images/exit.jpg \
    Images/cut.png \
    Images/csv_text.png \
    Images/copy.png \
    Images/close.png \
    Images/BlueMetal.png \
    XEMLStore/Templates/Standard.xeml


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../XemlCore/release/ -lXemlCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../XemlCore/debug/ -lXemlCore
else:unix: LIBS += -L$$OUT_PWD/../XemlCore/ -lXemlCore

INCLUDEPATH += $$PWD/../XemlCore
DEPENDPATH += $$PWD/../XemlCore

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../XemlCore/release/libXemlCore.a
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../XemlCore/debug/libXemlCore.a
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../XemlCore/libXemlCore.a
