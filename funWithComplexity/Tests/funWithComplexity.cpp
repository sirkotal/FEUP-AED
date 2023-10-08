// AED 2022/2023 - Aula Pratica 02
// Pedro Ribeiro (DCC/FCUP) [ultimo update: 25/09/2022]

#include "funWithComplexity.h"
#include <algorithm>
#include <climits>

// ----------------------------------------------------------
// Exercicio 4: Sequencias
// ----------------------------------------------------------
// TODO
int FunWithComplexity::maxSubArray(const vector<int> & v) {
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int n: v) {
        current_sum = current_sum + n;
        if (max_sum < current_sum) {
            max_sum = current_sum;
        }
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    return max_sum;
}

/*
EXPECT_EQ(-1, FunWithComplexity::maxSubArray({-2, -1, -3}));
EXPECT_EQ(30, FunWithComplexity::maxSubArray({2, 4, 6, 8, 10}));
*/


// ----------------------------------------------------------
// Exercicio 5: Analisando um rio
// ----------------------------------------------------------
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int len = v.size();
    int regions = 0;
    int deep = 0;
    for (int i = 0; i < k; i++) {
        if (v[i] >= t) {
            deep++;
        }
    }
    
    if (k % 2 == 0) {
        if (deep >= k/2) {
            regions++;
        }
    }
    else {
        if (deep > k/2) {
            regions++;
        }
    }

    for (int i = k; i < len; i++) {
        if (v[i] >= t) {
            deep++;
        } 
        if (v[i-k] >= t) {
            deep--;
        }
        if (k % 2 == 0) {
            if (deep >= k/2) {
                regions++;
            }
        }
        else {
            if (deep > k/2) {
                regions++;
            }
        }
    }
    return regions;
}

// ----------------------------------------------------------
// Exercicio 6: Espiral de Números
// ----------------------------------------------------------
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}

// ----------------------------------------------------------
// Exercicio 8: Caderno Quadriculado
// ----------------------------------------------------------
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}