#include "basicterm.h"

namespace Xeml {

	namespace Document{

		BasicTerm::BasicTerm()
		{
		}
		BasicTerm::BasicTerm(QString _termId){
			this->termId=_termId;
		}
		BasicTerm::~BasicTerm(void){
			//this->TaggedannotationCollection->clear();
			std::cerr << "deleting Basic term" << std::endl;
			for (std::map<TaggedAnnotation*,QString>::iterator it=this->TaggedannotationCollection->begin();it!=this->TaggedannotationCollection->end();++it){
				delete (*it).first;
			}
			this->TaggedannotationCollection->clear();
			std::cerr << " Basic term deleted" << std::endl;
		}

		BasicTerm::BasicTerm(QString _termId,QString _namespace,QString _namespacealias){
			this->termId=_termId;
			this->nameSpace=_namespace;
			this->nameSpacealias=_namespacealias;
		}

		BasicTerm::BasicTerm(const BasicTerm &term){
			this->termId=term.termId;
			this->nameSpacealias=term.nameSpacealias;
			this->nameSpace=term.nameSpace;
			this->name=term.name;
		}

		QString BasicTerm::get_namespacealias(){
			return this->nameSpacealias;
		}

		QString BasicTerm::get_namespace(){
			return this->nameSpace;
		}

		QString BasicTerm::get_name(){
			return this->name;
		}

		QString BasicTerm::get_termId(){
			return this->termId;
		}

		void BasicTerm::set_namespacealias(QString _namespacealias){
			this->nameSpacealias=_namespacealias;
		}

		void BasicTerm::set_namespace(QString _namespace){
			this->nameSpace=_namespace;
		}

		void BasicTerm::set_name(QString _name){
			this->name=_name;
		}

		void BasicTerm::set_termId(QString _termId){
			this->termId=_termId;
		}
		std::map<TaggedAnnotation*,QString> * BasicTerm::get_taggedannotation(){
			return this->TaggedannotationCollection;
		}
		void BasicTerm::add_tagged_annotation(TaggedAnnotation *TA){

			(*this->TaggedannotationCollection)[TA]=TA->getTag();
		}

		}
	}
