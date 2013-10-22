#ifndef TYPESPECIFICATION_H
#define TYPESPECIFICATION_H
#include"VariableDataTypes.h"
#include"typespecifics.h"
#include"typespecificsenum.h"
#include<list>
#include<vector>
#include<QString>

using Xeml::Document::VariableDataTypes;
using Xeml::Document::EnvironmentalOntology::TypeSpecifics;
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{
			class TypeSpecification
			{
				private:
					VariableDataTypes           baseType;
					std::list<TypeSpecifics*> * typeSpecifica;

				public:
					TypeSpecification();
					~TypeSpecification();
					VariableDataTypes           get_baseType();
					void                        set_baseType(VariableDataTypes _baseType);
					std::list<TypeSpecifics*> * get_typeSpecifica();
					std::list<Enum*>            get_listEnums();
			};
			class NamedTypeSpecification : public TypeSpecification
			{
				private:
					QString name;
				public:
					QString get_name();
					void set_name(QString _name);
			};
		}
	}
}




#endif // TYPESPECIFICATION_H
