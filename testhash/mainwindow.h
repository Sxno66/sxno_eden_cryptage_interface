#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_browse_hash_input_clicked();

    void on_pushButton_generate_hash_clicked();

    void on_pushButton_browse_test_input_clicked();

    void on_pushButton_verify_hash_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
