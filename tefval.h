#ifndef TEFVAL_H
#define TEFVAL_H

#include <QMainWindow>

namespace Ui {
class tefval;
}

class tefval : public QMainWindow
{
    Q_OBJECT

public:
    explicit tefval(QWidget *parent = nullptr);
    ~tefval();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tefval *ui;
};

#endif // TEFVAL_H
