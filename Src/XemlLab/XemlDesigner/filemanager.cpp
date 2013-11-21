#include "filemanager.h"

class ItfDocument;
//class XemlDocument;

FileManager::FileManager()
{
	//InitDirectory() fonction à vérifier
	current_XemlDoc =NULL;
}
QString FileManager::LoadXemlCodeFromFile(QFile * _xeml_doc){
	_xeml_doc->open(QIODevice::ReadOnly);
	QTextStream MonFichier(_xeml_doc);
	QString text;
	QString finaltext;
	while(!MonFichier.atEnd())
	{
		MonFichier >> text;
		finaltext+=text;
	}
	
	return finaltext;
}

void FileManager::New(){
	std::cerr<<" \ncreating new document \n";
	//try
	//{
		if (this->current_XemlDoc !=NULL){
			std::cerr << "failed created document, current document already exists" << std::endl;
		}

		
		/*
#if defined(Q_OS_WIN)
									   this->filePath= "C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#elif defined(Q_OS_MACX)
									   this->filePath="://XEMLStore/Templates/Standard.xeml";///Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";///Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml
#else
									   this->filePath="/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
#endif
*/
		
		
		
		//this->filePath= "C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
		//:/template/XEMLStore/Templates/Standard.xeml";
		//this->filePath="/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";
		//Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEMLStore/Templates/Standard.xeml";  
		//Users/benjamindartigues/cosmos/XemlLab/XemlDesigner 
		//HOME+"XemlInteractiveDesigner/XEMLStore/Templates/Standard.xeml";
		//="/Users/benjamindartigues/Qt5.0.1/Root/XemlInteractiveDesigner/XEMLStore/Templates/Standard.xeml";
		//std::cerr <<"templatefilepath" << this->filePath << std::endl;

		this->filePath="://XEMLStore/Templates/Standard.xeml";
		QDir::setSearchPaths("templates", QStringList("://XEMLStore/Templates"));
		QFile file(filePath);
		
		// On ouvre notre fichier en lecture seule et on vérifie l'ouverture
		if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
			LoadFile(this->filePath,true);
		}
		else{
			std::cerr << "failed to load file" << std::endl;
		}

		//if(fopen(this->filePath.toStdString().c_str(),"r")!=NULL){
			//LoadFile(this->filePath,true);
		//}


			/*
	}
	catch (exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	*/

}
void FileManager::LoadFile(QString path,bool asTemplate){

	try
	{
		QFile _xeml_doc(path.toStdString().c_str());

		if(_xeml_doc.exists()){
			LoadDocument(&_xeml_doc,asTemplate);
		}
		else{
			std::cerr << "File " + _xeml_doc.fileName().toStdString()+ " not Found" << std::endl;
		}
	}
	catch(exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}

void FileManager::LoadDocument(QFile * _xeml_doc,bool asTemplate){
	try
	{
		if(this->current_XemlDoc!=NULL){
			std::cerr << "xemldoc already existing" << std::endl;

			//évenement de validation otés.
		}
		if(asTemplate){


			this->current_XemlDoc=new Xeml::Document::XemlDocument();
			QString tmp(this->filePath.toStdString().c_str());
			SetXemlCode(tmp,asTemplate,false, false);
		}
		else{
			this->current_XemlDoc=new Xeml::Document::XemlDocument();
			QString tmp(_xeml_doc->fileName());
			SetXemlCode(tmp,asTemplate,false,false);
		}

	}
	catch(exception ex)
	{
		std::cerr << ex.what() << std::endl;
	}

}
void FileManager::SetXemlCode(QString path, bool asTemplate, bool raiseSomethingChangedEvent, bool doValidation)
{
	this->current_XemlDoc->Load(path,asTemplate);
}
Xeml::Document::Contracts::ItfDocument * FileManager::get_current_xeml(){
	return this->current_XemlDoc;
}
void                                    FileManager::purgedetailsFromdocument(){
	static_cast<XemlDocument*>(this->current_XemlDoc)->purge();
}




