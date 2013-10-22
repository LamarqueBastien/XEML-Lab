#include "positioningontologyhandler.h"
namespace Xeml{

	namespace Document{
		PositioningOntologyHandler::PositioningOntologyHandler()
		{
			this->terms= new std::map<QString,ItfVariableOntologyTerm*>();
			this->globalTypes=new std::map<QString,NamedTypeSpecification*>();
			this->globalUnits=new std::map<QString,UnitSet*>();
			this->contextCollection =new std::map<QString,QString>();
			URI=QString("http://www.mpimp-golm.mpg.de/2009/XEML/Positioning");
/*
#if defined(Q_OS_WIN)
									   this->FileLocationPrefix=QString("C:/Documents and Settings/Bryan/Mes documents/Cosmos/XemlLab/XemlDesigner/XEML/XEO_Positioning.obo");
#elif defined(Q_OS_MACX)
									   this->FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/XEO_Positioning.obo");
#else
									   this->FileLocationPrefix=QString("/home/bdartigues/cosmos/XemlLab/XemlDesigner/XEML/XEO_Positioning.obo");
#endif
*/
			this->FileLocationPrefix=QString("://XEML/XEO_Positioning.obo");

            //FileLocationPrefix=QString("/Users/benjamindartigues/cosmos/XemlLab/XemlDesigner/XEML/XEO_Positioning.obo");
			this->Nodes=new std::list<TermNode*>();
			this->alias=QString("");
			this->xmlNS=QString("http://www.mpimp-golm.mpg.de/2007/XEML/Environment");
		}
		PositioningOntologyHandler::~PositioningOntologyHandler(void){

		}

		//region itfVartiableOntologyHandler
		std::map<QString,ItfVariableOntologyTerm*> * PositioningOntologyHandler::get_terms(){
			return this->terms;
		}

		ItfVariableOntologyTerm                    * PositioningOntologyHandler::findKey(BasicTerm param){

		}

		ItfVariableOntologyTerm                    * PositioningOntologyHandler::findKey(QString termId){

		}
		//end region



		//region XemlComponent
		QString                                      PositioningOntologyHandler::get_publisher(){
			return "Max Planck Institute of Molecular Plant Physiology, Potsdam/Golm, Germany";
		}

		QString                                      PositioningOntologyHandler::get_version(){
			return "1.0.0";
		}

		QString                                      PositioningOntologyHandler::get_componentName(){
			return "Xeml positioning Ontology Handler";
		}

		QString                                      PositioningOntologyHandler::get_author(){
			return "Jan Hannemann";
		}

		QString                                      PositioningOntologyHandler::get_description(){
			return "The XEML framework standard component for the sample positioning information. This component handles ontologies of the XEO Xml dialect.";

		}

		QString                                      PositioningOntologyHandler::get_uri(){
			return this->URI;
		}

		ItfXemlComponent                           * PositioningOntologyHandler::copy(){
			return new PositioningOntologyHandler();
		}
		//end region


		//region validation source

		QString                                      PositioningOntologyHandler::get_validation_events(){
			QString tmp="validation problem";
			return tmp;
		}

		//end region

		//region ItfHierarchicalview
		std::list<TermNode*>             * PositioningOntologyHandler::get_listNodes(){
			return this->Nodes;
		}

		TermNode                              * PositioningOntologyHandler::findNode(ItfOntologyTerm *t){

			return findNode(t->get_termId());
		}

		TermNode                              * PositioningOntologyHandler::findNode_by_id(QString termId){
			for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
				if((*it)->get_term()->get_termId()==termId){
					return (*it);
				}
			}
			return NULL;
		}

		TermNode                              * PositioningOntologyHandler::findNode(QString termId){
			for(std::list<TermNode*>::iterator it=this->Nodes->begin();it!=this->Nodes->end();it++){
				if(findNode((*it),termId)!=NULL){
					return findNode((*it),termId);
				}


			}
			return NULL;

		}

		TermNode                              * PositioningOntologyHandler::findNode(TermNode * start,QString termId){
			TermNode * ret =NULL;
			if(!start->isContainer && start->get_term()->get_termId()==termId){
				ret=start;
			}
			else if (start->isContainer){
				for(std::list<AttributeRelation<TermNode*>*>::iterator it=start->get_childs()->begin();it!=start->get_childs()->end();it++){
					if(findNode((*it)->relation,termId)!=NULL){
						ret=findNode((*it)->relation,termId);
					}
				}

			}
			return ret;
		}

		//end region

		//region ItfOntologyHandler


		QString                                      PositioningOntologyHandler::get_namespace(){
			return this->nameSpace;
		}

		void                                         PositioningOntologyHandler::set_namespace(QString _nameSpace){
			this->nameSpace=_nameSpace;
		}
		QString                                      PositioningOntologyHandler::get_namespaceAlias(){
			return this->namespaceAlias;
		}
		void                                         PositioningOntologyHandler::set_namespaceAlias(QString _namespaceAlias){
			this->namespaceAlias=_namespaceAlias;
		}



		bool                                         PositioningOntologyHandler::get_autoValidation(){
			return this->autovalidation;
		}

		void                                         PositioningOntologyHandler::set_autoValidation(bool _autovalidation){
			this->autovalidation=_autovalidation;
		}

		QString                                      PositioningOntologyHandler::get_instanceLocation(){
			return this->instanceLocation;
		}

		void                                         PositioningOntologyHandler::set_instanceLocation(QString _instancelocation){
			if(this->instanceLocation!=_instancelocation){
				this->instanceLocation=_instancelocation;
				this->reloadNeeded=true;
			}
		}

		OntologyLoadState                            PositioningOntologyHandler::get_ontologyLoadState(){
			return this->ontologyLoadState;
		}

		QString                                      PositioningOntologyHandler::get_ontologyLoadMessage(){
			return this->ontologyLoadMessage;
		}

		OntologyType                                 PositioningOntologyHandler::get_ontologyType(){
			return Xeml::Document::Contracts::Positioning;
		}

		void                                         PositioningOntologyHandler::load(QString _nameSpaceAlias){
			load(_nameSpaceAlias,false);
		}

		void                                         PositioningOntologyHandler::load(QString _nameSpaceAlias, bool force){
			//std::cerr << "debut chargement " << std::endl;
			if(this->alias!=_nameSpaceAlias){
				this->alias=_nameSpaceAlias;
				this->ontologyLoadState=Xeml::Document::Contracts::ReloadNeeded;
				//this->reloadNeeded =true;
			}
			if(this->ontologyLoadState==Xeml::Document::Contracts::ReloadNeeded || force){
				this->terms->clear();
				this->globalTypes->clear();
				this->globalUnits->clear();
				this->contextCollection->clear();
				std::cerr << "create the download manager " << std::endl;
				downloadManager = new DownloadManager();
				QUrl tmp_url;
				tmp_url=downloadManager->retrieve_ontologies_url(this->URI);
				QFile tmpfile(FileLocationPrefix);
				if(!tmpfile.exists()){
					downloadManager->download_File(tmp_url,FileLocationPrefix);
				}
				QDomDocument * pos_onto = new QDomDocument("pos_onto");
				if(!tmpfile.open(QIODevice::ReadOnly))
				{
					std::cerr << "Erreur à l'ouverture du document XML" << std::endl;
				}
				if (!pos_onto->setContent(&tmpfile)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
				{
					tmpfile.close();
					std::cerr << "Erreur à l'association du document DOM au fichier XML" << std::endl;
				}
				init(pos_onto);
				buildHierarchy();
				this->ontologyLoadState=Xeml::Document::Contracts::Loaded;

				std::cerr << "file downloaded" <<std::endl;
			}


		}

		// end region

		//region private stuff

		TermNode * PositioningOntologyHandler::findSubNode(TermNode * _tn,QString _label,QString _attribute){
			//std::cerr << "entering findsubnode" << std::endl;
			//std::cerr << "size of node" <<this->Nodes->size() << "label : " << _label << std::endl;


			if(_tn==NULL){
				//std::cerr << "entering tn==NULL" << std::endl;

				for(std::list<TermNode*>::iterator it =this->Nodes->begin();it!=this->Nodes->end();++it){
					if((*it)->get_label()==_label){
						//std::cerr << "label 1" <<(*it)->get_label().toStdString() << std::endl;
						//std::cerr << "label 2" <<_label << std::endl;
						return (*it);
					}

				}
				return NULL;
			}
			else{
				for(std::list<AttributeRelation<TermNode*> *>::iterator it =_tn->get_childs()->begin();it!=_tn->get_childs()->end();++it){
					if((*it)->attribute==_attribute && (*it)->relation->get_label()==_label){

						return (*it)->relation;
					}
				}
				return NULL;
			}
		}

		void PositioningOntologyHandler::buildHierarchy(){
			//std::cerr << "entering build hierarchy" << std::endl;
			int cpt=0;
			/*
			std::list<TermNode*> * mylist=new std::list<TermNode*>();
			TermNode * test= TermNode::createContainerNode("root");
			TermNode * fils1=TermNode::createNode(new PosTerm("1","NS","zergz"));
			TermNode * fils2=TermNode::createNode(new PosTerm("2","NS","zergz"));
			test->addSubNode(fils1,"is_a");
			test->addSubNode(fils2,"is_a");
			mylist->push_back(test);
			for (std::list<TermNode*>::iterator it0 = mylist->begin();it0!=mylist->end();++it0){
				std::cerr << " node : " << (*it0)->get_label().toStdString()<< std::endl;
				if((*it0)->get_childs()!=0){
					for(std::list<AttributeRelation<TermNode*> *>::iterator it5 =(*it0)->get_childs()->begin();it5!=(*it0)->get_childs()->end();++it5){
						std::cerr << "att " << (*(*it5)->relation)->get_label().toStdString() << std::endl;
					}

				}
			}
			*/


			for(std::map<QString,ItfVariableOntologyTerm*>::iterator it = this->terms->begin();it!=this->terms->end();++it){
				cpt++;
				//std::cerr << "value collection size in build hierarchy: " << static_cast<VariableTerm*>(static_cast<PosTerm*>((*it).second)->get_prototype())->get_valuecollection()->size() << std::endl;
				//std::cerr << "passage : " << cpt << "- term Id : " << static_cast<PosTerm*>((*it).second)->get_termId().toStdString() << std::endl;
				TermNode *currentNode=NULL;
				//std::cerr << "entering loop for 1" << std::endl;
				int i=0;
				for(; i < static_cast<PosTerm*>((*it).second)->GroupLevels()->size();i++){
					//std::cerr << "size of group level : " << static_cast<PosTerm*>((*it).second)->GroupLevels()->size() << std::endl;
					//std::cerr << "entering loop for 2" << std::endl;
					TermNode * nextNode = findSubNode(currentNode,static_cast<PosTerm*>((*it).second)->GroupLevels()->at(i),"subgroup_of");
					//std::cerr << "entering findsubnode" << std::endl;
					if(nextNode==NULL){
						//std::cerr << "next node==NULL" << std::endl;

						nextNode = TermNode::createContainerNode(static_cast<PosTerm*>((*it).second)->GroupLevels()->at(i));
						//nextNode = TermNode::createNode(NULL);
						//nextNode->set_isContainer(true);
						//std::cerr << "next node label :" << nextNode->get_label().toStdString() << std::endl;
						//std::cerr << "next node child size :" << nextNode->get_childs()->size() << std::endl;
						if(i==0){
							//std::cerr << "i==0" << std::endl;
							//std::cerr << "node label : " << nextNode->get_label().toStdString()<< std::endl;

							this->Nodes->push_back(nextNode);
						}
						else{
							currentNode->addSubNode(nextNode,"subgroup_of");
						}
					}
					//std::cerr << "next node not NULL" << std::endl;
					//std::cerr << "node label : " << nextNode->get_label().toStdString()<< std::endl;
					currentNode=nextNode;
					//std::cerr << "current node label :" << currentNode->get_label().toStdString() << std::endl;

					//std::cerr << "node label : " << nextNode->get_label().toStdString()<< std::endl;
				}

				//std::cerr << "end loop for 2 : "<< std::endl;

				TermNode * leaf = TermNode::createNode((*it).second);
				//std::cerr << "leaf label : " << leaf->get_label().toStdString()<< std::endl;
				//std::cerr << "leaf term Id : " << leaf->get_term()->get_termId().toStdString()<< std::endl;
				this->Nodes->push_back(leaf);
				currentNode->addSubNode(leaf,"belongs_to");

			}
			/*
			for (std::list<TermNode*>::iterator it3 = this->Nodes->begin();it3!=this->Nodes->end();++it3){
				std::cerr << " node : " << (*it3)->get_label().toStdString()<< std::endl;
				if((*it3)->get_childs()!=0){
					//TermNode * tmp;
					std::list<AttributeRelation<TermNode*> *> * tmplist=(*it3)->get_childs();
					//tmplist->dumpObjectTree();
					//AttributeRelation<TermNode*> *att;
					std::cerr <<"childs exist and size =: " << (*it3)->get_childs()->size()<< std::endl;
					for(std::list<AttributeRelation<TermNode*> *>::iterator it2 =tmplist->begin();it2!=tmplist->end();++it2){
						//TermNode * tmp;//=new TermNode();// =static_cast<TermNode*>((*(*it2)->relation));
						//att=(*it2);
						//(*att->relation)

						//(*att->get_relation());
						TermNode * tmp = static_cast<AttributeRelation<TermNode*> *>((*it2))->relation;
						if(tmp==NULL){
							std::cerr << "ERRORRRRR" << std::endl;
						}
						else{
							if(tmp->get_isContainer()){

								std::cerr << "CONTAINER" << std::endl;
							}
							else{
								//TermNode *tmp3;
								std::cerr << "NOT CONTAINER" << std::endl;
								std::cerr << "att " << (*it2)->attribute.toStdString() << std::endl;
								std::cerr << "size " << tmp->get_childs()->size() << std::endl;
								std::cerr << "LABEL : " << static_cast<PosTerm*>(tmp->get_term())->get_termId().toStdString() << std::endl;

								for(std::list<AttributeRelation<TermNode*> *>::iterator it4 =tmp->get_childs()->begin();it4!=tmp->get_childs()->end();++it4){

									//TermNode * tmp2 = (*(*it4)->relation);
									std::cerr << "att " << (*it4)->attribute.toStdString() << std::endl;
									//std::cerr << " other size " << tmp2->get_childs()->size() << std::endl;
								}
								//std::cerr << "LABEL : " << static_cast<PosTerm*>(tmp->get_term())->get_termId().toStdString() << std::endl;
							}
							//std::cerr << "LABEL : " << tmp->get_label().toStdString() << std::endl;
						}
						//tmp =(*(*it2)->relation);

						//if(tmp==NULL){
						//	std::cerr << "NULL TERMNODE" << std::endl;
						//}
						//else{(*att->relation)
						//std::cerr << "node child name : "<< tmp->get_term()->get_termId().toStdString() << std::endl;
						//std::cerr << "node child attribute : "<< att->attribute.toStdString() << std::endl;

						//}

						//std::cerr << "node child name : "<< (*it2)->attribute.toStdString() << std::endl;
						//findNode("POS00002")->get_label().toStdString()
						//std::cerr << "node child name : "<< findNode("POS00002")->get_label().toStdString() << std::endl;
					}

				}
			}
			*/
			//std::cerr << " size of node : " << this->Nodes->size()<< std::endl;
		}

		void PositioningOntologyHandler::init(QDomDocument * ontoFile){
			//std::cerr << "entering init" << std::endl;
			QDomElement dom_element = ontoFile->documentElement();
			this->nameSpace=dom_element.attributeNode("NameSpace").value();
			QDomNode noeud = dom_element.firstChild();
			while(!noeud.isNull())// Tant que le nœud n'est pas vide.
			{
				if(!dom_element.isNull())
				{
					//std::cerr << "entering dom_element not null" << std::endl;

					if(noeud.toElement().tagName().toStdString()=="Resources"){
						//std::cerr << "ressources found  " << std::endl;
						QDomNodeList QNL=noeud.toElement().childNodes();
						for (int i = 0; i < QNL.length(); i++) {
							if(QNL.item(i).toElement().tagName().toStdString()=="TypeSets"){
								initGlobalType(QNL.item(i).toElement());

							}
							if(QNL.item(i).toElement().tagName().toStdString()=="UnitSets"){
								initGlobalUnit(QNL.item(i).toElement());

							}
							if(QNL.item(i).toElement().tagName().toStdString()=="ContextCollection"){
								initContextList(QNL.item(i).toElement());

							}
						}

					}
					if(noeud.toElement().tagName().toStdString()=="Variable"){
						QString termId= noeud.toElement().attributeNode("TermId").value();
						//std::cerr << "Term ID : " << noeud.toElement().attributeNode("TermId").value().toStdString() << "---------------" << std::endl;
						PosTerm * paramSpec = new PosTerm(termId,this->nameSpace,this->alias);
						paramSpec->set_name(noeud.toElement().attributeNode("Name").value());
						paramSpec->set_groupPath(noeud.toElement().attributeNode("Group").value());
						paramSpec->set_recomLevel(noeud.toElement().attributeNode("RecommendationLevel").value().toInt());
						QDomNodeList QNL=noeud.toElement().childNodes();
						//std::cerr << "value collection size in init :" <<  static_cast<VariableTerm*>(paramSpec->get_prototype())->get_valuecollection()->size() << std::endl;
						for (int i = 0; i < QNL.length(); i++) {
							if(QNL.item(i).toElement().tagName()=="Definition"){
								paramSpec->set_definition(QNL.item(i).toElement().text());
							}
							if(QNL.item(i).toElement().tagName()=="CommunityUrl"){
								//paramSpec->set_definition(QNL.item(i).toElement().text());
							}
							if(QNL.item(i).toElement().tagName()=="Context"){
								//std::cerr << "context found :" << QNL.item(i).toElement().attributeNode("Name").value().toStdString() << std::endl;
								VariableContextSpec * pc =new VariableContextSpec();
								//std::cerr << "new variable context spec " << std::endl;
								pc->set_name(QNL.item(i).toElement().attributeNode("Name").value());
								pc->set_description((*this->contextCollection)[pc->get_name()]);
								initTypeDefine(QNL.item(i).toElement(),pc);
								initUnit(QNL.item(i).toElement(),pc);
								if(pc->get_unitSet()->get_defUnit()!=NULL){
									//std::cerr << "unitset variable context spec " << pc->get_unitSet()->get_defUnit()->get_symbol()<<std::endl;
									for(std::list<ConvertableUnit*>::iterator it=pc->get_unitSet()->get_convUnits()->begin();it!=pc->get_unitSet()->get_convUnits()->end();++it){
										//std::cerr << "other symbol : " <<(*it)->get_symbol() << std::endl;
									}

								}


								QDomNodeList QNL2=QNL.item(i).toElement().childNodes();
								for (int j = 0; j < QNL2.length(); j++) {
									if(QNL2.item(j).toElement().tagName().toStdString()=="DefaultValue"){
										//std::cerr << "default value vfound" << QNL2.item(j).toElement().text().toStdString() << std::endl;
										pc->set_def_value(QNL2.item(j).toElement().text());
									}
								}
								(*paramSpec->get_contextCollection())[pc->get_name()]=pc;
							}


						}
						//std::cerr << "value collection size in init end :" <<  static_cast<VariableTerm*>(paramSpec->get_prototype())->get_valuecollection()->size() << std::endl;

						(*this->terms)[paramSpec->get_termId()]=paramSpec;

						//need to create posterm
					}
					noeud = noeud.toElement().nextSibling();
				}
				else{
					std::cerr << "problem null element" << std::endl;

				}


			}
			//std::cerr << "nombre de terms : " << this->terms->size() << std::endl;
		}

		void PositioningOntologyHandler::initContextList(QDomElement  elem){
			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="Context"){
					QString cName = QNL.item(i).toElement().attributeNode("Name").value();
					QString desc="";
					QDomNodeList QNL2=QNL.item(i).toElement().childNodes();
					for (int j = 0; j < QNL2.length(); j++) {
						if(QNL2.item(j).toElement().tagName().toStdString()=="Description"){
							desc=QNL2.item(j).toElement().text();
							(*this->contextCollection)[cName]=desc;
						}
					}
				}
			}
		}

		void PositioningOntologyHandler::initGlobalType(QDomElement  elem){
			//std::cerr << "entering init global type" << std::endl;

			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="TypeDefine"){
					NamedTypeSpecification  * nts = new NamedTypeSpecification();
					//std::cerr << "size : " << nts->get_typeSpecifica()->size() << std::endl;
					//std::cerr << "name : " <<QNL.item(i).toElement().attributeNode("Name").value().toStdString() << std::endl;
					initTypeDefine(QNL.item(i).toElement(),nts);
					nts->set_name(QNL.item(i).toElement().attributeNode("Name").value());
					if(contain_key_GLbType(nts->get_name())){
						this->globalTypes->erase(nts->get_name());
						(*this->globalTypes)[nts->get_name()]=nts;
					}
					else{
						(*this->globalTypes)[nts->get_name()]=nts;
					}
				}
			}
		}

		bool  PositioningOntologyHandler::contain_key_GLbType(QString _name){
			for(std::map<QString,NamedTypeSpecification*>::iterator it =this->globalTypes->begin();it!=this->globalTypes->end();++it){
				if ((*it).second->get_name()==_name){
					return true;
				}
			}
			return false;
		}

		void PositioningOntologyHandler::initGlobalUnit(QDomElement  elem){
			//std::cerr << "entering init global unit" << std::endl;

			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="Units"){
					UnitSet * us = new UnitSet();
					us->set_name(QNL.item(i).toElement().attributeNode("Name").value());
					initUnit(QNL.item(i).toElement(),us);
					(*this->globalUnits)[us->get_name()]=us;
				}
			}
		}

		void PositioningOntologyHandler::initUnit(QDomElement  elem,VariableContextSpec *pc){
			UnitSet * us =new UnitSet();
			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="UnitsSource"){
					if(this->globalUnits->find(QNL.item(i).toElement().attributeNode("unitRef").value())==this->globalUnits->end()){
						us=new UnitSet();
					}
				}
				else if(QNL.item(i).toElement().tagName().toStdString()=="Units"){
					initUnit(QNL.item(i).toElement(),us);
				}
			}
			pc->set_unitSet(us);
		}

		void PositioningOntologyHandler::initUnit(QDomElement  elem,UnitSet * us){
			QDomNodeList QNL=elem.childNodes();
			Unit  * u=new Unit();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="Default"){
					//u = new Unit();
					u->set_name(QNL.item(i).toElement().attributeNode("Name").value());
					u->set_symbol(QNL.item(i).toElement().attributeNode("Symbol").value());
					us->set_defUnit(u);
				}
				if(QNL.item(i).toElement().tagName().toStdString()=="Unit"){
					ConvertableUnit * cu = new ConvertableUnit();
					cu->set_name(QNL.item(i).toElement().attributeNode("Name").value());
					cu->set_symbol(QNL.item(i).toElement().attributeNode("Symbol").value());
					cu->set_conversionString(QNL.item(i).toElement().attributeNode("Conversion").value());
					cu->set_defaultUnit(u);
					us->get_convUnits()->push_back(cu);
				}

			}
		}

		void PositioningOntologyHandler::initTypeDefine(QDomElement  elem,TypeSpecification *td){
			//std::cerr << "entering init type define typespec found !!!!!!!" << std::endl;
			QString baseType=elem.attributeNode("BaseType").value();
			if(baseType== "Number")
			{
				//std::cerr << "Number found !!!!!!!" << std::endl;
				td->set_baseType(Xeml::Document::Number);

			}
			else if(baseType== "Text")
			{
				td->set_baseType(Xeml::Document::Text);

			}
			else if(baseType== "Date")
			{
				td->set_baseType(Xeml::Document::Date);

			}
			else if(baseType== "Boolean")
			{
				td->set_baseType(Xeml::Document::Bool);

			}
			else{
				td->set_baseType(Xeml::Document::Text);
			}
			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				TypeSpecifics * ts = NULL;
				if(QNL.item(i).toElement().tagName().toStdString()=="Enum"){
					//std::cerr << "enum found !!!!!!!" << std::endl;
					ts=new Xeml::Document::EnvironmentalOntology::Enum();
				}
				else if(QNL.item(i).toElement().tagName().toStdString()=="Min"){
					//std::cerr << "Min found !!!!!!!" << std::endl;
				}
				else if(QNL.item(i).toElement().tagName().toStdString()=="Max"){

				}
				else if(QNL.item(i).toElement().tagName().toStdString()=="Exclude"){

				}
				else{

				}
				if(ts!= NULL){
					//std::cerr << "value :" << QNL.item(i).toElement().text().toStdString() << std::endl;
					ts->set_textVal(QNL.item(i).toElement().text());
					switch(td->get_baseType())
					{
						case Xeml::Document::Number:
						{

							ts->set_numberVal(QNL.item(i).toElement().text().toDouble());
							break;
						}
						case Xeml::Document::Text:
						{
							//std::cerr << "text found !!!!!!!" << std::endl;
							ts->set_textVal(QNL.item(i).toElement().text());
							break;
						}
						case Xeml::Document::Date:
						{
							//ts->set_dateVal(QNL.item(i).toElement().text());
							break;
						}
						case Xeml::Document::Bool:
						{
							break;
						}
						default:
						{
							ts->set_textVal(QNL.item(i).toElement().text());
							break;

						}
					}
					td->get_typeSpecifica()->push_back(ts);
					//std::cerr << "type specifica size : " << td->get_typeSpecifica()->size()  << std::endl;
				}
				else {
					//std::cerr << "Ts NULL cause no Min Object so type specifica empty!!!!!!!" << std::endl;
				}


			}

		}

		void PositioningOntologyHandler::initTypeDefine(QDomElement  elem,VariableContextSpec * pc){
			//std::cerr << "entering initTypeDefine ( poshandler)" << std::endl;
			TypeSpecification * ts =new TypeSpecification();
			QDomNodeList QNL=elem.childNodes();
			for (int i = 0; i < QNL.length(); i++) {
				if(QNL.item(i).toElement().tagName().toStdString()=="TypeSource"){
					//std::cerr << "type source found !!!!!!!" << std::endl;
					//NamedTypeSpecification * nts;
					if (this->globalTypes->find(QNL.item(i).toElement().attributeNode("typeRef").value())!=this->globalTypes->end()){
						//std::cerr << "typeRef found !!!!!!!" << std::endl;
						for(std::map<QString,NamedTypeSpecification *>::iterator it=this->globalTypes->begin();it!=this->globalTypes->end();++it){
							if(QNL.item(i).toElement().attributeNode("typeRef").value()==(*it).first){
								//std::cerr << (*it).first.toStdString() << std::endl;
								ts=(*it).second;
								//ts=nts;
							}
						}
					}
				}
				else if (QNL.item(i).toElement().tagName().toStdString()=="TypeDefine"){
					//std::cerr << "type define found !!!!!!!" << std::endl;
					initTypeDefine(QNL.item(i).toElement(),ts);
				}
				else{
					//std::cerr << "PROBLEM !!!!!!!" << std::endl;

				}
			}
			pc->set_typeDefine(ts);
			//std::cerr << "size type specifica : "<< pc->get_typeDefine()->get_typeSpecifica()->size() << std::endl;
		}

		//end region
	}
}
