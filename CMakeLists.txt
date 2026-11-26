# Comando para executar:
# Dentro da pasta raiz: cd build
# cmake ..
# cmake --build .
# ./programa

cmake_minimum_required(VERSION 3.10)
project(programa)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(Headers)

set(Sources
    main.c
    Source/Pokemon.c
    Source/CentrodePesquisa.c
    Source/PokeLista.c
)
add_executable(programa ${Sources})
target_link_libraries(programa m)