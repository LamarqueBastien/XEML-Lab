#ifndef XEMLCOMPONENTLOADFAILEDEXCEPTION_H
#define XEMLCOMPONENTLOADFAILEDEXCEPTION_H
#include<exception>
#include<QUuid>
#include<string>
using namespace std;
namespace Xeml {

	namespace Document{
		class XemlComponentLoadFailedException : public std::exception
		{
			private:
				QUuid componentId;
				QString uri;
				QString message;
			public:
				virtual ~XemlComponentLoadFailedException() throw()
				{

				}

				virtual const char * what() const throw()
				{
					return this->message.toStdString().c_str();
				}
				XemlComponentLoadFailedException();



				XemlComponentLoadFailedException(QString _message);
				XemlComponentLoadFailedException(QString _uri, QString _message);
				XemlComponentLoadFailedException(QUuid _componentId,QString _message);
				//XemlComponentLoadFailedException(QUuid _componentId, QString _message, exception innerException);
				//XemlComponentLoadFailedException(QString _uri, QString _message, exception innerException);
				QUuid get_componentId();
				QString get_uri();
				QString get_message();
		};
	}
}

#endif // XEMLCOMPONENTLOADFAILEDEXCEPTION_H
