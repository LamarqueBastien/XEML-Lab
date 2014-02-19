#include "term.h"
namespace XemlUtilities{

	namespace ISA{

		namespace Ontology{
			Term::Term()
			{
			}
			QString Term::get_name(){
				return this->name;
			}

			QString Term::get_accession_number(){
				return this->accession_number;
			}

			void Term::set_name(QString _name){
				this->name=_name;
			}

			void Term::set_accession_number(QString _accession_number){
				this->accession_number=_accession_number;
			}
		}
	}
}
