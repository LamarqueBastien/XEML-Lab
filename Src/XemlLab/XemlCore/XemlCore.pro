#-------------------------------------------------
#
# Project created by QtCreator 2013-11-20T10:32:42
#
#-------------------------------------------------

QT       += core widgets network xml xmlpatterns


TARGET = XemlCore
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    CoreObjects/xemldocument.cpp \
    CoreObjects/xemlcomponentloadfailedexception.cpp \
    CoreObjects/xemlannotableobject.cpp \
    CoreObjects/variableterm.cpp \
    CoreObjects/valuebase.cpp \
    CoreObjects/value.cpp \
    CoreObjects/timespanextension.cpp \
    CoreObjects/timespan.cpp \
    CoreObjects/termattribute.cpp \
    CoreObjects/term.cpp \
    CoreObjects/taggedannotation.cpp \
    CoreObjects/storysplit.cpp \
    CoreObjects/storynode.cpp \
    CoreObjects/storyboard.cpp \
    CoreObjects/storybase.cpp \
    CoreObjects/story.cpp \
    CoreObjects/partition.cpp \
    CoreObjects/ontologyhandlerresources.cpp \
    CoreObjects/observationpoint.cpp \
    CoreObjects/observation.cpp \
    CoreObjects/keyword.cpp \
    CoreObjects/individualspool.cpp \
    CoreObjects/individual.cpp \
    CoreObjects/experimentheader.cpp \
    CoreObjects/experimenter.cpp \
    CoreObjects/event.cpp \
    CoreObjects/dynamicvaluebase.cpp \
    CoreObjects/dynamicvalue.cpp \
    CoreObjects/dynamicterm.cpp \
    CoreObjects/documentresources.cpp \
    CoreObjects/cycle.cpp \
    CoreObjects/basicterm.cpp \
    Interface/itfxemlcomponent.cpp \
    Interface/itfvariableontologyhandler.cpp \
    Interface/itfvalidator.cpp \
    Interface/itfvalidationsource.cpp \
    Interface/itftimeobject.cpp \
    Interface/itfplainontologyhandler.cpp \
    Interface/itfontologyterm.cpp \
    Interface/itfontologyhandler.cpp \
    Interface/itfhierarchicalview.cpp \
    Interface/itfdynamicontologyhandler.cpp \
    Interface/itfdocument.cpp \
    Manager/ontologymanager.cpp \
    Manager/downloadmanager.cpp \
    Ontologies/DevelopmentalStage/developmentalontologyhandler.cpp \
    Ontologies/Environment/xeoterm.cpp \
    Ontologies/Environment/variablecontextspec.cpp \
    Ontologies/Environment/unit.cpp \
    Ontologies/Environment/typespecificsenum.cpp \
    Ontologies/Environment/typespecifics.cpp \
    Ontologies/Environment/typespecification.cpp \
    Ontologies/Environment/defaultcycle.cpp \
    Ontologies/Environment/convertableunit.cpp \
    Ontologies/OBO/xeohandler.cpp \
    Ontologies/OBO/peohandler.cpp \
    Ontologies/OBO/oboreader.cpp \
    Ontologies/OBO/obohandler.cpp \
    Ontologies/OBO/envohandler.cpp \
    Ontologies/OBO/contextlesshandler.cpp \
    Ontologies/OBO/attributestore.cpp \
    Ontologies/PlantStructure/simpleoboterm.cpp \
    Ontologies/PlantStructure/plantstructureontologyhandler.cpp \
    Ontologies/Positioning/posterm.cpp \
    Ontologies/Positioning/positioningontologyhandler.cpp


HEADERS += \
    CoreObjects/xemldocument.h \
    CoreObjects/xemlcomponentloadfailedexception.h \
    CoreObjects/xemlannotableobject.h \
    CoreObjects/variableterm.h \
    CoreObjects/VariableDataTypes.h \
    CoreObjects/valuebase.h \
    CoreObjects/value.h \
    CoreObjects/Utilities.h \
    CoreObjects/ui_sortdialog.h \
    CoreObjects/ui_authenticationdialog.h \
    CoreObjects/timespanextension.h \
    CoreObjects/timespan.h \
    CoreObjects/termattribute.h \
    CoreObjects/term.h \
    CoreObjects/taggedannotation.h \
    CoreObjects/storysplit.h \
    CoreObjects/storynode.h \
    CoreObjects/storyboard.h \
    CoreObjects/storybase.h \
    CoreObjects/story.h \
    CoreObjects/partition.h \
    CoreObjects/ontologyhandlerresources.h \
    CoreObjects/observationpoint.h \
    CoreObjects/observation.h \
    CoreObjects/keyword.h \
    CoreObjects/individualspool.h \
    CoreObjects/individual.h \
    CoreObjects/experimentheader.h \
    CoreObjects/experimenter.h \
    CoreObjects/event.h \
    CoreObjects/dynamicvaluebase.h \
    CoreObjects/dynamicvalue.h \
    CoreObjects/dynamicterm.h \
    CoreObjects/documentresources.h \
    CoreObjects/cycle.h \
    CoreObjects/componentloadstate.h \
    CoreObjects/basicterm.h \
    Interface/itfxemlcomponent.h \
    Interface/itfvariableontologyhandler.h \
    Interface/itfvalidator.h \
    Interface/itfvalidationsource.h \
    Interface/itftimeobject.h \
    Interface/itfplainontologyhandler.h \
    Interface/itfontologyterm.h \
    Interface/itfontologyhandler.h \
    Interface/itfhierarchicalview.h \
    Interface/itfdynamicontologyhandler.h \
    Interface/itfdocument.h \
    Manager/ontologymanager.h \
    Manager/downloadmanager.h \
    Ontologies/DevelopmentalStage/developmentalontologyhandler.h \
    Ontologies/Environment/xeoterm.h \
    Ontologies/Environment/variablecontextspec.h \
    Ontologies/Environment/unit.h \
    Ontologies/Environment/typespecificsenum.h \
    Ontologies/Environment/typespecifics.h \
    Ontologies/Environment/typespecification.h \
    Ontologies/Environment/defaultcycle.h \
    Ontologies/Environment/convertableunit.h \
    Ontologies/OBO/xeohandler.h \
    Ontologies/OBO/peohandler.h \
    Ontologies/OBO/OboTermClass.h \
    Ontologies/OBO/OboTags.h \
    Ontologies/OBO/oboreader.h \
    Ontologies/OBO/OboHeaderTypes.h \
    Ontologies/OBO/obohandler.h \
    Ontologies/OBO/envohandler.h \
    Ontologies/OBO/contextlesshandler.h \
    Ontologies/OBO/attributestore.h \
    Ontologies/PlantStructure/simpleoboterm.h \
    Ontologies/PlantStructure/plantstructureontologyhandler.h \
    Ontologies/Positioning/posterm.h \
    Ontologies/Positioning/positioningontologyhandler.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}