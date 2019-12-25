#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

int main(int argc, char *argv[])
{
    int T;
    std::vector<int> fibonacci{ 1, 1 };

    std::cin >> T;
    while (T--)
    {
        size_t N, K;
        std::cin >> N >> K;

        int next;
        for (auto it = fibonacci.end(); (next = it[-1] + it[-2]) < K; it = fibonacci.end())
            fibonacci.push_back(next);

        std::vector<int> values(fibonacci.size());
        for (size_t i = 0; i < N; i++)
        {
            int A, B;
            std::cin >> A >> B;
            values[A] = std::max(values[A], B);
        }

        std::vector<int> dp;

        // IMPLEMENT DP

        std::cout << dp.back() << std::endl;
    }
    return 0;
}
