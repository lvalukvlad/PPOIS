 #include <gtest/gtest.h>
#include "BigInteger.h"

// Тесты для конструкторов
TEST(BigIntegerConstructor, DefaultConstructor) {
    BigInteger a;
    EXPECT_EQ(a, BigInteger("0"));
}

TEST(BigIntegerConstructor,StringConstructor) {
    BigInteger a("123");
    EXPECT_EQ(a, BigInteger("123"));
}

TEST(BigIntegerConstructor, NegativeStringConstructor) {
    BigInteger a("-123");
    EXPECT_EQ(a, BigInteger("-123"));
}

TEST(BigIntegerConstructor, VectorConstructor) {
    std::vector<int> digits = { 3, 2, 1 };
    BigInteger a(digits, true);
    EXPECT_EQ(a, BigInteger("123"));
}

TEST(BigIntegerConstructor, CopyConstructor) {
    BigInteger a("123");
    BigInteger b(a);
    EXPECT_EQ(b, a);
}

// Тесты для операторов присваивания
TEST(BigIntegerAssignment, AssignmentOperator) {
    BigInteger a("123");
    BigInteger b;
    b = a;
    EXPECT_EQ(b, a);
}

// Тесты для преобразования в int
TEST(BigIntegerConversion, ToInt) {
    BigInteger a("123");
    int b = a;
    EXPECT_EQ(b, 123);
}

// Тесты для сложения
TEST(BigIntegerAddition, AddPositiveNumbers) {
    BigInteger a("123");
    BigInteger b("456");
    EXPECT_EQ(a + b, BigInteger("579"));
}

TEST(BigIntegerAddition, AddNegativeNumbers) {
    BigInteger a("-123");
    BigInteger b("-456");
    EXPECT_EQ(a + b, BigInteger("-579"));
}

TEST(BigIntegerAddition, AddPositiveAndNegativeNumbers) {
    BigInteger a("123");
    BigInteger b("-456");
    EXPECT_EQ(a + b, BigInteger("-333"));
}

// Тесты для вычитания
TEST(BigIntegerSubtraction, SubtractPositiveNumbers) {
    BigInteger a("456");
    BigInteger b("123");
    EXPECT_EQ(a - b, BigInteger("333"));
}

TEST(BigIntegerSubtraction, SubtractNegativeNumbers) {
    BigInteger a("-456");
    BigInteger b("-123");
    EXPECT_EQ(a - b, BigInteger("-333"));
}

TEST(BigIntegerSubtraction, SubtractPositiveAndNegativeNumbers) {
    BigInteger a("123");
    BigInteger b("-456");
    EXPECT_EQ(a - b, BigInteger("579"));
}

// Тесты для умножения
TEST(BigIntegerMultiplication, MultiplyPositiveNumbers) {
    BigInteger a("123");
    BigInteger b("456");
    EXPECT_EQ(a * b, BigInteger("56088"));
}

TEST(BigIntegerMultiplication, MultiplyNegativeNumbers) {
    BigInteger a("-123");
    BigInteger b("-456");
    EXPECT_EQ(a * b, BigInteger("56088"));
}

TEST(BigIntegerMultiplication, MultiplyPositiveAndNegativeNumbers) {
    BigInteger a("123");
    BigInteger b("-456");
    EXPECT_EQ(a * b, BigInteger("-56088"));
}

// Тесты для деления
TEST(BigIntegerDivision, DividePositiveNumbers) {
    BigInteger a("56088");
    BigInteger b("456");
    EXPECT_EQ(a / b, BigInteger("123"));
}

TEST(BigIntegerDivision, DivideNegativeNumbers) {
    BigInteger a("-56088");
    BigInteger b("-456");
    EXPECT_EQ(a / b, BigInteger("123"));
}

TEST(BigIntegerDivision, DividePositiveAndNegativeNumbers) {
    BigInteger a("56088");
    BigInteger b("-456");
    EXPECT_EQ(a / b, BigInteger("-123"));
}

// Тесты для инкремента и декремента
TEST(BigIntegerIncrementDecrement, PreIncrement) {
    BigInteger a("123");
    ++a;
    EXPECT_EQ(a, BigInteger("124"));
}

TEST(BigIntegerIncrementDecrement, PostIncrement) {
    BigInteger a("123");
    BigInteger b = a++;
    EXPECT_EQ(a, BigInteger("124"));
    EXPECT_EQ(b, BigInteger("123"));
}

TEST(BigIntegerIncrementDecrement, PreDecrement) {
    BigInteger a("123");
    --a;
    EXPECT_EQ(a, BigInteger("122"));
}

TEST(BigIntegerIncrementDecrement, PostDecrement) {
    BigInteger a("123");
    BigInteger b = a--;
    EXPECT_EQ(a, BigInteger("122"));
    EXPECT_EQ(b, BigInteger("123"));
}

// Тесты для сравнения
TEST(BigIntegerComparison, CompareEqualNumbers) {
    BigInteger a("123");
    BigInteger b("123");
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(!(a != b));
    EXPECT_FALSE(!(a < b));
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(!(a > b));
    EXPECT_TRUE(a >= b);
}

TEST(BigIntegerComparison, CompareDifferentNumbers) {
    BigInteger a("123");
    BigInteger b("456");
    EXPECT_FALSE(!(a == b));
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a < b);
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(!(a > b));
    EXPECT_FALSE(!(a >= b));
}

TEST(BigIntegerComparison, CompareWithInt) {
    BigInteger a("123");
    int b = 123;
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(!(a != b));
    EXPECT_FALSE(!(a < b));
    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(!(a > b));
    EXPECT_TRUE(a >= b);
}

// Тесты для сложения с int
TEST(BigIntegerAddition, AddInt) {
    BigInteger a("123");
    int b = 456;
    EXPECT_EQ(a + b, BigInteger("579"));
}

TEST(BigIntegerAddition, AddNegativeInt) {
    BigInteger a("123");
    int b = -456;
    EXPECT_EQ(a + b, BigInteger("-333"));
}

// Тесты для вычитания с int
TEST(BigIntegerSubtraction, SubtractInt) {
    BigInteger a("456");
    int b = 123;
    EXPECT_EQ(a - b, BigInteger("333"));
}

TEST(BigIntegerSubtraction, SubtractNegativeInt) {
    BigInteger a("456");
    int b = -123;
    EXPECT_EQ(a - b, BigInteger("579"));
}

// Тесты для умножения с int
TEST(BigIntegerMultiplication, MultiplyInt) {
    BigInteger a("123");
    int b = 456;
    EXPECT_EQ(a * b, BigInteger("56088"));
}

TEST(BigIntegerMultiplication, MultiplyNegativeInt) {
    BigInteger a("123");
    int b = -456;
    EXPECT_EQ(a * b, BigInteger("-56088"));
}

// Тесты для деления с int
TEST(BigIntegerDivision, DivideInt) {
    BigInteger a("56088");
    int b = 456;
    EXPECT_EQ(a / b, BigInteger("123"));
}

TEST(BigIntegerDivision, DivideNegativeInt) {
    BigInteger a("56088");
    int b = -456;
    EXPECT_EQ(a / b, BigInteger("-123"));
}

int test_main(int argc, char** argv) {
    system("chcp 1251");
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}