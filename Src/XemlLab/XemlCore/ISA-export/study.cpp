#include "study.h"
namespace XemlUtilities{

	namespace ISA{
		Study::Study()
		{
		}
		void Study::get_stream(ItfDocument * _xemlDoc,QFile * _studyfile){


			QTextStream My_study(_studyfile);
			My_study << "hello world, I'm ben";

		}

		QString Study::get_fileName(ItfDocument * _xemlDoc){
			QString ret("/s_"+static_cast<XemlDocument*>(_xemlDoc)->get_experiment_name());
			return ret;
		}
	}
}
