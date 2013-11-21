#include "attributestore.h"
namespace Xeml {

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				//AttributeStore::AttributeStore(){}
				AttributeStore::~AttributeStore(void){
					//std::cerr << "call to destructor Attribute store" << std::endl;
					//for (std::vector<std::pair<OboTags,QString> >::iterator it=this->Obolist->begin();it!=this->Obolist->end();++it){
					//	static_cast<std::pair<OboTags,QString> >((*it)).pair.pair.pair.pair.pair;
					//}
					//std::cerr << "erase obolist Attribute store" << std::endl;

					this->Obolist->clear();
					//std::cerr << "erase obolist Attribute store" << std::endl;

					this->contextCollection->clear();
				}
				std::pair<OboTags,QString>  * AttributeStore::get_pair(OboTags _tag){
					for(std::vector<std::pair<OboTags,QString> >::iterator it=this->Obolist->begin();it!=this->Obolist->end();++it){
						if((*it).first==_tag){
							return &(*it);
						}
					}
					return NULL;

				}

				QString AttributeStore::get_value(OboTags _tag){

					for(std::vector<std::pair<OboTags,QString> >::iterator it=this->Obolist->begin();it!=this->Obolist->end();++it){
						if((*it).first==_tag){
							return (*it).second;
						}
					}
					return NULL;
				}
				std::vector<std::pair<OboTags,QString> > * AttributeStore::get_obo_list(){
					return this->Obolist;
				}

				OboTermClass AttributeStore::get_termClass(QString _classname){

					if(_classname=="EnvironmentVariable"){
						return Xeml::Document::Ontologies::OBO::EnvironmentVariable;
					}
					else if(_classname=="Context"){
						return Xeml::Document::Ontologies::OBO::Context;
					}
					else{
						return Xeml::Document::Ontologies::OBO::DataType;
					}
				}
				bool AttributeStore::contain_header_type(OboHeaderTypes _oht){
					if(this->headerType==_oht){
					//std::cerr << "debug" << std::endl;
						return true;
					}else{
						return false;
					}
				}

				AttributeStore::AttributeStore(QStringList _termList){
					//std::cerr << "calling constructor attribute store" << std::endl;
					this->term=NULL;
					this->contextCollection = new std::vector<VariableContextSpec*>();
					this->headerClass=Xeml::Document::Ontologies::OBO::None;
					this->Obolist = new std::vector<std::pair<OboTags,QString> >();
					this->regexStanza=new QRegExp("\\[\\w+\\]");
					this->regexTagValPair=new QRegExp(".+:.+");


					QString stanzaType = "Unknown";
					if(this->regexStanza->exactMatch(_termList[0]) || this->regexStanza->exactMatch(_termList[1])){
						if(this->regexStanza->exactMatch(_termList[0])){
							stanzaType=_termList[0].remove(0,1);
							stanzaType=stanzaType.remove(_termList[0].size()-1,1);
						}
						else if(this->regexStanza->exactMatch(_termList[1])){
							stanzaType=_termList[1].remove(0,1);
							stanzaType=stanzaType.remove(_termList[1].size()-1,1);
						}
						if(stanzaType=="Term"){
							this->headerType=Xeml::Document::Ontologies::OBO::Term;
						}
						else if(stanzaType=="Typedef"){
							this->headerType=Xeml::Document::Ontologies::OBO::Typedef;
						}
						else if(stanzaType=="Instance"){
							this->headerType=Xeml::Document::Ontologies::OBO::Instance;
						}
						for (int i=0;i<_termList.size();i++){
							QStringList list = _termList[i].split(": ");

							if(list.at(0).toStdString()=="id"){
								this->add(Xeml::Document::Ontologies::OBO::id,list.at(1));
							}
							else if(list.at(0).toStdString()=="name"){
								//std::cerr << "NAME: " << list.at(1).toStdString() << std::endl;
								this->add(Xeml::Document::Ontologies::OBO::name,list.at(1));
							}
							else if(list.at(0).toStdString()=="def"){
								this->add(Xeml::Document::Ontologies::OBO::def,list.at(1));
							}
							else if(list.at(0).toStdString()=="namespace"){
								this->add(Xeml::Document::Ontologies::OBO::_namespace,list.at(1));
							}
							else if(list.at(0)=="is_a"){
								QString ancester=list.at(1);
								if(ancester.count("!")!=0){
									QStringList tmp_list=ancester.split(" ! ");
									ancester=tmp_list.at(0);
								}
								this->add(Xeml::Document::Ontologies::OBO::is_a,ancester);
							}
							else if(list.at(0)=="instance_of"){
								this->add(Xeml::Document::Ontologies::OBO::instance_of,list.at(1));
							}
							else if(list.at(0)=="domain"){
								this->add(Xeml::Document::Ontologies::OBO::domain,list.at(1));
							}
							else if(list.at(0)=="range"){
								this->add(Xeml::Document::Ontologies::OBO::range,list.at(1));
							}
							else if(list.at(0)=="is_metadata_tag"){
								this->add(Xeml::Document::Ontologies::OBO::is_metadata_tag,list.at(1));
							}
							else if(list.at(0)=="synonym"){
								this->add(Xeml::Document::Ontologies::OBO::synonym,list.at(1));
							}
							else if(list.at(0)=="xref"){
								this->add(Xeml::Document::Ontologies::OBO::xref,list.at(1));
							}
							else if(list.at(0)=="part_of"){
								this->add(Xeml::Document::Ontologies::OBO::part_of,list.at(1));
							}
							else if(list.at(0)=="comment"){
								this->add(Xeml::Document::Ontologies::OBO::comment,list.at(1));
							}
							else if(list.at(0)=="property_value"){
								QString val=list.at(1);

								if(val.contains("has_context")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_context,val);
								}
								if(val.contains("has_enum")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_enum,val);
								}
								if(val.contains("has_symbol")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_symbol,val);
								}
								if(val.contains("has_datatype")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_datatype,val);
								}

							}
							else if(list.at(0)=="relationship"){
								this->add(Xeml::Document::Ontologies::OBO::relationship,list.at(1));
								QString val=list.at(1);

								if(val.contains("has_context")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_context,val);
								}
								if(val.contains("has_enum")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_enum,val);
								}
								if(val.contains("has_symbol")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_symbol,val);
								}
								if(val.contains("has_datatype")){
									QStringList list = val.split(" ");
									val=list.at(1);
									this->add(Xeml::Document::Ontologies::OBO::has_datatype,val);
								}

							}
							else if(list.at(0)=="is_obsolete"){
								this->add(Xeml::Document::Ontologies::OBO::is_obsolete,list.at(1));
							}
							else if(list.at(0)=="intersection_of"){
								this->add(Xeml::Document::Ontologies::OBO::intersection_of,list.at(1));
							}
							else if(list.at(0)=="alt_id"){
								this->add(Xeml::Document::Ontologies::OBO::alt_id,list.at(1));
							}
							else if(list.at(0)=="disjoint_from"){
								this->add(Xeml::Document::Ontologies::OBO::disjoint_from,list.at(1));
							}
							else if(list.at(0)=="consider"){
								this->add(Xeml::Document::Ontologies::OBO::consider,list.at(1));
							}
							else if(list.at(0)=="replaced_by"){
								this->add(Xeml::Document::Ontologies::OBO::replaced_by,list.at(1));
							}
							else if(list.at(0)=="created_by"){
								this->add(Xeml::Document::Ontologies::OBO::created_by,list.at(1));
							}
							else if(list.at(0)=="creation_date"){
								this->add(Xeml::Document::Ontologies::OBO::creation_date,list.at(1));
							}
							else if(list.at(0)=="is_transitive"){
								this->add(Xeml::Document::Ontologies::OBO::is_transitive,list.at(1));
							}
							else if(list.at(0)=="subset"){
								this->add(Xeml::Document::Ontologies::OBO::subset,list.at(1));
							}
							else if(list.at(0)=="xref_analog"){
								this->add(Xeml::Document::Ontologies::OBO::xref_analog,list.at(1));
							}
							else{
								this->add(Xeml::Document::Ontologies::OBO::XXX_unknown,_termList[i]);
							}
						}
					}
					else{

						this->add(Xeml::Document::Ontologies::OBO::id,_termList[0]);
					}


				}

				void AttributeStore::clear(){

				}

				XeoTerm * AttributeStore::get_term(QString _nameSpace,QString _nameSpaceAlias){
					if(this->contain(Xeml::Document::Ontologies::OBO::id)){
						this->term = new XeoTerm(this->get_value(Xeml::Document::Ontologies::OBO::id),_nameSpace,_nameSpaceAlias);
						//std::cerr << "TERM ID : " << this->term->get_termId().toStdString() << std::endl;
						return this->term;
					}
					else{
						return NULL;
					}
				}

				QString AttributeStore::get_id(){
					if(this->contain(Xeml::Document::Ontologies::OBO::id)){
						return this->get_value(Xeml::Document::Ontologies::OBO::id);
					}
					else{
						return "no tag Id";
					}

				}

				QString AttributeStore::get_name(){
					if(this->contain(Xeml::Document::Ontologies::OBO::name)){
						return this->get_value(Xeml::Document::Ontologies::OBO::name);
					}
					else{
						return "no tag Name";
					}
				}
				bool AttributeStore::isTerm(){
					return this->headerType==Xeml::Document::Ontologies::OBO::Term;
				}

				bool AttributeStore::isInstance(){
					return this->headerType==Xeml::Document::Ontologies::OBO::Instance;
				}

				bool AttributeStore::isTypeDef(){
					return this->headerType==Xeml::Document::Ontologies::OBO::Typedef;
				}
				bool AttributeStore::isEnvironmentVariableTerm(){
					return this->headerClass==Xeml::Document::Ontologies::OBO::EnvironmentVariable;
				}

				bool AttributeStore::isContextTerm(){
					return this->headerClass==Xeml::Document::Ontologies::OBO::Context;
				}

				bool AttributeStore::isDataTypeTerm(){
					return this->headerClass==Xeml::Document::Ontologies::OBO::DataType;
				}

				bool AttributeStore::isNoneTerm(){
					return this->headerClass==Xeml::Document::Ontologies::OBO::None;
				}
				bool AttributeStore::contain_N_compare(Xeml::Document::Ontologies::OBO::OboTags _tag,QString _value){
					//if(this->Obolist->empty()){
					//	std::cerr << "empty obolist" << std::endl;
					//}
					//else{
						//std::cerr << this->Obolist->size() << std::endl;
					//}
					for(std::vector<std::pair<OboTags,QString> >::iterator it=this->Obolist->begin();it!=this->Obolist->end();++it){
						//if((*it).second==""){
						//	std::cerr << "pair equal null" << std::endl;
						//}
						if((*it).first==_tag && (*it).second==_value){

							return true;
						}
					}
					return false;
				}
				bool AttributeStore::contain(Xeml::Document::Ontologies::OBO::OboTags _tag){
					for(std::vector<std::pair<OboTags,QString> >::iterator it=this->Obolist->begin();it!=this->Obolist->end();++it){
						if((*it).first==_tag){
							return true;
						}
					}
					return false;
				}

				void AttributeStore::add(OboTags _key,QString _value){
					Obolist->push_back(make_pair(_key,_value));
				}
			}
		}
	}
}
