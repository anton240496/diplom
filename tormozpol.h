#ifndef TORMOZPOL_H
#define TORMOZPOL_H

#include <QMainWindow>

namespace Ui {
class tormozpol;
}

class tormozpol : public QMainWindow
{
    Q_OBJECT

public:
    explicit tormozpol(QWidget *parent = nullptr);
    ~tormozpol();

private slots:
    void on_pushButton_clicked();

private:
    Ui::tormozpol *ui;
};

#endif // TORMOZPOL_H
