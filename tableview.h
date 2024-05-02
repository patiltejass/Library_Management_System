#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QDialog>
#include<map>

namespace Ui {
class TableView;
}

class TableView : public QDialog
{
    Q_OBJECT

public:
    explicit TableView(std::map<int,std::pair<QString,std::pair<QString,int>>>&logs,QWidget *parent = nullptr);
    ~TableView();


private:
    Ui::TableView *ui;
    std::map<int,std::pair<QString,std::pair<QString,int>>>&tablelogs;
};

#endif // TABLEVIEW_H
