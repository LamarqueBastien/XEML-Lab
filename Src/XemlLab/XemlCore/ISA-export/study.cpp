#include "study.h"
namespace XemlUtilities{

	namespace ISA{
		Study::Study(ItfDocument * _xemlDoc,QObject *parent) : IsaTable(parent)
		{
			Q_UNUSED(_xemlDoc);
		}
		void Study::get_stream(ItfDocument * _xemlDoc,QFile * _studyfile){


			QTextStream My_study(_studyfile);


			std::vector<QString> * source_name=new std::vector<QString>();
			source_name->push_back("Source Name");

			//organism part
			std::vector<QString> * characterictics_organism_part=new std::vector<QString>();
			characterictics_organism_part->push_back("characterictics[organism part]");
			std::vector<QString> * organism_part_term_source_ref=new std::vector<QString>();
			organism_part_term_source_ref->push_back("Term Source REF");
			std::vector<QString> * organism_part_term_accession_number=new std::vector<QString>();
			organism_part_term_accession_number->push_back("Term Accession Number");

			//organism
			std::vector<QString> * characterictics_organism=new std::vector<QString>();
			characterictics_organism->push_back("characterictics[organism]");
			std::vector<QString> * organism_term_source_ref=new std::vector<QString>();
			organism_term_source_ref->push_back("Term Source REF");
			std::vector<QString> * organism_term_accession_number=new std::vector<QString>();
			organism_term_accession_number->push_back("Term Accession Number");


			//creer un vecteur pour chaque variable et chaque context de variable
			//for each variable context{
				//std::vector<QString> * header=new std::vector<QString>();

				//std::vector<QString> * unit=new std::vector<QString>();

				//std::vector<QString> * term_source_ref=new std::vector<QString>();

				//std::vector<QString> * term_accession_number=new std::vector<QString>();
			//}




			int cpt_story=0;
			for( std::list<StoryNode*>::iterator it=_xemlDoc->get_storyboard()->get_storyBoard()->begin();it!=_xemlDoc->get_storyboard()->get_storyBoard()->end();++it){
				StoryNode *tmp_node=static_cast<StoryNode*>((*it));
				cpt_story++;
				for(std::vector<std::pair<Sample*,int> >::iterator it2=tmp_node->get_story()->get_samplesCollection()->begin();it2!=tmp_node->get_story()->get_samplesCollection()->end();++it2){
					Sample * tmp_sample=static_cast<Sample*>((*it2).first);
					for (std::vector<std::pair<QString, std::vector<std::pair<SampleIdMapping*,int> > *> >::iterator it3=static_cast<XemlDocument*>(_xemlDoc)->get_provider_data_mapping()->get_provider()->begin();it3!=static_cast<XemlDocument*>(_xemlDoc)->get_provider_data_mapping()->get_provider()->end();++it3){
						QString providername=static_cast<QString>((*it3).first);
						std::vector<std::pair<SampleIdMapping*,int> > * sampleIdVector=static_cast<std::vector<std::pair<SampleIdMapping*,int> > *>((*it3).second);
						for (std::vector<std::pair<SampleIdMapping*,int> >::iterator it4 = sampleIdVector->begin();it4!=sampleIdVector->end();++it4){
							if(static_cast<Sample*>((*it2).first)->get_id()==static_cast<SampleIdMapping*>((*it4).first)->get_sampleId()){
								SampleIdMapping* tmp_sid=static_cast<SampleIdMapping*>((*it4).first);
								if(tmp_sid->get_foreignKeyMap()->count()!=0){
									QString sn="rg"+QString::number(cpt_story);
									source_name->push_back(sn);
									Partition * first_partition=static_cast<Partition*>(tmp_sample->get_partitions()->at(0));
									for (std::map<BasicTerm*,QString>::iterator it5 = first_partition->get_materialCollection()->begin();it5!=static_cast<Partition*>(tmp_sample->get_partitions()->at(0))->get_materialCollection()->end();++it5){
										VariableTerm * tmp_struct_term=static_cast<VariableTerm*>((*it5).first);
										characterictics_organism_part->push_back(tmp_struct_term->get_name());
										organism_part_term_source_ref->push_back(tmp_struct_term->get_namespacealias());
										organism_part_term_accession_number->push_back(tmp_struct_term->get_termId());
									}


									for(std::vector<std::pair<ObservationPoint*,QDateTime> >::iterator it6=tmp_node->get_story()->get_obsPointCollection()->begin();it6!=tmp_node->get_story()->get_obsPointCollection()->end();++it6){
										ObservationPoint * op=static_cast<ObservationPoint*>((*it6).first);
										//qint64 milliseconds_ellapsed=get_seconds_from_date(_xemlDoc->get_startdate(),op->get_timepoint());

										//modelTable->setItem(cpt,2,new QStandardItem(translate_second_in_DD_HH_MM_SS(milliseconds_ellapsed)));
										//modelTable->setItem(cpt,3,new QStandardItem(xemlDoc->get_startdate().toString("yyyy-MM-dd hh:mm:ss")));


										QString tmp_pool="";
										//QString ind_ids="";
										for(std::vector<pair<Observation*,QDateTime> >::iterator it6=op->get_observationscollection()->begin();it6!=op->get_observationscollection()->end();++it6){
											Observation *  o=static_cast<Observation*>((*it6).first);
											//for(std::map<BasicTerm*,QString>::iterator it7=o->get_stageCollection()->begin();it7!=o->get_stageCollection()->end();++it7){
											//	modelTable->setItem(cpt,6,new QStandardItem(static_cast<VariableTerm*>((*it7).first)->get_name()));

											//}


											for(std::map<Partition*,int>::iterator it8=o->get_partitionCollection()->begin();it8!=o->get_partitionCollection()->end();++it8){
												//for (int i =0;i<id_parts.count();i++){
												if (static_cast<Partition*>((*it8).first)->get_id()==first_partition->get_id()){
													tmp_pool=o->get_pool()->get_germplasm();
													characterictics_organism->push_back(tmp_pool);
													organism_term_source_ref->push_back("EFO");
													if (o->get_pool()->get_annotation_by_tag("NcbiTaxonomyId")!=""){
														QString accnum="NCBITaxon:"+o->get_pool()->get_annotation_by_tag("NcbiTaxonomyId");
														organism_term_accession_number->push_back(accnum);
													}
												}

											}
											//modelTable->setItem(cpt,5,new QStandardItem(tmp_pool));
											//modelTable->setItem(cpt,9,new QStandardItem(ind_ids));
										}
									}
								}
							}
						}
					}

				}

			}
			for (int i=0;i<organism_part_term_accession_number->size();i++){
				My_study <<  IsaExporter::encapsulate(source_name->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(characterictics_organism_part->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(organism_part_term_source_ref->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(organism_part_term_accession_number->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(characterictics_organism->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(organism_term_source_ref->at(i)) << "\t"
						 //<<  IsaExporter::encapsulate(organism_term_accession_number->at(i)) << "\t"
						 //<<  IsaExporter::encapsulate(characterictics_organism->at(i)) << "\t"
						 //<<  IsaExporter::encapsulate(characterictics_organism->at(i)) << "\t"
						 //<<  IsaExporter::encapsulate(characterictics_organism->at(i)) << "\t"
						 //<<  IsaExporter::encapsulate(characterictics_organism->at(i)) << "\t"
						 <<  IsaExporter::encapsulate(organism_term_accession_number->at(i))<< "\n";
			}
			//each vector represents a column in story ISA file.
			//vector source name

			//Material stuff
			//vector characterictics[organism part]
			//vector characterictics organism part term source ref
			//vector characterictics organism part term accesssion number

			//Germplasm Stuff
			//vector characterictics[organism]
			//vector characterictics organism term source ref (ontology EFO à créer)
			//vector characterictics organism  term accesssion number

			//vector protocol ref

			//Xeo Stuff
			//vector header
			//vector dcunit
			//vector term source ref
			//vector term accesssion number

			//smallmolecule_abundance_std_error_sub

			//Sample stuff
			//vector samplename

		}

		QString Study::get_fileName(ItfDocument * _xemlDoc){
			QString ret("/s_"+static_cast<XemlDocument*>(_xemlDoc)->get_experiment_name());
			return ret;
		}
	}
}
