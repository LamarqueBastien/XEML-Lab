#ifndef STUDY_H
#define STUDY_H
#include<QTextStream>
#include<Interface/itfdocument.h>
#include<CoreObjects/xemldocument.h>
using namespace Xeml::Document;

namespace XemlUtilities{

	namespace ISA{

		class Study
		{
			public:
				Study();
				static void get_stream(ItfDocument * _xemlDoc,QFile *  _studyfile);
				static QString get_fileName(ItfDocument * _xemlDoc);
		};
	}
}

#endif // STUDY_H
