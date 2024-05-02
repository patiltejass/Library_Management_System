#ifndef ASSIGN_H
#define ASSIGN_H

#include <QDialog>
#include <map>
#include<set>
#include<list>
using namespace std;

namespace Ui {
class Assign;
}

class Assign : public QDialog
{
    Q_OBJECT

public:
    explicit Assign(map<QString,pair<int,bool>>& BooksList,
                    set<QString>& Users,
                    map<int,pair<QString,
                    pair<QString,int>>>& logs,
                    int &totalLogCount
                    ,QWidget *parent = nullptr);
    ~Assign();

private slots:
    void on_pushButton_clicked();
    void updateCount(const QString& value);
    void updateComboBox();
    // void on_radioButton_clicked(bool checked);

signals:
    void updatesignal();
private:
    Ui::Assign *ui;
    int &totalLogCount;
    map<QString,pair<int,bool>>& bookListMap;
    set<QString> &usersset;
    map<int,pair<QString,pair<QString,int>>>&librarylogs;
};

#endif // ASSIGN_H
