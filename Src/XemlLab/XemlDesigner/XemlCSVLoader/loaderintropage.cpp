#include "loaderintropage.h"


LoaderIntroPage::LoaderIntroPage(QWidget *parent)
: QWizardPage(parent)
{

	setTitle(tr("Introduction"));



	//QStringList  * testList=new QStringList;
	//testList->append("H1");
	//testList->append("H2");
	//testList->append("H3");
	//listView=new QListView;
	//QStringListModel * testModel = new QStringListModel((*testList));

	//this->listView->setSelectionMode(QAbstractItemView::MultiSelection);
	//this->listView->setModel(testModel);



	//setPixmap(QWizard::WatermarkPixmap, QPixmap(":/images/watermark.png"));

	topLabel = new QLabel(tr("<html>This wizard will help you to fill a  "
							 "<i>Xeml</i> files from a <i>CSV</i> file"
							 "<h2>example csv file</h2>"
							 "<ul>"
							 "<li>text delimiter : \"</li>"
							 "<li>data delimiter : ,</li>"
							 "</ul>"
							 "<pre>\"TimeHeader\",\"headerData_1\",\"HeaderData_2\"....,\"HeaderData_n\"</pre>"
							 "<pre>\"Time_Value\",\"value_Data_1\",\"value_Data_2\"....,\"Value_Data_n\"</pre>"
							 "<pre>\"Time_Value\",\"value_Data_1\",\"value_Data_2\"....,\"Value_Data_n\"</pre>"
							 "<pre>\"Time_Value\",\"value_Data_1\",\"value_Data_2\"....,\"Value_Data_n\"</pre>"
							 "<br/>"
							 "<img src=\"://Images/red-warning.jpg\" align=\"left\" width=\"30\" height=\"30\" /> you need to have at least one column for time value<blink></html>"));
	topLabel->setWordWrap(true);

	//registerRadioButton = new QRadioButton(tr("&Register your copy"));
	//evaluateRadioButton = new QRadioButton(tr("&Evaluate the product for 30 "
												  //"days"));
	//registerRadioButton->setChecked(true);
	//qRegisterMetaType<QItemSelectionModel*>("QItemSelectionModel*");
	//registerField("listViewSelection", this, "selectionModel");
	QVBoxLayout *layout = new QVBoxLayout;
	//layout->addWidget(this->listView);
	layout->addWidget(topLabel);
	//layout->addWidget(registerRadioButton);
	//layout->addWidget(evaluateRadioButton);
	setLayout(layout);
}
int LoaderIntroPage::nextId() const
{
	std::cerr << "Next id" << std::endl;
	return LoaderWizard::Page_DataFile;
}
