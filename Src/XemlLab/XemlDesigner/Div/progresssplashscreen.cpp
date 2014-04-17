#include "progresssplashscreen.h"

ProgressSplashScreen::ProgressSplashScreen(const QPixmap& pixmap):QSplashScreen(pixmap)
{
	progressBar = new QProgressBar (this);
	progressBar->setMinimum(0);
	progress=0;

	progressBar->show();
	connect(progressBar,SIGNAL(valueChanged(int)),this,SLOT(progressBarUpdated(int)));
}
ProgressSplashScreen::~ProgressSplashScreen()
{
}
void ProgressSplashScreen::progressBarUpdated(int _progress){
	//std::cerr << "progress new value : "<< _progress << std::endl;
	progress=_progress;
	//this->repaint();
}

void ProgressSplashScreen::drawContents(QPainter *painter)
{
	QSplashScreen::drawContents(painter);
	this->progressBar->render(painter);
	progressBar->setValue(progress);
	//std::cerr << "progress value changed" << std::endl;
	//std::cerr << "progress value :" << progress << std::endl;
	progressBar->update ();
}

