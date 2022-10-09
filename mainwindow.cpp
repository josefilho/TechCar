#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "addclient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCadastrarCliente_triggered()
{
    AddClient newClient;
    newClient.setWindowTitle("Cadastro de cliente");
    newClient.exec();
}

