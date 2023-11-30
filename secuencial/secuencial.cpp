#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <nombre_imagen_color> <nombre_imagen_grises>\n";
        return -1;
    }

    // Cargar la imagen
    Mat image = imread(argv[1], IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se encontró la imagen a color.\n";
        return -1;
    }

    // Inicio
    auto start = high_resolution_clock::now();

    // Matriz en escala de grises
    Mat grayImage(image.rows, image.cols, CV_8UC1);

    for (int r = 0; r < image.rows; r++) {
        for (int c = 0; c < image.cols; c++) {
            Vec3b pixel = image.at<Vec3b>(r, c);

            // Calcular la luminosidad
            uchar luminosity = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);

            grayImage.at<uchar>(r, c) = luminosity;
        }
    }

    // Fin
    auto stop = high_resolution_clock::now();

    std::chrono::duration<float> duration = (stop - start);

    cout << "El tiempo total en segundos es: " << duration.count() << " segundos" << endl;

    // Guardar la imagen
    imwrite(argv[2], grayImage);

    // Mostrar la imagen
    imshow("Imagen en escala de grises", grayImage);
    waitKey(0);

    return 0;
}
