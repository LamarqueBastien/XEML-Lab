#include "xemlobjectinfoview.h"

XemlObjectInfoView::XemlObjectInfoView(QWidget *parent) :
	QWidget(parent)
{

	ObjectLabelEdit= new QLineEdit;
	ObjectLabel=new QLabel("Label :");
	ObjectLabel->setBuddy(ObjectLabelEdit);
	ObjectLabelEdit->setEnabled(false);

	ObjectStartTime=new QDateTimeEdit;
	ObjectStartTime->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	ObjectStartTime->setDisabled(true);


	ObjectStartTimeLabel=new QLabel("Start time :");
	ObjectStartTimeLabel->setBuddy(ObjectStartTime);

	annotation= new QPushButton(QIcon(":/Images/annotation.png"),"");
	this->annotation->setEnabled(false);
	QHBoxLayout * hLayout=new QHBoxLayout;
	hLayout->addWidget(ObjectLabel);
	hLayout->addWidget(ObjectLabelEdit);
	hLayout->addWidget(ObjectStartTimeLabel);
	hLayout->addWidget(ObjectStartTime);
	hLayout->addWidget(annotation);
	hLayout->addStretch(4);
	connect(annotation,SIGNAL(clicked()),this,SLOT(add_annotation()));
	connect(ObjectLabelEdit,SIGNAL(textChanged(QString)),this,SLOT(change_name(QString)));
	this->setLayout(hLayout);

}
void XemlObjectInfoView::change_name(QString _label){
	//emit on_label_changed(_label);
	GraphicStoryItem * my_selected_story;
	GraphicEventItem * my_selected_event;
	GraphicObservationPointItem  * my_selected_obsPoint;
	if(this->object!=0){
		switch(object->type()){
			case GraphicStoryItem::Type:
				my_selected_story=static_cast<GraphicStoryItem*>(object);
				my_selected_story->set_label(_label);
				my_selected_story->get_story()->set_label(_label);
				my_selected_story->set_label(_label);






				break;
			case GraphicEventItem::Type:
				my_selected_event=static_cast<GraphicEventItem*>(object);
				my_selected_event->get_event()->set_label(_label);
				my_selected_event->set_label(_label);




				break;
			case GraphicObservationPointItem::Type:
				my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(object);
				my_selected_obsPoint->get_obspoint()->set_id(_label.toInt());








				break;
		}
	}
	emit refresh_view();

}

void XemlObjectInfoView::add_annotation(){

	this->annot_dialog=new AnnotationDialog();
	this->annot_dialog->show();
	connect(this->annot_dialog,SIGNAL(send_annotation_tag(QString,QString)),this,SLOT(on_annotation_added(QString,QString)));


}
void  XemlObjectInfoView::on_annotation_added(QString _annot,QString _tag){
	std::cerr << "entering annotation adding" << std::endl;
	GraphicStoryItem * my_selected_story;
	GraphicEventItem * my_selected_event;
	GraphicObservationPointItem  * my_selected_obsPoint;
	if(this->object!=0){
		switch(object->type()){
			case GraphicStoryItem::Type:
				my_selected_story=static_cast<GraphicStoryItem*>(object);
				my_selected_story->get_story()->add_tagged_annotation(new TaggedAnnotation(_tag,_annot));




				break;
			case GraphicEventItem::Type:
				my_selected_event=static_cast<GraphicEventItem*>(object);
				my_selected_event->get_event()->add_tagged_annotation(new TaggedAnnotation(_tag,_annot));




				break;
			case GraphicObservationPointItem::Type:
				my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(object);
				my_selected_obsPoint->get_obspoint()->add_tagged_annotation(new TaggedAnnotation(_tag,_annot));








				break;
		}
	}
}
/*
void  XemlObjectInfoView::reset_all(){
	this
}
*/

void  XemlObjectInfoView::set_doc( ItfDocument * _xemldoc){

	this->current_doc=_xemldoc;
	this->ObjectStartTime->setDateTime(this->current_doc->get_startdate());

}

void XemlObjectInfoView::set_object_info(QGraphicsItem * _object){


	std::cerr << "entering set_object_info" << std::endl;

	object=_object;
	GraphicStoryItem * my_selected_story;
	GraphicEventItem * my_selected_event;
	GraphicObservationPointItem  * my_selected_obsPoint;

	if(object!=0){

		switch(object->type()){
			case GraphicStoryItem::Type:
				std::cerr << "entering story item type" << std::endl;

				my_selected_story=static_cast<GraphicStoryItem*>(object);
				std::cerr << my_selected_story->get_story()->get_label().toStdString() << std::endl;

				std::cerr << "finishing story item type" << std::endl;

				this->ObjectLabelEdit->setText(my_selected_story->get_story()->get_label());
				this->ObjectLabel->setText("Story Label");
				if (my_selected_story->get_story()->get_IsStorySplit()){
					this->ObjectStartTime->setDateTime(static_cast<StorySplit*>(my_selected_story->get_story())->get_timepoint());
				}
				else{
					std::cerr << "define startdate for story " << std::endl;

					this->ObjectStartTime->setDateTime(this->current_doc->get_startdate());
				}
				std::cerr << "finishing story item type" << std::endl;




				break;
			case GraphicEventItem::Type:
				my_selected_event=static_cast<GraphicEventItem*>(object);
				this->ObjectLabelEdit->setText(my_selected_event->get_label());
				this->ObjectLabel->setText("Event Label");
				this->ObjectStartTime->setDateTime(static_cast<Event*>(my_selected_event->get_event())->get_timepoint());



				break;
			case GraphicObservationPointItem::Type:
				my_selected_obsPoint=static_cast<GraphicObservationPointItem*>(object);
				this->ObjectLabel->setText("obs Point n°");
				this->ObjectLabelEdit->setText(QString ("%1").arg(my_selected_obsPoint->get_obspoint()->get_id()));
				this->ObjectStartTime->setDateTime(static_cast<ObservationPoint*>(my_selected_obsPoint->get_obspoint())->get_timepoint());







				break;
		}
		this->annotation->setEnabled(true);
		this->ObjectLabelEdit->setEnabled(true);
	}
	else{

		this->ObjectLabelEdit->setText("");
		this->ObjectLabel->setText("Label ");
	}
}

