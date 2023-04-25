#include "qlistviewexplorermodel.h"
#include <QDebug>

QListViewExplorerModel::QListViewExplorerModel(QObject* parent)
    : QAbstractListModel(parent)
{
    path = new QString;
}

void QListViewExplorerModel::getFolderList(QString folderPath, QFileInfoList *dirList)
{
    QDir dir = QDir(folderPath);
    *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
    *path = dir.path();
    this->beginResetModel();
    this->aDirList = dirList;
    this->endResetModel();
}

QString *QListViewExplorerModel::getPath()
{
    return path;
}

void QListViewExplorerModel::setPath(QString* path)
{
    this->path = path;

}

QFileInfoList* QListViewExplorerModel::getDirList()
{
    return this->aDirList;
}

int QListViewExplorerModel::rowCount(const QModelIndex &) const
{
    return this->aDirList->count();
}

QVariant QListViewExplorerModel::data(const QModelIndex &index, int role) const
{
    QVariant value;
    switch (role)
    {
        case Qt::DisplayRole:
        {
            value = this->aDirList->at(index.row()).fileName();
        }
        break;
        case Qt::UserRole:
        {
            value = this->aDirList->at(index.row()).fileName();
        }
        break;
        default:
            break;
    }
    return  value;
}
