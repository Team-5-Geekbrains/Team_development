#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractListModel>
#include <QStringListModel>

#include "qlistviewexplorermodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void changePath(const QModelIndex &);
    void directoryUp();
    void startSearch();
    void search(QString);
public slots:
    void on_searchEdit_editingFinished();
    void setListManager(QListViewExplorerModel *);
    void linePath(QString*);

    void on_fileManager_doubleClicked(const QModelIndex &index);

    void on_cdup_clicked();

    void on_listMode_clicked();

    void on_IconMode_clicked();

    void resultSearch(QStringListModel *);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
