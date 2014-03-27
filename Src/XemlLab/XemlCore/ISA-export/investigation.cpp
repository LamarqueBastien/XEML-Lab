#include "investigation.h"

namespace XemlUtilities{

	namespace ISA{

		Investigation::Investigation()
		{

		}
		void Investigation::get_stream(ItfDocument *_xemlDoc, QFile *_investigationfile){

			QTextStream My_investigation(_investigationfile);
			//My_investigation << "hello world, I'm ben";

			My_investigation << "ONTOLOGY SOURCE REFERENCE\n" ;
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new[] {"Term Source Name"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, new[] {"OBI", "NCBITaxon", "XEO", "PO_Structure", "EO", "XEO_Positioning", "Chemical Methods Ontology" }))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new[] {"Term Source File"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, new[] {string.Empty, "http://bioportal.bioontology.org/ontologies/38802", "http://bioportal.bioontology.org/ontologies/3176", "http://www.plantontology.org/", "http://bioportal.bioontology.org/ontologies/45260", string.Empty, "http://www.rsc.org/ontologies/CMO/"}))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new[] {"Term Source Version"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, new[] {string.Empty, "38802", "today", "today", "today", "today", ""}))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new[] {"Term Source Description"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, new[] {"Ontology for Biomedical Investigations", "NCBI organismal classification", "XEML Environmental Ontology", "Plant Ontology (Structure)", "Plant Environmental Ontology", "XEML Plant Positioning Ontology", "Chemical Methods Ontology"}))));

			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new [] {"Term Source Name"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, OntologyBase.GetOntologies().Select(x => x.Acronym).ToArray()))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new [] {"Term Source File"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, OntologyBase.GetOntologies().Select(x => x.OntologyURL).ToArray()))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new [] {"Term Source Version"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, OntologyBase.GetOntologies().Select(x => x.Version).ToArray()))));
			//txtWriter.WriteLine(string.Join(IsaExporter.multipleFieldDelimiter, new [] {"Term Source Description"}.Concat(IsaExporter.Encapsulate(IsaExporter.fieldEncapsulater, OntologyBase.GetOntologies().Select(x => x.Name).ToArray()))));
			My_investigation <<"INVESTIGATION\n";

			My_investigation << "Investigation Identifier\t" << Investigation::quoted_empty_string()<< "\n";

			My_investigation << "Investigation Title\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Description\t"<< quoted_empty_string()<< "\n";
			My_investigation << "Investigation Submission Date\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Public Release Date\t"<< quoted_empty_string() << "\n";


			My_investigation << "INVESTIGATION PUBLICATIONS\n";
			My_investigation << "Investigation PubMed ID\t" <<  quoted_empty_string() << "\n";
			My_investigation << "Investigation Publication DOI\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Publication Author List\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Publication Title\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Publication Status\t" << quoted_empty_string()<< "\n";
			My_investigation << "Investigation Publication Status Term Accession Number\t" <<  quoted_empty_string()<< "\n";
			My_investigation << "Investigation Publication Status Term Source REF\t" << quoted_empty_string()<< "\n";

			My_investigation << "INVESTIGATION CONTACTS\n";
			My_investigation << "Investigation Person Last Name\t" <<  quoted_empty_string() << "\n";
			My_investigation << "Investigation Person First Name\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Mid Initials\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Email\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Phone\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Fax\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Address\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Affiliation\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Roles\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Roles Term Accession Number\t" << quoted_empty_string() << "\n";
			My_investigation << "Investigation Person Roles Term Source REF\t" << quoted_empty_string() << "\n";

			My_investigation << "STUDY\n";
			My_investigation << "Study Identifier\t" << IsaExporter::encapsulate(_xemlDoc->get_id().toString());

			My_investigation << "Study Title\t" << IsaExporter::encapsulate(_xemlDoc->get_experiment_name()) << "\n";
			My_investigation << "Study Description\t" << IsaExporter::encapsulate(_xemlDoc->get_description()) << "\n";
			My_investigation << "Study Submission Date\t" << IsaExporter::encapsulate(_xemlDoc->get_startdate().toString("yyyy-MM-dd")) << "\n";
			My_investigation << "Study Public Release Date\t"	<< IsaExporter::encapsulate(QDateTime::currentDateTime().toString("yyyy-MM-dd")) << "\n";
			My_investigation << "Study File Name\t" << IsaExporter::encapsulate(Study::get_fileName(_xemlDoc)) << "\n";


			My_investigation << "STUDY DESIGN DESCRIPTORS\n";
			/*
			txtWriter.WriteLine(String.Concat("Study Design Type\t", String.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(new[] { OBIInterventionDesign.Name, OBIStimilusStress.Name }))));
			txtWriter.WriteLine(String.Concat("Study Design Type Term Accession Number\t", String.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(new[] { OBIInterventionDesign.AccessionNr, OBIStimilusStress.AccessionNr }))));
			txtWriter.WriteLine(String.Concat("Study Design Type Term Source REF\t", String.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(new[] { OBIInterventionDesign.Ontology.Acronym, OBIStimilusStress.Ontology.Acronym }))));
*/
			My_investigation << "STUDY PUBLICATIONS\n";
			My_investigation << "Study PubMed ID\t" << quoted_empty_string() << "\n";
			QList<QString> dois;
			for (std::list<Keyword*>::iterator it= _xemlDoc->get_experimentheader()->get_keywords()->begin();it!=_xemlDoc->get_experimentheader()->get_keywords()->end();++it){
				if(static_cast<Keyword*>((*it))->get_value().startsWith("doi:")){
					dois.append(static_cast<Keyword*>((*it))->get_value());
				}
			}
			if (dois.empty()){
				My_investigation << "Study Publication DOI\t" << IsaExporter::encapsulate(quoted_empty_string()) << "\n";

			}
			else{
				My_investigation << "Study Publication DOI\t";
				for(int i=0;i<dois.count();i++){
					if(i==dois.count()-1){
						My_investigation <<  dois.at(i) <<  "\n";

					}
					else{
						My_investigation <<  dois.at(i) <<IsaExporter::multipleFieldDelimiter;

					}
				}
			}

			My_investigation << "Study Publication Author List\t" << quoted_empty_string()<< "\n";
			My_investigation << "Study Publication Title\t" << quoted_empty_string() << "\n";
			if (dois.empty()){
				My_investigation << "Study Publication Status\t" <<  IsaExporter::encapsulate("unpublished") << "\n";

			}
			else{
				My_investigation << "Study Publication Status\t" << IsaExporter::encapsulate("published") <<  "\n";



			}
			My_investigation << "Study Publication Status Term Accession Number\t" << quoted_empty_string()<< "\n";
			My_investigation << "Study Publication Status Term Source REF\t" << quoted_empty_string()<< "\n";


			/*
			List<Protocol.ProtocolBase> protocols = Protocol.ProtocolBase.GetProtocols().ToList();
			List<Protocol.Growth.GrowthStep> growthSteps = (protocols.Single(x => x is Protocol.Growth) as Protocol.Growth).GetGrowthSteps().Distinct().ToList();


			My_investigation << "STUDY FACTORS\n";
			My_investigation << "Study Factor Name\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, growthSteps.Select(x => IsaExporter.Encapsulate(x.ToString())).ToList()));
			My_investigation << "Study Factor Type\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, growthSteps.Select(x => IsaExporter.Encapsulate(x.Context)).ToList()));
			My_investigation << "Study Factor Type Term Accession Number\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, growthSteps.Select(x => IsaExporter.Encapsulate(x.term.AccessionNr)).ToList()));
			My_investigation << "Study Factor Type Term Source REF\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(growthSteps.Select(x => x.term.Ontology.Acronym).ToList())));

			My_investigation << "STUDY ASSAYS\n";
			My_investigation << "Study Assay File Name\t{0}", IsaExporter.Encapsulate(Assay.GetFileName(xds)));
			My_investigation << "Study Assay Measurement Type\t{0}", IsaExporter.Encapsulate(OBIMetaboliteProfiling.Name));  //ok by Philippe
			My_investigation << "Study Assay Measurement Type Term Accession Number\t{0}", IsaExporter.Encapsulate(OBIMetaboliteProfiling.AccessionNr)); //http://purl.obolibrary.org/obo/OBI_0000366
			My_investigation << "Study Assay Measurement Type Term Source REF\t{0}", IsaExporter.Encapsulate(OBIOntology.Acronym));
			My_investigation << "Study Assay Technology Type\t{0}", IsaExporter.Encapsulate(OBIMassSpec.Name ));
			My_investigation << "Study Assay Technology Type Term Accession Number\t{0}", IsaExporter.Encapsulate(OBIMassSpec.AccessionNr));  //http://purl.obolibrary.org/obo/OBI_0000470
			My_investigation << "Study Assay Technology Type Term Source REF\t{0}", IsaExporter.Encapsulate(OBIOntology.Acronym));
			My_investigation << "Study Assay Technology Platform\t{0}", IsaExporter.Encapsulate("GC-MS"));

			List<Term> protocolAccNrs = protocols.Select(x => x.AccessionNr).ToList();

			My_investigation << "STUDY PROTOCOLS\n";
			My_investigation << "Study Protocol Name\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => x.Name).ToList())));
			My_investigation << "Study Protocol Type\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => x.Type).ToList())));
			My_investigation << "Study Protocol Type Term Accession Number\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocolAccNrs.Select(x => x != null ? x.AccessionNr : String.Empty).ToList())));
			My_investigation << "Study Protocol Type Term Source REF\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocolAccNrs.Select(x => x != null ? x.Ontology.Acronym : String.Empty).ToList())));
			My_investigation << "Study Protocol Description\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => x.Description).ToList())));
			My_investigation << "Study Protocol URI\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Format(XemlDataSet.DocumentDataTable.UriTemplate, xemlId)).ToList())));
			My_investigation << "Study Protocol Version\t{0}", EmptyProtocolPlaceholder(protocols));
			My_investigation << "Study Protocol Parameters Name\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Join(IsaExporter.multipleValueDelimiter, x.GetParameters().Select(y => y.Name))).ToList())));
			My_investigation << "Study Protocol Parameters Name Term Accession Number\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Join(IsaExporter.multipleValueDelimiter, x.GetParameters().Select(y => y.AccessionNr != null ? y.AccessionNr.AccessionNr : ""))).ToList())));
			My_investigation << "Study Protocol Parameters Name Term Source REF\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Join(IsaExporter.multipleValueDelimiter, x.GetParameters().Select(y => y.AccessionNr != null ? y.AccessionNr.Ontology.Acronym : ""))).ToList())));
			//My_investigation << "Study Protocol Parameters Name Term Accession Number\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Join(IsaExporter.multipleValueDelimiter, x.GetParameters().Select(y => String.Empty))).ToList())));
			//My_investigation << "Study Protocol Parameters Name Term Source REF\t{0}", string.Join(IsaExporter.multipleFieldDelimiter, IsaExporter.Encapsulate(protocols.Select(x => string.Join(IsaExporter.multipleValueDelimiter, x.GetParameters().Select(y => String.Empty))).ToList())));
			My_investigation << "Study Protocol Components Name\t{0}", EmptyProtocolPlaceholder(protocols));
			My_investigation << "Study Protocol Components Type\t{0}", EmptyProtocolPlaceholder(protocols));
			My_investigation << "Study Protocol Components Type Term Accession Number\t{0}", EmptyProtocolPlaceholder(protocols));
			My_investigation << "Study Protocol Components Type Term Source REF\t{0}", EmptyProtocolPlaceholder(protocols));

			My_investigation << "STUDY CONTACTS\n";
			My_investigation << "Study Person Last Name\t{0}", IsaExporter.Encapsulate(xds.Document.Single().IsExperimenterLastNameNull() ? string.Empty : xds.Document.Single().ExperimenterLastName));
			My_investigation << "Study Person First Name\t{0}", IsaExporter.Encapsulate(xds.Document.Single().IsExperimenterFirstNameNull() ? string.Empty : xds.Document.Single().ExperimenterFirstName));
			My_investigation << "Study Person Mid Initials\t{0}", quoted_empty_string());
			My_investigation << "Study Person Email\t{0}", IsaExporter.Encapsulate(xds.Document.Single().IsExperimenterEmailNull() ? string.Empty : xds.Document.Single().ExperimenterEmail));
			My_investigation << "Study Person Phone\t{0}", quoted_empty_string());
			My_investigation << "Study Person Fax\t{0}", quoted_empty_string());
			My_investigation << "Study Person Address\t{0}", quoted_empty_string());
			My_investigation << "Study Person Affiliation\t{0}", IsaExporter.Encapsulate(xds.Document.Single().IsOrganisationNull() ? string.Empty : xds.Document.Single().Organisation));
			My_investigation << "Study Person Roles\t{0}", IsaExporter.Encapsulate("Experimenter"));
			My_investigation << "Study Person Roles Term Accession Number\t{0}", quoted_empty_string());
			My_investigation << "Study Person Roles Term Source REF\t{0}", quoted_empty_string());

			My_investigation << "Comment[ISA produced by]\tGolm Metabolome Database via XEML");
			txtWriter.Flush();
						*/







			//QFile investigation("investigation.txt");

			//investigation.open(QIODevice::WriteOnly | QIODevice::Text);
			//QTextStream txtWriter(&investigation);
			//txtWriter << "This file is generated by Qt\n";
			//qSetRealNumberPrecision()
			//out << "Result: " << qSetFieldWidth(10) << left << 3.14 << 2.7;

			// optional, as QFile destructor will already do it:
			//investigation.close();
		}
		QString Investigation::quoted_empty_string(){
			QString test;
			test=IsaExporter::fieldEncapsulater%IsaExporter::fieldEncapsulater;
			return test;
		}

		QString Investigation::get_fileName(ItfDocument * _xemlDoc){
			QString ret("/i_"+static_cast<XemlDocument*>(_xemlDoc)->get_experiment_name());
			return ret;
		}
	}
}
