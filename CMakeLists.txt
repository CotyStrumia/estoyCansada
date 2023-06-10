cmake_minimum_required(VERSION 3.24)
project(prueba)

set(CMAKE_CXX_STANDARD 17)

add_executable(prueba main.cpp Clientes.cpp Clientes.h Transacciones.cpp Transacciones.h tarjetas.cpp tarjetas.h)
