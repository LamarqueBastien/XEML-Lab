#include "mysqldataprovider.h"

MySqlDataProvider::MySqlDataProvider()
{

}
QImage * MySqlDataProvider::get_logo(){

}

void MySqlDataProvider::set_logo(){

}

bool MySqlDataProvider::support_auto_mapping(){

}

std::vector<QString> * MySqlDataProvider::listForeignKey(){

}

std::vector<QString> * MySqlDataProvider::filterKeyValues(QString _key,std::vector<std::pair<QString,QString> > * filter){

}

std::vector<SampleIdMapping*> * MySqlDataProvider::automap(QUuid expID, QString expName,std::vector<int> * samples){

}

SidLookUpResult MySqlDataProvider::validate(SampleIdMapping *sim){

}

ConnectResult MySqlDataProvider::testCredentials(QString _user, QString _password){

}
