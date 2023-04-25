#ifndef SEARCHCLASS_H
#define SEARCHCLASS_H

#include <QObject>
#include <QFileInfoList>
#include <QDirIterator>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QtDebug>

class searchClass : public QObject
{
    Q_OBJECT
public:
    searchClass();
signals:
    void searchFinished(QStringList);
private slots:
    void searchFile(QString str);
    void changePath(QModelIndex);
private:
    QModelIndex* searchIndex;
    QFileSystemModel *model;
};

#endif // SEARCHCLASS_H
