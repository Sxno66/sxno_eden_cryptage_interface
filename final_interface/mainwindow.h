#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>  // Include QFileDialog for file browsing

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
    void on_pushButton_browse_hash_input_clicked(); // Slot for first browse button
    void on_pushButton_generate_hash_clicked();

    void on_pushButton_browse_hash_input_2_clicked();

    void on_pushButton_test_hash_clicked();

    void on_pushButton_browse_file_to_key_clicked();

    void on_pushButton_generate_key_clicked();

    void on_pushButton_browse_input_clicked();

    void on_pushButton_browse_output_clicked();

    void on_pushButton_browse_aes_key_clicked();

    void on_pushButton_encrypt_clicked();

    void on_pushButton_browse_decrypt_input_clicked();

    void on_pushButton_browse_decrypt_output_clicked();

    void on_pushButton_browse_load_aes_key_clicked();

    void on_pushButton_decrypt_clicked();

    void on_pushButton_browse_rsa_pub_clicked();

    void on_pushButton_browse_rsa_priv_clicked();

    void on_pushButton_generate_rsa_keys_clicked();

    void on_pushButton_browse_rsa_public_encrypt_clicked();

    void on_pushButton_browse_rsa_encrypt_input_clicked();

    void on_pushButton_browse_rsa_encrypt_output_clicked();

    void on_pushButton_rsa_encrypt_clicked();

    void on_pushButton_browse_rsa_decrypt_input_2_clicked();

    void on_pushButton_browse_rsa_decrypt_input_clicked();

    void on_pushButton_browse_rsa_decrypt_output_clicked();

    void on_pushButton_rsa_decrypt_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
