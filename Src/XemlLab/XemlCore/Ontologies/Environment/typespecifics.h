#ifndef TYPESPECIFICS_H
#define TYPESPECIFICS_H
#include<ctime>
#include<QString>
using namespace std;
namespace Xeml{

	namespace Document{

		namespace EnvironmentalOntology{

			class TypeSpecifics
			{
				public:
					TypeSpecifics();
					virtual ~TypeSpecifics();
					virtual double      get_numberVal()=0;
					virtual void        set_numberVal(double _numberVal)=0;
					virtual time_t      get_dateVal()=0;
					virtual void        set_dateVal(time_t _dateVal)=0;
					virtual QString get_textVal()=0;
					virtual void        set_textVal(QString _textVal)=0;
					virtual bool        get_booleanVal()=0;
					virtual void        set_booleanVal(bool _booleanVal)=0;
					static int          compareTypeSpecificsByName( TypeSpecifics * x, TypeSpecifics * y){
						if (x == NULL)
						{
							if(y==NULL)
							{
								return 0;
							}
							else{
								return -1;
							}
						}
						else{
							if(y==NULL)
							{
								return 1;
							}
							else
							{
								int retval= x->get_textVal().compare(y->get_textVal());
								if(retval!=0)
								{
									return retval;
								}
								else{
									return x->get_textVal().compare(y->get_textVal());
								}
							}
						}
					}
					static bool compare_nocase_typeSpec (TypeSpecifics * first, TypeSpecifics * second)
					{

						int i=0;
						while ( (i<first->get_textVal().length()) && (i<second->get_textVal().length()) )
						{
							if ((first->get_textVal()).toLower().at(i)<(second->get_textVal()).toLower().at(i)){

								return true;
							}
							else if ((first->get_textVal()).toLower().at(i)>(second->get_textVal()).toLower().at(i)){
								return false;
							}
							++i;
						}
						if (first->get_textVal().length()<second->get_textVal().length()){

							return true;
						}
						else{
							return false;
						}
					}
			};
		}
	}
}

#endif // TYPESPECIFICS_H


