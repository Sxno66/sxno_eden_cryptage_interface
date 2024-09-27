#ifndef AESWIDGET_H
#define AESWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>

class AESWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AESWidget(QWidget *parent = nullptr);

private:
    QLineEdit *inputEdit;
    QLineEdit *outputEdit;
    QPushButton *hashButton;
    QLabel *titleLabel;

};
#endif
