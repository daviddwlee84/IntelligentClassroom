#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QWebEngineView>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createConnection()
{
    // Get Ip Address from textEdit box
    QString ipaddress = ui->textEdit->toPlainText();

    // Create new connection
    QWebEngineView *view = new QWebEngineView();
    view->load(QUrl("http://" + ipaddress + ":8090/camera.mjpeg"));
    QWebEngineView *view2 = new QWebEngineView();
    view2->load(QUrl("http://" + ipaddress + ":8091/screen.mjpeg"));
    ui->verticalLayout->addWidget(view);
    ui->verticalLayout->addWidget(view2);
}

void MainWindow::on_pushButton_clicked()
{
    // Close all current widget (i.e. WebEngineView)
    for(int i = 0; i < ui->verticalLayout->count(); i++)
    {
        QWidget *old_view = ui->verticalLayout->itemAt(i)->widget();
        old_view->close();
    }

    createConnection();
}
