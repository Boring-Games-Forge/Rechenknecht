#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rechner = new Rechner();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete rechner;
}


void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "1");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "5");
}

void MainWindow::on_pushButton_plus_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "+");
}

void MainWindow::on_pushButton_equal_clicked()
{
    QString qstr = QString("%1").arg(rechner->calc(ui->lineEdit->text()));
    ui->lineEdit->setText(qstr);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "6");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "7");
}

void MainWindow::on_pushButton_8_clicked()
{
        ui->lineEdit->setText(ui->lineEdit->text() + "8");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "9");
}

void MainWindow::on_pushButton_0_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "0");
}

void MainWindow::on_pushButton_minus_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "-");
}

void MainWindow::on_pushButton_multiplication_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "*");
}

void MainWindow::on_pushButton_division_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "/");
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_right_bracket_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + ")");
}

void MainWindow::on_pushButton_left_bracket_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "(");
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "^");
}

void MainWindow::on_pushButton_pi_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text() + "3.1415");
}
