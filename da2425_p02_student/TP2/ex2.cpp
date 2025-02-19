// By: Gonçalo Leão
// Updated by DA 24/25 Team

bool subsetSumBF(unsigned int A[], unsigned int n, unsigned int T, unsigned int subset[], unsigned int &subsetSize) {
    // using brute force
    subsetSize = 0;  // This variable is defined for the unit test to work. You should update it in your implementation.

    /* A -> array
     * n -> array size
     * subset -> subarray that sums equals to T
     * subsetSize -> subarray size
     * T -> target sum
     * returns true if there is a subset, false otherwise
     */

    int curCand[n] = {0};

    while (true) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i]*curCand[i];
        }

        if (sum == T) {
            for (int i = 0; i < n; i++) {
                if (curCand[i] == 1) {
                    subset[subsetSize++] = A[i];
                }
            }
            return true;
        }

        int curIdx = 0;
        while (curCand[curIdx] != 0) {
            curIdx++;

            if (curIdx == n) { break; }
        }

        if (curIdx == n) { break; }

        for (int i = 0; i < curIdx; i++) {
            curCand[i] = 0;
        }

        curCand[curIdx] = 1;
    }

    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

unsigned int sum(unsigned int A[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

// Checks if A is a subset of B
bool isSubset(unsigned int A[], unsigned int nA, unsigned int B[], unsigned int nB) {
    for(unsigned int i = 0; i < nA; i++) {
        bool foundNum = false;
        for(unsigned int j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                foundNum = true;
                break;
            }
        }
        if(!foundNum) return false;
    }
    return true;
}

TEST(TP2_Ex2, testSubsetSum) {
    unsigned int A[] = {3, 34, 4, 12, 5, 2};
    unsigned int subset[6];
    unsigned int subsetSize;

    unsigned int T = 9;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 20;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 30;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), false);
}