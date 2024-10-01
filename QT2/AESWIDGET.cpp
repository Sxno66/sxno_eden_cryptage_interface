#include "AESWIDGET.h"

AESWidget::AESWidget(QWidget *parent) : QWidget(parent)
{
    titleLabel = new QLabel("lili", this);
    QFont font = titleLabel->font();
    font.setPointSize(14);
    titleLabel->setFont(font);

    inputEdit = new QLineEdit(this);
    outputEdit = new QLineEdit(this);
    hashButton = new QPushButton("louluo", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(inputEdit);
    layout->addWidget(hashButton);
    layout->addWidget(outputEdit);

    setLayout(layout);


}
