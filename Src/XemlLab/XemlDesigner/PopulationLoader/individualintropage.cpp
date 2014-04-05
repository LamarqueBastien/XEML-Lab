#include "individualintropage.h"

IndividualIntroPage::IndividualIntroPage(QWidget *parent)
: QWizardPage(parent)
{
	topLabel = new QLabel(tr("This wizard will help you define your population for this specific germplasm "));
	topLabel->setWordWrap(true);
	bottomLabel = new QLabel(tr("check the box if you want to import individuals from file else choose the number of individuals you want to use (individual are randomly created)"));
	import_from_files=new QCheckBox("import from tabular file (csv, xls)");
	import_from_files->setCheckState(Qt::Unchecked);


	this->ind_box=new QSpinBox;
	this->ind_label=new QLabel("individuals #");
	this->ind_label->setBuddy(this->ind_box);
	connect(this->ind_box,SIGNAL(valueChanged(int)),this,SLOT(on_value_changed(int)));


	QHBoxLayout * layout_h= new QHBoxLayout;
	layout_h->addWidget(import_from_files);
	layout_h->addWidget(ind_label);
	layout_h->addWidget(ind_box);


	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(topLabel);

	layout->addWidget(bottomLabel);
	layout->addLayout(layout_h);
	layout->addStretch(1);
	setLayout(layout);
	setWindowTitle("defines population for specific pool ");
}
void IndividualIntroPage::on_value_changed(int _value){
	IndividualWizard::set_individual_count(_value);

}

int IndividualIntroPage::nextId() const
{
	//std::cerr << "Next id" << std::endl;
	if (this->import_from_files->isChecked()){
		return IndividualWizard::Page_ImportFile;
	}
	else{
		std::cerr << "individual = " << this->ind_box->value() << std::endl;
		return IndividualWizard::Page_Creation;
	}

}
