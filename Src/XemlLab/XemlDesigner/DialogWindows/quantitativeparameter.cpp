#include "quantitativeparameter.h"

QuantitativeParameter::QuantitativeParameter(QDateTime _datetime,QWidget * parent)
: QDialog(parent)
{
	this->counter=0;
	this->counter_row=0;
	this->dateTime=_datetime;
	this->label = new QLabel(tr("Value :"));
	this->labelUnit = new QLabel(tr("Unit :"));
	this->addCycle = new QPushButton(tr("&+"));
	this->addCycle->setCheckable(true);
	this->addCycle->setEnabled(false);
	this->removeCycle = new QPushButton(tr("&-"));
	this->removeCycle->setEnabled(false);
	connect(removeCycle,SIGNAL(clicked()),this,SLOT(remove_cycle()));
	connect(addCycle,SIGNAL(clicked()),this,SLOT(add_cycle()));
	this->_time=new QDateTimeEdit;
	this->_time->setDisplayFormat("hh:mm:ss");
	this->valueBox = new QSpinBox;
	this->valueBox->setRange(0, 1000);
	this->valueBox->setValue(0);
	this->unitBox=new QComboBox;
	this->_value=new QRadioButton("Fixed Value");
	this->_cycle=new QRadioButton("Cycle Value");
	_value->setChecked(true);
	this->label->setBuddy(valueBox);
	this->labelUnit->setBuddy(unitBox);
	this->title=new QLabel("                              Quantity Context");
	this->title->setStyleSheet("background-color: white;border-style: outset;border-width: 2px;border-color: beige;");
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Reset"));

	connect(unitBox,SIGNAL(activated(int)),labelUnit,SLOT(show()));
	connect(valueBox,SIGNAL(valueChanged(int)),this,SLOT(enabledOkButton(int)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	connect(cancelButton,SIGNAL(clicked()),this,SLOT(reset()));

	QHBoxLayout * topleftLayout1 = new QHBoxLayout;
	topleftLayout1->addWidget(label);
	topleftLayout1->addWidget(valueBox);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(labelUnit);
	topleftLayout2->addWidget(unitBox);
	QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
	bottomLeftLayout->addWidget(_value);
	bottomLeftLayout->addWidget(_cycle);
	QVBoxLayout * topleftLayout= new QVBoxLayout;
	topleftLayout->addLayout(topleftLayout1);
	topleftLayout->addLayout(topleftLayout2);

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
	//QLineEdit * tmp_text = new QLineEdit;
	QSpinBox * tmp_text = new QSpinBox;
	tmp_text->setRange(0, 1000);
	tmp_text->setValue(0);
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
	QVBoxLayout * supermainLayout= new QVBoxLayout;
	supermainLayout->addWidget(this->title);

	//supermainLayout->setDirection(QBoxLayout::TopToBottom);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	supermainLayout->addLayout(mainLayout);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	//supermainLayout->addWidget(&m_TitleBar);

	//supermainLayout->setRowStretch(1, 1); // Put the title bar at the top of the window
	//mainLayout->addLayout(mainLayout);
	supermainLayout->addWidget(extension);
	setLayout(supermainLayout);
	setWindowTitle(tr("freetext panel"));
	//connect(this,SIGNAL(WindowTitleChanged()),&m_TitleBar,SLOT(UpdateWindowTitle()));
	//setFixedHeight((sizeHint().height()));
	this->setStyleSheet("QDialog  { border-color: black; border-style: outset;border-width: 2px; color: red; height: 5px; background-color: rgb(210,233,234); }");
	setMaximumHeight(400);
	extension->hide();
}
QuantitativeParameter::QuantitativeParameter(QWidget * parent)
: QDialog(parent)
{

	//this->dateTime=_datetime;
	this->label = new QLabel(tr("Value :"));
	this->labelUnit = new QLabel(tr("Unit :"));
	//this->addCycle = new QPushButton(tr("&+"));
	//this->addCycle->setCheckable(true);
	//this->addCycle->setEnabled(false);
	//this->removeCycle = new QPushButton(tr("&-"));
	//this->removeCycle->setEnabled(false);
	//connect(removeCycle,SIGNAL(clicked()),this,SLOT(remove_cycle()));
	//connect(addCycle,SIGNAL(clicked()),this,SLOT(add_cycle()));
	//this->_time=new QDateTimeEdit;
	//this->_time->setDisplayFormat("hh:mm:ss");
	this->valueBox = new QSpinBox;
	this->valueBox->setRange(0, 1000);
	this->valueBox->setValue(0);
	this->unitBox=new QComboBox;
	//this->_value=new QRadioButton("Fixed Value");
	//this->_cycle=new QRadioButton("Cycle Value");
	//_value->setChecked(true);
	this->label->setBuddy(valueBox);
	this->labelUnit->setBuddy(unitBox);
	this->title=new QLabel("                              Quantity Context");
	this->title->setStyleSheet("background-color: white;border-style: outset;border-width: 2px;border-color: beige;");
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Reset"));

	connect(unitBox,SIGNAL(activated(int)),labelUnit,SLOT(show()));
	connect(valueBox,SIGNAL(valueChanged(int)),this,SLOT(enabledOkButton(int)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	connect(cancelButton,SIGNAL(clicked()),this,SLOT(reset()));

	QHBoxLayout * topleftLayout1 = new QHBoxLayout;
	topleftLayout1->addWidget(label);
	topleftLayout1->addWidget(valueBox);
	QHBoxLayout * topleftLayout2 = new QHBoxLayout;
	topleftLayout2->addWidget(labelUnit);
	topleftLayout2->addWidget(unitBox);
	//QHBoxLayout * bottomLeftLayout = new QHBoxLayout;
	//bottomLeftLayout->addWidget(_value);
	//bottomLeftLayout->addWidget(_cycle);
	QVBoxLayout * topleftLayout= new QVBoxLayout;
	topleftLayout->addLayout(topleftLayout1);
	topleftLayout->addLayout(topleftLayout2);

	QVBoxLayout * leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topleftLayout);
	//leftLayout->addLayout(bottomLeftLayout);
	//extension = new QWidget;
	//connect(_cycle,SIGNAL(toggled(bool)),extension,SLOT(setVisible(bool)));
	//connect(_cycle,SIGNAL(toggled(bool)),this,SLOT(inactive_value(bool)));
	/*
	QGridLayout *extensionLayout = new QGridLayout;
	extensionLayout->setSizeConstraint(QLayout::SetFixedSize);
	extensionLayout->addWidget(_time,counter_row,0);
	QLabel * tmp_label = new QLabel(tr("value :"));
	//QLineEdit * tmp_text = new QLineEdit;
	QSpinBox * tmp_text = new QSpinBox;
	tmp_text->setRange(0, 1000);
	tmp_text->setValue(0);
	tmp_label->setBuddy(tmp_text);
	counter++;
	extensionLayout->addWidget(tmp_label,counter_row,1);
	counter++;
	extensionLayout->addWidget(tmp_text,counter_row,2);

	extension->setLayout(extensionLayout);
	//extension->setFixedHeight(sizeHint().height());
	*/
	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	//rightLayout->addWidget(this->addCycle);
	//rightLayout->addWidget(this->removeCycle);
	rightLayout->addStretch();
	QVBoxLayout * supermainLayout= new QVBoxLayout;
	supermainLayout->addWidget(this->title);

	//supermainLayout->setDirection(QBoxLayout::TopToBottom);

	QHBoxLayout * mainLayout = new QHBoxLayout;
	supermainLayout->addLayout(mainLayout);
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	//supermainLayout->addWidget(&m_TitleBar);

	//supermainLayout->setRowStretch(1, 1); // Put the title bar at the top of the window
	//mainLayout->addLayout(mainLayout);
	//supermainLayout->addWidget(extension);
	setLayout(supermainLayout);
	setWindowTitle(tr("freetext panel"));
	//connect(this,SIGNAL(WindowTitleChanged()),&m_TitleBar,SLOT(UpdateWindowTitle()));
	//setFixedHeight((sizeHint().height()));
	this->setStyleSheet("QDialog  { border-color: black; border-style: outset;border-width: 2px; color: red; height: 5px; background-color: rgb(210,233,234); }");
	setMaximumHeight(400);
	//extension->hide();
}
void QuantitativeParameter::reset(){
	this->valueBox->setValue(0);
	this->unitBox->clear();
	for(std::vector<QString>::iterator it=this->enume->begin();it!=this->enume->end();++it){
		this->unitBox->addItem((*it));
	}
}
void QuantitativeParameter::inactive_value(bool _CycleMode){
	if(_CycleMode){
		this->valueBox->setEnabled(false);
		this->addCycle->setEnabled(true);
		this->removeCycle->setEnabled(true);
	}
	else{
		this->valueBox->setEnabled(true);
		//this->addCycle->setEnabled(false);
		//this->removeCycle->setEnabled(false);
	}
}
void QuantitativeParameter::set_dateTime(QDateTime _datetime){
	this->dateTime=_datetime;
}
void QuantitativeParameter::enabledOkButton(int _tmp){
	this->okButton->setEnabled(true);
}
void  QuantitativeParameter::set_term(BasicTerm * _term){
	this->current_term=_term;
}

void           QuantitativeParameter::set_context(QString _context){
	this->context=_context;
}
/*
void QuantitativeParameter::setWindowTitle(const QString &title)
{
  QWidget::setWindowTitle(title);

  emit WindowTitleChanged();
}
*/


QString  QuantitativeParameter::get_context(){
	return this->context;
}
void QuantitativeParameter::add_cycle(){
	this->counter_row++;
	QLabel * tmp_label = new QLabel(tr("value :"));
	QSpinBox * tmp_text = new QSpinBox;
	tmp_text->setRange(0, 1000);
	tmp_text->setValue(0);
	connect(tmp_text,SIGNAL(valueChanged(int)),this,SLOT(enabledOkButton(int)));
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
void QuantitativeParameter::remove_cycle()
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
void QuantitativeParameter::OkClicked(){

	QString textunit;
	QString textvalue;
	//std::cerr << " OK CLICKED namespace : " << this->term->get_prototype()->get_namespacealias().toStdString() << std::endl;
	if(this->current_term->get_namespacealias()=="XEO_Positioning"){

	//if(this->term->get_prototype()->get_namespacealias()=="XEO_Positioning"){
		//std::cerr << "Xeopos Term" << std::endl;
		textunit= this->unitBox->currentText();
		textvalue = this->valueBox->text();
		Value * d = new Value();
		d->set_context(this->context);
		d->set_unit(textunit);
		//v->set_label();
		//d->set_label();
		d->set_value(textvalue);
		static_cast<VariableTerm*>(this->current_term)->add_value(d);

		//static_cast<VariableTerm*>(this->term->get_prototype())->add_value(d);
		std::cerr << "value added : " << textvalue.toStdString() <<" unit :" << textunit.toStdString() << std::endl;



	}
	else{
		textunit= this->unitBox->currentText();
		textvalue = this->valueBox->text();
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
					std::cerr << " modulo i : " << i << std::endl;

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
					std::cerr << "checkpoint 1 " << std::endl;
					//v->set_context(this->context);
					v->set_value(static_cast<QSpinBox*>(item2->widget())->text());
					std::cerr << "checkpoint 2 " << std::endl;


					std::cerr << "checkpoint 3 " << std::endl;

					c->add_cycleValue(std::make_pair(v,static_cast<QDateTimeEdit*>(item->widget())->dateTime()));


				}
			}
			c->set_timepoint(this->dateTime);
			c->set_context(this->context);
			c->set_unit(textunit);
			static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(c);
		}
		else{


			DynamicValue * v = new DynamicValue();
			v->set_is_cyclevalue(false);
			v->set_timepoint(this->dateTime);
			v->set_context(this->context);
			v->set_value(textvalue);
			v->set_unit(textunit);
			static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(v);

			//static_cast<DynamicTerm*>(this->term->get_prototype())->add_dynamicvalue(v);
		}
	}
	this->setEnabled(false);
}
void QuantitativeParameter::set_enumUnit(std::vector<QString> * _enume){

	this->enume=_enume;
	for(std::vector<QString>::iterator it=_enume->begin();it!=_enume->end();++it){
		this->unitBox->addItem((*it));
	}
}
