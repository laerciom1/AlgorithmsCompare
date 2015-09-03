#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sstream"
#include "algorithms.h"
#include <QVector>

using namespace std;

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
    QVector<int> tamanhos;
    for(int i = 0; i<n;i++){
        tamanhos.append(begin.toInt() + (i*gap.toInt()));
    }

    Algorithms alg(tamanhos, iterations);
    QVector<int> tempos;

    if(ui->QuickBox->isChecked() && ui->BubbleBox->isChecked()){
        tempos.append(alg.executeAll());
    }
    else if(ui->BubbleBox->isChecked()){
        tempos = alg.executeBb();
    }
    else if(ui->QuickBox->isChecked()){
        tempos = alg.executeQk();
    }

    QString result("");
    QString aux("");
    for(int i=0;i<tempos.size();i++){
        aux = QString::number(tempos[i]) + " ";
        result.append(aux);
    }

    ui->testes->setText(result);

}
