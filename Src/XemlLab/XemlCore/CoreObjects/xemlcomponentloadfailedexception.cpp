#include "xemlcomponentloadfailedexception.h"
namespace Xeml {

	namespace Document{
		XemlComponentLoadFailedException::XemlComponentLoadFailedException()
		{

		}
		XemlComponentLoadFailedException::XemlComponentLoadFailedException(QString _message)
		{
			this->message=_message;
		}
		XemlComponentLoadFailedException::XemlComponentLoadFailedException(QString _uri, QString _message)
		{
			this->message=_message;
			this->uri=_uri;
		}
		XemlComponentLoadFailedException::XemlComponentLoadFailedException(QUuid _componentId,QString _message){
			this->message=_message;
			this->componentId=_componentId;

		}
		QUuid XemlComponentLoadFailedException::get_componentId(){
			return this->componentId;
		}
		QString XemlComponentLoadFailedException::get_uri(){
			return this->uri;
		}

		/*
		//XemlComponentLoadFailedException::XemlComponentLoadFailedException(QUuid _componentId, QString _message, exception innerException){
		//    this->componentId=_componentId;
		//    this->message=_message;
		//    this->exception=innerException;
		//}
		*/
		/*
		//XemlComponentLoadFailedException::XemlComponentLoadFailedException(QString _uri, QString _message, exception innerException){
		//    this->message=_message;
		//    this->exception=innerException;
		//    this->uri=_uri;
		//}
		*/
	}
}
