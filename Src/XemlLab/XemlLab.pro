TEMPLATE = subdirs

SUBDIRS+= \
	Ontologies \
	XemlDesigner

CONFIG+= console debug
CONFIG+=static

RESOURCES+= \
	Divers.qrc
