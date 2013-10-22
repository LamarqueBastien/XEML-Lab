#ifndef ABSTRACTEXPERIMENTITEM_H
#define ABSTRACTEXPERIMENTITEM_H
#include<QStandardItem>
class AbstractExperimentItem : public QStandardItem
{

	private:
		QString      name;
	public:
		AbstractExperimentItem(const QString & _name);
		virtual bool isRoot()=0;

};

#endif // ABSTRACTEXPERIMENTITEM_H
