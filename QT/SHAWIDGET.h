// shawidget.h
#ifndef SHAWIDGET_H
#define SHAWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class SHAWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SHAWidget(QWidget *parent = nullptr);

private:
    QLineEdit *inputEdit;
    QLineEdit *outputEdit;
    QPushButton *hashButton;
    QLabel *titleLabel;
};

#endif
