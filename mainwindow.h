#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<map>
#include<set>
#include<string>
#include<list>
#include "insert_dlt.h"
#include "assign.h"
#include "tableview.h"
#include "add_member.h"
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void createDialog();
    void show_drop();
    void bookcount();
    void handleInsert(const QString &book_name, const int &books_num,const bool &flag);
    void handleDelete(const QString &book_name, const int &books_num,const bool &flag);



signals:


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();

    void updateCount(const QString& value);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
     map<QString, pair<int,bool>> *BooksList;
     set<QString> *Users;
     map<int, pair<QString, pair<QString,int>>> *logs;
    int *countBooks;
    int totalLogCount  = 0;
    Insert_dlt *insert();
    Assign *assi();
    TableView *tableview;
    Add_Member *add_member() ;
};
#endif // MAINWINDOW_H
