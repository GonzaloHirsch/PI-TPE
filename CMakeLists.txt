cmake_minimum_required(VERSION 3.10)
project(PI_TPE C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PI_TPE
        ADT/AirportADT.c
        ADT/AirportADT.h
        Types.h
        ADT/ListADT.c
        ADT/ListADT.h
        main.c
        ADT/MovementADT.c
        ADT/MovementADT.h
        ProcessData.c
        ProcessData.h
        ErrorHandler.c
        ErrorHandler.h
        Querys.c
        Querys.h)
