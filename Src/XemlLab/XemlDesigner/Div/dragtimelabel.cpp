#include "dragtimelabel.h"

DragTimeLabel::DragTimeLabel(const QString &text, QWidget *parent)
	: QLabel(text, parent)
{
	setAutoFillBackground(true);
	setFrameShape(QFrame::Panel);
	setFrameShadow(QFrame::Raised);
}
