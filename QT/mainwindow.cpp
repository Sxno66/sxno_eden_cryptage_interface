#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Charger le logo dans le label logolabel
    QPixmap logo("C:\\Users\\CIEL23_admin\\Documents\\TafavkCarl\\crypter_interface\\clef_style");
    ui->logolabel->setPixmap(logo.scaled(1000, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Afficher la page d'accueil au démarrage
    showHomePage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHomePage()
{
    ui->contentArea->setText("Bienvenue dans l'interface de cryptographie");
    ui->contentArea->setAlignment(Qt::AlignCenter);
}

void MainWindow::showSHAPage()
{
    QString content = "Page SHA-256\n\n"
                      "Entrez le texte à hacher :\n"
                      "[Zone de texte]\n"
                      "[Bouton Hacher]\n"
                      "Résultat du hachage :\n"
                      "[Zone de résultat]";
    ui->contentArea->setText(content);
    ui->contentArea->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void MainWindow::showRSAPage()
{
    QString content = "Page RSA\n\n"
                      "Génération de clés :\n"
                      "[Bouton Générer]\n"
                      "Clé publique : [Zone de texte]\n"
                      "Clé privée : [Zone de texte]\n\n"
                      "Chiffrement/Déchiffrement :\n"
                      "Texte : [Zone de texte]\n"
                      "[Bouton Chiffrer] [Bouton Déchiffrer]\n"
                      "Résultat : [Zone de résultat]";
    ui->contentArea->setText(content);
    ui->contentArea->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void MainWindow::showAESPage()
{
    QString content = "Page AES\n\n"
                      "Clé : [Zone de texte]\n"
                      "Texte à chiffrer/déchiffrer : [Zone de texte]\n"
                      "[Bouton Chiffrer] [Bouton Déchiffrer]\n"
                      "Résultat : [Zone de résultat]";
    ui->contentArea->setText(content);
    ui->contentArea->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void MainWindow::on_shabutton_clicked()
{
    showSHAPage();
}

void MainWindow::on_rsabutton_clicked()
{
    showRSAPage();
}

void MainWindow::on_aesbutton_clicked()
{
    showAESPage();
}

void MainWindow::on_homebutton_clicked()
{
    showHomePage();
}
