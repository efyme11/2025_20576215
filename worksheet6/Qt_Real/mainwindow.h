#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStandardItemModel>
#include <QMainWindow>
#include <QSortFilterProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void onItemSelected(const QModelIndex &current,
                        const QModelIndex &previous);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxyModel;
};
#endif // MAINWINDOW_H
