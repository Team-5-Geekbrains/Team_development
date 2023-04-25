#ifndef BACK_H
#define BACK_H

#include <QObject>
#include <QAbstractListModel>
#include <QListView>
#include <QStringListModel>
#include <QThread>

#include "qlistviewexplorermodel.h"
#include "searchclass.h"

class back : public QObject
{
    Q_OBJECT
public:
    explicit back(QObject *parent = nullptr);

signals:
    void setModel(QListViewExplorerModel*);
    void linePath(QString*);
    void sendStrListModel(QStringListModel *);
    void setSearch(QString);
public slots:
    void timeOut();
    void changePath(const QModelIndex &);
    void shandeDirUp();
    void resultSearch(QStringList);
    void slotGetSearch(QString);
private:
    QListViewExplorerModel* qlvem;
    QListView* lv;
    QFileInfoList* fil;
    QDir currentFolder;

    searchClass* sc;
    QStringListModel* strListModel;
};

#endif // BACK_H
