cmake_minimum_required(VERSION 3.26)
project(tp_final)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(tp_final
        src/Aeropuerto.cpp
        src/Aeropuerto.h
        src/Vuelo.h
        src/Vuelo.cpp
        src/main.cpp
        src/Graph.cpp
        src/Graph.h
        src/Aplicacion.h
        src/Menu.cpp
        src/Menu.h
        src/Controlador.cpp
        src/Controlador.h
        src/Hash.h
        src/LectorArchivos.h
        src/LectorArchivos.cpp
)
