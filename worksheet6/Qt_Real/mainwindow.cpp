#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(QStringList() << "Items");

    QStandardItem *fruits = new QStandardItem("Fruits");
    QStandardItem *apple = new QStandardItem("Apple");
    QStandardItem *banana = new QStandardItem("Banana");

    fruits->appendRow(apple);
    fruits->appendRow(banana);

    QStandardItem *vegetables = new QStandardItem("Vegetables");
    QStandardItem *carrot = new QStandardItem("Carrot");
    QStandardItem *onion = new QStandardItem("Onion");

    vegetables->appendRow(carrot);
    vegetables->appendRow(onion);

    model->appendRow(fruits);
    model->appendRow(vegetables);

    apple->setCheckable(true);
    banana->setCheckable(true);
    fruits->setCheckable(true);

    // 🔥 CREATE proxyModel FIRST
    proxyModel = new QSortFilterProxyModel(this);

    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setRecursiveFilteringEnabled(true);

    ui->treeView->setModel(proxyModel);

    // 🔥 CONNECT AFTER proxyModel exists
    connect(ui->searchBox,
            &QLineEdit::textChanged,
            proxyModel,
            &QSortFilterProxyModel::setFilterFixedString);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int a = ui->lineEdit1->text().toInt();
    int b = ui->lineEdit2->text().toInt();
    int result = a + b;

    ui->label->setText("Result: " + QString::number(result));
}

void MainWindow::onItemSelected(const QModelIndex &current,
                                const QModelIndex &previous)
{
    Q_UNUSED(previous);

    QString text = current.data().toString();
    qDebug() << "Selected:" << text;
}
