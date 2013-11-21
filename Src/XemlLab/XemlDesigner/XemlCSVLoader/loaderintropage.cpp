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

	topLabel = new QLabel(tr("This wizard will help you to fill a  "
								 "<i>Xeml</i> files from a <i>CSV</i> file "));
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
