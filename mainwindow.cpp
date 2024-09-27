#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Charger le logo dans le label logolabel
    QPixmap logo("C:\\Users\\CIEL23_admin\\Documents\\TafavkCarl\\crypter_interface\\clef_style");
    ui->logolabel->setPixmap(logo.scaled(180, 180, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Afficher la page d'accueil au démarrage
    on_homebutton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearContentArea()
{
    ui->contentArea->clear();
}

void MainWindow::setContentText(const QString &text)
{
    ui->contentArea->setText(text);
}

void MainWindow::on_shabutton_clicked()
{
    clearContentArea();
    setContentText("SHA-256");
}

void MainWindow::on_rsabutton_clicked()
{
    clearContentArea();
    setContentText("RSA Encryption/Decryption");
}

void MainWindow::on_aesbutton_clicked()
{
    clearContentArea();
    setContentText("AES Encryption/Decryption");
}

void MainWindow::on_homebutton_clicked()
{
    clearContentArea();
    setContentText("Bienvenue dans l'interface de cryptographie");
}
