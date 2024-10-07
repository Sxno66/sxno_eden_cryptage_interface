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

//hash generate
void MainWindow::on_pushButton_browse_hash_input_clicked()
{
    //lineEdit_hash_input_file
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_hash_input_file->setText(filePath);
    }

}


void MainWindow::on_pushButton_generate_hash_clicked()
{
    //lineEdit_hash_input_file
    //lineEdit_hash_output_file
    QString inputFilePath = ui->lineEdit_hash_input_file->text();
    inputFilePath.replace("/", "\\");
    std::string inputFileStd = inputFilePath.toStdString();
    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);

    Crypter Hash;
    ui->lineEdit_hash_output_file->setText(QString::fromStdString(Hash.Hashfile(inputFileStd)));
}




//verifiing
void MainWindow::on_pushButton_browse_hash_input_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_hash_input_file_2->setText(filePath);
    }
}


void MainWindow::on_pushButton_test_hash_clicked()
{
    //lineEdit_hash_input_file_2
    //lineEdit_hash_input_hash
    //HashVerif
    QString inputFilePath = ui->lineEdit_hash_input_file->text();
    QString inputHash = ui->lineEdit_hash_input_hash->text();

    inputFilePath.replace("/", "\\");

    std::string inputFileStd = inputFilePath.toStdString();
    std::string inputHASHStd = inputHash.toStdString();

    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);
    qDebug() << "Input File:" << QString::fromStdString(inputHASHStd);

    Crypter cry;

    if(cry.Hashfile(inputFileStd) == inputHASHStd ){
        ui->HashVerif->setText("Valid hash");
        ui->HashVerif->setStyleSheet("color: green;");
    }else{
        ui->HashVerif->setText("INValid hash !");
        ui->HashVerif->setStyleSheet("color: red;");
    }
}


void MainWindow::on_pushButton_browse_file_to_key_clicked()
{
    //lineEdit_input_aes_key
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_input_aes_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_generate_key_clicked()
{
    //lineEdit_input_aes_key
     QString inputFilePath = ui->lineEdit_input_aes_key->text();
    inputFilePath.replace("/", "\\");
     std::string inputFileStd = inputFilePath.toStdString();
    qDebug() << "Input File:" << QString::fromStdString(inputFileStd);

     AesGestion aes;
    aes.GenerateAESKey();
    aes.SaveAESKeyToFile(inputFileStd);
}


void MainWindow::on_pushButton_browse_input_clicked()
{
    //lineEdit_input_file
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
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_aes_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_encrypt_clicked()
{
    //lineEdit_input_file
    //lineEdit_output_file
    //lineEdit_aes_key
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


void MainWindow::on_pushButton_browse_rsa_pub_clicked()
{
    //lineEdit_rsa_pub_key
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_pub_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_rsa_priv_clicked()
{
    //lineEdit_rsa_priv_key
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_priv_key->setText(filePath);
    }
}


void MainWindow::on_pushButton_generate_rsa_keys_clicked()
{
    //genrate key
    QString Publickey = ui->lineEdit_rsa_pub_key->text();
    QString PrivateKey = ui->lineEdit_rsa_priv_key->text();

    Publickey.replace("/", "\\");
    PrivateKey.replace("/", "\\");

    std::string Publickeystd = Publickey.toStdString();
    std::string PrivateKeystd = PrivateKey.toStdString();

    qDebug() << "public File:" << QString::fromStdString(Publickeystd);
    qDebug() << "Private File:" << QString::fromStdString(PrivateKeystd);

    RsaGestion RSA;
    RSA.generationClef(Publickeystd, PrivateKeystd, 2048);

}


void MainWindow::on_pushButton_browse_rsa_public_encrypt_clicked()
{
    //lineEdit_rsa_public_path
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_public_path->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_rsa_encrypt_input_clicked()
{
    //lineEdit_rsa_encrypt_input_file
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_encrypt_input_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_rsa_encrypt_output_clicked()
{
    //lineEdit_rsa_encrypt_output_file
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_encrypt_output_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_rsa_encrypt_clicked()
{
    QString Publickey = ui->lineEdit_rsa_public_path->text();
    QString inputfile = ui->lineEdit_rsa_encrypt_input_file->text();
    QString outputfile = ui->lineEdit_rsa_encrypt_output_file->text();

    Publickey.replace("/", "\\");
    inputfile.replace("/", "\\");
    outputfile.replace("/", "\\");

    std::string Publickeystd = Publickey.toStdString();
    std::string inputfilestd = inputfile.toStdString();
    std::string outputfilestd = outputfile.toStdString();

    qDebug() << "public File:" << QString::fromStdString(Publickeystd);
    qDebug() << "file input File:" << QString::fromStdString(inputfilestd);
    qDebug() << "file output File:" << QString::fromStdString(outputfilestd);

    RsaGestion RSA;

    RSA.chargementClefsPublic(Publickeystd);
    RSA.chiffrementFichier(inputfilestd, outputfilestd, true);
}


void MainWindow::on_pushButton_browse_rsa_decrypt_input_2_clicked()
{
    //lineEdit_Private_Path
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_Private_Path->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_rsa_decrypt_input_clicked()
{
    //lineEdit_rsa_decrypt_input_file
    QString filePath = QFileDialog::getOpenFileName(this, QObject::tr("Select Input File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_decrypt_input_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_browse_rsa_decrypt_output_clicked()
{
    //lineEdit_rsa_decrypt_output_file
    QString filePath = QFileDialog::getSaveFileName(this, QObject::tr("Select Output File"), "", QObject::tr("All Files (*)"));
    if (!filePath.isEmpty())
    {
        ui->lineEdit_rsa_decrypt_output_file->setText(filePath);
    }
}


void MainWindow::on_pushButton_rsa_decrypt_clicked()
{
    //lineEdit_Public_Path
    //lineEdit_rsa_decrypt_input_file
    //lineEdit_rsa_decrypt_output_file
    QString Privatekey = ui->lineEdit_rsa_public_path->text();
    QString inputfile = ui->lineEdit_rsa_decrypt_input_file->text();
    QString outputfile = ui->lineEdit_rsa_decrypt_output_file->text();

    Privatekey.replace("/", "\\");
    inputfile.replace("/", "\\");
    outputfile.replace("/", "\\");

    std::string Privatekeykeystd = Privatekey.toStdString();
    std::string inputfilestd = inputfile.toStdString();
    std::string outputfilestd = outputfile.toStdString();

    qDebug() << "public File:" << QString::fromStdString(Privatekeykeystd);
    qDebug() << "file input File:" << QString::fromStdString(inputfilestd);
    qDebug() << "file output File:" << QString::fromStdString(outputfilestd);


    RsaGestion RSA;
    RSA.chargementClefsPrive(Privatekeykeystd);

    RSA.dechiffrementFichier(inputfilestd, outputfilestd, true);
}


