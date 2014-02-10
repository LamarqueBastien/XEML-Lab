#ifndef PROVIDERDATAMAPPINGS_H
#define PROVIDERDATAMAPPINGS_H

#include<iostream>
#include<vector>
#include"sampleidentification.h"

using namespace std;

namespace Xeml {
	namespace Document{
		class ProviderDataMappings
		{
			public:
				ProviderDataMappings();
				void add(QString _key, std::vector<std::pair<SampleIdMapping*,int> > * _dm);
				void clear();
				void remove(QString  _key);
				int  count();
				bool contain_key(QString _key);
				bool contain_sid(SampleIdMapping * _sid,std::vector<std::pair<SampleIdMapping*,int> > * _sidvector,QString _provider);
				std::vector<std::pair<SampleIdMapping*,int> > * get_sample_id_mapping_by_provider(QString _provider);

				std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> > * get_provider();

			private:
				std::vector< std::pair<QString,std::vector<std::pair<SampleIdMapping*,int> > *> > * provider;

		};
	}
}

#endif // PROVIDERDATAMAPPINGS_H
