#ifndef INVESTIGATION_H
#define INVESTIGATION_H
#include<QTextStream>
#include<QFile>
#include<QTextStreamManipulator>
#include"ISA-export/Ontology/ontologybase.h"
class Investigation
{
	public:
		Investigation();
		static QString get_stream();
};

#endif // INVESTIGATION_H
