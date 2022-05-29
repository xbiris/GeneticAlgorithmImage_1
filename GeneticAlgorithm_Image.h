#ifndef GENETICALGORITHM_IMAGE_H
#define GENETICALGORITHM_IMAGE_H
#include "Solution.h"
#include <vector>
#include <random>

class GeneticAlgorithm_Image{
public:
    GeneticAlgorithm_Image(QImage ref);
    void Start();
    void InitializePopulation();
    void Solve();
    void Mutate(std::vector<Solution> &sample, double lb, double ub);
    void Crossover(std::vector<Solution> &sample);
private:
    std::random_device device;
    QImage referenceImage;
    ImageRepresentation refImage;
    std::vector<Solution> solutions;
    uint generations = 0;
    friend class MainWindow;
};

#endif // GENETICALGORITHM_IMAGE_H
