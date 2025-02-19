// By: Gonçalo Leão
// With contributions by Eduardo Almeida
// Updated by DA 24/25 Team

int maxSubsequenceBF(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    // using brute force

    // i -> where the subarray starts
    // j -> where the subarray ends
    // A -> array
    // n -> length do array

    int max_sum = 0;
    int sum = 0;

    for (int k = 0; k < n; k++) {
        sum =+ A[k];
        for (int l = k+1; l < n; l++) {
            sum += A[l];

            if (sum > max_sum) {
                max_sum = sum;
                i = k; j = l;
            }
        }
    }


    return max_sum;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex1, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequenceBF(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}