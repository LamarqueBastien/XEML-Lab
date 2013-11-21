#ifndef OBOTAGS_H
#define OBOTAGS_H
namespace Xeml {

	namespace Document{

		namespace Ontologies{

			namespace OBO{

				typedef enum
					{
					id,
					name,
					def,
					_namespace,
					instance_of,
					is_a,
					domain,
					range,
					is_metadata_tag,
					has_symbol,
					has_context,
					has_enum,
					has_datatype,
					comment,
					//this next tags are additionally comming from the envo ontology
					synonym,
					xref,
					part_of,
					relationship,
					is_obsolete,
					intersection_of,
					subset,
					alt_id,
					disjoint_from,
					consider,
					replaced_by,
					created_by,
					creation_date,
					is_transitive,

					//this next tag is additionally comming from the EO ontology
					xref_analog,

					XXX_unknown// = Byte.MaxValue
					}OboTags;
			}
		}
	}
}
#endif // OBOTAGS_H
