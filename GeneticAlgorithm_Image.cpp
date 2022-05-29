#include "GeneticAlgorithm_Image.h"
#define SAMPLE_SIZE 40  // How many top solutions to select
#define NUM 100       // Number of solutions per generation
#define MINIMUM 0       // domain min
#define MAXIMUM 255     // domain max
#define MAXGENERATIONS 100
#define MUTATION_PERCENT 100
#define MUTATION_LB 0.99
#define MUTATION_UB 1.01
#include <QColor>

GeneticAlgorithm_Image::GeneticAlgorithm_Image(QImage ref) : refImage(ref){
    this->referenceImage = ref;
    for(int i = 0; i<NUM; i++)
        this->solutions.push_back(Solution(QImage(ref.width(), ref.height(), QImage::Format_RGB16), ref));
}

void GeneticAlgorithm_Image::Start(){
    InitializePopulation();
    Solve();
}

void GeneticAlgorithm_Image::InitializePopulation(){
    std::uniform_int_distribution<int> uniformIntDistribution(MINIMUM, MAXIMUM);
    QSize size = referenceImage.size();
    for(auto &sol : solutions){
        for(int i = 0; i<size.width() * size.height(); i++){
            sol.image.red[i] = uniformIntDistribution(device);
            sol.image.green[i] = uniformIntDistribution(device);
            sol.image.blue[i] = uniformIntDistribution(device);
        }
    }
}

void GeneticAlgorithm_Image::Solve(){
    while(generations < MAXGENERATIONS){
        for(auto& s : solutions) { s.fitness(); }
        std::partial_sort(
                    solutions.begin(),
                    solutions.begin() + SAMPLE_SIZE,
                    solutions.end(),
                    [](const auto& lhs,const auto& rhs){
            return lhs.rank < rhs.rank;
        });

        generations += 1;

        std::vector<Solution> sample;
        std::copy(
                    solutions.begin(),
                    solutions.begin() + SAMPLE_SIZE,
                    std::back_inserter(sample)
                    );
        solutions.clear();


        Mutate(sample, MUTATION_LB, MUTATION_UB);


        Crossover(sample);

    }
}

void GeneticAlgorithm_Image::Mutate(std::vector<Solution> &sample, double lb, double ub){
    QSize size = referenceImage.size();
    std::uniform_real_distribution<double> m(lb,ub);
    std::for_each(sample.begin(), sample.begin() + (MUTATION_PERCENT / 100) * sample.size(), [&](auto& sol){
        for(int i = 0; i<size.width()*size.height(); i++){
           sol.image.red[i] = (int)(sol.image.red[i] * m(device))%256;
           sol.image.green[i] = (int)(sol.image.green[i] * m(device))%256;
           sol.image.blue[i] = (int)(sol.image.blue[i] * m(device))%256;
        }
    });
}

void GeneticAlgorithm_Image::Crossover(std::vector<Solution> &sample){
    QSize size = referenceImage.size();
    std::uniform_int_distribution<int> cross(0, SAMPLE_SIZE-1);
    for(int i = 0; i < NUM; i++){
        ImageRepresentation imr(size.width(), size.height());
        Solution sol(imr, refImage);
        for(int i = 0; i<size.width()*size.height(); i++){
            int x = cross(device);
            sol.image.red[i] = sample[x].image.red[i];
            sol.image.green[i] = sample[x].image.green[i];
            sol.image.blue[i] = sample[x].image.blue[i];

            /*sol.image.red[i] = (sample[0].image.red[i] + sample[1].image.red[i])/2;
            sol.image.green[i] = (sample[0].image.green[i] + sample[1].image.green[i])/2;
            sol.image.blue[i] = (sample[0].image.blue[i] + sample[1].image.blue[i])/2;*/
        }
        solutions.push_back(sol);
    }
}
