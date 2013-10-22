#ifndef GENOTYPEITEM_H
#define GENOTYPEITEM_H
#include<QStandardItem>

class GenotypeItem : public QStandardItem
{
	public:
		typedef enum
		  {
			NameRole = Qt::UserRole+1,
			PathRole,
			HashRole,
			SizeRole,
			SizeTextRole,
			SubdirRole,
			SubdirTextRole
		  }Roles;

		typedef enum
		  {
		   Genotype = QStandardItem::UserType + 1
		  }Type;
		GenotypeItem(const QString &);
		int               type() const { return Genotype; }

};

#endif // GENOTYPEITEM_H
