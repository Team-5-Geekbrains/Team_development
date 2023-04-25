#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->fileManager->setWrapping(true);
    this->ui->fileManager->setWordWrap(true);
    ui->resultSearch->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchEdit_editingFinished()
{
    if (ui->searchEdit->text() != "")
    {
        emit search(ui->searchEdit->text());
    }
    else
        ui->resultSearch->setVisible(false);
}

void MainWindow::setListManager(QListViewExplorerModel *alm)
{
    ui->fileManager->setModel(alm);
}

void MainWindow::linePath(QString * strPath)
{
    ui->pathEdit->setText(*strPath);
}

void MainWindow::on_fileManager_doubleClicked(const QModelIndex &index)
{
    emit changePath(index);
}

void MainWindow::on_cdup_clicked()
{
    emit directoryUp();
}

void MainWindow::on_listMode_clicked()
{
    this->ui->fileManager->setUniformItemSizes(false);
    this->ui->fileManager->setViewMode(QListView::ListMode);
}

void MainWindow::on_IconMode_clicked()
{
    this->ui->fileManager->setUniformItemSizes(true);
    this->ui->fileManager->setViewMode(QListView::IconMode);
}

void MainWindow::resultSearch(QStringListModel* str)
{
    ui->resultSearch->setVisible(true);
    ui->resultSearch->setModel(str);
}
