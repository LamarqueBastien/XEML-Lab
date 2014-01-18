#include "parameterview.h"

ParameterView::ParameterView(QTreeView *parent)
	:QTreeView(parent)
{
}
void ParameterView::dragEnterEvent(QDragEnterEvent *event)
 {
	std::cerr << "entering dragEnterEvent" << std::endl;

	 if (event->mimeData()->hasText()) {
		 if (event->source() == this) {
			 event->setDropAction(Qt::MoveAction);
			 event->accept();
		 } else {
			 event->acceptProposedAction();
		 }
	 } else {
		 event->ignore();
	 }

	 event->acceptProposedAction();
 }


void ParameterView::dragMoveEvent(QDragMoveEvent *event)
{

	if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
		if (event->source() == this) {
			event->setDropAction(Qt::MoveAction);
			event->accept();
		} else {
			event->acceptProposedAction();
		}
	} else {
		event->ignore();
	}

	event->acceptProposedAction();
}
/*
void ParameterView::dropEvent(QDropEvent *event)
{

	std::cerr << "entering drop event" << std::endl;
	if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
		QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
		QDataStream dataStream(&itemData, QIODevice::ReadOnly);

		QPixmap pixmap;
		QPoint offset;
		dataStream >> pixmap >> offset;

		QLabel *newIcon = new QLabel(this);
		newIcon->setPixmap(pixmap);
		newIcon->move(event->pos() - offset);
		newIcon->show();
		newIcon->setAttribute(Qt::WA_DeleteOnClose);

		if (event->source() == this) {
			event->setDropAction(Qt::MoveAction);
			event->accept();
		} else {
			event->acceptProposedAction();
		}
	} else {
		event->ignore();
	}

	event->acceptProposedAction();
}
*/

void ParameterView::mousePressEvent(QMouseEvent *event)
{

	//ParameterView::indexAt()
	//QItemSelectionModel * selection = this->selectionModel();
	QModelIndex indexelementselected =static_cast<QModelIndex>(indexAt(event->pos()));
	//QModelIndex indexelementselected =selection->currentIndex();
	//QVariant elementSelected = this->model()->data(indexelementselected);

	//ParameterItem  *tmp =static_cast<ParameterItem*>(this->model()->i->itemFromIndex(indexelementselected));

	//std::cerr << indexelementselected.row() << indexelementselected.column() << std::endl;
	QVariant elementSelected;
	ParameterItem * tmp;
	//if(selection->isSelected(indexelementselected)){
	elementSelected = static_cast<QStandardItemModel*>(this->model())->data(indexelementselected);
	//QString tmp_label=elementSelected.toString();
	//std::cerr << elementSelected.toString().toStdString() << std::endl;
	tmp =static_cast<ParameterItem*>(static_cast<QStandardItemModel*>(this->model())->itemFromIndex(indexelementselected));
	if(tmp->isRoot){
		std::cerr << "root"  << std::endl;

	}
	else{
		std::cerr << "test" << tmp->get_term()->get_termId().toStdString() << std::endl;
		QLabel  * child=new QLabel(tmp->get_term()->get_termId());
		child->move(event->pos().x(),event->pos().y());
		child->setAutoFillBackground(true);
		child->adjustSize();
		child->setFrameShape(QFrame::Panel);
		child->setFrameShadow(QFrame::Raised);
		//child->setAttribute(Qt::WA_TranslucentBackground,true);
		//QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
		if (!child)
			return;

		//child->setScaledContents(true);
		std::cerr << "eventpos : " << event->pos().x() << "----" << event->pos().y() << std::endl;
		QPoint hotSpot = event->pos()- child->pos();

		QMimeData *mimeData = new QMimeData;
		mimeData->setText(child->text());
		mimeData->setData("application/x-hotspot",
						  QByteArray::number(hotSpot.x()) + " " + QByteArray::number(hotSpot.y()));

		//QPixmap pixmap(child->size());
		QPixmap pixmap(child->size());
		std::cerr <<"child width :" << child->width() << "child height : " << child->height() << std::endl;
		pixmap.scaledToWidth(child->width());
		child->render(&pixmap);

		QDrag *drag = new QDrag(this);
		drag->setMimeData(mimeData);
		drag->setPixmap(pixmap);
		drag->setHotSpot(hotSpot);

		Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

		if (dropAction == Qt::MoveAction)
			child->close();
	}

	//}






}
