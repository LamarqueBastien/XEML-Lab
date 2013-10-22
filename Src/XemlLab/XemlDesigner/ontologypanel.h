#ifndef ONTOLOGYPANEL_H
#define ONTOLOGYPANEL_H
#include<QtWidgets>
#include"documentresources.h"
using namespace Xeml::Document;
using namespace Xeml::Document::Contracts;
class OntologyPanel : public QWidget
{
		Q_OBJECT
	public:
		OntologyPanel(QWidget * parent=0);
		QCheckBox * EOcheckbox;// = new QCheckBox("C&ase sensitive", this);
		QCheckBox * EnvOcheckbox;
		QCheckBox * XEOcheckbox;
		QPushButton * okButton;
		QPushButton * cancelButton;
		bool XEO_ischecked;
		bool EO_ischecked;
		bool EnvO_ischecked;
		void initialize(DocumentResources * _doc);
	signals:
		void ontologies_to_load(bool _xeoIsChecked,bool _eoIsChecked,bool _envoIsChecked);
	private slots:
		void set_up_end();

};

#endif // ONTOLOGYPANEL_H
