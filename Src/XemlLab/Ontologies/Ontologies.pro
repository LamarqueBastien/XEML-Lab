#-------------------------------------------------
#
# Project created by QtCreator 2013-04-18T11:01:55
#
#-------------------------------------------------

QT       += core widgets network xml xmlpatterns

TARGET = Ontologies
TEMPLATE = lib
CONFIG += staticlib


SOURCES += \
    itfdocument.cpp \
    individualspool.cpp \
    individual.cpp \
    experimentheader.cpp \
    experimenter.cpp \
    event.cpp \
    dynamicvaluebase.cpp \
    dynamicvalue.cpp \
    dynamicterm.cpp \
    downloadmanager.cpp \
    documentresources.cpp \
    developmentalontologyhandler.cpp \
    cycle.cpp \
    xemldocument.cpp \
    xemlcomponentloadfailedexception.cpp \
    xemlannotableobject.cpp \
    variableterm.cpp \
    valuebase.cpp \
    value.cpp \
    timespan.cpp \
    termattribute.cpp \
    term.cpp \
    taggedannotation.cpp \
    storyboard.cpp \
    storybase.cpp \
    story.cpp \
    simpleoboterm.cpp \
    ontologymanager.cpp \
    ontologyhandlerresources.cpp \
    observationpoint.cpp \
    observation.cpp \
    oboreader.cpp \
    keyword.cpp \
    itfxemlcomponent.cpp \
    itfvalidator.cpp \
    itfvalidationsource.cpp \
    itftimeobject.cpp \
    itfplainontologyhandler.cpp \
    itfontologyterm.cpp \
    itfontologyhandler.cpp \
    itfhierarchicalview.cpp \
    plantstructureontologyhandler.cpp \
    itfdynamicontologyhandler.cpp \
    xeoterm.cpp \
    unit.cpp \
    convertableunit.cpp \
    typespecifics.cpp \
    typespecification.cpp \
    typespecificsenum.cpp \
    defaultcycle.cpp \
    variablecontextspec.cpp \
    obohandler.cpp \
    attributestore.cpp \
    xeohandler.cpp \
    itfvariableontologyhandler.cpp \
	basicterm.cpp \
    storynode.cpp \
    storysplit.cpp \
    partition.cpp \
    timespanextension.cpp \
    positioningontologyhandler.cpp \
    posterm.cpp \
    contextlesshandler.cpp \
    peohandler.cpp \
    envohandler.cpp

HEADERS += \
    itfdocument.h \
    individualspool.h \
    individual.h \
    experimentheader.h \
    experimenter.h \
    event.h \
    dynamicvaluebase.h \
    dynamicvalue.h \
    dynamicterm.h \
    downloadmanager.h \
    documentresources.h \
    developmentalontologyhandler.h \
    cycle.h \
    componentloadstate.h \
    xemldocument.h \
    xemlcomponentloadfailedexception.h \
    xemlannotableobject.h \
    variableterm.h \
    valuebase.h \
    value.h \
    timespan.h \
    termattribute.h \
    term.h \
    taggedannotation.h \
    storyboard.h \
    storybase.h \
    story.h \
    simpleoboterm.h \
    ontologymanager.h \
    ontologyhandlerresources.h \
    observationpoint.h \
    observation.h \
    oboreader.h \
    keyword.h \
    itfxemlcomponent.h \
    itfvalidator.h \
    itfvalidationsource.h \
    itftimeobject.h \
    itfplainontologyhandler.h \
    itfontologyterm.h \
    itfontologyhandler.h \
    itfhierarchicalview.h \
    plantstructureontologyhandler.h \
    VariableDataTypes.h \
    itfdynamicontologyhandler.h \
    xeoterm.h \
    unit.h \
    convertableunit.h \
    typespecifics.h \
    typespecification.h \
    typespecificsenum.h \
    defaultcycle.h \
    variablecontextspec.h \
    Utilities.h \
    OboTags.h \
    obohandler.h \
    OboTermClass.h \
    OboHeaderTypes.h \
    attributestore.h \
    xeohandler.h \
    itfvariableontologyhandler.h \
	basicterm.h \
    storynode.h \
    storysplit.h \
    partition.h \
    timespanextension.h \
    positioningontologyhandler.h \
    posterm.h \
    contextlesshandler.h \
    peohandler.h \
    envohandler.h \
    ui_authenticationdialog.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}


INCLUDEPATH += $$PWD/../Xeml
DEPENDPATH += $$PWD/../Xeml
