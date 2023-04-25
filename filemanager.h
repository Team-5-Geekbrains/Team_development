#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QWidget>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>

#include <QFileSystemModel>
#include <QListView>
#include <QListWidget>
#include <QStringListModel>

class fileManager : public QWidget
{
    Q_OBJECT
public:
    explicit fileManager(QWidget *parent = nullptr);

private slots:
    void DoubleClicked(const QModelIndex &index);
    void setResultSearch(QString strPath);
signals:
    void path(QFileInfo);
    void toSearch(QModelIndex);
private:
    QFileSystemModel *model;
    QListView* listView;
    QStringListModel* strSearch;
};

#endif // FILEMANAGER_H
