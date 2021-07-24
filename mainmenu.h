#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

namespace Ui {
class mainmenu;
}

class mainmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_start_clicked(); // слот мастер поиска неиспраностей

    void on_pcopymode_clicked();

    void on_pfaksmodel_clicked();

    void on_pcomputernetwork_clicked();

    void on_ppositronicsmpf_clicked();

    void on_pfacsdevice_clicked();

    void on_fuser_clicked();

    void on_pqualitypictures_clicked();

    void on_avtor_triggered();

    void on_inst_triggered();

private:
    Ui::mainmenu *ui;
};

#endif // MAINMENU_H
