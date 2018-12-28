#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStackedWidget>
#include <QWebEngineView>
#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView();
    view->load(QUrl("http://localhost:8090/camera.mjpeg"));
    QWebEngineView *view2 = new QWebEngineView();
    view2->load(QUrl("http://localhost:8091/screen.mjpeg"));
    ui->verticalLayout->addWidget(view);
    ui->verticalLayout->addWidget(view2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
