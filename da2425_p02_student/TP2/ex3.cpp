// By: Gonçalo Leão
// Updated by DA 24/25 Team

#include <vector>
#include <algorithm> // for sort
#include <gmock/gmock-matchers.h>

unsigned int knapsackBF(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    // using brute force; similar to ex2

    /*
     * values[] -> values of items i
     * weights[] -> weights of items i
     * n -> i items
     * maxWeight -> max weight of the knapsack
     * usedItems[] -> items that will go in the knapsack
     */

    for (int i = 0; i < n; i++) {
        usedItems[i] = false;
    }

    int max_sum = 0;
    int cur_weight = 0;
    while (true) {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += values[i]*usedItems[i];
            cur_weight += weights[i]*usedItems[i];
        }

        if () {
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

    return 0;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyValue(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    // most valuable items
    return 0;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyWeight(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    // ligther items
    return 0;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex3, testKnapsack_4items) {
    const unsigned int n = 4;
    {
        unsigned int values[n] = {10, 7, 11, 15};
        unsigned int weights[n] = {1, 2, 1, 3};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 36);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], false);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
    }

    {
        unsigned int values[n] = {3, 4, 5, 6};
        unsigned int weights[n] = {2, 3, 4, 5};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 7);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], false);
        EXPECT_EQ(usedItems[3], false);
    }
}

// this test is expected to fail
TEST(TP2_Ex3, testKnapsack_4items_greedy_fail) {
    const unsigned int n = 4;
    {
        unsigned int values[n] = {10, 7, 11, 15};
        unsigned int weights[n] = {1, 2, 1, 5};
        bool usedItems[n];

        EXPECT_EQ(knapsackGreedyValue(values, weights, n, 5, usedItems), 28);
        weights[0]=1;
        weights[1]=1;
        weights[3]=3;
        EXPECT_EQ(knapsackGreedyWeight(values, weights, n, 5, usedItems), 36);

    }
}


TEST(TP2_Ex3, testKnapsack_5items) {
    const unsigned int n = 5;
    {
        unsigned int values[n] = {1, 2, 5, 9, 4};
        unsigned int weights[n] = {2, 3, 3, 4, 6};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 10, usedItems), 16);
        EXPECT_EQ(usedItems[0], false);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
        EXPECT_EQ(usedItems[4], false);
    }
}


TEST(TP2_Ex3, testKnapsack_40items) {
    const unsigned int n = 20;
    {
        unsigned int values[n] = {1, 2, 5, 9, 4, 1,  2, 3, 8, 4,12, 20,
                                  1, 4, 4 ,3, 3, 6, 6, 4};
        unsigned int weights[n] = {2, 3, 3, 4, 4,3, 2, 1, 4, 6,10, 10, 3, 1, 6,2, 3, 3, 4, 6};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 10, usedItems), 24);

    }
}