#include "observationwizard.h"
#include"observationintropage.h"
#include"observationgenotypepage.h"
#include"observationdetailspage.h"
#include"observationmaterialpage.h"
std::vector<ObservationDetails *> * ObservationWizard::observations=new std::vector<ObservationDetails *>();

ObservationWizard::ObservationWizard(StoryNode * _current,StoryNode * _root,ObservationPoint * _obs,DocumentResources * _doc_resources,ItfDocument * _doc, QWidget *parent)
	: QWizard(parent)
{
	this->observations->clear();
	this->setMinimumHeight(700);
	this->setMinimumWidth(1100);
	this->doc_resources = _doc_resources;
	this->storyRoot=_root;
	this->current_storynode=_current;
	this->obspoint = _obs;
	this->xeml_doc=_doc;
	QStringList * genList=new QStringList;
	for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(_root->get_story())->get_individualspoolcollection()->begin();it!= static_cast<Story*>(_root->get_story())->get_individualspoolcollection()->end();++it){
		genList->append((*it).second);
	}
	/*
	if (genList->empty()){
		int r = QMessageBox::warning(this, tr("XemlDocument"),
		tr("No pool germplasm for this story.\n"
		   "You need to add a genotype to the root Story"),
		QMessageBox::Ok | QMessageBox::Default);
		if (r == QMessageBox::Ok) {
			std::cerr << "OK clicked" << std::endl;
			return -1;
		}
	}
	*/


	addPage(new ObservationIntroPage);
	addPage(new ObservationGenotypePage(genList));
	addPage(new ObservationDetailsPage(this->doc_resources,this->storyRoot));
	//addPage(new ObservationMaterialPage(this->doc_resources));
	setWindowTitle("defines sampling strategy for genotype ");
	connect(this,SIGNAL(destroyed()),this,SLOT(close()));

}
std::vector<ObservationDetails *> * ObservationWizard::get_observations(){
	return observations;
}

void ObservationWizard::accept(){
	std::cerr << "entering accept end of sample loader" << std::endl;
	//int replica=field("Replica").toInt();
	this->indexlist=new QModelIndexList;
	(*indexlist)=static_cast<QItemSelectionModel*>(field("genViewSelection").value<QItemSelectionModel*>())->selectedRows();
	for (int i=0;i<indexlist->size();i++){
		std::cerr << "index list germplasm :" << indexlist->at(i).data().toString().toStdString() << std::endl;

	}
	for (std::vector<ObservationDetails*>::iterator it=ObservationWizard::get_observations()->begin();it!=ObservationWizard::get_observations()->end();++it){
		ObservationDetails * tmp=static_cast<ObservationDetails*>((*it));
		QList<BasicTerm *> dev_list;
		QList<BasicTerm *> struct_list;
		QList<Sample*> sample_list;

		//first way : using a model to define all individuals
		if (tmp->get_template_check_box()->isChecked()){
			std::cerr << "use model" << std::endl;

			for (int h=0;h<indexlist->size();h++){
				for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){

					if((*it).second==indexlist->at(h).data().toString()){
						IndividualsPool * tmp_pool=static_cast<IndividualsPool*>((*it).first);
						QStandardItem * root_item=tmp->get_model()->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0];
						if(root_item->hasChildren()){

							//premier passage pour récupérer les stades de devellopement et les partitions du modèle
							for (int i =0;i<root_item->rowCount();i++){

								if(root_item->child(i)->checkState()==Qt::Checked && root_item->child(i)->isEnabled()){
									QStandardItem * model_item=root_item->child(i);
									if(model_item->hasChildren()){
										for (int j =0;j<model_item->rowCount();j++){

											if(model_item->child(j)->text()=="developmental-stage"){
												if(model_item->child(j)->hasChildren()){
													for (int k =0;k<model_item->child(j)->rowCount();k++){
														QStandardItem * dev_item = model_item->child(j)->child(k);
														QString id=dev_item->text().remove("(");
														id.remove(")");
														QStringList dev_string_list=id.split("-");
														QString devname=dev_string_list.at(0);
														QString devid=dev_string_list.at(1);
														//devid.remove(" ");

														BasicTerm * devTerm= new BasicTerm(devid);
														devTerm->set_name(devname);
														devTerm->set_namespacealias("PO_Development");
														std::list<TermNode*>  * my_devtree=static_cast<DevelopmentalOntologyHandler*>((*doc_resources->get_devHandler())["PO_Development"]->get_handler())->get_listNodes();
														for (std::list<TermNode*>::iterator it=my_devtree->begin();it!=my_devtree->end();++it){
															if (static_cast<TermNode*>((*it))->get_term()->get_termId()==devTerm->get_termId()){
																BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
																for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){

																	devTerm->add_tagged_annotation((*it2).first);
																}
																//delete test;
															}
														}
														dev_list.append(devTerm);
													}

												}
											}
											else if(model_item->child(j)->text()=="partitions"){
												QStandardItem * partition_item=model_item->child(j);
												if(partition_item->hasChildren()){

													for (int k =0;k<partition_item->rowCount();k++){
														if (partition_item->child(k)->text()=="structure"){
															QStandardItem * struct_item=partition_item->child(k);
															if(struct_item->hasChildren()){
																for (int l =0;l<struct_item->rowCount();l++){

																	QStandardItem * structchild_item=struct_item->child(l);

																	QString id=structchild_item->text().remove("(");
																	id.remove(")");
																	std::cerr << "struct id : "<< id.toStdString() << std::endl;
																	QStringList struct_string_list=id.split("-");
																	std::cerr <<"list size in accept() : " << struct_string_list.size() << std::endl;
																	QString structname=struct_string_list.at(0);
																	QString structid=struct_string_list.at(1);
																	//structid.remove(" ");
																	BasicTerm * structTerm =new BasicTerm(structid);
																	structTerm->set_namespacealias("PO_Structure");
																	structTerm->set_name(structname);
																	std::list<TermNode*>  * my_structree=static_cast<PlantStructureOntologyHandler*>((*doc_resources->get_structHandler())["PO_Structure"]->get_handler())->get_listNodes();

																	for (std::list<TermNode*>::iterator it=my_structree->begin();it!=my_structree->end();++it){
																		if (static_cast<TermNode*>((*it))->get_term()->get_termId()==structTerm->get_termId()){
																			BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
																			std::cerr << "displaying tag annotation" << std::endl;
																			test->display_all_tags();
																			std::cerr << "end displaying tag annotation" << std::endl;
																			for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){
																				structTerm->add_tagged_annotation((*it2).first);

																				//structTerm->add_tagged_annotation(new TaggedAnnotation("def",static_cast<TermNode*>((*it))->get_term()->get_definition()));
																			}
																			//delete test;

																		}
																	}
																	struct_list.append(structTerm);
																}
															}

														}
														if (partition_item->child(k)->text()=="position"){


														}
													}

												}

											}
										}
									}


								}
							}
							//second passage pour ajouter les observations correspondantes

							//if pooling box is checked, join together all partition with same material term
							if(tmp->get_pooling_check_box()->checkState()==Qt::Checked){

								for (int i=0;i<struct_list.size();i++){
									Sample * s=new Sample();
									static_cast<Story*>(this->storyRoot->get_story())->increment_sample_count();
									s->set_id(static_cast<Story*>(this->storyRoot->get_story())->get_sample_count());
									this->current_storynode->get_story()->add_sample(s);
									sample_list.append(s);
								}
								for(std::map<Individual*,int>::iterator it= tmp_pool->get_individualscollection()->begin();it!= tmp_pool->get_individualscollection()->end();++it){
									Individual *tmp_individual=static_cast<Individual*>((*it).first);
									if (!tmp_individual->is_destroyed()){
										Observation * ob = new Observation();
										QString test=tmp->get_time()->dateTime().toString("hh:mm:ss");
										ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));


										//check here to change from destructive to non destructive
										if (tmp->get_destruct_check_box()->checkState()==Qt::Checked){
											ob->set_destructiveinfo(true);
											tmp_individual->set_is_destroyed(true);
										}
										else{
											ob->set_destructiveinfo(false);
										}

										ob->set_ind((*it).first);
										ob->set_pool(tmp_pool);
										for (int i=0;i<dev_list.size();i++){
											if(!(ob->contain_stages(dev_list.at(i)->get_termId()))){
												ob->add_stage(dev_list.at(i));
											}
										}
										for (int i=0;i<struct_list.size();i++){
											Partition * p = new Partition();
											this->current_storynode->get_story()->story_partition_counter++;
											p->set_id(this->current_storynode->get_story()->story_partition_counter);
											//static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
											//p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);
											p->addMaterialTerm(struct_list.at(i));
											if(!(ob->contain_partition(p))){
												ob->add_partition(p);
											}
											sample_list.at(i)->add_partition(p);

										}
										ob->set_individualInfluence(false);

										this->obspoint->add_observation(ob);
									}
								}



							}
							//if pooling box isn't checked
							else{
								for(std::map<Individual*,int>::iterator it= tmp_pool->get_individualscollection()->begin();it!= tmp_pool->get_individualscollection()->end();++it){
									Individual *tmp_individual=static_cast<Individual*>((*it).first);
									if (!tmp_individual->is_destroyed()){

										Observation * ob = new Observation();
										QString test=tmp->get_time()->dateTime().toString("hh:mm:ss");
										ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));


										//check here to change from destructive to non destructive
										if (tmp->get_destruct_check_box()->checkState()==Qt::Checked){

											ob->set_destructiveinfo(true);
											tmp_individual->set_is_destroyed(true);

										}
										else{
											ob->set_destructiveinfo(false);

										}
										ob->set_ind(tmp_individual);
										ob->set_pool(tmp_pool);

										for (int i=0;i<dev_list.size();i++){
											if(!(ob->contain_stages(dev_list.at(i)->get_termId()))){
												ob->add_stage(dev_list.at(i));
											}
										}
										for (int i=0;i<struct_list.size();i++){
											Partition * p = new Partition();
											this->current_storynode->get_story()->story_partition_counter++;
											p->set_id(this->current_storynode->get_story()->story_partition_counter);
											//static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
											//p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);
											p->addMaterialTerm(struct_list.at(i));
											if(!(ob->contain_partition(p))){
												ob->add_partition(p);
											}
											Sample * s=new Sample();
											s->add_partition(p);
											static_cast<Story*>(this->storyRoot->get_story())->increment_sample_count();
											s->set_id(static_cast<Story*>(this->storyRoot->get_story())->get_sample_count());
											this->current_storynode->get_story()->add_sample(s);

										}
										//p->addPositionTerm(posTerm);



										ob->set_individualInfluence(false);

										this->obspoint->add_observation(ob);
									}

								}
							}
							dev_list.clear();
							struct_list.clear();
							sample_list.clear();


							//for (int i =0;i<root_item->rowCount();i++){
								//if(root_item->child(i)->checkState()==Qt::Checked){
								//QStandardItem * ind_item=root_item->child(i);



								//}

							//}

						}
					}
				}
			}

		}
		//second way : only individuals clicked will be observed
		else{
			std::cerr << "not use model individual" << std::endl;

			QStandardItem * root_item=tmp->get_model()->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0];
			Individual * tmp_ind;
			IndividualsPool * tmp_pool;
			if(root_item->hasChildren()){
				for (int i =0;i<root_item->rowCount();i++){


					//individuals items
					QStandardItem * child_item=root_item->child(i);


					if (child_item->checkState()==Qt::Checked){

						//item is selected so retrieve information for each child (variables or other individuals)
						if(child_item->hasChildren()){


							//start for each child loop
							for (int j =0;j<child_item->rowCount();j++){
								if(child_item->child(j)->text()=="developmental-stage"){
									if(child_item->child(j)->hasChildren()){
										for (int k =0;k<child_item->child(j)->rowCount();k++){
											QStandardItem * dev_item = child_item->child(j)->child(k);
											QString id=dev_item->text().remove("(");
											id.remove(")");
											QStringList dev_string_list=id.split("-");
											QString devname=dev_string_list.at(0);
											QString devid=dev_string_list.at(1);
											//devid.remove(" ");

											BasicTerm * devTerm= new BasicTerm(devid);
											devTerm->set_name(devname);
											devTerm->set_namespacealias("PO_Development");
											std::list<TermNode*>  * my_devtree=static_cast<DevelopmentalOntologyHandler*>((*doc_resources->get_devHandler())["PO_Development"]->get_handler())->get_listNodes();
											for (std::list<TermNode*>::iterator it=my_devtree->begin();it!=my_devtree->end();++it){
												if (static_cast<TermNode*>((*it))->get_term()->get_termId()==devTerm->get_termId()){
													BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
													for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){

														devTerm->add_tagged_annotation((*it2).first);
													}
													//delete test;
												}
											}
											dev_list.append(devTerm);
										}
									}
								}
								if(child_item->child(j)->text()=="partitions"){
									QStandardItem * partition_item=child_item->child(j);
									if(partition_item->hasChildren()){

										for (int k =0;k<partition_item->rowCount();k++){
											if (partition_item->child(k)->text()=="structure"){
												QStandardItem * struct_item=partition_item->child(k);
												if(struct_item->hasChildren()){
													for (int l =0;l<struct_item->rowCount();l++){

														QStandardItem * structchild_item=struct_item->child(l);

														QString id=structchild_item->text().remove("(");
														id.remove(")");
														std::cerr << "struct id : "<< id.toStdString() << std::endl;
														QStringList struct_string_list=id.split("-");
														std::cerr <<"list size in accept() : " << struct_string_list.size() << std::endl;
														QString structname=struct_string_list.at(0);
														QString structid=struct_string_list.at(1);
														//structid.remove(" ");
														BasicTerm * structTerm =new BasicTerm(structid);
														structTerm->set_namespacealias("PO_Structure");
														structTerm->set_name(structname);
														std::list<TermNode*>  * my_structree=static_cast<PlantStructureOntologyHandler*>((*doc_resources->get_structHandler())["PO_Structure"]->get_handler())->get_listNodes();

														for (std::list<TermNode*>::iterator it=my_structree->begin();it!=my_structree->end();++it){
															if (static_cast<TermNode*>((*it))->get_term()->get_termId()==structTerm->get_termId()){
																BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
																std::cerr << "displaying tag annotation" << std::endl;
																test->display_all_tags();
																std::cerr << "end displaying tag annotation" << std::endl;
																for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){
																	structTerm->add_tagged_annotation((*it2).first);

																	//structTerm->add_tagged_annotation(new TaggedAnnotation("def",static_cast<TermNode*>((*it))->get_term()->get_definition()));
																}
																//delete test;

															}
														}
														struct_list.append(structTerm);
													}
												}

											}

										}

									}
								}
								/*
								if(child_item->child(j)->isCheckable() && child_item->child(j)->checkState()==Qt::Checked){
									QStandardItem * sub_child_item=child_item->child(j);
									QString sub_ind_id=sub_child_item->text().remove("(");
									sub_ind_id.remove(")");
									QStringList ind_string_list=sub_ind_id.split("-");
									QString sub_ind_id=ind_string_list.at(0);
									QString sub_germ_id=ind_string_list.at(1);
									for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
										if((*it).second==sub_germ_id){
											IndividualsPool * tmp_pool=static_cast<IndividualsPool*>((*it).first);
											for(std::map<Individual*,int>::iterator it2= tmp_pool->get_individualscollection()->begin();it2!= tmp_pool->get_individualscollection()->end();++it2){
												if(static_cast<Individual*>((*it2).first)->get_id()==sub_ind_id){
													Individual * tmp_ind=static_cast<Individual*>((*it2).first);
												}
											}
										}
									}
								}
								*/

							}//end of for each child loop
							//restart for each child loop
							for (int j =0;j<child_item->rowCount();j++){
								if(child_item->child(j)->isCheckable() && child_item->child(j)->checkState()==Qt::Checked){
									QStandardItem * sub_child_item=child_item->child(j);
									QString sub_ind=sub_child_item->text().remove("(");
									sub_ind.remove(")");
									QStringList ind_string_list=sub_ind.split("-");
									QString sub_ind_id=ind_string_list.at(0);
									QString sub_germ_id=ind_string_list.at(1);
									for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
										if((*it).second==sub_germ_id){
											tmp_pool=static_cast<IndividualsPool*>((*it).first);
											for(std::map<Individual*,int>::iterator it2= tmp_pool->get_individualscollection()->begin();it2!= tmp_pool->get_individualscollection()->end();++it2){
												if(static_cast<Individual*>((*it2).first)->get_id()==sub_ind_id.toInt()){
													tmp_ind=static_cast<Individual*>((*it2).first);
												}
											}
										}
									}

									Observation * ob = new Observation();
									QString test=tmp->get_time()->dateTime().toString("hh:mm:ss");
									ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));


									//check here to change from destructive to non destructive
									ob->set_destructiveinfo(true);
									ob->set_ind(tmp_ind);
									ob->set_pool(tmp_pool);

									for (int i=0;i<dev_list.size();i++){
										if(!(ob->contain_stages(dev_list.at(i)->get_termId()))){
											ob->add_stage(dev_list.at(i));
										}
									}
									for (int i=0;i<struct_list.size();i++){
										Partition * p = new Partition();
										this->current_storynode->get_story()->story_partition_counter++;
										p->set_id(this->current_storynode->get_story()->story_partition_counter);
										//static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
										//p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);
										p->addMaterialTerm(struct_list.at(i));
										if(!(ob->contain_partition(p))){
											ob->add_partition(p);
										}
									}
									//p->addPositionTerm(posTerm);



									ob->set_individualInfluence(false);

									this->obspoint->add_observation(ob);
									//describe a new observation for sub child item
								}

							}



						}//end of "if(child_item->hasChildren()){"
						QString ind=child_item->text().remove("(");
						ind.remove(")");
						QStringList ind_string_list=ind.split("-");
						QString ind_id=ind_string_list.at(0);
						QString germ_id=ind_string_list.at(1);
						for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
							if((*it).second==germ_id){
								tmp_pool=static_cast<IndividualsPool*>((*it).first);
								for(std::map<Individual*,int>::iterator it2= tmp_pool->get_individualscollection()->begin();it2!= tmp_pool->get_individualscollection()->end();++it2){
									if(static_cast<Individual*>((*it2).first)->get_id()==ind_id.toInt()){
										tmp_ind=static_cast<Individual*>((*it2).first);
									}
								}
							}
						}
						Observation * ob = new Observation();
						QString test=tmp->get_time()->dateTime().toString("hh:mm:ss");
						ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));


						//check here to change from destructive to non destructive
						ob->set_destructiveinfo(true);
						ob->set_ind(tmp_ind);
						ob->set_pool(tmp_pool);

						for (int i=0;i<dev_list.size();i++){
							if(!(ob->contain_stages(dev_list.at(i)->get_termId()))){
								ob->add_stage(dev_list.at(i));
							}
						}
						for (int i=0;i<struct_list.size();i++){
							Partition * p = new Partition();
							this->current_storynode->get_story()->story_partition_counter++;
							p->set_id(this->current_storynode->get_story()->story_partition_counter);
							//static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
							//p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);
							p->addMaterialTerm(struct_list.at(i));
							if(!(ob->contain_partition(p))){
								ob->add_partition(p);
							}

						}
						//p->addPositionTerm(posTerm);



						ob->set_individualInfluence(false);

						this->obspoint->add_observation(ob);
						//clear variables collection
						dev_list.clear();
						struct_list.clear();

						//here describe a new observation for child item children


						/*
						for (int j=0;j<indexlist->size();j++){
							for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
								if((*it).second==indexlist->at(j).data().toString()){
									IndividualsPool * tmp_pool=static_cast<IndividualsPool*>((*it).first);
									QString pool_name=tmp_pool->get_germplasm();
								}
							}
						}
						*/
					}//end of if child_item->isChecked()

				}
			}
		}
	}


	/*
	 *older version
	for (int j=0;j<indexlist->size();j++){
		for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
			if((*it).second==indexlist->at(j).data().toString()){
				for (std::vector<ObservationDetails*>::iterator it=ObservationWizard::get_observations()->begin();it!=ObservationWizard::get_observations()->end();++it){
					ObservationDetails * tmp=static_cast<ObservationDetails*>((*it));
					//Ajouter to


					QStandardItem * root_item=tmp->get_model()->findItems("Observations",Qt::MatchFixedString | Qt::MatchRecursive)[0];
					if(root_item->hasChildren()){
						std::cerr << " accept : row count: " << root_item->rowCount() << std::endl;
						for (int i =0;i<root_item->rowCount();i++){
							root_item->child(i);
							Observation * ob = new Observation();
							QString test=QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss");
							ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));
							if(tmp->get_destruct_check_box()->isChecked()){
								std::cerr << "destruct box is checked" << std::endl;
								ob->set_destructiveinfo(true);
								//static_cast<IndividualsPool*>((*it).first)->get_individualscollection()->at(i)

							}
							else{
								ob->set_destructiveinfo(false);

								std::cerr << "destruct box is not checked" << std::endl;

							}
							if(tmp->get_template_check_box()->isChecked()){

							}
							else{

							}
						}
					}
				}
			}
		}
	}
	*/
	/*
	for (int j=0;j<indexlist->size();j++){
		for(std::map<IndividualsPool*,QString>::iterator it= static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->begin();it!=static_cast<Story*>(this->storyRoot->get_story())->get_individualspoolcollection()->end();++it){
			if((*it).second==indexlist->at(j).data().toString()){
			//if((*it).second==field("GermPlasm").toString()){
				for(int i = 0; i<field("Individuals").toInt();i++){

					Individual * ind = new Individual(1+ rand() % 1000000000);

					Sample * s=new Sample();
					static_cast<Story*>(this->storyRoot->get_story())->increment_sample_count();
					s->set_id(static_cast<Story*>(this->storyRoot->get_story())->get_sample_count());
					this->current_storynode->get_story()->add_sample(s);
					static_cast<IndividualsPool*>((*it).first)->add_Individual(ind);

					Observation * ob = new Observation();
					QString test=QDateTime::fromString(field("Duration").toString(),"yyyy-MM-ddThh:mm:ss").toString("hh:mm:ss");
					ob->set_duration(QDateTime::fromString(test,"hh:mm:ss"));


					//check here to change from destructive to non destructive
					ob->set_destructiveinfo(true);
					ob->set_ind(ind);
					ob->set_pool((*it).first);

					Partition * p = new Partition();
					static_cast<XemlDocument*>(this->xeml_doc)->partition_counter+=1;
					p->set_id(static_cast<XemlDocument*>(this->xeml_doc)->partition_counter);

					BasicTerm * devTerm= new BasicTerm(field("DevTermId").toString());
					devTerm->set_name(field("DevName").toString());
					devTerm->set_namespacealias("PO_Development");
					std::list<TermNode*>  * my_devtree=static_cast<DevelopmentalOntologyHandler*>((*doc_resources->get_devHandler())["PO_Development"]->get_handler())->get_listNodes();
					for (std::list<TermNode*>::iterator it=my_devtree->begin();it!=my_devtree->end();++it){
						if (static_cast<TermNode*>((*it))->get_term()->get_termId()==devTerm->get_termId()){
							BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
							for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){

								devTerm->add_tagged_annotation((*it2).first);
							}
							//delete test;
						}
					}



					BasicTerm * structTerm =new BasicTerm(field("StructTermID").toString());
					structTerm->set_namespacealias("PO_Structure");
					structTerm->set_name(field("structName").toString());
					std::list<TermNode*>  * my_structree=static_cast<PlantStructureOntologyHandler*>((*doc_resources->get_structHandler())["PO_Structure"]->get_handler())->get_listNodes();

					for (std::list<TermNode*>::iterator it=my_structree->begin();it!=my_structree->end();++it){
						if (static_cast<TermNode*>((*it))->get_term()->get_termId()==structTerm->get_termId()){
							BasicTerm  * test=static_cast<SimpleOboTerm*>(static_cast<TermNode*>((*it))->get_term())->get_prototype();
							//std::cerr << "displaying tag annotation" << std::endl;
							//test->display_all_tags();
							//std::cerr << "end displaying tag annotation" << std::endl;
							for (std::map<TaggedAnnotation*,QString>::iterator it2=test->get_taggedannotation()->begin();it2!=test->get_taggedannotation()->end();++it2){
								structTerm->add_tagged_annotation((*it2).first);

								//structTerm->add_tagged_annotation(new TaggedAnnotation("def",static_cast<TermNode*>((*it))->get_term()->get_definition()));
							}
							//delete test;

						}
					}

					VariableTerm * posTerm=new VariableTerm(field("PosTermId").toString());
					posTerm->set_namespacealias("XEO_Positioning");
					posTerm->set_name(field("PosTermName").toString());

					Value * quantityContext= new Value();
					quantityContext->set_context("Quantity");
					quantityContext->set_unit(field("Unit").toString());
					quantityContext->set_value(field("QValue").toString());
					posTerm->add_value(quantityContext);

					Value * qualityContext =new Value();
					qualityContext->set_context("Quality");
					qualityContext->set_value(field("Value").toString());
					posTerm->add_value(qualityContext);

					p->addPositionTerm(posTerm);
					p->addMaterialTerm(structTerm);
					if(!(ob->contain_stages(field("DevTermId").toString()))){
						ob->add_stage(devTerm);
					}
					if(!(ob->contain_partition(p))){
						ob->add_partition(p);
					}
					ob->set_individualInfluence(false);

					this->obspoint->add_observation(ob);
				}
			}

		}
	}
	*/

	QDialog::accept();
 }






















/*
QWizardPage * ObservationWizard::createIntroPage(){
	QWizardPage *page = new QWizardPage;
	page->setTitle("Introduction");

	QLabel * label = new QLabel("This wizard will help you register your observation "
							   "point.");
	label->setWordWrap(true);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	page->setLayout(layout);

	return page;
}

QWizardPage * ObservationWizard::createRegistrationPage(){
	QWizardPage * Regpage = new QWizardPage;
	Regpage->setTitle("GermPlasm");
	Regpage->setSubTitle("Please fill both fields.");

	QLabel *nameLabel = new QLabel("Name:");
	QLineEdit *nameLineEdit = new QLineEdit;
	//Regpage->registerField("LabelName*", nameLineEdit);

	QLabel *emailLabel = new QLabel("Email address:");
	QLineEdit *emailLineEdit = new QLineEdit;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel, 0, 0);
	layout->addWidget(nameLineEdit, 0, 1);
	layout->addWidget(emailLabel, 1, 0);
	layout->addWidget(emailLineEdit, 1, 1);
	Regpage->setLayout(layout);

	return Regpage;
}
QWizardPage * ObservationWizard::createMaterialPage(){
	QWizardPage *page = new QWizardPage;

	page->setTitle("Material");
	page->setSubTitle("Please fill both fields.");

	QLabel *nameLabel = new QLabel("Name:");
	QLineEdit *nameLineEdit = new QLineEdit;


	QLabel *emailLabel = new QLabel("Email address:");
	QLineEdit *emailLineEdit = new QLineEdit;

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel, 0, 0);
	layout->addWidget(nameLineEdit, 0, 1);
	layout->addWidget(emailLabel, 1, 0);
	layout->addWidget(emailLineEdit, 1, 1);
	page->setLayout(layout);

	return page;
}


QWizardPage * ObservationWizard::createConclusionPage(){
	//le signal de retour sera émis à partir de cette fonction
	//qui renverra toutes les données collectées
	QWizardPage *page = new QWizardPage;
	page->setTitle("Conclusion");

	QLabel *label = new QLabel("You are now successfully registered. Have a "
							   "nice day!");
	label->setWordWrap(true);

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(label);
	page->setLayout(layout);

	return page;
}

QWizard * ObservationWizard::get_wizard(){
	return this->wizard;
}
*/
