#ifndef INFOTIPBUTTON_H
#define INFOTIPBUTTON_H

#include <QFrame>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>

#include <QStyle>


/*
  Class TipButton : button used in the BalloonTip class
*/
class InfoTipButton : public QPushButton {
  Q_OBJECT
public:
  /* The role determines the look-and-feel of the button. Not used for now... */
  enum TipButtonRoles {
	Close,
	Config
  };
Q_DECLARE_FLAGS( TipButtonRole, TipButtonRoles )
Q_ENUMS( TipButtonRoles )

protected:
  TipButtonRole my_role;

public:

  InfoTipButton( TipButtonRole role, QWidget* parent = 0 ) : QPushButton( parent ) {
	setFixedSize( 20, 20 );
	my_role = role;
  }

  void paintEvent(QPaintEvent *) {
	QPainter painter( this );
	painter.setRenderHint( QPainter::Antialiasing );

	QColor color( 150, 150, 150 );

	QRect border( 2, 2, 16, 16 );
	painter.setPen( QPen( color, 2 ) );
	painter.drawRoundedRect( border, 3, 3 );

	if ( my_role == InfoTipButton::Close ) {
	painter.setPen( QPen( color, 3 ) );
	painter.drawLine( 6, 6, 14, 14 );
	painter.drawLine( 6, 14, 14, 6 );

	} else if ( my_role == InfoTipButton::Config ) {
	  painter.setPen( Qt::transparent );
	  painter.setBrush( color );
	  QPainterPath path;
	  QPainterPath path2;
	  path.addEllipse( 4, 3, 12, 9 );
	  path.addRect( 8, 3, 4, 4 );
	  path2.addRect( 8, 11, 4, 5 );

	  path = path.united(path2).simplified();
	  painter.drawPath( path );
	}
  }
};

#endif // INFOTIPBUTTON_H
