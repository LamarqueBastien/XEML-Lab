#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H
#include<QDialog>
#include<QObject>
#include<QNetworkAccessManager>
#include<QUrl>
//#include<Iostream>
#include<QByteArray>
#include<QDomDocument>
#include<QtXml>
#include<iostream>

using namespace std;

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFile;
class QLineEdit;
class QSslError;
class QAuthenticator;
class QNetworkReply;


QT_END_NAMESPACE

namespace Xeml{

	namespace Document{

		namespace Manager{

			class DownloadManager : public QObject
			{
					Q_OBJECT

				public:
					DownloadManager(QWidget *parent = 0);

					QUrl                  retrieve_ontologies_url(const QString Uri);
					void                  startRequest(QUrl url);
					//QFile * getFile();
					void                  download_File(QUrl url, QString  filename2);
					void                  closeFile();
					bool                  finished_process;
					QByteArray            get_obocontent();
				signals:
					void                  monSignal();
					void                  monSignal2();
				private slots:
					void                  quit();
					void                  downloadFile();
					void                  display();
					void                  cancelDownload();
					void                  httpFinished();
					void                  httpReadyRead();
					void                  updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);

					void                  slotAuthenticationRequired(QNetworkReply*,QAuthenticator *);

#ifndef QT_NO_SSL
					void                  sslErrors(QNetworkReply*,const QList<QSslError> &errors);
#endif

				private:

					QLineEdit           * urlLineEdit;
					QString               oboStringContent;
					//QProgressDialog     * progressDialog;
					//QPushButton         * downloadButton;
					//QPushButton         * quitButton;
					//QDialogButtonBox    * buttonBox;
					QByteArray            obocontent;
					QUrl                  url;
					QNetworkAccessManager qnam;
					QNetworkReply       * reply;
					QFile               * file;
					//QFile *tmp_file;
					int                   httpGetId;
					bool                  ignoreSslerror;
					bool                  httpRequestAborted;
					QString               Filename;
			};
		}
	}
}

#endif //DOWNLOADMANAGER

