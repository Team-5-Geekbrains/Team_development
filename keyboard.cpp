#include "keyboard.h"
#include "ui_keyboard.h"

#include <QApplication>
#include <QModelIndex>

Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keyboard)
{
    ui->setupUi(this);
    list << "Ctrl+O" << "Ctrl+S" << "F1" << "Ctrl+Q";
    stringListModel = new QStringListModel();
    stringListModel->setStringList(list);
    ui->listView->setModel(stringListModel);
    connect(stringListModel, &QStringListModel::dataChanged, [this](QModelIndex const &,
            QModelIndex const &)
    {
        QStringList changedList;
        for (int i = 0; i < stringListModel->rowCount(); ++i)
        {
            QModelIndex index = stringListModel->index(i);
            changedList << index.data().toString();
        }
        emit Changed(changedList);
    });
}
Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::on_pushButton_clicked()
{
    QStringList list = QStringList() << "Ctrl+O" << "Ctrl+S" << "F1" << "Ctrl+Q";
    stringListModel->setStringList(list);
}

void Keyboard::getList(QStringList strList)
{
    stringListModel->setStringList(strList);
}
