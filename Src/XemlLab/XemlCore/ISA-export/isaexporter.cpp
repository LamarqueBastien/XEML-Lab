#include "isaexporter.h"

IsaExporter::IsaExporter(QUuid _xemlId,QString _connectionString)
{
	//QProcess gzip;
	//gzip.start();
	this->xemlId=_xemlId;
	this->connectionString=_connectionString;
	OntologyBase::set_connection_string(_connectionString);

}
std::vector<QString> * IsaExporter::encapsulate(std::vector<QString> * l){

}

std::vector<QString> * IsaExporter::encapsulate(QString encap_char,std::vector<QString> * l){

}

QString IsaExporter::encapsulate(QString _s){

}

QStringList * IsaExporter::encapsulate(QStringList * _s){

}

QStringList * IsaExporter::encapsulate(QString encap_char,QStringList * _s){

}

QString IsaExporter::escape(QString _s){

}

void IsaExporter::add_chromatogram_file(QString _filename,QTextStream _infile){

}

void IsaExporter::write(XemlDataSet * _xds,QTextStream _outStream){

}

