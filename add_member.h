#ifndef ADD_MEMBER_H
#define ADD_MEMBER_H

#include <QDialog>
#include<set>
namespace Ui {
class Add_Member;
}

class Add_Member : public QDialog
{
    Q_OBJECT

public:
    explicit Add_Member(std::set<QString> &Users,QWidget *parent = nullptr);
    ~Add_Member();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Add_Member *ui;
    std::set<QString>&memberlist;
};

#endif // ADD_MEMBER_H
