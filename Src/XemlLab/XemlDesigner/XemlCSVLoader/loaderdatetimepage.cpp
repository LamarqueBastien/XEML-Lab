#include <QtWidgets>
#include "Div/dragtimelabel.h"
#include "XemlCSVLoader/loaderdatetimepage.h"
LoaderDateTimePage::LoaderDateTimePage(int _column,int _row,QWidget *parent)
	: QWidget(parent)
{
	this->row=_row;
	this->column=_column;




	//std::cerr << _valueTest.toStdString()<< std::endl;

	//QString word="hello";
	/*
	QStringList list=_valueTest.split(" ");
	QString YearMonthDay=list.at(0);
	QString HourMinSec=list.at(1);
	QStringList listYearMonthDay=YearMonthDay.split("/");
	QStringList listHourMinSec=HourMinSec.split(":");
	DragTimeLabel * timeLabel1=new DragTimeLabel(listYearMonthDay.at(0),this);
	timeLabel1->setAttribute(Qt::WA_DeleteOnClose);
	DragTimeLabel * timeLabel2=new DragTimeLabel(listYearMonthDay.at(1),this);
	timeLabel2->setAttribute(Qt::WA_DeleteOnClose);
	DragTimeLabel * timeLabel3=new DragTimeLabel(listYearMonthDay.at(2),this);
	timeLabel3->setAttribute(Qt::WA_DeleteOnClose);
	DragTimeLabel * timeLabel4=new DragTimeLabel(listHourMinSec.at(0),this);
	timeLabel4->setAttribute(Qt::WA_DeleteOnClose);
	DragTimeLabel * timeLabel5=new DragTimeLabel(listHourMinSec.at(1),this);
	timeLabel5->setAttribute(Qt::WA_DeleteOnClose);
	DragTimeLabel * timeLabel6=new DragTimeLabel(listHourMinSec.at(2),this);
	timeLabel6->setAttribute(Qt::WA_DeleteOnClose);
	//DragTimeLabel * wordLabel = new DragTimeLabel(_valueTest, this);
	*/
	/*
	if (!word.isEmpty()) {
		DragTimeLabel * wordLabel = new DragTimeLabel(word, this);
		wordLabel->move(x, y);
		wordLabel->show();
		wordLabel->setAttribute(Qt::WA_DeleteOnClose);
		x += wordLabel->width() + 2;
		if (x >= 245) {
			x = 5;
			y += wordLabel->height() + 2;
		}
	}
	*/
	QVBoxLayout * mainlayout=new QVBoxLayout;
	//QGridLayout * dragandroplayout=new QGridLayout;
	//QVBoxLayout * leftlayout=new QVBoxLayout;
	//QVBoxLayout * middlelayout=new QVBoxLayout;
	//QVBoxLayout * rightlayout=new QVBoxLayout;
	/*
	this->year=new QLineEdit;
	this->yearLabel=new QLabel("Year");
	this->yearLabel->setBuddy(this->year);
	middlelayout->addWidget(yearLabel);
	middlelayout->addWidget(year);
	this->month=new QLineEdit;
	this->monthLabel=new QLabel("Month");
	this->monthLabel->setBuddy(this->month);
	middlelayout->addWidget(monthLabel);
	middlelayout->addWidget(month);
	this->day=new QLineEdit;
	this->dayLabel=new QLabel("Day");
	this->dayLabel->setBuddy(this->day);
	middlelayout->addWidget(dayLabel);
	middlelayout->addWidget(day);
	this->hour=new QLineEdit;
	this->hourLabel=new QLabel("Hour");
	this->hourLabel->setBuddy(this->hour);
	middlelayout->addWidget(hourLabel);
	middlelayout->addWidget(hour);
	this->minute=new QLineEdit;
	this->minuteLabel=new QLabel("Minute");
	this->minuteLabel->setBuddy(this->minute);
	middlelayout->addWidget(minuteLabel);
	middlelayout->addWidget(minute);
	this->second=new QLineEdit;
	this->secondLabel=new QLabel("Second");
	this->secondLabel->setBuddy(this->second);
	middlelayout->addWidget(secondLabel);
	middlelayout->addWidget(second);
	*/

	QHBoxLayout * combolayout=new QHBoxLayout;
	dateTimeDelimiter= new QLabel(tr("date Time delimiters:"));
	this->selectDateTimeDelimiter =new QComboBox;
	this->selectDateTimeDelimiter->addItem("YY/MM/DD HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("MM/DD/YY HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("MMM/DD/YY HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("YY/DD/MMMM HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("dd/MM/yyyy hh:mm:ss");
	this->selectDateTimeDelimiter->addItem("YY/MM/DD HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("DD/YY/MM HH:mm:ss");
	this->selectDateTimeDelimiter->addItem("YY/MM/DD HH:mm");
	this->selectDateTimeDelimiter->addItem("mm/DD/YY HH:mm");
	this->selectDateTimeDelimiter->addItem("MM/DD/YY HH:mm");
	this->selectDateTimeDelimiter->addItem("YY/DD/MM HH:mm");
	this->selectDateTimeDelimiter->addItem("DD/MM/YY HH:mm");
	this->selectDateTimeDelimiter->addItem("dd/MM/yyyy hh:mm");
	this->selectDateTimeDelimiter->addItem("DD/YY/MM HH:mm");

	/*
	leftlayout->addWidget(timeLabel1);
	leftlayout->addWidget(timeLabel2);
	leftlayout->addWidget(timeLabel3);
	leftlayout->addWidget(timeLabel4);
	leftlayout->addWidget(timeLabel5);
	leftlayout->addWidget(timeLabel6);
	*/
	combolayout->addWidget(dateTimeDelimiter);
	combolayout->addWidget(selectDateTimeDelimiter);
	//rightlayout->addLayout(combolayout);
	//rightlayout->addStretch();

	mainlayout->addLayout(combolayout);
	//mainlayout->addWidget(topLabel);
	//mainlayout->addStretch();

	QDialogButtonBox * button_Box = new QDialogButtonBox(QDialogButtonBox::Help,Qt::Horizontal);
	this->okButton=new QPushButton("OK");
	this->cancelButton=new QPushButton("Cancel");
	this->add_new_expression=new QPushButton("add your own expression");
	button_Box->addButton(this->okButton,QDialogButtonBox::ActionRole);
	button_Box->addButton(this->cancelButton,QDialogButtonBox::ActionRole);
	//button_Box->addButton(this->add_new_expression,QDialogButtonBox::ActionRole);

	//this->okButton->setEnabled(false);
	mainlayout->addWidget(button_Box);

	//rightlayout->addWidget(this->okButton);
	//rightlayout->addWidget(this->cancelButton);
	connect(button_Box,SIGNAL(helpRequested()),this,SLOT(show_help()));
	connect(this->okButton,SIGNAL(clicked()),this,SLOT(set_up_finished()));
	connect(this->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
	//connect(this->add_new_expression,SIGNAL(clicked()),this,SLOT(on_new_expression_added()));
	//dragandroplayout->addLayout(leftlayout,0,0);
	//dragandroplayout->addLayout(middlelayout,0,1);
	//dragandroplayout->addLayout(rightlayout,0,2);

	//mainlayout->addLayout(dragandroplayout);

	//setWindowFlags(Qt::WindowStaysOnTopHint);
	setAcceptDrops(true);
	setLayout(mainlayout);
	setMinimumSize(400,400);
	setWindowTitle(tr("Date time creator"));


}
void LoaderDateTimePage::on_new_expression_added(){
	QDialog * timedialog=new QDialog();
	QLineEdit * timeEdit=new QLineEdit("enter your expression");
	QDialogButtonBox * button_Box = new QDialogButtonBox(Qt::Horizontal);
	QPushButton *okButton=new QPushButton("OK");
	QPushButton *cancelButton=new QPushButton("Cancel");
	button_Box->addButton(okButton,QDialogButtonBox::ActionRole);
	button_Box->addButton(cancelButton,QDialogButtonBox::ActionRole);

	QVBoxLayout * layout= new QVBoxLayout;

	layout->addWidget(timeEdit);
	timedialog->setLayout(layout);
	timedialog->show();
}

void LoaderDateTimePage::show_help(){
			   QString  HtmlString(tr("<html>"
									  "<h2>example time format</h2>"
									  "<pre>dd      the day as number with a leading zero (01 to 31)</pre>"
									  "<pre>ddd     the abbreviated localized day name (e.g. 'Mon' to 'Sun')</pre>"
									  "<pre>dddd    the long localized day name (e.g. 'Monday' to 'Sunday')</pre>"
									  "<pre>M       the month as number without a leading zero (1-12)</pre>"
									  "<pre>MM      the month as number with a leading zero (01-12)</pre>"
									  "<pre>MMM     the abbreviated localized month name (e.g. 'Jan' to 'Dec')</pre>"
									  "<pre>MMMM    the long localized month name (e.g. 'January' to 'December')</pre>"
									  "<pre>yy      the year as two digit number (00-99)</pre>"
									  "<pre>yyyy    the year as four digit number</pre>"
									  "<pre>h       the hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)</pre>"
									  "<pre>hh      the hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)</pre>"
									  "<pre>H       the hour without a leading zero (0 to 23, even with AM/PM display)</pre>"
									  "<pre>HH      the hour with a leading zero (00 to 23, even with AM/PM display)</pre>"
									  "<pre>mm      the minute with a leading zero (00 to 59)</pre>"
									  "<pre>ss      the second with a leading zero (00 to 59)</pre>"
									  "<html/>"));
	QMessageBox::about(this,"Time helper",HtmlString);

}

void LoaderDateTimePage::set_up_finished(){
	emit delimitered_dateTime(this->column,this->row,this->selectDateTimeDelimiter->currentText());
	this->close();

}

void LoaderDateTimePage::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasText()) {
		if (event->source() == this) {
			event->setDropAction(Qt::MoveAction);
			event->accept();
		} else {
			event->acceptProposedAction();
		}
	} else {
		event->ignore();
	}
}

void LoaderDateTimePage::dropEvent(QDropEvent *event)
{
	if (event->mimeData()->hasText()) {
		const QMimeData *mime = event->mimeData();
		QStringList pieces = mime->text().split(QRegExp("\\s+"),
							 QString::SkipEmptyParts);
		QPoint position = event->pos();
		QPoint hotSpot;

		QList<QByteArray> hotSpotPos = mime->data("application/x-hotspot").split(' ');
		if (hotSpotPos.size() == 2) {
			hotSpot.setX(hotSpotPos.first().toInt());
			hotSpot.setY(hotSpotPos.last().toInt());
		}

		foreach (QString piece, pieces) {
			DragTimeLabel *newLabel = new DragTimeLabel(piece, this);
			newLabel->move(position - hotSpot);
			newLabel->show();
			newLabel->setAttribute(Qt::WA_DeleteOnClose);

			position += QPoint(newLabel->width(), 0);
		}

		if (event->source() == this) {
			event->setDropAction(Qt::MoveAction);
			event->accept();
		} else {
			event->acceptProposedAction();
		}
	} else {
		event->ignore();
	}
	foreach (QObject *child, children()) {
		if (child->inherits("QWidget")) {
			QWidget *widget = static_cast<QWidget *>(child);
			if (!widget->isVisible())
				widget->deleteLater();
		}
	}
}

void LoaderDateTimePage::mousePressEvent(QMouseEvent *event)
{
	QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
	if (!child)
		return;

	QPoint hotSpot = event->pos() - child->pos();

	QMimeData *mimeData = new QMimeData;
	mimeData->setText(child->text());
	mimeData->setData("application/x-hotspot",
					  QByteArray::number(hotSpot.x()) + " " + QByteArray::number(hotSpot.y()));

	QPixmap pixmap(child->size());
	child->render(&pixmap);

	QDrag *drag = new QDrag(this);
	drag->setMimeData(mimeData);
	drag->setPixmap(pixmap);
	drag->setHotSpot(hotSpot);

	Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

	if (dropAction == Qt::MoveAction)
		child->close();
}
