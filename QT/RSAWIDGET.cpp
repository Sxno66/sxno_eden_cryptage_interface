#include "RSAWIDGET.h"

RSAWidget::RSAWidget(QWidget *parent) : QWidget(parent)
{
    titleLabel = new QLabel("lolo", this);
    QFont font = titleLabel->font();
    font.setPointSize(14);
    titleLabel->setFont(font);

    inputEdit = new QLineEdit(this);
    outputEdit = new QLineEdit(this);
    hashButton = new QPushButton("lala", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(titleLabel);
    layout->addWidget(inputEdit);
    layout->addWidget(hashButton);
    layout->addWidget(outputEdit);

    setLayout(layout);
}
