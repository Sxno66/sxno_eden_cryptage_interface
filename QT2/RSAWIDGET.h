#ifndef RSAWIDGET_H
#define RSAWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>


class RSAWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RSAWidget(QWidget *parent = nullptr);

private:
    QLineEdit *inputEdit;
    QLineEdit *outputEdit;
    QPushButton *hashButton;
    QLabel *titleLabel;

};

#endif
