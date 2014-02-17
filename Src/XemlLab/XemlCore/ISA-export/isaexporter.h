#ifndef ISAEXPORTER_H
#define ISAEXPORTER_H
#include<map>
#include<vector>
#include<zlib.h>
#include<QTextStream>
#include<QStringBuilder>
#include"DataSet/xemldataset.h"
#include"ISA-export/Ontology/ontologybase.h"

#include<QUuid>



using namespace std;

class IsaExporter
{
	public:
		IsaExporter(QUuid _xemlId,QString _connectionString);
		static std::vector<QString> * encapsulate(std::vector<QString> * l);
		static std::vector<QString> * encapsulate(QString encap_char,std::vector<QString> * l);
		static QString encapsulate(QString _s);
		static QStringList * encapsulate(QStringList * _s);
		static QStringList * encapsulate(QString encap_char,QStringList * _s);
		static QString escape(QString _s);
		void add_chromatogram_file(QString _filename,QTextStream _infile);
		void write(XemlDataSet * _xds,QTextStream _outStream);
		virtual void dispose(){

		}



	private:
		static const QString multipleValueDelimiter;
		static const QString multipleFieldDelimiter;
		static const QString fieldEncapsulater;
		static std::map<QString,QTextStream> * chromatogramFiles;
		QUuid xemlId;
		QString connectionString;
		static QTextStream get_readMe(XemlDataSet * _xds,QUuid _xemlId);

};

#endif // ISAEXPORTER_H
