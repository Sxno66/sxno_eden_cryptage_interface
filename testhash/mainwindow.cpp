#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include"Crypter.h"
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

void MainWindow::on_pushButton_browse_hash_input_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_hash_input_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_generate_hash_clicked()
{
    Crypter crypt;
    QString inputFilePath = ui->lineEdit_hash_input_file->text();
    inputFilePath.replace("/", "\\");
    std::string inputFileStd = inputFilePath.toStdString();
    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);

    // Convert std::string to QString before setting text in the QLineEdit
    ui->lineEdit_hash_output_file->setText(QString::fromStdString(crypt.Hashfile(inputFileStd)));
}



void MainWindow::on_pushButton_browse_test_input_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_test_input_file->setText(filePath);
    }

}


void MainWindow::on_pushButton_verify_hash_clicked()
{
    Crypter crypt;
    QString inputFilePath = ui->lineEdit_test_input_file->text();
    inputFilePath.replace("/", "\\");
    std::string inputFileStd = inputFilePath.toStdString();
    std::string inputHASH = ui->lineEdit_test_hash->text().toStdString();
    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);


    if(crypt.HashVerify(inputFileStd, inputHASH)== true){
        qDebug() << "HASH GOOD:";

    }else{
        qDebug() << "HASH BAD:";
    }
}

