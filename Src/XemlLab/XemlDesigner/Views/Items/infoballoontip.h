#ifndef INFOBALLOONTIP_H
#define INFOBALLOONTIP_H

#include <QFrame>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>

#include <QStyle>
#include"Views/Items/infotipbutton.h"
/*
  Class BalloonTip : A balloon tip used to display messages
*/
class InfoBalloonTip : public QWidget {
  Q_OBJECT
  Q_PROPERTY( ArrowPosition my_arrowPos READ arrowPosition WRITE setArrowPosition )
public:
  /* This enum determine in which corner will be displayed the arrow */
  enum ArrowPositions {
	TopLeft     = 0,
	TopRight    = 1,
	BottomLeft  = 2,
	BottomRight = 3
  };
Q_DECLARE_FLAGS( ArrowPosition, ArrowPositions )
Q_ENUMS( ArrowPositions )

protected:
  QPixmap my_icon;
  QString my_text;
  QString my_title;
  QPoint my_pos;
  ArrowPosition my_arrowPos;
  QRect my_popupRect;
  QRect my_textRect;
  int my_duration;
  bool my_animated;

  QPropertyAnimation* my_animation;

  InfoTipButton* my_closeButton;
  InfoTipButton* my_configButton;

  void   paintEvent( QPaintEvent* ev);

  QRect  relativePopupRect();
  QRect  relativeTextRect();

  void   enterEvent( QEvent* ev );
  void   leaveEvent( QEvent* ev );
  void   init();
  void   createAnimation();
  void   defineArrowPosition();
  void   createRects();
  bool   eventFilter(QObject *, QEvent *);

public:
  explicit InfoBalloonTip( QString title, QString text,
					   int duration = 2000, QWidget* parent = 0 );
  explicit InfoBalloonTip( QPixmap pix, QString title, QString text,
					   int duration = 2000, QWidget* parent = 0 );
  explicit InfoBalloonTip( QStyle::StandardPixmap pix, QString title,
					   QString text, int duration = 2000, QWidget* parent = 0 );

  ~InfoBalloonTip();
  ArrowPosition arrowPosition();
  void          setArrowPosition( ArrowPosition pos );
  void          move( QPoint pos );

signals:
  void finished();

public slots:
  void   show();
  bool   close();
};

#endif // INFOBALLOONTIP_H
