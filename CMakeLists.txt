cmake_minimum_required(VERSION 3.10)
project(ytdlp-cli LANGUAGES C VERSION 1.0.0)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
#setup

add_executable(ytdlp-cli main.c)


install(TARGETS ytdlp-cli DESTINATION bin)