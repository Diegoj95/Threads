# Procesamiento paralelo de imágenes utilizando hebras

## Contenido

1. [Descripción](#descripción)
2. [Compilación y ejecución](#compilación-y-ejecución)
3. [Pruebas](#pruebas)
4. [Autores](#autores)

## Descripción

Este repositorio tiene la finalidad de aplicar un filtro a una imagen para transformarla a escala de grises utilizando el método de luminosidad por medio de diferentes enfoques para visualizar las ventajas de la paralelización.

Ejemplo:
![Imagen de Ejemplo](https://i.imgur.com/xAGpmmE.png)

## Compilación y ejecución

Prerequisitos:

   ```bash
   sudo apt-get install g++
   ```

   ```bash
   sudo apt-get install make
   ```

   ```bash
   sudo apt install libopencv-dev
   ```
   
Ver Readme para cada versión.

   - [Secuencial](secuencial/README.MD)
   - [Paralela Threads](thread/README.MD)
   - [Paralela OpenMP](openmp/README.MD)

## Pruebas

Se hicieron pruebas para cada versión, utilizando la misma imagen y diferentes números de hebras, mostrando sus tiempos de ejecución.

- Secuencial:
  
![Pruebas Secuenciales](https://i.imgur.com/9MLyTnw.png)

- Threads:
  
![Pruebas con Threads](https://i.imgur.com/dVdK3EF.png)

- OpenMP:
  
![Pruebas con OpenMP](https://i.imgur.com/0RAJBAR.png)

## Autores

- Diego Jiménez
- Tomás Munizaga
