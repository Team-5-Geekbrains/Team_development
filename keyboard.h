#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QShortcut>
#include <QKeyEvent>
#include <QEvent>
#include <QtWidgets>

namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

private slots:

    void on_pushButton_clicked();

    void getList(QStringList strList);

signals:
    void Changed(QStringList);

private:
    Ui::Keyboard *ui;
    QStringListModel* stringListModel;
    QStringList list;
};

#endif // KEYBOARD_H
