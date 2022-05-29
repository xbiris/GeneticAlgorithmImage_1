#ifndef SOLUTION_H
#define SOLUTION_H
#include <QImage>
#include "imagerepresentation.h"

/*
class Solution{
public:
    Solution(QImage img, QImage ref);
    QImage getImage();
    void fitness();
    static int absoluteValue(int x);
private:
    friend class GeneticAlgorithm_Image;
    QImage image;
    QImage refImage;
    uint rank;
};
*/

class Solution{
public:
    Solution(ImageRepresentation img, ImageRepresentation ref);
    QImage getImage();
    void fitness();
    static int absoluteValue(int x);
private:
    friend class GeneticAlgorithm_Image;
    ImageRepresentation image;
    ImageRepresentation refImage;
    uint rank;
};
#endif // SOLUTION_H
