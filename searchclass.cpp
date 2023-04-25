#include "searchclass.h"

searchClass::searchClass()
{
    searchIndex = new QModelIndex();
    model = new QFileSystemModel();
}

void searchClass::searchFile(QString str)
{
    QString targetStr = str;
    QFileInfoList hitList;
    QStringList strlist;
    QString directory = "";
    if(searchIndex->isValid())
        directory = model->filePath(*searchIndex);
    qDebug() << searchIndex;
    QDirIterator it(directory, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString filename = it.next();
        QFileInfo file(filename);
        if (file.isDir())
        {
            continue;
        }

        if (file.fileName().contains(targetStr, Qt::CaseInsensitive))
        {
            hitList.append(file);
            strlist.append(file.absoluteFilePath());
        }
    }
    emit searchFinished(strlist);
}

void searchClass::changePath(QModelIndex index)
{
    *searchIndex = index;
    qDebug() << index;
}
