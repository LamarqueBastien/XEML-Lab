#ifndef PROGRESSSPLASHSCREEN_H
#define PROGRESSSPLASHSCREEN_H
#include<QtWidgets>
#include<iostream>

using namespace std;

class ProgressSplashScreen : public QSplashScreen
{
	public:
		ProgressSplashScreen(const QPixmap& pixmap);
		~ProgressSplashScreen();
		QProgressBar * progressBar;
	protected:
		virtual void drawContents(QPainter *painter);
	private:
		int progress;
	private slots:
		void progressBarUpdated(int _progress);
};

#endif // PROGRESSSPLASHSCREEN_H
