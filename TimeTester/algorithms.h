#ifndef ALGORITHMS
#define ALGORITHMS

#include <QVector>
#include <QProgressBar>

class Algorithms{
    private:
        QVector<int> tamanhos;
        int iteracoes;
    public:
        Algorithms(QVector<int> t, int i);
        QVector<double> executeQk(QProgressBar *pb);
        QVector<double> executeBb(QProgressBar *pb);
        QVector<double> executeAll(QProgressBar *pb);
        void quick(int *v, int e, int d);
        void bubble(int *list, int n);
        QVector<int> getTamanhos();
        int getIteracoes();
};

#endif // QUICKSORT

