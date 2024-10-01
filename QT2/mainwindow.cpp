#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    applystyles();
    showHomePage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showHomePage()
{
    QWidget *homeWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(homeWidget);

    QLabel *welcomeLabel = new QLabel("Bienvenue dans l'interface de cryptographie", this);
    welcomeLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(welcomeLabel);

    // Ajouter des boutons pour naviguer
    QPushButton *shaButton = new QPushButton("SHA", this);
    QPushButton *rsaButton = new QPushButton("RSA", this);
    QPushButton *aesButton = new QPushButton("AES", this);

    connect(shaButton, &QPushButton::clicked, this, &MainWindow::on_shabutton_clicked);
    connect(rsaButton, &QPushButton::clicked, this, &MainWindow::on_rsabutton_clicked);
    connect(aesButton, &QPushButton::clicked, this, &MainWindow::on_aesbutton_clicked);

    layout->addWidget(shaButton);
    layout->addWidget(rsaButton);
    layout->addWidget(aesButton);

    homeWidget->setLayout(layout);
    setCentralWidget(homeWidget);
}

void MainWindow::showSHAPage()
{
    QWidget *shaWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(shaWidget);

    QPushButton *returnButton = new QPushButton("Retour", this);
    QPushButton *hashButton = new QPushButton("Hacher", this);
    QPushButton *resetButton = new QPushButton("Réinitialiser", this); // Second bouton
    QLineEdit *inputText = new QLineEdit(this);
    QTextEdit *resultText = new QTextEdit(this);
    resultText->setReadOnly(true);

    layout->addWidget(new QLabel("Entrez le texte à hacher :")); // Label pour le texte à hacher
    layout->addWidget(inputText); // Zone de texte pour l'entrée
    layout->addWidget(hashButton); // Bouton pour hacher
    layout->addWidget(new QLabel("Résultat du hachage :")); // Label pour le résultat
    layout->addWidget(resultText); // Zone de texte pour le résultat
    layout->addWidget(resetButton); // Bouton pour réinitialiser
    layout->addWidget(returnButton); // Ajouter le bouton Retour

    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_homebutton_clicked);

    connect(hashButton, &QPushButton::clicked, this, [inputText, resultText]() {
        QString hashed = "hashed_" + inputText->text(); // Remplacer par la fonction de hachage réelle
        resultText->setText(hashed);
        qDebug() << "Hachage effectué pour :" << inputText->text();
    });

    connect(resetButton, &QPushButton::clicked, [inputText, resultText]() {
        inputText->clear(); // Effacer la zone de texte
        resultText->clear(); // Effacer le résultat
    });

    shaWidget->setLayout(layout);
    setCentralWidget(shaWidget);

}

void MainWindow::showRSAPage()
{
    QWidget *rsaWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(rsaWidget);

    QPushButton *returnButton = new QPushButton("Retour", this);
    QPushButton *generateButton = new QPushButton("Générer Clés", this);
    QLineEdit *publicKeyText = new QLineEdit(this);
    QLineEdit *privateKeyText = new QLineEdit(this);
    QPushButton *encryptButton = new QPushButton("Chiffrer", this);
    QPushButton *decryptButton = new QPushButton("Déchiffrer", this);
    QTextEdit *resultText = new QTextEdit(this);
    resultText->setReadOnly(true);

    layout->addWidget(returnButton); // Ajouter le bouton Retour
    layout->addWidget(new QLabel("Génération de clés :"));
    layout->addWidget(generateButton);
    layout->addWidget(new QLabel("Clé publique :"));
    layout->addWidget(publicKeyText);
    layout->addWidget(new QLabel("Clé privée :"));
    layout->addWidget(privateKeyText);
    layout->addWidget(new QLabel("Texte à chiffrer :"));
    layout->addWidget(encryptButton);
    layout->addWidget(decryptButton);
    layout->addWidget(new QLabel("Résultat :"));
    layout->addWidget(resultText);

    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_homebutton_clicked); // Connecter le bouton
    connect(generateButton, &QPushButton::clicked, this, [publicKeyText, privateKeyText]() {
        publicKeyText->setText("public_key"); // Remplacer par la génération réelle de clés
        privateKeyText->setText("private_key"); // Remplacer par la génération réelle de clés
        qDebug() << "Clés générées.";
    });

    rsaWidget->setLayout(layout);
    setCentralWidget(rsaWidget);
}

void MainWindow::showAESPage()
{
    QWidget *aesWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(aesWidget);

    QPushButton *returnButton = new QPushButton("Retour", this);
    QLineEdit *keyText = new QLineEdit(this);
    QLineEdit *inputText = new QLineEdit(this);
    QPushButton *encryptButton = new QPushButton("Chiffrer", this);
    QPushButton *decryptButton = new QPushButton("Déchiffrer", this);
    QTextEdit *resultText = new QTextEdit(this);
    resultText->setReadOnly(true);

    layout->addWidget(returnButton); // Ajouter le bouton Retour
    layout->addWidget(new QLabel("Clé :"));
    layout->addWidget(keyText);
    layout->addWidget(new QLabel("Texte à chiffrer/déchiffrer :"));
    layout->addWidget(inputText);
    layout->addWidget(encryptButton);
    layout->addWidget(decryptButton);
    layout->addWidget(new QLabel("Résultat :"));
    layout->addWidget(resultText);

    connect(returnButton, &QPushButton::clicked, this, &MainWindow::on_homebutton_clicked); // Connecter le bouton

    aesWidget->setLayout(layout);
    setCentralWidget(aesWidget);
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

void MainWindow::on_return_clicked()
{
    showHomePage();
}

void MainWindow::applystyles()
{
    this->setStyleSheet("QWidget { background-color: #f0f0f0; }"
                        "QPushButton { background-color: #007BFF; color: white; border: none; padding: 10px; border-radius: 5px; }"
                        "QPushButton:hover { background-color: #0056b3; }"
                        "QLineEdit, QTextEdit { border: 1px solid #ccc; border-radius: 5px; padding: 10px; }"
                        "QLabel { font-size: 16px; font-weight: bold; }");
}


