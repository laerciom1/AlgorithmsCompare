#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sstream"
#include "string"
#include "iostream"
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btExecute_clicked()
{
    int iterations = ui->iterations->text().toInt();
    QStringList dimensions = ui->dimensions->text().split(":", QString::SkipEmptyParts);
    QString gap = dimensions.at(0);
    QString begin = dimensions.at(1);
    QString end = dimensions.at(2);
    int n = ((end.toInt() - begin.toInt())/gap.toInt())+1;
    int tamanhos[n];
    for(int i = 0; i<n;i++){
        tamanhos[i] = begin.toInt() + (i*gap.toInt());
    }

    QString result("");                             // Testando se ta
    for(int i = 0; i<n; i++){                       // tudo OK com os
        QString aux = QString::number(tamanhos[i]); // valores do vetor
        result.append(aux);                         // dos tamanhos;
    }

    ui->iterations->setText(result);                //Pra imprimir no campo de interações quando clica no Execute;

    if(ui->QuickBox->isChecked() && ui->BubbleBox->isChecked()){

    }
    else if(ui->BubbleBox->isChecked()){

    }
    else if(ui->QuickBox->isChecked()){

    }
}
