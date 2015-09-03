#ifndef ALGORITHMS
#define ALGORITHMS

#include <QVector>

class Algorithms{
    private:
        QVector<int> tamanhos;
        int iteracoes;
    public:
        Algorithms(QVector<int> t, int i);
        QVector<int> executeQk();
        QVector<int> executeBb();
        QVector<int> executeAll();
        void quick(int *v, int e, int d);
        void bubble(int *list, int n);
        QVector<int> getTamanhos();
        int getIteracoes();
};

#endif // QUICKSORT

