#ifndef ITFONTOLOGYTERM_H
#define ITFONTOLOGYTERM_H
#include<QString>
#include<string>
#include<list>
#include<map>
#include"basicterm.h"
#include"VariableDataTypes.h"
#include"valuebase.h"
#include"cycle.h"
#include"dynamicvalue.h"
#include"timespan.h"

//#include"/Users/benjamindartigues/Qt5.0.1/Root/XemlCore/CoreObjects/termattribute.h"
#include"termattribute.h"
#include"basicterm.h"
//#include"/Users/benjamindartigues/Qt5.0.1/Root/XemlCore/CoreObjects/term.h"
//#include"xemlannotableobject.h"

using namespace std;
using  Xeml::Document::TermAttribute;
using Xeml::Document::BasicTerm;
//using Xeml::Document::Term;

namespace Xeml {

	namespace Document{

		namespace Contracts{

			class ItfOntologyTerm
			{
				protected:
					std::map<QString,TermAttribute*>            termattributecollection;
					std::list<BasicTerm*>                       supervisedObject;
					QString                                     termId;
					BasicTerm                                 * prototype;
					QString                                     definition;


				public:
					ItfOntologyTerm();
					virtual ~ItfOntologyTerm();
					//const std::list<Term*> &readonlySupervisedObject;
					virtual QString                             get_termId()=0;
					virtual std::list<BasicTerm*>               get_supervisedObject()=0;
					virtual BasicTerm                         * get_prototype()=0;
					virtual QString                             get_definition()=0;
					virtual void                                set_definition(QString _definition)=0;
					virtual bool                                contains(QString _id)=0;
					virtual void                                display_attributes()=0;
					virtual TermAttribute                     * get_termAttributesByKey(QString _key)=0;
					virtual void                                add_termAttribute(TermAttribute * _tA)=0;
					virtual void                                remove_termAttribute(QString _name)=0;
					virtual std::map<QString,TermAttribute*>    get_termAttributeCollection()=0;
					virtual BasicTerm                         * emit_DefaultObject(bool supervised)=0;
					virtual void                                supervise(BasicTerm *t)=0;
					virtual void                                reject_supervision(BasicTerm *t)=0;
					virtual void                                validate_SupervisedProperties()=0;
					virtual void                                push_SupervisedProperties()=0;
					//créer un event "Validation" qui contient des validations messages


			};
			class ItfVariableOntologyTerm : public ItfOntologyTerm
			{
				protected:

					std::list<QString> * contexts;
					int contextCount;

				public:
					virtual bool hasDefaultValue(QString context)=0;
					virtual bool hasDefaultUnit(QString _context)=0;
					virtual QString defaultUnitName(QString context)=0;
					virtual QString defaultUnitSymbol(QString context)=0;
					virtual VariableDataTypes getDataTypes(QString context)=0;
					virtual std::vector<std::pair<QString,QString> > * listUnits(QString context)=0;
					virtual std::vector<std::pair<QString,QString> > * getEnums(QString context)=0;
					//check for Min and Max , ?????
					virtual ValueBase * defaultValue(QString context)=0;


					//virtual std::list<std::pair<QString, QString>> listUnits(QString context)=0;

					//virtual VariableDataTypes GetDataType(string context);

					//virtual decimal? GetMin(string context);

					//virtual decimal? GetMax(string context);

					//virtual List<KeyValuePair<string, string>> GetEnums(string context);

					//virtual ValueBase DefaultValue(string context);

			};
			class ItfDynamicOntologyTerm : public ItfVariableOntologyTerm
			{
					virtual bool hasDefaultCycle(QString context)=0;
					virtual Cycle * defaultCycle(QString _context)=0;
					virtual DynamicValue * defaultdynamicValue(QString context, QDateTime _time)=0;
					virtual Cycle * defaultCycle(QString context, QDateTime _time)=0;
			};
		}
	}
}

#endif // ITFONTOLOGYTERM_H
