#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

    Mat image = imread("../imagenes/imagen.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se encontró imagen.\n";
        return -1;
    }

    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            printf("(%d %d %d) ", pixel[0], pixel[1], pixel[2]);
        }
    }

    return 0;
}
