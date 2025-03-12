#include "exercises.h"
#include "cmath"

int aux_recursion(int A[], int beg, int end, int &i, int &j) {
    // base
    if (beg == end) {
        i = j = beg;
        return A[beg];
    }

    // recursion
    int beg2 = int(round((beg+end)/2.0));  // new starting point
    int end1 = beg2-1;

    int ir, jr;
    int bestSumRight = aux_recursion(A, beg, end1, ir, jr);

    int il, jl;
    int bestSumLeft = aux_recursion(A, beg2, end, il, jl);

    // check the other solution considering the middle
    // left
    auto curSum = A[end1];
    auto bestCrossingSumLeft = A[end1];
    auto iCrossing = end1;

    for (int k = end1 -1; k >= beg; k--) {
        curSum += A[k];

        if (curSum > bestCrossingSumLeft) {
            bestCrossingSumLeft = curSum;
            iCrossing = k;
        }
    }

    // right
    curSum = A[beg2];
    auto bestCrossingSumRight = A[beg2];
    auto jCrossing = beg2;

    for (int k = beg2 + 1; k <= end; k++) {
        curSum += A[k];

        if (curSum > bestCrossingSumRight) {
            bestCrossingSumRight = curSum;
            jCrossing = k;
        }
    }

    auto bestCrossingSum = bestCrossingSumLeft + bestCrossingSumRight;

    // compare all solutions
    if ((bestCrossingSum > bestSumLeft) && (bestCrossingSum > bestSumRight)) {
        i = iCrossing;
        j = jCrossing;

        return bestCrossingSum;
    }
    else if (bestSumLeft > bestSumRight) {
        i = il;
        j = jl;

        return bestSumLeft;
    }
    else {
        i = ir;
        j = jr;

        return bestSumRight;
    }
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {

    return aux_recursion(A, 0, n-1, i, j);;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex1, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}