#include "individualconclusionpage.h"

IndividualConclusionPage::IndividualConclusionPage(QWidget *parent)
	:QWizardPage(parent)
{
	topLabel = new QLabel(tr("click to finalize the new pool germplasm "));
	topLabel->setWordWrap(true);

	this->table= new QTableView;
	this->model=new QStandardItemModel(1,1,this);
	this->model->setHorizontalHeaderItem(0, new QStandardItem(QString("IndividualsId")));


	this->table->setModel(this->model);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(this->table);
	layout->addWidget(topLabel);

	setLayout(layout);

}
void IndividualConclusionPage::initializePage(){
	//this->indexlist=new QModelIndexList;
	//(*indexlist)=static_cast<QItemSelectionModel*>(field("headerViewSelection2").value<QItemSelectionModel*>())->selectedColumns();
	//for (int i=0;i<indexlist->size();i++){

	//}
	for (int j =1;j<IndividualWizard::get_CSV_data()->at(0)->size();j++){
		std::cerr << "vector size" << IndividualWizard::get_CSV_data()->at(0)->size() << std::endl;
		std::cerr << IndividualWizard::get_CSV_data()->at(0)->at(j).toStdString() << std::endl;
		//this->model->findItems("IndividualsId",Qt::MatchFixedString | Qt::MatchRecursive)[0]->appendRow(new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));

		this->model->setItem(j-1,0,new QStandardItem(IndividualWizard::get_CSV_data()->at(0)->at(j)));


	}

}

int IndividualConclusionPage::nextId() const
{
	return -1;
}
