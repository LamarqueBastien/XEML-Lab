#include "platodatapage.h"

PlatoDataPage::PlatoDataPage(ItfDocument * _xeml_doc, QWidget *parent)
	: QWizardPage(parent)
{
	this->xeml_doc=_xeml_doc;
	setTitle(tr("build XEML Skeleton from <i>CSV files</i>&trade;"));
	setSubTitle(tr("Please choose a csv file. Make sure to provide a valid "
					   "file path (e.g., Path/to/file.extensionfiles) "
				   "then select the header you want to keep to continue"));

	Filename = new QLabel(tr("F&ilename:"));
	FilenameLineEdit = new QLineEdit;
	FilenameLineEdit->setValidator(new QRegExpValidator(QRegExp("(.+\/)+(.*[+*$^.?]?.*)(\\..+)"), this));
	this->headerview=new QTableView;
	//this->headerview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->model = new QStandardItemModel(this);
	this->headerview->setSelectionMode(QAbstractItemView::MultiSelection);
	this->headerview->setModel(this->model);
	Filename->setBuddy(FilenameLineEdit);
	browseButton =new QPushButton("Browse");
	browseButton->setDefault(true);
	loadButton =new QPushButton("Load");
	loadButton->setDefault(false);
	ShowXemlButton =new QPushButton("Show Xeml Code");
	ShowXemlButton->setDefault(false);
	connect(this->browseButton,SIGNAL(clicked()),this,SLOT(open_file()));
	connect(this->loadButton,SIGNAL(clicked()),this,SLOT(load_file()));
	connect(this->ShowXemlButton,SIGNAL(clicked()),this,SLOT(show_xeml_code()));
	//connect(this->FilenameLineEdit,SIGNAL(),this->loadButton,SLOT(setEnabled(bool))
	dataDelimiter= new QLabel(tr("data delimiters:"));
	this->selectDataDelimiter =new QComboBox;
	//connect(selectDataDelimiter,SIGNAL(activated(int)),dataDelimiter,SLOT(show()));
	this->selectDataDelimiter->addItem(",");
	this->selectDataDelimiter->addItem("/");
	this->selectDataDelimiter->addItem(";");
	this->selectDataDelimiter->addItem(" ");


	textDelimiter= new QLabel(tr("text delimiters:"));
	this->selectTextDelimiter =new QComboBox;
	//connect(selectTextDelimiter,SIGNAL(activated(int)),textDelimiter,SLOT(show()));

	this->selectTextDelimiter->addItem("\"");
	this->selectTextDelimiter->addItem("\'");
	this->selectTextDelimiter->addItem("");
	registerField("FileName*", FilenameLineEdit);
	qRegisterMetaType<QItemSelectionModel*>("QItemSelectionModel*");
	registerField("headerViewSelection", this, "selectionModel");

	//registerField("DataDelimiter*", selectDataDelimiter);
	//registerField("TextDelimiter*", selectTextDelimiter);

	QDialogButtonBox * browseAndLoadBox=new QDialogButtonBox(Qt::Horizontal);

	browseAndLoadBox->addButton(this->loadButton,QDialogButtonBox::ActionRole);
	browseAndLoadBox->addButton(this->browseButton,QDialogButtonBox::ActionRole);
	browseAndLoadBox->addButton(this->ShowXemlButton,QDialogButtonBox::ActionRole);


	QGroupBox *groupBox = new QGroupBox(tr("data delimiter selection"));
	QHBoxLayout * hlayout1=new QHBoxLayout;
	hlayout1->addWidget(dataDelimiter);
	hlayout1->addWidget(selectDataDelimiter);
	QHBoxLayout * hlayout2=new QHBoxLayout;
	hlayout2->addWidget(textDelimiter);
	hlayout2->addWidget(selectTextDelimiter);
	QVBoxLayout * boxLayout = new QVBoxLayout;
	boxLayout->addLayout(hlayout1);
	boxLayout->addLayout(hlayout2);
	boxLayout->addStretch(1);
	groupBox->setLayout(boxLayout);

	QGroupBox *groupBoxFile = new QGroupBox(tr("file selection"));
	QHBoxLayout * hlayout3=new QHBoxLayout;
	hlayout3->addWidget(Filename);
	hlayout3->addWidget(FilenameLineEdit);


	QVBoxLayout * boxLayoutFile = new QVBoxLayout;
	boxLayoutFile->addLayout(hlayout3);
	boxLayoutFile->addWidget(browseAndLoadBox);
	boxLayoutFile->addStretch(1);
	groupBoxFile->setLayout(boxLayoutFile);


	QGroupBox *groupBoxHeader = new QGroupBox(tr("header selection"));
	QVBoxLayout * boxLayoutHeader = new QVBoxLayout;
	boxLayoutHeader->addWidget(headerview);
	groupBoxHeader->setLayout(boxLayoutHeader);


	//QHBoxLayout * hlayout=new QHBoxLayout;
	//hlayout->addWidget(Filename);
	//hlayout->addWidget(FilenameLineEdit);
	//hlayout->addWidget(browseButton);
	//hlayout->addWidget(loadButton);
	QVBoxLayout * mainlayout=new QVBoxLayout;

	QGridLayout *layout = new QGridLayout;


	layout->addWidget(groupBox, 0, 0,1,8);
	layout->addWidget(groupBoxFile, 1, 0,1,8);
	layout->addWidget(groupBoxHeader, 2, 0,1,8);
	//layout->addWidget(browseAndLoadBox,1,0,1,8);

	//layout->addWidget(selectDataDelimiter, 1, 1);
	//layout->addWidget(textDelimiter, 2, 0);
	//layout->addWidget(selectTextDelimiter, 2, 1);
	//mainlayout->addLayout(hlayout);
	mainlayout->addLayout(layout);
	//mainlayout->addWidget(headerview);
	setLayout(mainlayout);

}
void PlatoDataPage::open_file(){
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
void PlatoDataPage::show_xeml_code(){
	XemlCodeEditor * code_edit= new XemlCodeEditor(static_cast<XemlDocument*>(this->xeml_doc)->generate_string_xml());
	code_edit->show();
}

void PlatoDataPage::load_file(){
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
		if(!PlatoWizard::get_plant_data()->empty()){
			PlatoWizard::get_plant_data()->clear();
		}
		tmpvec=PlatoWizard::get_plant_data();

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
					missingValues+="missing value line : "+QString::number(count_row+1)+"-";
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
				//std::cerr << "end of line" << std::endl;
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

	validated=true;
	if(!validated){
		QMessageBox msgBox;
		msgBox.setModal(true);

		//msgBox.setWindowFlags(Qt::WindowStaysOnTopHint);
		msgBox.setWindowTitle("Loader Wizard missing values");
		msgBox.setText(missingValues+"Do you want to keep this datafile ? ");
		msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
		msgBox.setDefaultButton(QMessageBox::No);
		msgBox.show();
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
bool PlatoDataPage::checkForDelimiters(int _count_line,QString &_word, QString _dataDelimiter,QString _textDelimiter,QChar character){

	//std::cerr << "line : " << _count_line << " word : " << _word.toStdString() << std::endl;
	_word.clear();
	//std::cerr << " character : " << character << " data delimiter : " << _dataDelimiter << " text delimiter : " << _textDelimiter << std::endl;
	//if(QRegExp(\\"|\\'.*\\"|\\')->exactMatch(_line)){

	return true;
}
void PlatoDataPage::process_line(const QString &)
{

}
int PlatoDataPage::nextId() const
{
	//std::cerr << "Next id" << std::endl;

	return PlatoWizard::Page_ParamSet;
}
