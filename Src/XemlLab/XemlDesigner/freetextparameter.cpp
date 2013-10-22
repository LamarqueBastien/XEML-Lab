#include <QtGui>
#include "freetextparameter.h"

FreeTextParameter::FreeTextParameter(QDateTime _datetime,QWidget * parent)
: QDialog(parent)
{
	this->dateTime=_datetime;
	this->label = new QLabel(tr("value :"));
	//this->timelabel = new QLabel(tr("observation StartTime :"));
	this->textEdit = new QLineEdit;
	this->title=new QLabel("                              Free Text Context");
	this->title->setStyleSheet("background-color: white;border-style: outset;border-width: 2px;border-color: beige;");
	this->label->setBuddy(textEdit);
	//this->daytimeedit=new QDateTimeEdit();
	//this->daytimeedit->setDisplayFormat("dd.hh:mm:ss");
	//this->timelabel->setBuddy(daytimeedit);
	addCycle = new QPushButton(tr("&+"));
	this->addCycle->setEnabled(false);
	addCycle->setCheckable(true);
	removeCycle = new QPushButton(tr("&-"));
	this->removeCycle->setEnabled(false);
	//removeCycle->setCheckable(true);
	connect(removeCycle,SIGNAL(clicked()),this,SLOT(remove_cycle()));

	connect(addCycle,SIGNAL(clicked()),this,SLOT(add_cycle()));
	this->counter=0;
	this->counter_row=0;
	this->okButton =new QPushButton(tr("OK"));
	this->okButton->setCursor(Qt::PointingHandCursor);
	this->okButton->setDefault(true);
	this->okButton->setEnabled(false);
	this->cancelButton = new QPushButton(tr("Cancel"));
	this->cancelButton->setCursor(Qt::PointingHandCursor);
	_value=new QRadioButton("Fixed Value");
	_cycle=new QRadioButton("Cycle Value");
	_value->setChecked(true);
	this->_time=new QDateTimeEdit;
	this->_time->setDisplayFormat("hh:mm:ss");
	connect(textEdit,SIGNAL(textChanged(QString)),this,SLOT(enabledOkButton(QString)));
	connect(okButton,SIGNAL(clicked()),this,SLOT(OkClicked()));
	QVBoxLayout * supermainlayout=new QVBoxLayout;
	//QHBoxLayout * topLayout = new QHBoxLayout;
	QHBoxLayout * topleftLayout = new QHBoxLayout;
	topleftLayout->addWidget(label);
	topleftLayout->addWidget(textEdit);
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
	QLineEdit * tmp_text = new QLineEdit;
	tmp_label->setBuddy(tmp_text);
	counter++;
	extensionLayout->addWidget(tmp_label,counter_row,1);
	counter++;
	extensionLayout->addWidget(tmp_text,counter_row,2);

	extension->setLayout(extensionLayout);
	//extension->setFixedHeight(sizeHint().height());
	//extensionLayout->;

	QVBoxLayout * rightLayout = new QVBoxLayout;
	rightLayout->addWidget(this->cancelButton);
	rightLayout->addWidget(this->okButton);
	rightLayout->addWidget(this->addCycle);
	rightLayout->addWidget(this->removeCycle);
	rightLayout->addStretch();

	QHBoxLayout * mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	//topLayout->addWidget(timelabel);
	//topLayout->addWidget(daytimeedit);
	supermainlayout->addWidget(this->title);
	//supermainlayout->addLayout(topLayout);
	supermainlayout->addLayout(mainLayout);
	supermainlayout->addWidget(extension);
	setLayout(supermainlayout);
	//setWindowTitle(tr("freetext panel"));
	this->setWindowTitle("TEST2");
	setMaximumHeight(400);
	//setFixedHeight((sizeHint().height()));
	this->setStyleSheet("QDialog  { border-color: black; color: red;  border-style: outset;border-width: 2px;height: 5px;background-color: rgb(235,230,234); }");

	extension->hide();

}
void FreeTextParameter::set_dateTime(QDateTime _datetime){
	this->dateTime=_datetime;

}

void FreeTextParameter::inactive_value(bool _CycleMode){
	if(_CycleMode){
		this->textEdit->setEnabled(false);
		this->addCycle->setEnabled(true);
		this->removeCycle->setEnabled(true);
	}
	else{
		this->textEdit->setEnabled(true);
		this->addCycle->setEnabled(false);
		this->removeCycle->setEnabled(false);
	}
}

void FreeTextParameter::add_cycle(){
	this->counter_row++;
	QLabel * tmp_label = new QLabel(tr("value :"));
	QLineEdit * tmp_text = new QLineEdit;
	connect(tmp_text,SIGNAL(textChanged(QString)),this,SLOT(enabledOkButton(QString)));
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
void FreeTextParameter::remove_cycle()
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
void FreeTextParameter::enabledOkButton(QString _text){
	this->okButton->setEnabled(true);
}
void  FreeTextParameter::set_term(BasicTerm * _term){
	this->current_term=_term;
}



void           FreeTextParameter::set_context(QString _context){
	this->context=_context;
}

QString  FreeTextParameter::get_context(){
	return this->context;
}
void FreeTextParameter::OkClicked(){

	//this->okButton->setEnabled(true);
	std::cerr << "counter" << counter << std::endl;
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

				//v->set_context(this->context);
				v->set_value(static_cast<QLineEdit*>(item2->widget())->text());
				c->add_cycleValue(std::make_pair(v,static_cast<QDateTimeEdit*>(item->widget())->dateTime()));


			}

		}
		c->set_timepoint(this->dateTime);
		c->set_context(this->context);
		static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(c);

	}
	else{
		QString text= this->textEdit->text();
		DynamicValue * v = new DynamicValue();
		v->set_is_cyclevalue(false);
		v->set_timepoint(this->dateTime);
		v->set_context(this->context);
		v->set_value(text);
		//this->current_term->get_namespace()
		static_cast<DynamicTerm*>(this->current_term)->add_dynamicvalue(v);
	}

	//static_cast<DynamicTerm*>(this->term->get_prototype())->add_dynamicvalue(v);
	this->setEnabled(false);
}
