cmake_minimum_required(VERSION 3.4)

project(OlimpiadiSquadre)

set(EXERCISES
    23
    blindpunch
    butoaie
    fibonaccibug
    funnygraph
    grades
    smartphone
    sprei
    teleport2)

foreach(ex IN LISTS EXERCISES)
    add_executable(${ex} src/${ex}/main.cpp)
endforeach(ex IN EXERCISES)
