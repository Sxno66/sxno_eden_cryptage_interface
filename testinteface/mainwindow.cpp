#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "Crypter.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_browse_input_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_input_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_output_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_output_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_aes_key_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select AES Key File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_aes_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_encrypt_clicked()
{
    QString inputFilePath = ui->lineEdit_input_file->text();
    QString outputFilePath = ui->lineEdit_output_file->text();
    QString aesKeyFilePath = ui->lineEdit_aes_key->text();

    inputFilePath.replace("/", "\\");
    outputFilePath.replace("/", "\\");
    aesKeyFilePath.replace("/", "\\");

    std::string inputFileStd = inputFilePath.toStdString();
    std::string outputFileStd = outputFilePath.toStdString();
    std::string aesKeyFileStd = aesKeyFilePath.toStdString();

    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);
    qDebug() << "Output File:" << QString::fromStdString(outputFileStd);
    qDebug() << "AES Key File:" << QString::fromStdString(aesKeyFileStd);

    Crypter CRPT;


    CRPT.AEScrypt(aesKeyFileStd, inputFileStd, outputFileStd);
}


void MainWindow::on_pushButton_browse_decrypt_input_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Encrypted File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_decrypt_input_file->setText(filePath);
    }
}

void MainWindow::on_pushButton_browse_decrypt_output_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Decrypted Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_decrypt_output_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_load_aes_key_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select AES Key File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_load_aes_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_decrypt_clicked()
{
    QString encryptedFilePath = ui->lineEdit_decrypt_input_file->text();
    QString decryptedFilePath = ui->lineEdit_decrypt_output_file->text();
    QString aesKeyFilePath = ui->lineEdit_load_aes_key->text();

    encryptedFilePath.replace("/", "\\");
    decryptedFilePath.replace("/", "\\");
    aesKeyFilePath.replace("/", "\\");

    std::string encryptedFileStd = encryptedFilePath.toStdString();
    std::string decryptedFileStd = decryptedFilePath.toStdString();
    std::string aesKeyFileStd = aesKeyFilePath.toStdString();

    qDebug() << "Encrypted File:" << QString::fromStdString(encryptedFileStd);
    qDebug() << "Decrypted Output File:" << QString::fromStdString(decryptedFileStd);
    qDebug() << "AES Key File:" << QString::fromStdString(aesKeyFileStd);

    Crypter CRPT;


    CRPT.AESDecrypt(aesKeyFileStd, encryptedFileStd, decryptedFileStd);
}
