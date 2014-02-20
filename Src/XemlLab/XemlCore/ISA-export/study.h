#ifndef STUDY_H
#define STUDY_H
#include<QTextStream>

#include<CoreObjects/xemldocument.h>
#include<ISA-export/isatable.h>

using namespace Xeml::Document;

namespace XemlUtilities{

	namespace ISA{

		class Study : public IsaTable
		{
			public:
				Study(ItfDocument * _xemldoc,QObject *parent = 0);
				static void get_stream(ItfDocument * _xemlDoc,QFile *  _studyfile);
				static QString get_fileName(ItfDocument * _xemlDoc);

		};
	}
}

#endif // STUDY_H
