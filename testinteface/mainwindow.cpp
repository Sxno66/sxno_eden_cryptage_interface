#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>  // Include this for QFileDialog
//#include"Crypter.h"
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
        ui->lineEdit_input_file->setText(filePath);  // Set the input file path
    }
}

void MainWindow::on_pushButton_browse_output_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_output_file->setText(filePath);  // Set the output file path here (use correct QLineEdit for output)
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
    // Retrieve values from the text boxes
    QString inputFilePath = ui->lineEdit_input_file->text();
    QString outputFilePath = ui->lineEdit_output_file->text();
    QString aesKeyFilePath = ui->lineEdit_aes_key->text();

    // Replace forward slashes with double backslashes
    inputFilePath.replace("/", "\\");
    outputFilePath.replace("/", "\\");
    aesKeyFilePath.replace("/", "\\");

    // Print the modified values to the console
    qDebug() << "Input File:" << inputFilePath;
    qDebug() << "Output File:" << outputFilePath;
    qDebug() << "AES Key File:" << aesKeyFilePath;
}



