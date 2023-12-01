#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>

using namespace cv;
using namespace std;

int main() {

    Mat image = imread("C:\Users\Tomás\Documents\Code\Threads-master\imagenes", IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se encontró imagen.\n";
        return -1;
    }

    int num_hilos;
    
    do {
        cout << "Ingrese la cantidad de hilos (1-16): ";
        cin >> num_hilos;

        if (num_hilos < 1 || num_hilos > 16) {
            cout << "Número de hilos no válido. Debe estar entre 1 y 16.\n";
        }
    } while (num_hilos < 1 || num_hilos > 16);

    // hilos
    omp_set_num_threads(num_hilos);

    #pragma omp parallel for
    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            // Escala de grises
            uchar gray_value = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];


            printf("(%d) ", gray_value);
        }
    }

    return 0;
}