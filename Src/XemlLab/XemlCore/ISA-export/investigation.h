#ifndef INVESTIGATION_H
#define INVESTIGATION_H
#include<QTextStream>
#include<QFile>
#include<QTextStreamManipulator>
#include"ISA-export/Ontology/ontologybase.h"
#include"Interface/itfdocument.h"
#include"CoreObjects/xemldocument.h"
#include"ISA-export/isaexporter.h"

using namespace Xeml::Document;

namespace XemlUtilities{

	namespace ISA{
		class Investigation
		{
			public:
				Investigation();
				static void get_stream(ItfDocument * _xemlDoc,QFile *  _investigationfile);
				static QString get_fileName(ItfDocument * _xemlDoc);
			private:
				static QString quoted_empty_string();

		};
	}
}

#endif // INVESTIGATION_H
