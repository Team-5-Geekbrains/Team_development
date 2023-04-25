#ifndef QLISTVIEWEXPLORERMODEL_H
#define QLISTVIEWEXPLORERMODEL_H

#include <QObject>
#include <QDir>
#include <QModelIndex>

class QListViewExplorerModel : public QAbstractListModel
{
public:
    QListViewExplorerModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    void getFolderList(QString folderPath, QFileInfoList* dirList);
    QString* getPath();
    void setPath(QString*);
    QFileInfoList* getDirList();
private:
    QFileInfoList* aDirList;
    QString* path;
};

#endif // QLISTVIEWEXPLORERMODEL_H
