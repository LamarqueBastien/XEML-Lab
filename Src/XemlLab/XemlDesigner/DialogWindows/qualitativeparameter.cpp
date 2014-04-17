#include <QtGui>
#include "qualitativeparameter.h"

QualitativeParameter::QualitativeParameter(std::vector<QString> * _enumeration,QDateTime _datetime,QWidget * parent)
	: QDialog(parent)
{
	this->enumeration=new std::vector<QString>();
	enumeration=_enumeration;
	this->dateTime=_datetime;
	this->labelvalue = new QLabel(tr("Value :"));
	this->labelunit = new QLabel(tr("Unit :"));
	labelEdit = new QLineEdit;
	addCycle = new QPushButton(tr("&+"));
	this->addCycle->setEnabled(false);
	addCycle->setCheckable(true);
	removeCycle = new QPushButton(tr("&-"));
	this->removeCycle->setEnabled(false);
	connect(removeCycle,SIGNAL(clicked()),this,SLOT(remove_cycle()));
	connect(addCycle,SIGNAL(clicked()),this,SLOT(add_cycle()));
	this->counter=0;
	this->counter_row=0;
	this->_time=new QDateTimeEdit;
	this->_time->setDisplayFormat("hh:mm:ss");
	this->values=new QComboBox;
	this->unit=new QComboBox;
	this->title=new QLabel("                              Quality Context");
	this->title->setStyleSheet("background-color: white;border-style: outset;border-width: 2px;border-color: beige;");
	this->labelvalue->setBuddy(values);
	this->labelunit->setBuddy(unit);
	_value=new QRadioButton("Fixed Value");
	_cycle=new QRadioButton("Cycle Value");
	_value->setChecked(true);
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));

	connect(values,SIGNAL(currentIndexChanged(QString)),this,SLOT(enabledOkButton(QString)));
	connect(values,SIGNAL(activated(int)),labelvalue,SLOT(show()));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));

	QVBoxLayout * topleftLayout = new QVBoxLayout;
	QHBoxLayout * topleftLayout1 = new QHBoxLayout;
	topleftLayout1->addWidget(labelvalue);
	topleftLayout1->addWidget(values);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(labelunit);
	topleftLayout2->addWidget(unit);
	topleftLayout->addLayout(topleftLayout1);
	topleftLayout->addLayout(topleftLayout2);
	QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
	bottomLeftLayout->addWidget(_value);
	bottomLeftLayout->addWidget(_cycle);
	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	leftLayout->addLayout(bottomLeftLayout);
	extension = new QWidget;
	connect(_cycle,SIGNAL(toggled(bool)),extension,SLOT(setVisible(bool)));
	connect(_cycle,SIGNAL(toggled(bool)),this,SLOT(inactive_value(bool)));
	QGridLayout *extensionLayout = new QGridLayout;
	extensionLayout->setSizeConstraint(QLayout::SetFixedSize);
	extensionLayout->addWidget(_time,counter_row,0);
	QLabel * tmp_label = new QLabel(tr("value :"));
	QComboBox * tmp_text = new QComboBox;
	for(std::vector<QString>::iterator it=this->enumeration->begin();it!=this->enumeration->end();++it){
		tmp_text->addItem((*it));
	}
	tmp_label->setBuddy(tmp_text);
	counter++;
	extensionLayout->addWidget(tmp_label,counter_row,1);
	counter++;
	extensionLayout->addWidget(tmp_text,counter_row,2);

	extension->setLayout(extensionLayout);
	//extension->setFixedHeight(sizeHint().height());
	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addWidget(this->addCycle);
	rightLayout->addWidget(this->removeCycle);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	QVBoxLayout * supermainlayout=new QVBoxLayout;
	supermainlayout->addWidget(this->title);
	supermainlayout->addLayout(mainLayout);
	supermainlayout->addWidget(extension);
	setLayout(supermainlayout);
	setWindowTitle(tr("qualitative tuning"));
	//setFixedHeight((sizeHint().height()));
	this->setStyleSheet("QDialog  { border-color: black; color: red;  border-style: outset;border-width: 2px;height: 5px;background-color: rgb(235,230,234); }");

	setMaximumHeight(400);
	extension->hide();


}
QualitativeParameter::QualitativeParameter(QWidget * parent)
	: QDialog(parent)
{
	//this->enumeration=new std::vector<QString>();
	//enumeration=_enumeration;
	//this->dateTime=_datetime;
	this->labelvalue = new QLabel(tr("Value :"));
	this->labelunit = new QLabel(tr("Unit :"));
	labelEdit = new QLineEdit;
	//addCycle = new QPushButton(tr("&+"));
	//this->addCycle->setEnabled(false);
	//addCycle->setCheckable(true);
	//removeCycle = new QPushButton(tr("&-"));
	//this->removeCycle->setEnabled(false);
	//connect(removeCycle,SIGNAL(clicked()),this,SLOT(remove_cycle()));
	//connect(addCycle,SIGNAL(clicked()),this,SLOT(add_cycle()));
	//this->counter=0;
	//this->counter_row=0;
	//this->_time=new QDateTimeEdit;
	//:this->_time->setDisplayFormat("hh:mm:ss");
	this->values=new QComboBox;
	this->unit=new QComboBox;
	this->title=new QLabel("                              Quality Context");
	this->title->setStyleSheet("background-color: white;border-style: outset;border-width: 2px;border-color: beige;");
	this->labelvalue->setBuddy(values);
	this->labelunit->setBuddy(unit);
	//_value=new QRadioButton("Fixed Value");
	//_cycle=new QRadioButton("Cycle Value");
	//_value->setChecked(true);
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));

	connect(values,SIGNAL(currentIndexChanged(QString)),this,SLOT(enabledOkButton(QString)));
	connect(values,SIGNAL(activated(int)),labelvalue,SLOT(show()));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));

	QVBoxLayout * topleftLayout = new QVBoxLayout;
	QHBoxLayout * topleftLayout1 = new QHBoxLayout;
	topleftLayout1->addWidget(labelvalue);
	topleftLayout1->addWidget(values);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(labelunit);
	topleftLayout2->addWidget(unit);
	topleftLayout->addLayout(topleftLayout1);
	topleftLayout->addLayout(topleftLayout2);
	//QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
	//bottomLeftLayout->addWidget(_value);
	//bottomLeftLayout->addWidget(_cycle);
	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	//leftLayout->addLayout(bottomLeftLayout);
	//extension = new QWidget;
	//connect(_cycle,SIGNAL(toggled(bool)),extension,SLOT(setVisible(bool)));
	//connect(_cycle,SIGNAL(toggled(bool)),this,SLOT(inactive_value(bool)));
	//QGridLayout *extensionLayout = new QGridLayout;
	//extensionLayout->setSizeConstraint(QLayout::SetFixedSize);
	//extensionLayout->addWidget(_time,counter_row,0);
	//QLabel * tmp_label = new QLabel(tr("value :"));
	//QComboBox * tmp_text = new QComboBox;
	//for(std::vector<QString>::iterator it=this->enumeration->begin();it!=this->enumeration->end();++it){
	//	tmp_text->addItem((*it));
	//}
	//tmp_label->setBuddy(tmp_text);
	//counter++;
	//extensionLayout->addWidget(tmp_label,counter_row,1);
	//counter++;
	//extensionLayout->addWidget(tmp_text,counter_row,2);

	//extension->setLayout(extensionLayout);
	//extension->setFixedHeight(sizeHint().height());
	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	//rightLayout->addWidget(this->addCycle);
	//rightLayout->addWidget(this->removeCycle);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	QVBoxLayout * supermainlayout=new QVBoxLayout;
	supermainlayout->addWidget(this->title);
	supermainlayout->addLayout(mainLayout);
	//supermainlayout->addWidget(extension);
	setLayout(supermainlayout);
	setWindowTitle(tr("qualitative tuning"));
	//setFixedHeight((sizeHint().height()));
	this->setStyleSheet("QDialog  { border-color: black; color: red;  border-style: outset;border-width: 2px;height: 5px;background-color: rgb(235,230,234); }");

	setMaximumHeight(400);
	//extension->hide();


}
void QualitativeParameter::inactive_value(bool _CycleMode){
	if(_CycleMode){
		this->values->setEnabled(false);
		this->addCycle->setEnabled(true);
		this->removeCycle->setEnabled(true);

	}
	else{
		this->values->setEnabled(true);
		this->addCycle->setEnabled(false);
		this->removeCycle->setEnabled(false);
	}
}
void QualitativeParameter::set_dateTime(QDateTime _datetime){
	this->dateTime=_datetime;
}
void QualitativeParameter::set_enum(std::vector<QString> * _enume){
	this->unit->setDisabled(true);
	this->enumeration=_enume;
	for(std::vector<QString>::iterator it=_enume->begin();it!=_enume->end();++it){
		this->values->addItem((*it));
	}
}

void QualitativeParameter::set_term(BasicTerm * _term){
	this->current_term=_term;
}

void QualitativeParameter::set_context(QString _context){
	this->context=_context;
}

QString QualitativeParameter::get_context(){
	return this->context;
}
void QualitativeParameter::add_cycle(){
	this->counter_row++;
	QLabel * tmp_label = new QLabel(tr("value :"));
	QComboBox * tmp_text = new QComboBox;
	for(std::vector<QString>::iterator it=this->enumeration->begin();it!=this->enumeration->end();++it){
		tmp_text->addItem((*it));
	}
	connect(tmp_text,SIGNAL(currentIndexChanged(QString)),this,SLOT(enabledOkButton(QString)));
	tmp_label->setBuddy(tmp_text);

	QDateTimeEdit * tmp_time=new QDateTimeEdit;

	tmp_time->setDisplayFormat("hh:mm:ss");
	static_cast<QGridLayout*>(extension->layout())->addWidget(tmp_time,counter_row,0);
	counter++;
	static_cast<QGridLayout*>(extension->layout())->addWidget(tmp_label,counter_row,1);
	counter++;
	static_cast<QGridLayout*>(extension->layout())->addWidget(tmp_text,counter_row,2);
	counter++;


	extension->resize(static_cast<QGridLayout*>(extension->layout())->maximumSize());
	//extension->
	extension->setVisible(true);
	extension->setFixedHeight(sizeHint().height());
}
void QualitativeParameter::remove_cycle()
{
	QLayoutItem *item;
	//if (item->layout()) {
	int tmp=counter;
		for (int i = tmp; i > tmp-3; --i){
			item=static_cast<QGridLayout*>(extension->layout())->takeAt(i);
			if (item->layout())
			{
				//clearLayout(item->layout());
				delete item->layout();
			}
			delete item->widget();
			delete item;
			counter--;

		}
		counter_row--;
	//}
	/*
	if(counter>=0){
		while ((item = static_cast<QGridLayout*>(extension->layout())->takeAt(counter)))
		{
			if (item->layout())
			{
				//clearLayout(item->layout());
				delete item->layout();
			}
			delete item->widget();
			delete item;
		}
		counter--;
	}
	*/
	//else{
		//QMessageBox()
		//std::cerr << "error no value to remove" << std::endl;
	//}
	extension->resize(static_cast<QGridLayout*>(extension->layout())->minimumSize());

}
void QualitativeParameter::enabledOkButton(const QString &text){
	this->okButton->setEnabled(true);
}

void QualitativeParameter::OkClicked(){


	QString textvalue;
	QString textunit;
	if(this->current_term->get_namespacealias()=="XEO_Positioning"){

	//if(this->term->get_prototype()->get_namespacealias()=="XEO_Positioning"){
		//std::cerr << "is Xeo pos term " << std::endl;
		textvalue= this->values->currentText();
		textunit= this->unit->currentText();
		Value * d = new Value();
		d->set_context(this->context);
		if(textunit!=""){
			d->set_unit(textunit);
		}
		if(textvalue!=""){
			d->set_value(textvalue);
		}
		static_cast<VariableTerm*>(this->current_term)->add_value(d);

		//static_cast<VariableTerm*>(this->term->get_prototype())->add_value(d);
		//std::cerr << "value added : " << textvalue.toStdString() <<" unit : " << textunit.toStdString() << std::endl;

	}
	else{
		textunit= this->unit->currentText();
		textvalue = this->values->currentText();
		QLayoutItem *item;
		QLayoutItem *item2;
		//if (item->layout()) {
		int tmp=counter;
		if (this->_cycle->isChecked()){
			Cycle * c=new Cycle();
			for (int i = 0; i <= tmp; ++i){
				std::cerr << "i : " << i << std::endl;
				item=static_cast<QGridLayout*>(extension->layout())->itemAt(i);
				if(i%3==0){
					//std::cerr << " modulo i : " << i << std::endl;

					//if(item->widget()){
						//std::cerr << "time : " << static_cast<QDateTimeEdit*>(item->widget())->time().toString("hh:mm:ss").toStdString() << std::endl;
					//}
					//std::cerr << "text : " << static_cast<QLineEdit*>(item->widget())->text().toStdString() << std::endl;
					DynamicValue * v = new DynamicValue();
					v->set_is_cyclevalue(true);
					//QDateTime * dt=new QDateTime(static_cast<QDateTimeEdit*>(item->widget())->dateTime());
					if(item->widget()){
						v->set_timepoint(static_cast<QDateTimeEdit*>(item->widget())->dateTime());
					}
					item2=static_cast<QGridLayout*>(extension->layout())->itemAt(i+2);
					//std::cerr << "checkpoint 1 " << std::endl;
					//v->set_context(this->context);
					v->set_value(static_cast<QComboBox*>(item2->widget())->currentText());
					//std::cerr << "checkpoint 2 " << std::endl;

					//std::cerr << "checkpoint 3 " << std::endl;

					c->add_cycleValue(std::make_pair(v,static_cast<QDateTimeEdit*>(item->widget())->dateTime()));


				}
			}
			c->set_timepoint(this->dateTime);
			c->set_context(this->context);
			if(textunit!=""){
				c->set_unit(textunit);
			}
			static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(c);
		}
		else{



			DynamicValue * v = new DynamicValue();

			v->set_is_cyclevalue(false);

			v->set_timepoint(this->dateTime);//new TimeSpan(12,23,59,59));

			v->set_context(this->context);

			if(textunit!=""){
				v->set_unit(textunit);
			}
			if(textvalue!=""){
				v->set_value(textvalue);
			}
			static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(v);

			//static_cast<DynamicTerm*>(this->term->get_prototype())->add_dynamicvalue(v);
		}
	}
	this->setEnabled(false);






	//std::cerr << "avant envoi" << std::endl;



	//static_cast<XeoTerm*>(this->term)->
	//emit this->send_value(text);
	//std::cerr << "apres envoi" << std::endl;
}

//void StorySplitDialog::send_signal(QString _text){
//	emit mon_signal2(_text);

//}
