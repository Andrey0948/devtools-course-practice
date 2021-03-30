// Copyright 2021 Gapon Andry

#include <gtest/gtest.h>

#include <tuple>
#include <cmath>

#include "include/complex_number.h"

TEST(Gapon_Andrey_ComplexNumberTest, Calculation) {
    ComplexNumber a(5.5, 2.3);
    ComplexNumber b(6.5, 4.3);
    ComplexNumber c(-4.0, 8.0);
    ComplexNumber num1 = (a + b) * c;
    ComplexNumber num2 = (a - b) / c;
    ComplexNumber res(-100.8, 69.6);
    ComplexNumber res2(-0.15, 0.2);
    EXPECT_EQ(res, num1);
    EXPECT_EQ(res2, num2);
}

typedef testing::TestWithParam<std::tuple<double, double,
    double, double, double, double>>
Gapon_Andrey_ComplexNumberTest_Param;
TEST_P(Gapon_Andrey_ComplexNumberTest_Param, associative_Test) {
    ComplexNumber num1(std::get<0>(GetParam()),
        std::get<1>(GetParam()));
    ComplexNumber num2(std::get<2>(GetParam()),
        std::get<3>(GetParam()));
    ComplexNumber num3(std::get<4>(GetParam()),
        std::get<5>(GetParam()));

    ComplexNumber res1 = (num1 + num2) + num3;
    ComplexNumber res2 = num1 + (num2 + num3);

    EXPECT_EQ(res1, res2);
}

TEST_P(Gapon_Andrey_ComplexNumberTest_Param,
    distributive_Test) {
    ComplexNumber num1(std::get<0>(GetParam()),
        std::get<1>(GetParam()));
    ComplexNumber num2(std::get<2>(GetParam()),
        std::get<3>(GetParam()));
    ComplexNumber num3(std::get<4>(GetParam()),
        std::get<5>(GetParam()));

    ComplexNumber res1 = (num1 + num2) * num3;
    ComplexNumber res2 = num1 * num3 + num2 * num3;

    EXPECT_EQ(res1, res2);
}

INSTANTIATE_TEST_CASE_P(, Gapon_Andrey_ComplexNumberTest_Param,
    testing::Values(
        std::make_tuple(1.0, 2.0, 3.0, 4.0, 5.0, 6.0),
        std::make_tuple(7.0, 8.0, 9.0, 1.0, 2.0, 3.0),
        std::make_tuple(4.0, 5.0, 6.5, 7.0, 8.0, 9.0),
        std::make_tuple(1.0, 2.0, 3.0, 4.0, 5.0, 6.0)));
