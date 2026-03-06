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

    //Create/allocate the ModalList
    this ->partList = new ModelPartList("PartsList");

    //Linlk it to the treeview in the GUI
    ui ->treeView->setModel(this->partList);

    /*Manulaly create a model tree - there a much better and more
     flexible ways of doing this e.g nested functions*/
    ModelPart *rootItem = this->partList->getRootItem();

    //Add 3 top level items
    for (int i=0; i<3; i++){
        //Create strings for both data column
        QString name = QString ("Toplevel %1").arg(i);
        QString visible("true");

        //create child item
        ModelPart *childItem = new ModelPart({name, visible});

        //Append to tree top level
        rootItem -> appendChild(childItem);

        //Add 5 subItems
        for (int j = 0; j<5; j++){
            QString name = QString("Item %1,%2").arg(i).arg(j);
            QString visible("true");
            ModelPart *childChildItem = new ModelPart({name, visible});

            //Append to parent
            childItem -> appendChild(childChildItem);
        }
    }
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

