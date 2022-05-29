#ifndef IMAGEREPRESENTATION_H
#define IMAGEREPRESENTATION_H
#include <vector>
#include <QImage>

class ImageRepresentation
{
public:
    ImageRepresentation(int w, int h);
    ImageRepresentation(QImage image);
    ImageRepresentation(const ImageRepresentation &image);
    ImageRepresentation &operator=(const ImageRepresentation &other);
private:
    std::vector<unsigned char> red;
    std::vector<unsigned char> green;
    std::vector<unsigned char> blue;
    int w;
    int h;
    friend class GeneticAlgorithm_Image;
    friend class Solution;
    int rank = 0;
};


#endif // IMAGEREPRESENTATION_H
