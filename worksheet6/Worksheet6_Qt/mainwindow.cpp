#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::on_pushButton_clicked);
    connect(ui->pushButton_2, &QPushButton::released, this, &MainWindow::on_pushButton_2_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
   // QMessageBox msgBox;
   // msgBox.setText("The right button was clicked");//message displayed
   // msgBox.exec(); //opens the dialogoue window
   emit statusUpdateMessage(QString("The right button was clicked"),0);
}


void MainWindow::on_pushButton_clicked()
{
   // QMessageBox msgBox;
   // msgBox.setText("The left button was clicked");//message displayed
   // msgBox.exec(); //opens the dialogoue window
   emit statusUpdateMessage(QString("The left button was clicked"),0);
}

