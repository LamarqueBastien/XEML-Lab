#include "observationgenotypepage.h"

ObservationGenotypePage::ObservationGenotypePage(StoryNode * _root,QWidget *parent)
	: QWizardPage(parent)
{
	genList=new QStringList;
	//std::cerr << "entering new genotype page" << std::endl;
	for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(_root->get_story())->get_individualspoolcollection()->begin();it!= static_cast<Story*>(_root->get_story())->get_individualspoolcollection()->end();++it){
		genList->append((*it).second);
	}
	if (genList->empty()){
		int r = QMessageBox::warning(this, tr("XemlDocument"),
		tr("No pool germplasm for this story.\n"
		   "You need to add a genotype to the root Story"),
		QMessageBox::Ok | QMessageBox::Default);
		if (r == QMessageBox::Ok) {
			this->close();
		}
	}
	setTitle(tr("Class Information"));
	setSubTitle(tr("Select by double-clicking one genotype to associate with your samples "));

	//genList=new QStringList;
	//std::cerr << "genlist created" << std::endl;

	//genList->append("Arabidhopsis");
	//genList->append("Espagne");
	//genList->append("Italie");
	//ObservationWizard::

	//std::cerr << "before creating gene model" << std::endl;

	this->germPlasm =new QLabel("Germplasm");
	this->germPlasmEdit =new QLineEdit();
	this->germPlasm->setBuddy(this->germPlasmEdit);

	//std::cerr << "before creating gene model" << std::endl;
	this->genModel = new QStringListModel((*genList));
	//std::cerr << "after creating gene model" << std::endl;
	this->genView= new QListView;
	genView->setModel(this->genModel);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(this->genView);
	QHBoxLayout * bottomLayout = new QHBoxLayout;
	bottomLayout->addWidget(this->germPlasm);
	bottomLayout->addWidget(this->germPlasmEdit);
	layout->addLayout(bottomLayout);
	setLayout(layout);
	connect(this->genView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(validate(QModelIndex)));
	registerField("GermPlasm*", this->germPlasmEdit);


}
void ObservationGenotypePage::validate(QModelIndex _QMI){
		QVariant selectedElement = this->genModel->data(_QMI, Qt::DisplayRole);
		this->germPlasmEdit->setText(selectedElement.toString());
}
