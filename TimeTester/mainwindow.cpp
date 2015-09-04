#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sstream"
#include "algorithms.h"
#include "data.h"
#include <QVector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    ui->plot->addGraph();
    ui->plot->addGraph();

    ui->plot->legend->setVisible(true);
    ui->plot->xAxis->setLabel("Vector Size");
    ui->plot->yAxis->setLabel("MS Time");

    ui->plot->graph(0)->setPen(QPen(Qt::cyan));
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 8));
    ui->plot->graph(0)->setName("QuickSort");
    ui->plot->graph(0)->setVisible(false);

    ui->plot->graph(1)->setPen(QPen(Qt::red));
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 8));
    ui->plot->graph(1)->setName("BubbleSort");
    ui->plot->graph(1)->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btExecute_clicked()
{
    ui->plot->graph(0)->setVisible(false);
    ui->plot->graph(1)->setVisible(false);
    int iterations = ui->iterations->text().toInt();
    Data data(iterations);
    QStringList dimensions = ui->dimensions->text().split(":", QString::SkipEmptyParts);
    QString gap = dimensions.at(0);
    QString begin = dimensions.at(1);
    QString end = dimensions.at(2);

    ui->plot->xAxis->setRange(begin.toInt()-(begin.toInt()/4),end.toInt()+(end.toInt()/4));

    int n = ((end.toInt() - begin.toInt())/gap.toInt())+1;
    QVector<int> tamanhos;
    QVector<double> tamanhosDouble;
    for(int i = 0; i<n;i++){
        tamanhos.append(begin.toInt() + (i*gap.toInt()));
        tamanhosDouble.append(begin.toInt() + (i*gap.toInt()));
    }

    Algorithms alg(tamanhos, iterations);
    QVector<double> tempos;
    QVector<double> QSTimeAux;
    QVector<double> BSTimeAux;
    int maior=-1;
    int menor;

    if(ui->QuickBox->isChecked() && ui->BubbleBox->isChecked()){
        tempos.append(alg.executeAll(ui->progressBar));
        menor = tempos[0];
        for(int i=0;i<tempos.size();i++){
            if(tempos[i] > maior){
                maior = tempos[i];
            }
            if(tempos[i] < menor){
                menor = tempos[i];
            }
        }
        ui->plot->yAxis->setRange(menor/2,2*maior);
        for(int i=0;i<tempos.size();i++){
            if(i%2==0){
                BSTimeAux.append(tempos[i]);
            }
            else{
                QSTimeAux.append(tempos[i]);
            }
        }
        ui->plot->graph(0)->setData(tamanhosDouble,data.getTempos(QSTimeAux));
        ui->plot->graph(1)->setData(tamanhosDouble,data.getTempos(BSTimeAux));
        ui->plot->graph(0)->setVisible(true);
        ui->plot->graph(1)->setVisible(true);
    }
    else if(ui->BubbleBox->isChecked()){
        tempos = alg.executeBb(ui->progressBar);
        menor = tempos[0];
        for(int i=0;i<tempos.size();i++){
            if(tempos[i] > maior){
                maior = tempos[i];
            }
            if(tempos[i] < menor){
                menor = tempos[i];
            }
        }
        ui->plot->yAxis->setRange(menor/2,2*maior);
        ui->plot->graph(1)->setData(tamanhosDouble,data.getTempos(tempos));
        ui->plot->graph(1)->setVisible(true);
    }
    else if(ui->QuickBox->isChecked()){
        tempos = alg.executeQk(ui->progressBar);
        menor = tempos[0];
        for(int i=0;i<tempos.size();i++){
            if(tempos[i] > maior){
                maior = tempos[i];
            }
            if(tempos[i] < menor){
                menor = tempos[i];
            }
        }
        ui->plot->yAxis->setRange(menor/2,2*maior);
        ui->plot->graph(0)->setData(tamanhosDouble,data.getTempos(tempos));
        ui->plot->graph(0)->setVisible(true);
    }

    ui->progressBar->setValue(100);
    ui->plot->replot();
}
