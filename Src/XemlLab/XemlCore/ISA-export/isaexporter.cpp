#include "isaexporter.h"


namespace XemlUtilities{

	namespace ISA{
		//static variables
		const QString IsaExporter::fieldEncapsulater = "\"";
		const QString IsaExporter::multipleFieldDelimiter="\t";
		const QString IsaExporter::multipleValueDelimiter="; ";


		IsaExporter::IsaExporter(QUuid _xemlId,QString _connectionString)
		{
			//QProcess gzip;
			//gzip.start();
			this->xemlId=_xemlId;
			this->connectionString=_connectionString;
			OntologyBase::set_connection_string(_connectionString);

		}
		std::vector<QString> * IsaExporter::encapsulate(std::vector<QString> * l){
			return encapsulate(fieldEncapsulater,l);
		}

		std::vector<QString> * IsaExporter::encapsulate(QString encap_char,std::vector<QString> * l){
			for (int i=0;i<l->size();i++){
				l->at(i)=encap_char % l->at(i) % encap_char;
			}
		}

		QString IsaExporter::encapsulate(QString _s){
			QString ret=fieldEncapsulater%_s%fieldEncapsulater;
			return ret;
		}

		QStringList * IsaExporter::encapsulate(QStringList * _s){

		}

		QStringList * IsaExporter::encapsulate(QString encap_char,QStringList * _s){

		}

		QString IsaExporter::escape(QString _s){

		}

		void IsaExporter::add_chromatogram_file(QString _filename,QTextStream _infile){

		}
		//we need to develop some relational database miming the Xeml document
		//for now, we only used the XemlDocument
		void IsaExporter::write(ItfDocument * _xds,QTextStream * _test){

			//Create the ISA_exported_files repository
			QDir Isa_directory(QCoreApplication::applicationFilePath());
			while (! Isa_directory.path().endsWith("XEML-Lab")){
				Isa_directory.cdUp();
			}
			Isa_directory.cd("ISA_exported_files");
			Isa_directory.mkdir("ISA_"%_xds->get_experiment_name());
			Isa_directory.cd("ISA_"%_xds->get_experiment_name());

			//QString study_file_name(Isa_directory.path()+Study::get_fileName(_xds));
			QString investigation_file_name(Isa_directory.path()+"/i_"+_xds->get_experiment_name());
			QString assay_file_name(Isa_directory.path()+"/a_"+_xds->get_experiment_name());



			QFile * study_file=new QFile(Isa_directory.path()+Study::get_fileName(_xds));

			if (!study_file->open(QIODevice::WriteOnly)) {

				delete study_file;
				study_file = 0;
				return;
			}
			else{

				Study::get_stream(_xds,study_file);

			}

			QFile * investigation_file=new QFile(Isa_directory.path()+Investigation::get_fileName(_xds));
			if (!investigation_file->open(QIODevice::WriteOnly)) {

				delete investigation_file;
				investigation_file = 0;
				return;
			}
			else{

				Investigation::get_stream(_xds,investigation_file);

			}
			/*
			QFile * assay_file=new QFile(Isa_directory.path()+Assay::get_fileName(_xds));
			if (!assay_file->open(QIODevice::WriteOnly)) {

				delete assay_file;
				assay_file = 0;
				return;
			}
			else{

				Assay::get_stream(_xds,assay_file);

			}
			*/



			//QFile * metabolites_file;
			QFile * readme_file;
			QFile * Xeml_file;
		}
	}
}

