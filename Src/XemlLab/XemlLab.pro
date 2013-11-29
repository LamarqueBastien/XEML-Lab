cache()
TEMPLATE = subdirs
QT += testlib
SUBDIRS+= \
	XemlCore \
	XemlDesigner

CONFIG+= gui debug
CONFIG+=static

RESOURCES+= \
	Divers.qrc
