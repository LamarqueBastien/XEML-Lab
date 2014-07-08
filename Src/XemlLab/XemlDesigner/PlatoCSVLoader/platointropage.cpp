#include "platointropage.h"

PlatoIntroPage::PlatoIntroPage(QWidget *parent)
: QWizardPage(parent)
{
	setTitle(tr("Introduction"));
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
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);
	setLayout(layout);
}
int PlatoIntroPage::nextId() const
{
	std::cerr << "Next id" << std::endl;
	return PlatoWizard::Page_Data;
}
