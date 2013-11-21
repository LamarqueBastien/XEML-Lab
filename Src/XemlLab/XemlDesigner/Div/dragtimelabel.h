#ifndef DRAGTIMELABEL_H
#define DRAGTIMELABEL_H

#include <QLabel>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDragMoveEvent;
class QFrame;
QT_END_NAMESPACE

class DragTimeLabel : public QLabel
{
public:
	DragTimeLabel(const QString &text, QWidget *parent);
};

#endif // DRAGTIMELABEL_H
