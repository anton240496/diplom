#ifndef ROLIKPODACHI_H
#define ROLIKPODACHI_H

#include <QMainWindow>

namespace Ui {
class rolikpodachi;
}

class rolikpodachi : public QMainWindow
{
    Q_OBJECT

public:
    explicit rolikpodachi(QWidget *parent = nullptr);
    ~rolikpodachi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rolikpodachi *ui;
};

#endif // ROLIKPODACHI_H
