#include "data.h"
#include "math.h"

Data::Data(int i){
    this->iterations = i;
};

QVector<double> Data::getTempos(QVector<double> tempos){
    double soma = 0;
    QVector<double> TempoMedia;
    for(int i=0; i<tempos.size();i+=this->iterations){
        for(int j=i;j<i+this->iterations;j++){
            soma+=tempos[j];
        }
        TempoMedia.append(soma/this->iterations);
    }
    return TempoMedia;
};

QVector<double> Data::getDesvioPadrao(QVector<double> tempos){
    double soma = 0;
    double media = 0;
    double variancia = 0;
    QVector<double> DesvioPadrao;
    for(int i=0; i<tempos.size();i+=this->iterations){
        for(int j=i;j<i+this->iterations;j++){
            soma+=tempos[j];
        }
        media=soma/this->iterations;
        for(int j=i;j<i+this->iterations;j++){
            variancia+=pow((tempos[j]-media),2);
        }
        variancia/=this->iterations;
        DesvioPadrao.append(sqrt(variancia));
    }
    return DesvioPadrao;
};
