#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include "shawidget.h"
#include "rsawidget.h"
#include "aeswidget.h"
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_shabutton_clicked();
    void on_rsabutton_clicked();
    void on_aesbutton_clicked();
    void on_homebutton_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *contentLayout;
    void clearContentArea();
    void addButtonToContentArea(const QString &text);
    void addLabelToContentArea(const QString &text);
    void setContentText(const QString &text);
    void showHomePage();
    void showSHAPage();
    void showRSAPage();
    void showAESPage();
};
#endif // MAINWINDOW_H
