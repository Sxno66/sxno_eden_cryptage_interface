#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_browse_input_clicked();
    void on_pushButton_browse_output_clicked();
    void on_pushButton_browse_aes_key_clicked();

    void on_pushButton_encrypt_clicked();

    void on_pushButton_browse_decrypt_input_clicked();

    void on_pushButton_browse_decrypt_output_clicked();

    void on_pushButton_browse_load_aes_key_clicked();

    void on_pushButton_decrypt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
