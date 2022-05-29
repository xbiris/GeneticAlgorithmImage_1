#include "imagerepresentation.h"

ImageRepresentation::ImageRepresentation(int w, int h)
{
    for(int i = 0; i<w; i++){
        for(int j = 0; j<h; j++){
            red.push_back(0);
            green.push_back(0);
            blue.push_back(0);
        }
    }
    this->w = w;
    this->h = h;
}

ImageRepresentation::ImageRepresentation(QImage image)
{
    QSize size = image.size();
    for(int i = 0; i<size.width(); i++){
        for(int j = 0; j<size.height(); j++){
            red.push_back(image.pixelColor(i,j).red());
            green.push_back(image.pixelColor(i,j).green());
            blue.push_back(image.pixelColor(i,j).blue());
        }
    }
    this->w = size.width();
    this->h = size.height();
}

ImageRepresentation::ImageRepresentation(const ImageRepresentation &image)
{
    this->w = image.w;
    this->h = image.h;
    for(int i = 0; i<image.w*image.h; i++){
        this->red.push_back(image.red[i]);
        this->green.push_back(image.green[i]);
        this->blue.push_back(image.blue[i]);
    }
}

ImageRepresentation &ImageRepresentation::operator=(const ImageRepresentation &image){
    if (this == &image)
         return *this;
    this->w = image.w;
    this->h = image.h;
    this->red.clear();
    this->blue.clear();
    this->green.clear();
    for(int i = 0; i<image.w*image.h; i++){
        this->red.push_back(image.red[i]);
        this->green.push_back(image.green[i]);
        this->blue.push_back(image.blue[i]);
    }
    return *this;
}

