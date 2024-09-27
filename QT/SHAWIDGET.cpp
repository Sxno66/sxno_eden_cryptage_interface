#include "shawidget.h"

// Par exemple, dans shawidget.cpp
SHAWidget::SHAWidget(QWidget *parent) : QWidget(parent)
{
    titleLabel = new QLabel("SHA-256 Hashing", this);
    QFont font = titleLabel->font();
    font.setPointSize(14);
    titleLabel->setFont(font);

    inputEdit = new QLineEdit(this);
    outputEdit = new QLineEdit(this);
    hashButton = new QPushButton("Hash", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(inputEdit);
    layout->addWidget(hashButton);
    layout->addWidget(outputEdit);

    setLayout(layout);

}
