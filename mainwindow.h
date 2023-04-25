#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QKeyEvent>
#include <QEvent>
#include <QSharedPointer>
#include <QMdiArea>
#include <QPrinter>
#include <QPrintDialog>
#include <QDateTime>
#include <QTimer>

#include "form.h"
#include "keyboard.h"
#include "filemanager.h"
//#include "mythread.h"
#include "searchclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void changeEvent(QEvent* event) override;

signals:
    void sendToKeyboard(QStringList strList);
    void chandgeSearch(QString arg1);
    void searchInDir(QString strPant);
private slots:

    //Слоты действий меню
    void open();
    void openOnlyRead();
    void save();
    void help();

    //Слоты изменения языка приложения
    void changeLanguageUS();
    void changeLanguageRU();

    //Слот нового документа
    void newD();

    //Слоты изменения темы редактора
    void on_dark_clicked();
    void on_light_clicked();

    //Слот работы с файловым менеджером
    void changePath(QFileInfo fileInfo);
    void printD();

    //Урок 7
    //Слоты изменения формата фрагмента текста
    void copyFText();
    void setFText();
    //Слоты положения текста
    void setTextLeft();
    void setTextCenter();
    void setTextRight();
    //Cлот диалога с шрифтами
    void setFont();

    //Слот вставки времени
    void setDateTime();

    void on_lineEdit_2_textEdited(const QString &arg1);
    void resultSearch(QStringList);
    void on_searchView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    Keyboard* keyboard;
    fileManager* f;
    QShortcut* openKey;
    QShortcut* saveKey;
    QShortcut* helpKey;
    QShortcut* quitKey;
    QMdiArea* area;

    //Урок 7
    QTextCharFormat* tcf;
    int* aligment;

    //Урок 8
    QDateTime* dt;
    QStringListModel* searchModel;
    searchClass* sc;
    QThread* search;

};
#endif // MAINWINDOW_H
