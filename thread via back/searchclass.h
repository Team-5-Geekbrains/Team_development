#ifndef SEARCHCLASS_H
#define SEARCHCLASS_H

#include <QObject>
#include <QFileInfoList>
#include <QDirIterator>
#include <QModelIndex>
#include <QFileSystemModel>

class searchClass : public QObject
{
    Q_OBJECT
public:
    explicit searchClass(QObject *parent = nullptr);
    void setIndex(QString strIndex);
signals:
    void searchFinished(QStringList);
public slots:
    void searchFile(QString str);
    void setSearchIndex(QString*strSearch);
private:
    QString* searchIndex;
    QFileSystemModel* model;
};

#endif // SEARCHCLASS_H
