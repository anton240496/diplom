#ifndef KATRIG_H
#define KATRIG_H

#include <QMainWindow>

namespace Ui {
class katrig;
}

class katrig : public QMainWindow
{
    Q_OBJECT

public:
    explicit katrig(QWidget *parent = nullptr);
    ~katrig();

private slots:
    void on_pushButton_clicked();

private:
    Ui::katrig *ui;
};

#endif // KATRIG_H
