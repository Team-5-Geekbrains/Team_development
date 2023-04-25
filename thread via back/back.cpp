#include "back.h"
#include <QTimer>
#include <QDebug>

back::back(QObject *parent) : QObject(parent)
{
    fil = new QFileInfoList();
    qlvem = new QListViewExplorerModel();
    qlvem->getFolderList("", fil);
    this->currentFolder = QDir(QDir::currentPath());
    this->qlvem->getFolderList(this->currentFolder.absolutePath(), qlvem->getDirList());
    sc = new searchClass();
    strListModel = new QStringListModel;
    connect(this, SIGNAL(setSearch(QString)), sc, SLOT(searchFile(QString)));
    connect(sc, SIGNAL(searchFinished(QStringList)), this, SLOT(resultSearch(QStringList)));
    connect(this, SIGNAL(linePath(QString*)), sc, SLOT(setSearchIndex(QString*)));
    QThread* scThread = new QThread;
    sc->moveToThread(scThread);
    scThread->start();
}

void back::timeOut()
{
    emit setModel(qlvem);
    QString str = currentFolder.path();
    emit linePath(&str);
}

void back::changePath(const QModelIndex &index)
{
    if (qlvem->getDirList()->at(index.row()).isDir())
    {
        currentFolder = qlvem->getDirList()->at(index.row()).path();
        QString tmp = currentFolder.path();
        qlvem->getFolderList(qlvem->getDirList()->at(index.row()).absoluteFilePath(), qlvem->getDirList());
        emit linePath(qlvem->getPath());
    }
}

void back::shandeDirUp()
{
    currentFolder.cdUp();
    QString str = currentFolder.path();
    qlvem->getFolderList(currentFolder.absolutePath(),qlvem->getDirList());
    emit linePath(qlvem->getPath());
}

void back::resultSearch(QStringList strList)
{
    this->strListModel->setStringList(strList);
    emit sendStrListModel(strListModel);
}

void back::slotGetSearch(QString str)
{
    emit setSearch(str);
}
