// mainwindow.cpp

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "insert_dlt.h"
#include <QDebug>
#include<string>
#include<iostream>
#include<QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Library Management System");
    BooksList = new  map<QString, pair<int,bool>>;
    Users = new  set<QString>;
    logs= new  map<int, pair<QString, pair<QString,int>>>;
    (*BooksList)["C++"] =  make_pair(7,true);
    (*BooksList)["History"] =  make_pair(8,false);
    (*Users).insert("ABC");
    ui->comboBox->addItem("Select an option");
    show_drop();
    bookcount();


    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::createDialog);
    connect(ui->comboBox,&QComboBox::currentTextChanged,this,&MainWindow::updateCount);
}
void MainWindow::updateCount(const QString& value){
    ui->label_3->setNum((*BooksList)[value].first);
}

void MainWindow::show_drop(){
    for(auto it : *BooksList){
        ui->comboBox->addItem(it.first);
    }
}
void MainWindow::bookcount(){
   countBooks = new int(0);
    for(auto it : *BooksList){
       *countBooks+=it.second.first;
   }
    QString itemName = QString::number(*countBooks);
    ui->label_3->setText(itemName);
}
void MainWindow::createDialog(){
    Insert_dlt *insert = new Insert_dlt(this); // Pass parent
    insert->show();
    connect(insert, &Insert_dlt::insert_books, this, &MainWindow::handleInsert);
    connect(insert, &Insert_dlt::delete_books, this, &MainWindow::handleDelete);
}

void MainWindow::handleInsert(const QString& books_name, const int& book_num,const bool& flag){



    qDebug() << "hjnujkik";
    auto it = BooksList->find(books_name);
    if(it!=BooksList->end()){
        it->second.first+=book_num;
        bookcount();
    }
    else{
        qDebug()<<books_name<<" "<<book_num<<" "<<flag;
        (*BooksList)[books_name]= make_pair(book_num,flag);
        ui->comboBox->addItem(books_name);
        bookcount();
    }

}
void MainWindow::handleDelete(const QString& books_name, const int& book_num,const bool &flag){
    auto it = BooksList->find(books_name);
    if(it == BooksList->end()){
        QMessageBox::warning(nullptr,"Warning","Book is not available in Library");
        bookcount();
    }
    else {
        QMessageBox::information(nullptr,"Success","Book Deletion successful");
        if(it->second.first <= book_num){
            QString itemTextToRemove = books_name;
            int index = ui->comboBox->findText(itemTextToRemove);
            if (index != -1) {
                ui->comboBox->removeItem(index);
            }

            BooksList->erase(it);
        }
        else{
            it->second.first -= book_num;
        }
        bookcount();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete BooksList;
    delete countBooks;
}

void MainWindow::on_pushButton_2_clicked()
{
    Assign *assi = new Assign(*BooksList,*Users,*logs, totalLogCount); // Pass parent
    assi->show();
    connect(assi,&Assign::updatesignal,this,&MainWindow::bookcount);
}


void MainWindow::on_pushButton_4_clicked()
{
    TableView *tableview = new TableView(*logs);
    tableview->show();
}
void MainWindow::on_pushButton_3_clicked(){
    Add_Member *add_member = new Add_Member(*Users); // Pass parent
    add_member->show();
}



