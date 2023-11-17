set(SOURCES_SECUENCIAL secuencial.cpp)
set(SOURCES_THREAD thread.cpp)
set(SOURCES_OPENMP openmp.cpp)


add_executable(Secuencial ${SOURCES_SECUENCIAL})
add_executable(Thread ${SOURCES_THREAD})
add_executable(OpenMP ${SOURCES_OPENMP})
