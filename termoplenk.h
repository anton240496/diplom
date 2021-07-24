#ifndef TERMOPLENK_H
#define TERMOPLENK_H

#include <QMainWindow>

namespace Ui {
class termoplenk;
}

class termoplenk : public QMainWindow
{
    Q_OBJECT

public:
    explicit termoplenk(QWidget *parent = nullptr);
    ~termoplenk();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::termoplenk *ui;
};

#endif // TERMOPLENK_H
