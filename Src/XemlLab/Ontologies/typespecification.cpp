#include "typespecification.h"
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			TypeSpecification::TypeSpecification()
			{
				this->typeSpecifica=new std::list<TypeSpecifics*>();
			}
			TypeSpecification::~TypeSpecification(void)
			{

			}

			VariableDataTypes TypeSpecification::get_baseType(){
				return this->baseType;
			}

			void TypeSpecification::set_baseType(VariableDataTypes _baseType){
				this->baseType=_baseType;
			}

			std::list<TypeSpecifics*> * TypeSpecification::get_typeSpecifica(){
				return this->typeSpecifica;
			}
			std::list<Enum*> TypeSpecification::get_listEnums(){
				std::list<Enum*> * ret = new std::list<Enum*>();
				for(std::list<Enum*>::iterator it=ret->begin();it!=ret->end();++it){

				}
				return (*ret);


			}
			QString NamedTypeSpecification::get_name(){
				return this->name;
			}

			void NamedTypeSpecification::set_name(QString _name){
				this->name=_name;
			}
		}
	}
}
