#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage StartGA();
private:
    Ui::MainWindow *ui;
    QLabel *label_0;
    QLabel *label_1;

    QImage img;
    QImage img_1;
};
#endif // MAINWINDOW_H
