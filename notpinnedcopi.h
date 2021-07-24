#ifndef NOTPINNEDCOPI_H
#define NOTPINNEDCOPI_H

#include <QMainWindow>
#include<QtSql/QSqlQueryModel>

namespace Ui {
class notpinnedcopi;
}

class notpinnedcopi : public QMainWindow
{
    Q_OBJECT

public:
    explicit notpinnedcopi(QWidget *parent = nullptr);
    ~notpinnedcopi();

private slots:
    void on_main_triggered();

    void on_nazad_triggered();



    void on_notpin_clicked(const QModelIndex &index);

    void on_paper_clicked();

    void on_fuser_clicked();

private:
    Ui::notpinnedcopi *ui;
     QSqlQueryModel* notpinmodel;
};

#endif // NOTPINNEDCOPI_H
