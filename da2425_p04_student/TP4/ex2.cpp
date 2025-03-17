#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include "exercises.h"

std::string hanoiDC(unsigned int n, char src, char dest) {
    std::string res = "";

    if (n == 1) {
        res += src;
        res += "->";
        res += dest;
    }
    else {
        char aux = 'A' + 'B' + 'C' - src - dest;
        res += hanoiDC(n-1, src, aux) + ",";
        res += src;
        res += "->";
        res += dest;
        res += "," + hanoiDC(n-1, aux, dest);
    }

    return res;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, testHanoi_height4) {
    std::string moves = hanoiDC(4, 'A', 'B');
    EXPECT_EQ(std::count(moves.begin(),moves.end(),','),14); // there are 15 moves
    EXPECT_EQ(moves,"A->C,A->B,C->B,A->C,B->A,B->C,A->C,A->B,C->B,C->A,B->A,C->B,A->C,A->B,C->B");
}