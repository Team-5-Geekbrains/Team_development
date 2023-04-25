#include "searchclass.h"


searchClass::searchClass(QObject *parent) : QObject(parent)
{
    searchIndex = new QString();
    model = new QFileSystemModel();
}

void searchClass::setIndex(QString strIndex)
{
    searchIndex = &strIndex;
}

void searchClass::searchFile(QString str)
{
    QString targetStr = str;
    QStringList strList;
    QString directory = *searchIndex;
    QDirIterator it(directory, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString fileName = it.next();
        QFileInfo file(fileName);
        if (file.isDir())
            continue;
        if (file.fileName().contains(targetStr, Qt::CaseInsensitive))
        {
            strList.append(file.absolutePath());
        }
    }
    emit searchFinished(strList);
}

void searchClass::setSearchIndex(QString* strSearch)
{
    searchIndex = strSearch;
}
