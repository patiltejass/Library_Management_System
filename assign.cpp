#include "assign.h"
#include "ui_assign.h"
#include"mainwindow.h"
#include<QDebug>
#include<QMessageBox>
using namespace std;


Assign::Assign(map<QString, pair<int, bool>>& BooksList,
               set<QString> &Users,
               map<int, pair<QString, pair<QString, int>>> &logs,
               int &totalLogCount,
               QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Assign),
    bookListMap(BooksList),
    usersset(Users),
    librarylogs(logs),
    totalLogCount(totalLogCount)
{
    ui->setupUi(this);
    setWindowTitle("Assign Books");
    // ui->comboBox_2->addItem("Select an Option");
    ui->comboBox->addItem("Select an Option");
    ui->textEdit->setPlaceholderText("Enter the No. of Books");
    for(auto it:usersset){
        ui->comboBox->addItem(it);
    }

    connect(ui->comboBox_2,&QComboBox::currentTextChanged,this,&Assign::updateCount);
    connect(ui->radioButton, &QRadioButton::clicked, this, &Assign::updateComboBox);
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &Assign::updateComboBox);
    connect(ui->radioButton_3, &QRadioButton::clicked, this, &Assign::updateComboBox);
    updateComboBox();
}

void Assign::updateComboBox() {
     // Always fully clear the combo box first

    // Add the placeholder item

    if (ui->radioButton->isChecked()) {
        ui->comboBox_2->clear();
        for (auto it : bookListMap) {
            if (it.second.second == true) {
                ui->comboBox_2->addItem(it.first);
                qDebug()<<"tech"<<it.first;
            }
        }
    } else if (ui->radioButton_2->isChecked()) {
        ui->comboBox_2->clear();
        for (auto it : bookListMap) {
            if (it.second.second == false) {
                ui->comboBox_2->addItem(it.first);
                qDebug()<<"non-tech"<<it.first;
            }
        }
    } else if (ui->radioButton_3->isChecked()) {
        ui->comboBox_2->clear();
        for (auto it : bookListMap) {
            ui->comboBox_2->addItem(it.first);
            qDebug()<<"all"<<it.first;
        }
    }
}


void Assign::updateCount(const QString& value) {
    int count = bookListMap[value].first;
    ui->textEdit_2->setPlainText(QString::number(count));
}



Assign::~Assign()
{
    delete ui;
}

void Assign::on_pushButton_clicked()
{



    QString Username = ui->comboBox->currentText();
    QString Book_Name = ui->comboBox_2->currentText();
    // qDebug()<<Book_Name;

    int books_cnt = ui->textEdit->toPlainText().toInt();
    auto it = bookListMap.find(Book_Name);
    // qDebug()<< "count in map: "<<it->second;
    // qDebug()<<"count entered: " <<books_cnt;
    if (it == bookListMap.end()) {
        QMessageBox::warning(nullptr, "Warning", "The selected book is not available.");
        return;
    }

    if (books_cnt <= 0) {
        QMessageBox::warning(nullptr, "Warning", "Please enter a valid count (greater than zero).");
        return;
    }

    if(((it->second.first)<books_cnt)){

        QMessageBox::warning(nullptr,"Warning","not enough books for allocation");
        return;
    }
    librarylogs[totalLogCount] = make_pair(Book_Name, make_pair(Username, books_cnt));
    totalLogCount++;
    // qDebug()<<it->second<<" "<<books_cnt;
    it->second.first-=books_cnt;
    // qDebug()<<it->second;
    QMessageBox::information(nullptr,"Success","Book allocated successfuly");
    emit updatesignal();
    this->close();
}




