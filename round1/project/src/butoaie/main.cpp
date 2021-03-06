#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[])
{
    int N, K, P, Q;
    std::cin >> N >> K >> P >> Q;

    auto max = 0;
    std::vector<int> vec(N);
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> vec[i];
        if (max < vec[i])
            max = vec[i];
    }

    if (P > Q)
    {
        auto tmp = P;
        P = Q;
        Q = tmp;
        K = N - K;
    }

    int a = (max - 1) / Q + 1;
    int b = (max - 1) / P + 1;

    while (a < b)
    {
        int median = (a + b) / 2;

        int extra = 0;
        for (size_t i = 0; i < N; i++)
            extra += (std::max(vec[i] - median * P, 0) + Q - P - 1) / (Q - P);

        if (extra > (N - K) * median)
            a = median + 1;
        else
            b = median;
    }

    std::cout << a;
    return 0;
}