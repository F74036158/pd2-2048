#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
    void rand2();
    void moveleft();
    void moveright();
    void moveup();
    void movedown();
    void shownum();
    void firstshow();
    void movefalse();
    void bloc();
    void plusleft();
    void plusright();
    void plusup();
    void plusdown();
    void gameover();
    void winn();
    int sco;
    bool win;
    bool wintime;
    int choose;
private slots:
    void on_reset_clicked();

    void on_conti_clicked();

    void on_dog_clicked();

    void on_GG_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
