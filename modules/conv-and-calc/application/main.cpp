// Copyright 2021 Bulychev Vladislav

#include <iostream>
#include <string>

#include "include/NumConvCalcApplication.h"

int main(int argc, const char* argv[]) {
    NumConvCalcApplication app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
