#include <iostream>
#include <cassert>

#include <algorithm>
#include <vector>

std::vector<int> fibonacci{ 1, 1 };

typedef struct {
    int weight;
    int value;
} KnapsackItem;

int unboundedKnapsack(size_t W, std::vector<KnapsackItem> items)
{
    int* dp = new int[W + 1]{ 0 };

    for (size_t i = 0; i <= W; i++)
    {
        for (size_t j = 0; j < items.size(); j++)
        {
            auto item = items[j];
            if (item.weight <= i)
                dp[i] = std::max(dp[i], dp[i - item.weight] + item.value);
        }
    }

#if LIMITED_MEMORY
    int ret = dp[W];
    delete[] dp;
    return ret;
#else
    return dp[W];
#endif
}

int main(int argc, char *argv[])
{
    int T;
    assert(1 == scanf("%d", &T));
    for (size_t t = 0; t < T; t++)
    {
        int N, K;
        assert(2 == scanf("%d %d", &N, &K));

        for (size_t lastIndex = fibonacci.size() - 1; fibonacci.back() < K; lastIndex++)
            fibonacci.push_back(fibonacci[lastIndex - 1] + fibonacci[lastIndex]);

        std::vector<KnapsackItem> vec(N);
        for (size_t i = 0; i < N; i++)
        {
            int A, B;
            assert(2 == scanf("%d %d", &A, &B));
            vec[i] = { fibonacci[A], B };
        }

        printf("%d\n", unboundedKnapsack(K, vec));
    }
    return 0;
}
