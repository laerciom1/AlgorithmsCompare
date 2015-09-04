#ifndef DATA_H
#define DATA_H

#include <QVector>

class Data{
    private:
        int iterations;
    public:
        Data(int i);
        QVector<double> getTempos(QVector<double> tempos);
        QVector<double> getDesvioPadrao(QVector<double> tempos);
};

#endif // DATA_H
