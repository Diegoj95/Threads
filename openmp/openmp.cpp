#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace chrono;

void procesarPorcion(Mat& image, Mat& grayImage, int startRow, int endRow) {
    for (int r = startRow; r < endRow; ++r) {
        #pragma omp parallel for
        for (int c = 0; c < image.cols; ++c) {
            Vec3b pixel = image.at<Vec3b>(r, c);

            // Calcular la luminosidad
            uchar luminosity = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);

            // Asignar directamente el valor en lugar de usar una sección crítica
            grayImage.at<uchar>(r, c) = luminosity;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <nombre_imagen_color> <nombre_imagen_grises> <num_hebras>\n";
        return -1;
    }

    // Cargar la imagen
    cout << "Cargando imagen . . ." << endl;
    Mat image = imread(argv[1], IMREAD_COLOR);

    if (image.empty()) {
        cout << "No se encontró la imagen a color.\n";
        return -1;
    }

    // Mostrar información de la imagen
    cout << "Filas: " << image.rows << " Columnas: " << image.cols << endl;

    // Inicio
    auto start = high_resolution_clock::now();

    // Matriz en escala de grises
    Mat grayImage(image.rows, image.cols, CV_8UC1);

    int numThreads = atoi(argv[3]);

    // Dividir la imagen en partes para cada hebra
    int rowsPerThread = image.rows / numThreads;

    #pragma omp parallel num_threads(numThreads)
    {
        int threadID = omp_get_thread_num();
        int startRow = threadID * rowsPerThread;
        int endRow = (threadID == numThreads - 1) ? image.rows : startRow + rowsPerThread;

        procesarPorcion(image, grayImage, startRow, endRow);
    }

    // Fin
    auto stop = high_resolution_clock::now();

    // Calcular el tiempo de ejecución en segundos
    chrono::duration<float> duration = (stop - start);

    cout << "Inicio de la conversión . . ." << endl;
    cout << "Fin de la conversión . . ." << endl;
    cout << "El tiempo total en segundos es: " << duration.count() << " segundos" << endl;

    // Guardar la imagen
    imwrite(argv[2], grayImage);

    // Mostrar la imagen
    imshow("Imagen en escala de grises", grayImage);
    waitKey(0);

    return 0;
}
