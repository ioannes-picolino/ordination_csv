cmake_minimum_required(VERSION 3.10)

project(ordenacao_csv)

# Adiciona todos os arquivos .cpp presentes no diretório ao executável
file(GLOB SOURCES "*.cpp")

add_executable(teste ${SOURCES})
