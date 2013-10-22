#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include<iostream>
#include<cstdio>
#include"itfdocument.h"
#include"xemldocument.h"
#include<QFile>
#include<QTextStream>
#include<QIODevice>
using namespace std;
#include<QString>

using Xeml::Document::Contracts::ItfDocument;
using Xeml::Document::XemlDocument;

class FileManager
{
	private:
		Xeml::Document::Contracts::ItfDocument * current_XemlDoc;
		QString                              filePath;
	public:
		FileManager();
		void                                     New();
		void                                     LoadFile(QString path,bool asTemplate);
		void                                     LoadDocument(QFile *_xeml_doc,bool asTemplate);
		void                                     SetXemlCode(QString _xemlcode,
															 bool asTemplate,
															 bool raiseSomethingChangedEvent,
															 bool doValidation);
		QString                                  LoadXemlCodeFromFile(QFile * _xeml_doc);
		Xeml::Document::Contracts::ItfDocument * get_current_xeml();
		void                                     purgedetailsFromdocument();

};

#endif // FILEMANAGER_H
