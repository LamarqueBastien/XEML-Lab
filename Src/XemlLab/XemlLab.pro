cache()
TEMPLATE = subdirs

SUBDIRS+= \
	XemlCore \
	XemlDesigner

CONFIG+= gui debug
CONFIG+=static

RESOURCES+= \
	Divers.qrc
