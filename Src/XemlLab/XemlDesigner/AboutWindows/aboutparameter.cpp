#include "aboutparameter.h"

AboutParameter::AboutParameter(ItfDocument * _xemldoc,StoryNode * _story,QWidget * parent)
	:QDialog(parent)
{
	
	
	usemode=false;
	this->story=_story;
	this->current_doc=_xemldoc;
	this->timelabel = new QLabel(tr("observation StartTime :"));
	this->daytimeedit=new QDateTimeEdit(static_cast<XemlDocument*>(this->current_doc)->get_startdate());
	this->daytimeedit->setDisplayFormat("dd-MM-yyyyThh:mm:ss");
	this->daytimeedit->setCalendarPopup(true);
	this->daytimeedit->setMinimumDateTime(static_cast<XemlDocument*>(this->current_doc)->get_startdate());
	this->daytimeedit->setMaximumDateTime(static_cast<XemlDocument*>(this->current_doc)->get_enddate());
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->freeText,SLOT(set_dateTime(QDateTime)));
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->quantity,SLOT(set_dateTime(QDateTime)));
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->quality,SLOT(set_dateTime(QDateTime)));
	//connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->responseRange,SLOT(set_dateTime(QDateTime)));

	this->timelabel->setBuddy(daytimeedit);
	
	//this->storyitem=_storyitem;
	line1 = new QFrame(this);
	line2 = new QFrame(this);
	line3 = new QFrame(this);
	line1->setObjectName(QString::fromUtf8("line"));
	line1->setGeometry(QRect(160, 120, 41, 81));
	line1->setFrameShape(QFrame::VLine);
	line1->setFrameShadow(QFrame::Sunken);
	line2->setObjectName(QString::fromUtf8("line"));
	line2->setGeometry(QRect(160, 120, 41, 81));
	line2->setFrameShape(QFrame::VLine);
	line2->setFrameShadow(QFrame::Sunken);
	line3->setObjectName(QString::fromUtf8("line"));
	line3->setGeometry(QRect(160, 120, 41, 81));
	line3->setFrameShape(QFrame::VLine);
	line3->setFrameShadow(QFrame::Sunken);
	this->listWidget =new QListWidget;
	this->param_window=new QWidget(this);
	//this->param_window->setAutoFillBackground(true);
	this->stackLayout= new QStackedLayout;

	this->mainlayout=new QVBoxLayout;
	this->paramLayout=new QHBoxLayout;
	//this->paramLayout->addWidget(this->param_window);
	this->param_window->setLayout(paramLayout);
	this->splitter=new QSplitter(Qt::Horizontal);
	this->splitter->setLineWidth(3);
	this->cancelButton = new QPushButton("Cancel");
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	this->okButton = new QPushButton("Add");
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->finishButton = new QPushButton("Finish");
	this->finishButton->setCursor(Qt::PointingHandCursor);
	this->finishButton->setToolTip("click when you have finished to set values");
	this->cancelButton->setDefault(true);

	connect(this->listWidget,SIGNAL(currentRowChanged(int)),stackLayout,SLOT(setCurrentIndex(int)));
	connect(this->finishButton,SIGNAL(clicked()),this,SLOT(on_setup_finished()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QString fenObjectName("ParameterContext");
	this->setObjectName(fenObjectName);
	this->setStyleSheet("QWidget#"+fenObjectName +"{ background-image: url(/Users/benjamindartigues/Pictures/BlueMetal.png);}");
}
AboutParameter::AboutParameter(QWidget * parent)
	:QDialog(parent)
{
	//QFrame *line;
	usemode=true;
	line1 = new QFrame(this);
	line2 = new QFrame(this);
	line3 = new QFrame(this);
	line1->setObjectName(QString::fromUtf8("line"));
	line1->setGeometry(QRect(160, 120, 41, 81));
	line1->setFrameShape(QFrame::VLine);
	line1->setFrameShadow(QFrame::Sunken);
	line2->setObjectName(QString::fromUtf8("line"));
	line2->setGeometry(QRect(160, 120, 41, 81));
	line2->setFrameShape(QFrame::VLine);
	line2->setFrameShadow(QFrame::Sunken);
	line3->setObjectName(QString::fromUtf8("line"));
	line3->setGeometry(QRect(160, 120, 41, 81));
	line3->setFrameShape(QFrame::VLine);
	line3->setFrameShadow(QFrame::Sunken);
	this->listWidget =new QListWidget;
	this->param_window=new QWidget(this);
	//this->param_window->setAutoFillBackground(true);
	this->stackLayout= new QStackedLayout;

	this->mainlayout=new QVBoxLayout;
	this->paramLayout=new QHBoxLayout;
	//this->paramLayout->addWidget(this->param_window);
	this->param_window->setLayout(paramLayout);
	this->splitter=new QSplitter(Qt::Vertical);
	this->splitter->setLineWidth(3);
	this->cancelButton = new QPushButton("Cancel");
	this->cancelButton->setCursor(Qt::PointingHandCursor);

	this->okButton = new QPushButton("Add");
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->finishButton = new QPushButton("Finish");
	this->finishButton->setCursor(Qt::PointingHandCursor);
	this->finishButton->setToolTip("click when you have finished to set values");
	this->cancelButton->setDefault(true);

	connect(this->listWidget,SIGNAL(currentRowChanged(int)),stackLayout,SLOT(setCurrentIndex(int)));
	connect(this->finishButton,SIGNAL(clicked()),this,SLOT(on_setup_finished()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	QString fenObjectName("ParameterContext");
	this->setObjectName(fenObjectName);
	this->setStyleSheet("QWidget#"+fenObjectName +"{ background-image: url(/Users/benjamindartigues/Pictures/BlueMetal.png);}");
}

void AboutParameter::set_term(ItfOntologyTerm * _term){
	this->term=_term;
}

ItfOntologyTerm * AboutParameter::get_term(){
	return this->term;
}

void             AboutParameter::on_setup_finished(){
	if(usemode){
		emit set_up_finished(this->term);
	}
	else{
		emit set_up_finished(this->story,this->newTerm);

	}
	this->close();
}

void AboutParameter::initialize(){
	std::cerr << "entering Initialize" << std::endl;
	//std::cerr << "EO TERM : " << this->term->get_prototype()->get_namespacealias().toStdString()<< "test" << std::endl;
	this->mainlayout->addStretch();
	if(this->term->get_prototype()->get_namespacealias()=="XEO_Positioning"){
		std::vector<QString> * enume;
		newTerm=new VariableTerm((*static_cast<VariableTerm*>(this->term->get_prototype())));

		std::cerr << "context collection size : " << static_cast<PosTerm*>(this->term)->get_termId().toStdString()<<  std::endl;

		//std::cerr << "context collection size : " << static_cast<PosTerm*>(this->term)->get_contextCollection()->size() <<  std::endl;

		for(std::map<QString,VariableContextSpec*>::iterator it =static_cast<PosTerm*>(this->term)->get_contextCollection()->begin();it!=static_cast<PosTerm*>(this->term)->get_contextCollection()->end();++it){
			//if((*it).second->get_unitSet()->get_defUnit()!=NULL){

			//}


			enume =new std::vector<QString>();
			std::cerr << "context : " << (*it).first.toStdString() << std::endl;
			//std::cerr << "description " << (*it).second->get_description() << std::endl;
			//std::vector<QString> * enume;
			if((*it).first=="ResponseRange"){
				//std::cerr << "response Range found : " << (*it).first << std::endl;
				for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){
					enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
				}
				//AJOUTER CONDITIONS SPECIALES LORS DU CHARGEMENT D'UN SAMPLE
				if(usemode){
					//responseRange=new ResponseRangeParameter;

				}
				else{
					responseRange=new ResponseRangeParameter(enume,this->daytimeedit->dateTime());

				}
				responseRange->set_context((*it).first);
				responseRange->set_enum(enume);
				responseRange->set_term(newTerm);

				this->listWidget->addItem(tr("ResponseRange"));
				this->paramLayout->addWidget(responseRange);
				//this->stackLayout->addWidget(responseRange);

			}
			else if((*it).first=="FreeText"){

				//std::cerr << "free text found : " << (*it).first << std::endl;

				//AJOUTER CONDITIONS SPECIALES LORS DU CHARGEMENT D'UN SAMPLE

				freeText=new FreeTextParameter(this->daytimeedit->dateTime());
				freeText->set_context((*it).first);
				freeText->set_term(newTerm);
				this->listWidget->addItem(tr("FreeText"));
				this->paramLayout->addWidget(freeText);

				//this->stackLayout->addWidget(freeText);
			}
			else if((*it).first=="Quantity"){
				std::cerr << "problem before" << std::endl;
				std::vector<std::pair<QString,QString> > * tmp;
				tmp=static_cast<PosTerm*>(this->term)->listUnits((*it).first);
				if(static_cast<PosTerm*>(this->term)->hasDefaultUnit((*it).first)){
					enume =new std::vector<QString>();
					for(std::vector<std::pair<QString,QString> >::iterator it2 =tmp->begin();it2!=tmp->end();++it2){
						enume->push_back((*it2).second);
					}
				}
				//std::cerr << "new Qp param" << std::endl;

				//AJOUTER CONDITIONS SPECIALES LORS DU CHARGEMENT D'UN SAMPLE
				if(usemode){
					//responseRange=new ResponseRangeParameter;
					std::cerr << "new Qp param" << std::endl;
					quantity=new QuantitativeParameter;


				}
				else{
					quantity=new QuantitativeParameter(this->daytimeedit->dateTime());
				}
				std::cerr << "new Qp param1" << std::endl;
				quantity->set_context((*it).first);
				std::cerr << "new Qp param2" << std::endl;
				quantity->set_term(newTerm);
				std::cerr << "new Qp param3" << std::endl;
				quantity->set_enumUnit(enume);
				std::cerr << "new Qp param4" << std::endl;
				//this->listWidget->addItem(tr("Quantity"));
				std::cerr << "new Qp param4" << std::endl;
				this->paramLayout->addWidget(quantity);
				//this->stackLayout->addWidget(quantity);

			}
			else{
				//std::cerr << "typespecifica size  : " << (*it).second->get_typeDefine()->get_typeSpecifica()->size() << std::endl;

				for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){

					//std::cerr << "textVal : " << static_cast<Enum*>((*it3))->get_textVal() << std::endl;
					enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
				//enume->push_back(static_cast<Enum*>(static_cast(*it).second->get_typeDefine()->get_typeSpecifica())[0]).get_textVal());
				}
				//std::cerr << "Quality found : " << (*it).first << std::endl;

				//AJOUTER CONDITIONS SPECIALES LORS DU CHARGEMENT D'UN SAMPLE

				if(usemode){
					//responseRange=new ResponseRangeParameter;
					quality=new QualitativeParameter;

				}
				else{
					quality=new QualitativeParameter(enume,this->daytimeedit->dateTime());
				}
				quality->set_context((*it).first);
				quality->set_enum(enume);
				quality->set_term(newTerm);
				this->listWidget->addItem(tr("Quality"));
				this->paramLayout->addWidget(quality);
				//this->stackLayout->addWidget(quality);
			}
		}


	}
	if(this->term->get_prototype()->get_namespacealias()=="XEO"){
		//this->daytimeedit=new QDateTimeEdit(this-);
		//this->splitter->addWidget(this->daytimeedit);
		//std::cerr << "XEO TERM : " << std::endl;
		if(this->story->get_story()->contain_variableId(this->term->get_termId())){
			for(std::vector<std::pair<BasicTerm*,QString> >::iterator it=this->story->get_story()->get_variablesCollection()->begin();it!=this->story->get_story()->get_variablesCollection()->end();++it){
				if((*it).second==this->term->get_termId()){
					newTerm=static_cast<DynamicTerm*>((*it).first);
				}

			}
		}
		else{
			newTerm=new DynamicTerm((*static_cast<DynamicTerm*>(this->term->get_prototype())));
		}
		//static_cast<DynamicTerm*>(newTerm)->
		for(std::map<QString,VariableContextSpec*>::iterator it =static_cast<XeoTerm*>(this->term)->get_contextCollection()->begin();it!=static_cast<XeoTerm*>(this->term)->get_contextCollection()->end();++it){

			std::vector<std::pair<QString,QString> > * tmp;
			//std::vector<std::pair<QString,QString> > * tmp2;
			tmp=static_cast<XeoTerm*>(this->term)->listUnits((*it).first);

			std::vector<QString> * enume;
			if(static_cast<XeoTerm*>(this->term)->hasDefaultUnit((*it).first)){
				enume =new std::vector<QString>();
				for(std::vector<std::pair<QString,QString> >::iterator it2 =tmp->begin();it2!=tmp->end();++it2){
					enume->push_back((*it2).first);

				}
				if((*it).first=="ResponseRange"){

				}else if((*it).first=="FreeText"){

				}
				else{
					quantity=new QuantitativeParameter(this->daytimeedit->dateTime());

					connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->quantity,SLOT(set_dateTime(QDateTime)));

					quantity->set_context((*it).first);
					quantity->set_term(newTerm);
					quantity->set_enumUnit(enume);
					this->listWidget->addItem(tr("Quantity"));
					//this->stackLayout->addWidget(quantity);
					//connect(quantity,SIGNAL(destroyed()),this->splitter,SLOT()
					this->splitter->addWidget(quantity);
					//this->splitter->resizeEvent(QResizeEvent * e);
					//this->paramLayout->addWidget(this->line1);

				}
			}
			else{
				enume =new std::vector<QString>();

				if((*it).first=="ResponseRange"){

					for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){
						enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
					}
					responseRange=new ResponseRangeParameter(enume,this->daytimeedit->dateTime());

					connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->responseRange,SLOT(set_dateTime(QDateTime)));
					responseRange->set_context((*it).first);
					responseRange->set_enum(enume);
					responseRange->set_term(newTerm);

					this->listWidget->addItem(tr("ResponseRange"));
					//this->stackLayout->addWidget(responseRange);
					this->splitter->addWidget(responseRange);
					//this->paramLayout->addWidget(this->line2);


				}
				else if((*it).first=="FreeText"){

					freeText=new FreeTextParameter(this->daytimeedit->dateTime());
					connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->freeText,SLOT(set_dateTime(QDateTime)));

					freeText->set_context((*it).first);
					freeText->set_term(newTerm);
					this->listWidget->addItem(tr("FreeText"));
					//this->stackLayout->addWidget(freeText);
					this->splitter->addWidget(freeText);
					//this->paramLayout->addWidget(this->line3);

				}
				else{
					for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){
						enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
					}
					quality=new QualitativeParameter(enume,this->daytimeedit->dateTime());

					connect(this->daytimeedit,SIGNAL(dateTimeChanged(QDateTime)),this->quality,SLOT(set_dateTime(QDateTime)));
					quality->set_context((*it).first);
					quality->set_enum(enume);
					quality->set_term(newTerm);
					this->listWidget->addItem(tr("Quality"));
					//this->stackLayout->addWidget(quality);
					this->splitter->addWidget(quality);
					//this->paramLayout->addWidget(this->line3);



				}
			}

			/*
			if(static_cast<XeoTerm*>(this->term)->hasDefaultValue((*it).first)){
				std::cerr << "has default Value : " << (*it).second->get_defValue() <<std::endl;
			}
			else{
				std::cerr << "no default Value : " << (*it).second->get_defValue() <<std::endl;
			}
			*/

		}
	}

		//std::cerr << "EO TERM : " << this->term->get_prototype()->get_namespacealias().toStdString() << std::endl;
	if(this->term->get_prototype()->get_namespacealias() == "EO" || this->term->get_prototype()->get_namespacealias()=="EnvO"){
		newTerm=new DynamicTerm((*static_cast<DynamicTerm*>(this->term->get_prototype())));

		std::vector<QString> * enume;
		//std::cerr << "context collection size : " << static_cast<XeoTerm*>(this->term)->get_contextCollection()->size() <<  std::endl;

		for(std::map<QString,VariableContextSpec*>::iterator it =static_cast<XeoTerm*>(this->term)->get_contextCollection()->begin();it!=static_cast<XeoTerm*>(this->term)->get_contextCollection()->end();++it){

			enume =new std::vector<QString>();
			//std::cerr << "context : " << (*it).first << std::endl;
			//std::vector<QString> * enume;
			if((*it).first=="ResponseRange"){
				//std::cerr << "response Range found : " << (*it).first << std::endl;
				for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){
					enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
				}
				responseRange=new ResponseRangeParameter(enume,this->daytimeedit->dateTime());
				responseRange->set_context((*it).first);
				responseRange->set_enum(enume);
				responseRange->set_term(newTerm);

				//this->listWidget->addItem(tr("ResponseRange"));

				//this->stackLayout->addWidget(responseRange);
				this->splitter->addWidget(responseRange);

			}
			else if((*it).first=="FreeText"){

				//std::cerr << "free text found : " << (*it).first << std::endl;
				freeText=new FreeTextParameter(this->daytimeedit->dateTime());
				freeText->set_context((*it).first);
				freeText->set_term(newTerm);
				//this->listWidget->addItem(tr("FreeText"));
				//this->stackLayout->addWidget(freeText);
				this->splitter->addWidget(freeText);
			}
			else{
				//std::cerr << "typespecifica size  : " << (*it).second->get_typeDefine()->get_typeSpecifica()->size() << std::endl;

				for(std::list<TypeSpecifics*>::iterator it3=(*it).second->get_typeDefine()->get_typeSpecifica()->begin();it3!=(*it).second->get_typeDefine()->get_typeSpecifica()->end();++it3){

					//std::cerr << "textVal : " << static_cast<Enum*>((*it3))->get_textVal() << std::endl;
					enume->push_back(static_cast<Enum*>((*it3))->get_textVal());
				//enume->push_back(static_cast<Enum*>(static_cast(*it).second->get_typeDefine()->get_typeSpecifica())[0]).get_textVal());
				}
				//std::cerr << "Quality found : " << (*it).first << std::endl;

				quality=new QualitativeParameter(enume,this->daytimeedit->dateTime());
				quality->set_context((*it).first);
				quality->set_enum(enume);
				quality->set_term(newTerm);
				//this->listWidget->addItem(tr("Quality"));
				//this->stackLayout->addWidget(quality);
				this->splitter->addWidget(quality);
			}
		}

	}


	//QVBoxLayout * leftLayout = new QVBoxLayout;
	//leftLayout->addWidget(listWidget);

	//QVBoxLayout * rightLayout = new QVBoxLayout;
	//rightLayout->addLayout(stackLayout);
	//QHBoxLayout * mainLayout = new QHBoxLayout;
	this->paramLayout->addWidget(this->splitter);
	this->splitter->setLineWidth(10);

	if (!usemode){
		QHBoxLayout * topLayout=new QHBoxLayout;
		topLayout->addWidget(timelabel);
		topLayout->addWidget(daytimeedit);
		this->mainlayout->addLayout(topLayout);
	}

	//this->splitter->setStyleSheet("QSplitter  { border-color: black; color: red;  height: 5px;background-color: rgb(225,230,234); }");

	this->mainlayout->addWidget(this->param_window);
	this->mainlayout->addStretch();
	QHBoxLayout * bottomlayout=new QHBoxLayout;
	bottomlayout->addStretch();
	bottomlayout->addWidget(this->cancelButton);
	bottomlayout->addWidget(this->finishButton);
	this->mainlayout->addLayout(bottomlayout);
	//mainLayout->addWidget(this->finishButton);
	//mainLayout->addLayout(leftLayout);
	//mainLayout->addLayout(rightLayout);
	this->setLayout(this->mainlayout);
	this->setStyleSheet("QDialog { background-color: white }");
	listWidget->setCurrentRow(0);
	this->setWindowTitle("Set Parameter Context");
	this->show();
}



void AboutParameter::set_up_qualitativeValue(DynamicValue * _v){


	//regler les differents attributs de ce term
	//envoyer le term regle en parametre de set_up_finished(ItfOntologyTerm * _term)
	//ce signal sera recu par storyview dans la fonction set_up_parameter()
	//emit set_up_finished();
}
void             AboutParameter::set_up_responseRangeValue(DynamicValue * _v){

}

void             AboutParameter::set_up_quantitativeValue(DynamicValue * _v){

}

void             AboutParameter::set_up_freeTextValue(DynamicValue * _v){

}
