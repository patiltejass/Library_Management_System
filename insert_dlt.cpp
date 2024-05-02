#include "insert_dlt.h"
#include "ui_insert_dlt.h"
#include <QMessageBox>

Insert_dlt::Insert_dlt(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Insert_dlt)
{
    ui->setupUi(this);
    setWindowTitle("Update Library");
    ui->textEdit->setPlaceholderText("Enter the Name of Book");
    ui->textEdit_2->setPlaceholderText("Enter the number of Books");
}

Insert_dlt::~Insert_dlt()
{
    delete ui;
}

void Insert_dlt::on_pushButton_clicked()
{
    const QString books_name = ui->textEdit->toPlainText();
    QString books_number = ui->textEdit_2->toPlainText();
    bool flag;
    if(ui->radioButton->isChecked())    flag=true;
    else flag=false;
    if(books_number.toInt()){
        book_num = new int(books_number.toInt());
        emit insert_books(books_name,*book_num,flag);
        this->close();
    }
    else{
        QMessageBox::warning(nullptr,"Warning","Please Enter Valid Value");
    }

}


void Insert_dlt::on_pushButton_2_clicked()
{

    const QString books_name = ui->textEdit->toPlainText();
    QString books_number = ui->textEdit_2->toPlainText();
    bool flag;
    if(ui->radioButton->isChecked())    flag=true;
    else flag=false;
    if(books_number.toInt()){
        book_num = new int(books_number.toInt());
        emit delete_books(books_name,*book_num,flag);
        this->close();
    }
    else{
        QMessageBox::warning(nullptr,"Warning","Please Enter Valid Value");
    }
}




