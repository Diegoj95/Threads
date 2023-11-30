#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("../imagenes/imagen.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se encontró la imagen.\n";
        return -1;
    }

    // Nueva matriz
    Mat grayImage(image.rows, image.cols, CV_8UC1);

    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);

            // Calcular la luminosidad
            uchar luminosity = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);

            // Asignar el valor de luminosidad al píxel en la nueva imagen en escala de grises
            grayImage.at<uchar>(r, c) = luminosity;

            //cout << static_cast<int>(luminosity) << " ";
        }
        cout << endl;
    }

    // Mostrar la imagen en escala de grises
    imshow("Imagen en escala de grises", grayImage);
    waitKey(0);

    return 0;
}
