#ifndef INSERT_DLT_H
#define INSERT_DLT_H

#include <QDialog>

namespace Ui {
class Insert_dlt;
}

class Insert_dlt : public QDialog
{
    Q_OBJECT

public:
    explicit Insert_dlt(QWidget *parent = nullptr);
    ~Insert_dlt();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


signals:
    void insert_books(QString books_name,int book_num,bool flag);
    void delete_books(QString books_name,int book_num,bool flag);

private:
    Ui::Insert_dlt *ui;
    int *book_num;
};

#endif // INSERT_DLT_H
