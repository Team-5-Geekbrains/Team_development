#include "mainwindow.h"
#include "back.h"
#include "searchclass.h"

#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    back b;
    QObject::connect(&b, SIGNAL(setModel(QListViewExplorerModel*)), &w, SLOT(setListManager(QListViewExplorerModel*)));
    QObject::connect(&b, SIGNAL(linePath(QString*)), &w, SLOT(linePath(QString*)));
    QObject::connect(&w, SIGNAL(changePath(const QModelIndex &)), &b, SLOT(changePath(const QModelIndex &)));
    QObject::connect(&w, SIGNAL(directoryUp()), &b, SLOT(shandeDirUp()));
    QObject::connect(&w, SIGNAL(search(QString)), &b, SLOT(slotGetSearch(QString)));
    QObject::connect(&b, SIGNAL(sendStrListModel(QStringListModel *)), &w, SLOT(resultSearch(QStringListModel *)));

    b.timeOut();
    w.show();
    return a.exec();
}
