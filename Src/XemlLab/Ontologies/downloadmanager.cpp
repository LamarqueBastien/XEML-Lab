#include <QtWidgets>
#include <QtNetwork>

#include "downloadmanager.h"
#include "ui_authenticationdialog.h"
using namespace std;

namespace Xeml{

	namespace Document{

		namespace Manager{

			DownloadManager::DownloadManager(QWidget *parent)
				: QObject(parent)
			{
#ifndef QT_NO_SSL
				urlLineEdit = new QLineEdit("http://rest.bioontology.org/bioportal/ontologies/download/49450?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d");
#else
				urlLineEdit = new QLineEdit("http://rest.bioontology.org/bioportal/ontologies/download/49450?apikey=db0a05bc-af0e-4e24-99e6-02f2cb830b7d");
#endif
				ignoreSslerror=false;
				finished_process=false;


				connect(&qnam, SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),
						this, SLOT(slotAuthenticationRequired(QNetworkReply*,QAuthenticator*)));
#ifndef QT_NO_SSL
				connect(&qnam, SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
						this, SLOT(sslErrors(QNetworkReply*,QList<QSslError>)));
#endif

			}

			QUrl  DownloadManager::retrieve_ontologies_url(const QString Uri){
				QFile xml_doc(":/default.xeml");
				QUrl current_uml;
				//QStringList urls;
				//QStringList files;
				QDomDocument *dom = new QDomDocument("mon_xml");
				if(!xml_doc.open(QIODevice::ReadOnly)) // Si l'on n'arrive pas à ouvrir le fichier XML.
				{
					//QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être ouvert.");
					std::cerr << "Erreur à l'ouverture du document XML" << std::endl;
					//return urls;
				}
				if (!dom->setContent(&xml_doc)) // Si l'on n'arrive pas à associer le fichier XML à l'objet DOM.
				{
					xml_doc.close();
					//QMessageBox::warning(this, "Erreur à l'ouverture du document XML", "Le document XML n'a pas pu être attribué à l'objet QDomDocument.");
					//return urls;
				}
				QDomElement dom_element = dom->documentElement();
				QDomNode noeud = dom_element.firstChild();

				while(!noeud.isNull())// Tant que le nœud n'est pas vide.
				{
					if(!dom_element.isNull())
					{
						if(noeud.toElement().tagName().toStdString()=="xeml:Resources"){
							QDomElement element = noeud.toElement();
							QDomNodeList QNL=element.childNodes();
							for (int i = 0; i < QNL.length(); i++) {
								if(QNL.item(i).toElement().attributeNode("HandlerUri").value()==Uri){
									current_uml=QNL.item(i).toElement().attributeNode("InstanceLocation").value();
									//_filename=":/new/prefix1/"+QNL.item(i).toElement().attributeNode("NS").value()+"obo";
								}
							}
						}
						noeud = noeud.toElement().nextSibling();
					}
					else{
						std::cerr << "problem null element" << std::endl;
					}

				}

				xml_doc.close(); //

				return current_uml;
			}

			void DownloadManager::startRequest(QUrl url)
			{
				reply = qnam.get(QNetworkRequest(url));
				QEventLoop loop;
				connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

				//connect(this,SIGNAL(monSignal2()),this,SLOT(quit()));
				connect(this,SIGNAL(monSignal()),this,SLOT(display()));
				connect(reply, SIGNAL(finished()),
						this, SLOT(httpFinished()));
				connect(reply, SIGNAL(readyRead()),
						this, SLOT(httpReadyRead()));
				connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
						this, SLOT(updateDataReadProgress(qint64,qint64)));
				loop.exec();
				std::cerr << "fin de requEte dans startRequest" <<std::endl;
			}
			QByteArray DownloadManager::get_obocontent(){
				return this->obocontent;
			}

			void DownloadManager::quit(){
				//std::cerr << "end of display" << std::endl;
			}
			void DownloadManager::display(){
				emit monSignal2();
			}

			void DownloadManager::downloadFile()
			{
				url = urlLineEdit->text();

				QFileInfo fileInfo(url.path());
				QString fileName2 ="/Users/benjamindartigues/Qt5.0.1/CoreObject/ben14.txt";

				QString fileName = fileInfo.fileName();
				if (fileName.isEmpty())
					fileName = "index.html";


				file = new QFile(fileName2);
				if (!file->open(QIODevice::WriteOnly)) {

					delete file;
					file = 0;
					return;
				}



				// schedule the request
				httpRequestAborted = false;
				startRequest(url);
			}
			void DownloadManager::download_File(QUrl url, QString fileName2)
			{

				this->Filename=fileName2;

				if (fileName2.isEmpty())
					fileName2 = "index.html";

				if (QFile::exists(fileName2)) {

					std::cerr << "same filename" << std ::endl;
					QFile::remove(fileName2);

				}

				file = new QFile(fileName2);
				if (!file->open(QIODevice::WriteOnly)) {

					delete file;
					file = 0;
					std::cerr <<"impossible d'ouvrir ce fichier" << std::endl;
					return;
				}



				// schedule the request
				httpRequestAborted = false;
				//std::cerr << "debut requete" << std::endl;
				startRequest(url);
				//std::cerr << "fin requete" << std::endl;

			}



			void DownloadManager::cancelDownload()
			{

				httpRequestAborted = true;
				reply->abort();

			}


			void DownloadManager::closeFile(){
				file->close();
			}

			void DownloadManager::httpFinished()
			{

				if (httpRequestAborted) {
					if (file) {
						file->close();
						file->remove();
						delete file;
						file = 0;
					}
					reply->deleteLater();
					return;
				}


				std::cerr << "download finished" <<std::endl;
				file->flush();
				file->close();
				std::cerr << "file closed" <<std::endl;



				QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
				if (reply->error()) {
					std::cerr << "error" <<std::endl;
					file->remove();

				} else if (!redirectionTarget.isNull()) {
					QUrl newUrl = url.resolved(redirectionTarget.toUrl());

					url = newUrl;
					reply->deleteLater();
					file->open(QIODevice::WriteOnly);
					file->resize(0);
					startRequest(url);
					return;
					//}
				} else {
					QString fileName = QFileInfo(QUrl(urlLineEdit->text()).path()).fileName();

				}

				emit monSignal();
				reply->deleteLater();
				reply = 0;
				delete file;
				file = 0;
				std::cerr << "file deleted" <<std::endl;
			}



			void DownloadManager::httpReadyRead()
			{
				// this slot gets called every time the QNetworkReply has new data.
				// We read all of its new data and write it into the file.
				// That way we use less RAM than when reading it at the finished()
				// signal of the QNetworkReply
				if (file)
					file->write(reply->readAll());
			}

			void DownloadManager::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
			{
			Q_UNUSED(bytesRead);
			Q_UNUSED(totalBytes);
				if (httpRequestAborted)
					return;


			}






			void DownloadManager::slotAuthenticationRequired(QNetworkReply*,QAuthenticator *authenticator)
			{
				QDialog dlg;
				Ui::Dialog ui;
				ui.setupUi(&dlg);
				dlg.adjustSize();
				ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm()).arg(url.host()));

				// Did the URL have information? Fill the UI
				// This is only relevant if the URL-supplied credentials were wrong
				ui.userEdit->setText(url.userName());
				ui.passwordEdit->setText(url.password());

				if (dlg.exec() == QDialog::Accepted) {
					authenticator->setUser(ui.userEdit->text());
					authenticator->setPassword(ui.passwordEdit->text());
				}
			}

#ifndef QT_NO_SSL
			void DownloadManager::sslErrors(QNetworkReply*,const QList<QSslError> &errors)
			{
				QString errorString;
				foreach (const QSslError &error, errors) {
					if (!errorString.isEmpty())
						errorString += ", ";
					errorString += error.errorString();
				}
				if(ignoreSslerror){
					reply->ignoreSslErrors();
				}

			}
#endif
		}
	}
}



