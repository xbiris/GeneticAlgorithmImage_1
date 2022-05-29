#include "Solution.h"

/*
Solution::Solution(QImage img, QImage ref){
    this->image = img;
    this->refImage = ref;
    rank = 0;
}
void Solution::fitness(){
    uint diff = 0;
    for(int i = 0; i<image.width(); i++){
        for(int j = 0; j<image.height(); j++){
            int r_0 = image.pixelColor(i,j).red();
            int g_0 = image.pixelColor(i,j).green();
            int b_0 = image.pixelColor(i,j).blue();

            int r_1 = refImage.pixelColor(i,j).red();
            int g_1 = refImage.pixelColor(i,j).green();
            int b_1 = refImage.pixelColor(i,j).blue();
            diff += absoluteValue(r_0 - r_1);
            diff += absoluteValue(g_0 - g_1);
            diff += absoluteValue(b_0 - b_1);
            //diff += absoluteValue(image.pixel(i, j) - refImage.pixel(i, j));

        }
    }
    rank = diff;
}

void Solution::fitness() {
    rank = 0;
    QSize size = image.size();
    for (int y = 0; y < size.height(); y++) {
        const QRgb *line = (const QRgb *)image.scanLine(y);
        const QRgb *refLine = (const QRgb *)refImage.scanLine(y);
        for (int x = 0; x < size.width(); x++) {
            rank += abs(line[x].qRed() - refLine[x].qRed()) +
                    abs(line[x].qGreen() - refLine[x].qGreen()) +
                    abs(line[x].qBlue() - refLine[x].qBlue());
        }
    }
}


void Solution::fitness() {
  rank = 0;
  QSize size = image.size();
  for (int y = 0; y < size.height(); y++) {
    for (int x = 0; x < size.width(); x++) {
      QColor c1 = image.pixelColor(x,y);
      QColor c2 = refImage.pixelColor(x,y);
      rank += abs(c1.red() - c2.red()) + abs(c1.green() - c2.green()) + abs(c1.blue() - c2.blue());
    }
  }
}
*/

Solution::Solution(ImageRepresentation img, ImageRepresentation ref) : image(img), refImage(ref){
    rank = 0;
}

int Solution::absoluteValue(int x){
    if(x > 0)
        return x;
    return x * -1;
}

QImage Solution::getImage(){
    QImage image(this->image.w, this->image.h, QImage::Format_RGB16);
    int k = 0;
    for(int i = 0; i<this->image.w; i++){
        for(int j = 0; j<this->image.h; j++){
            QColor c(this->image.red[k], this->image.green[k],  this->image.blue[k]);
            image.setPixelColor(i,j, c);
            k++;
        }
    }
    return image;
}

void Solution::fitness() {
    rank = 0;
    for(int i = 0; i<this->image.w * this->image.h; i++){
        int d1 = absoluteValue(this->image.red[i] - this->refImage.red[i]);
        int d2 =  absoluteValue(this->image.green[i] - this->refImage.green[i]);
        int d3 = absoluteValue(this->image.blue[i] - this->refImage.blue[i]);
        rank += d1 * d1 + d2 * d2 + d3 * d3;
    }
}



