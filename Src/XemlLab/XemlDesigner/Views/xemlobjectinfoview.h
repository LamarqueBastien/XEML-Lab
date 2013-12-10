#ifndef XEMLOBJECTINFOVIEW_H
#define XEMLOBJECTINFOVIEW_H

#include <QWidget>
#include <QtWidgets>
#include"DialogWindows/annotationdialog.h"
#include"Views/GraphicStoryView/Items/graphiceventitem.h"
#include"Views/GraphicStoryView/Items/graphicobservationpointitem.h"
#include"Views/GraphicStoryView/Items/graphicstoryitem.h"
#include"CoreObjects/xemldocument.h"
#include"Interface/itfdocument.h"
using namespace Xeml::Document;
class XemlObjectInfoView : public QWidget
{
		Q_OBJECT
	public:
		explicit XemlObjectInfoView(QWidget *parent = 0);
		void set_doc( ItfDocument * _xemldoc);


	private:
		QLineEdit          * ObjectLabelEdit;
		QLabel             * ObjectLabel;
		QDateTimeEdit      * ObjectStartTime;
		QLabel             * ObjectStartTimeLabel;
		QPushButton        * annotation;
		AnnotationDialog   * annot_dialog;
		QGraphicsItem      * object;
		ItfDocument        * current_doc;


	signals:
		void on_label_changed(QString _label);
		void refresh_view();

	public slots:

		void add_annotation();
		//void on_annotation_added(QString _annot,QString _tag);
		void set_object_info(QGraphicsItem * _object);
		void on_annotation_added(QString _annot,QString _tag);
		void change_name(QString _label);


};

#endif // XEMLOBJECTINFOVIEW_H
