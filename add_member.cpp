#include "add_member.h"
#include "ui_add_member.h"
#include<QMessageBox>

Add_Member::Add_Member(std::set<QString> &Users,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Add_Member),
    memberlist(Users)
{
    ui->setupUi(this);
    setWindowTitle("Add User");
    ui->textEdit->setPlaceholderText("Enter Member Name");

}

Add_Member::~Add_Member()
{
    delete ui;
}

void Add_Member::on_pushButton_3_clicked()
{

    QString name = ui->textEdit->toPlainText();
    if(name==""){
        QMessageBox::warning(nullptr,"Warning","Please Enter an Value");
        return;
    }
    memberlist.insert(name);
    QMessageBox::information(nullptr,"Success","User Added Succesfully");
    this->close();
}

