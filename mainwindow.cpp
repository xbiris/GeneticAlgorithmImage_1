#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHBoxLayout>
#include <GeneticAlgorithm_Image.h>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout  *layout = new QHBoxLayout;
    label_0 = new QLabel;
    label_1 = new QLabel;
    img = QImage("D:/Facultate/OOP/extra_credit_4/GeneticAlgorithmImage/Images/I.png");
    //img_1 = QImage(img.width(), img.height(), QImage::Format_RGB16);

    QImage img_1 = StartGA();

    QPixmap pm = QPixmap::fromImage(img);
    QPixmap pm_1 = QPixmap::fromImage(img_1);

    label_0->setPixmap(pm);
    label_1->setPixmap(pm_1);

    layout->addWidget(label_0);
    layout->addWidget(label_1);

    label_0->setScaledContents(true);
    label_1->setScaledContents(true);

    QWidget* w = new QWidget(this);
    w->setMinimumSize(QSize(img.width() * 8, img.height() * 4));
    this->setMinimumSize(QSize(img.width() * 8, img.height() * 4));

    w->setLayout(layout);
}

QImage MainWindow::StartGA(){
    GeneticAlgorithm_Image ga(this->img);
    ga.Start();
    return ga.solutions[0].getImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}
