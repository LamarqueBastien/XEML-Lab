#ifndef WINDOWTITLEBAR_H
#define WINDOWTITLEBAR_H

#include <QtWidgets>
#include <QLabel>
#include <QPixmap>

class WindowTitleBar : public QWidget
{
Q_OBJECT

	public:
  WindowTitleBar(QWidget *parent = 0);
  ~WindowTitleBar();
	private:
  QPixmap *m_Cache;
  QLabel m_Title;
	protected:
	  void resizeEvent(QResizeEvent *event);
	  void paintEvent (QPaintEvent  *event);
	public slots:
	  void UpdateWindowTitle();
};

#endif

