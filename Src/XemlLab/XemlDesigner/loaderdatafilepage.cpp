#include "loaderdatafilepage.h"

LoaderDataFilePage::LoaderDataFilePage(QWidget *parent)
	: QWizardPage(parent)
{
	setTitle(tr("Evaluate <i>CSV files</i>&trade;"));
	setSubTitle(tr("Please choose a csv file. Make sure to provide a valid "
					   "file path (e.g., Path/to/file.extensionfiles)."
				   "then select the header you want to keep to continue"));

	Filename = new QLabel(tr("F&ilename:"));
	FilenameLineEdit = new QLineEdit;
	FilenameLineEdit->setValidator(new QRegExpValidator(QRegExp("(.+\/)+(.*[+*$^.?]?.*)(\\..+)"), this));
	this->headerview=new QTableView;
	this->model = new QStandardItemModel(1,1,this);
	this->headerview->setSelectionMode(QAbstractItemView::MultiSelection);
	this->headerview->setModel(this->model);
	Filename->setBuddy(FilenameLineEdit);
	browseButton =new QPushButton("Browse");
	browseButton->setDefault(true);
	loadButton =new QPushButton("Load");
	browseButton->setDefault(false);
	connect(this->browseButton,SIGNAL(clicked()),this,SLOT(open_file()));
	connect(this->loadButton,SIGNAL(clicked()),this,SLOT(load_file()));
	//connect(this->FilenameLineEdit,SIGNAL(),this->loadButton,SLOT(setEnabled(bool))
	dataDelimiter= new QLabel(tr("data delimiters:"));
	this->selectDataDelimiter =new QComboBox;
	//connect(selectDataDelimiter,SIGNAL(activated(int)),dataDelimiter,SLOT(show()));
	this->selectDataDelimiter->addItem(",");
	this->selectDataDelimiter->addItem("/");

	textDelimiter= new QLabel(tr("text delimiters:"));
	this->selectTextDelimiter =new QComboBox;
	//connect(selectTextDelimiter,SIGNAL(activated(int)),textDelimiter,SLOT(show()));

	this->selectTextDelimiter->addItem("\"");
	this->selectTextDelimiter->addItem("\'");
	registerField("FileName*", FilenameLineEdit);
	qRegisterMetaType<QItemSelectionModel*>("QItemSelectionModel*");
	registerField("headerViewSelection", this, "selectionModel");

	//registerField("DataDelimiter*", selectDataDelimiter);
	//registerField("TextDelimiter*", selectTextDelimiter);
	QHBoxLayout * hlayout=new QHBoxLayout;
	hlayout->addWidget(Filename);
	hlayout->addWidget(FilenameLineEdit);
	hlayout->addWidget(browseButton);
	hlayout->addWidget(loadButton);
	QVBoxLayout * mainlayout=new QVBoxLayout;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(Filename, 0, 0);
	layout->addWidget(browseButton, 0, 1);
	layout->addWidget(FilenameLineEdit, 0, 2);
	layout->addWidget(loadButton, 0, 3);
	layout->addWidget(dataDelimiter, 1, 0);
	layout->addWidget(selectDataDelimiter, 1, 1);
	layout->addWidget(textDelimiter, 2, 0);
	layout->addWidget(selectTextDelimiter, 2, 1);
	mainlayout->addLayout(hlayout);
	mainlayout->addLayout(layout);
	mainlayout->addWidget(headerview);
	setLayout(mainlayout);
}
void LoaderDataFilePage::process_line(const QString &)
{

}
void LoaderDataFilePage::open_file(){
	//QStringList * tmplist=new QStringList;


	/*
	QModelIndexList * indexlist=new QModelIndexList;
	(*indexlist)=static_cast<QItemSelectionModel*>(field("listViewSelection").value<QItemSelectionModel*>())->selectedRows();
	for (int i=0;i<indexlist->size();i++){
		std::cerr << indexlist->at(i).data().toString().toStdString() << std::endl;
	}
	*/



	//(*tmplist)=static_cast<QItemSelectionModel*>(field("listViewSelection").value<QItemSelectionModel*>())->currentIndex().data().toStringList();
	//(*tmplist)=field("listViewSelection").toStringList();
	//for (int i=0;i<tmplist->size();i++){
	//	std::cerr << tmplist->at(i).toStdString() << std::endl;
	//}
	//std::cerr << "listsize : "<< tmplist->size() << std::endl;
	//std::cerr << "row count : "<< static_cast<QItemSelectionModel*>(field("listViewSelection").value<QItemSelectionModel*>())->model()->rowCount()<<std::endl;

	this->FilenameLineEdit->setText(QFileDialog::getOpenFileName(this,tr("open csv files"),"\\/",tr("csv files (*.csv)\n")));
}


//bool LoaderDataFilePage::validatePage(){
//	emit data_loaded(tmpvec);
//}



int LoaderDataFilePage::nextId() const
{
	//std::cerr << "Next id" << std::endl;

	return LoaderWizard::Page_ParamSet;
}

void LoaderDataFilePage::load_file(){
	QString fileName = this->FilenameLineEdit->text();
			//QFileDialog::getOpenFileName(this,tr("open csv files"),"\\/",tr("csv files (*.csv)\n"));
	bool validated=true;
	QString missingValues;
	if (!fileName.isEmpty()) {
		int count_row=0;
		size_t count_column=0;

		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			return;
		QString data = file.readAll();
		//registerField("Data*",data);
		data.remove(QRegExp("\r"));//remove all occurrences of carriage return

		QString word;
		QChar character;
		QTextStream in(&data);
		//tmpvec=new std::vector<std::vector<QString> *>();
		if(!LoaderWizard::get_CSV_data()->empty()){
			LoaderWizard::get_CSV_data()->clear();
		}
		tmpvec=LoaderWizard::get_CSV_data();

		while (!in.atEnd()) {
			in >> character;
			//std::cerr << character.toLatin1() << std::endl;
			if(character == this->selectDataDelimiter->currentText().toStdString().at(0)){

				if(count_row==0){
					tmpvec->push_back(new std::vector<QString>());
				}
				//std::cerr << " column : " << count_column << std::endl;
				if(word==""){
					//std::cerr << "empty word" << std::endl;
					validated=false;
					missingValues+="missing value line : "+QString::number(count_row+1)+"\n";
				}
				word.remove(QRegExp("^"+this->selectTextDelimiter->currentText()));
				word.remove(QRegExp(this->selectTextDelimiter->currentText()+"$"));
				if(count_row==0){
					QString headerTitle=QString("Header%1").arg(count_column+1);
					this->model->setHorizontalHeaderItem(count_column,new QStandardItem(headerTitle));
					this->model->setItem(0,count_column,new QStandardItem(word));
				}
				//std::cerr << "word : " << word.toStdString() << std::endl;
				tmpvec->at(count_column)->push_back(word);
				//QString initial = "Ceci est le texte à sérialiser";
				QString final = "";
				//QVariant chaine_serialise;
				//chaine_serialise.setValue(word);
				//final = chaine_serialise.value<QString>();
				//std::cerr << word.toStdString()<<endl;
				word.clear();
				//checkForDelimiters(count_row,word, this->selectDataDelimiter->currentText(),this->selectTextDelimiter->currentText(),character);
				count_column++;
			}
			else if(character == '\n'){
				std::cerr << "end of line" << std::endl;
				if(count_row==0){
					tmpvec->push_back(new std::vector<QString>());
					word.remove(QRegExp("^"+this->selectTextDelimiter->currentText()));
					word.remove(QRegExp(this->selectTextDelimiter->currentText()+"$"));
					QString headerTitle=QString("Header%1").arg(count_column+1);
					this->model->setHorizontalHeaderItem(count_column,new QStandardItem(headerTitle));
					this->model->setItem(0,count_column,new QStandardItem(word));

					//size_controler=count_column+1;
				}
				//std::cerr << " column : " << count_column << "size controller : "<< size_controler <<  std::endl;
				if(word.size()==0){
					validated=false;
					missingValues+="missing value line"+QString::number(count_row+1)+"\n";

				}
				//checkForDelimiters(count_row,word, this->selectDataDelimiter->currentText(),this->selectTextDelimiter->currentText(),character);
				//if (count_column<size_controler){
				//	std::cerr << "a value is missing in line :" << count_row << std::endl;
				//}
				word.remove(QRegExp("^"+this->selectTextDelimiter->currentText()));
				word.remove(QRegExp(this->selectTextDelimiter->currentText()+"$"));
				tmpvec->at(count_column)->push_back(word);
				word.clear();
				count_row++;
				count_column=0;


			}
			else if(in.atEnd()){
				word.append(character);
				//checkForDelimiters(count_row,word, this->selectDataDelimiter->currentText(),this->selectTextDelimiter->currentText());
				tmpvec->at(count_column)->push_back(word);
				word.clear();

			}
			else{
				word.append(character);
			}
		}
		std::cerr << "size : " << tmpvec->at(0)->size() << std::endl;



		/*QString line = in.readLine();
		int count_line=0;
		while (!line.isNull()) {
			process_line(line);
			line = in.readLine();
			count_line++;

			if(checkForDelimiters(count_line,line, this->selectDataDelimiter->currentText(),this->selectTextDelimiter->currentText())){

			}
			else{
				QMessageBox::information(this, tr("Loader Wizard Bad file format"), tr("bad file format"));


			}

		}
		*/

	}
	else{
		QMessageBox msgBoxNofile;
		msgBoxNofile.setWindowTitle("Loader Wizard no file to load");
		msgBoxNofile.setText("Add a file to load");
	}

	if(!validated){
		QMessageBox msgBox;
		msgBox.setWindowTitle("Loader Wizard missing values");
		msgBox.setText(missingValues+"Do you want to keep this datafile ? ");
		msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
		msgBox.setDefaultButton(QMessageBox::No);
		if(msgBox.exec() == QMessageBox::Yes){
			this->FilenameLineEdit->setText(fileName);

		}else {
			tmpvec->clear();



		}
		/*
		QMessageBox::information(this, tr("Loader Wizard missing values at line"), tr(missingValues.toStdString().c_str()));
		//QMessageBox::question(this,tr("Loader Wizard missing values at line"),tr("Do you want to keep this datafile ? ",QMessageBox::Yes|QMessageBox::No));
		if (QMessageBox::Yes == QMessageBox::question(this, "Loader Wizard missing values at line", "Do you want to keep this datafile ? ", QMessageBox::Yes|QMessageBox::No)){
			this->FilenameLineEdit->setText(fileName);

		}
		else{
			tmpvec=new std::vector<std::vector<QString> *>();
		}
		*/


	}
	else{

		//this->FilenameLineEdit->setText(fileName);
	}

}
bool LoaderDataFilePage::checkForDelimiters(int _count_line,QString &_word, QString _dataDelimiter,QString _textDelimiter,QChar character){

	//std::cerr << "line : " << _count_line << " word : " << _word.toStdString() << std::endl;
	_word.clear();
	//std::cerr << " character : " << character << " data delimiter : " << _dataDelimiter << " text delimiter : " << _textDelimiter << std::endl;
	//if(QRegExp(\\"|\\'.*\\"|\\')->exactMatch(_line)){

	return true;
}

