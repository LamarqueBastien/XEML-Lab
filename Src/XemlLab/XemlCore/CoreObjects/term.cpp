#include "term.h"
namespace Xeml {

	namespace Document{

		Term::Term()
		{
		}
		Term::Term(QString _termId){
			this->termId=_termId;
		}

		Term::Term(QString _termId,QString _namespace,QString _namespacealias){
			this->termId=_termId;
			this->nameSpace=_namespace;
			this->nameSpacealias=_namespacealias;
		}

		Term::Term(const Term &term){
			this->termId=term.termId;
			this->nameSpacealias=term.nameSpacealias;
			this->nameSpace=term.nameSpace;
			this->name=term.name;
		}
		Term::~Term(void)
		{
		}
		QString Term::get_namespacealias(){
			return this->nameSpacealias;
		}

		QString Term::get_namespace(){
			return this->nameSpace;
		}

		QString Term::get_name(){
			return this->name;
		}

		QString Term::get_termId(){
			return this->termId;
		}

		void Term::set_namespacealias(QString _namespacealias){
			this->nameSpacealias=_namespacealias;
		}

		void Term::set_namespace(QString _namespace){
			this->nameSpace=_namespace;
		}

		void Term::set_name(QString _name){
			this->name=_name;
		}

		void Term::set_termId(QString _termId){
			this->termId=_termId;
		}
		std::map<TaggedAnnotation*,QString> * Term::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void Term::add_tagged_annotation(TaggedAnnotation *TA){
			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}

		}
	}
