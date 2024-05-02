#include "tableview.h"
#include "ui_tableview.h"

TableView::TableView(std::map<int,std::pair<QString,std::pair<QString,int>>>&logs,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TableView),
    tablelogs(logs)
{
    ui->setupUi(this);
    setWindowTitle("Library Logs");
    ui->tableWidget->setRowCount(20);
    int roe=0;
    for(auto it:tablelogs){
        ui->tableWidget->setItem(roe,0,new QTableWidgetItem(QString::number(it.first+1)));
        ui->tableWidget->setItem(roe,1,new QTableWidgetItem(it.second.first));
        ui->tableWidget->setItem(roe,2,new QTableWidgetItem(it.second.second.first));
        ui->tableWidget->setItem(roe,3,new QTableWidgetItem(QString::number(it.second.second.second)));
        roe++;
    }
}

TableView::~TableView()
{
    delete ui;
}


