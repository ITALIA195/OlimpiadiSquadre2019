#include <iostream>
#include <vector>
#include <iomanip>

int binarySearch(std::vector<std::pair<float, float>> vec, float num)
{
    int left = 0;
    int right = (int)vec.size() - 1;
    while (left <= right)
    {
        auto median = left + (right - left >> 1);
        auto pivot = vec[median].first;

        if (num == pivot)
            return num;
        if (num < pivot)
            right = median - 1;
        if (num > pivot)
            left = median + 1;
    }
    // When not found return insert index
    return left;
}

int main(int argc, char *argv[])
{
    int T;
    std::cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        int N, K;
        std::cin >> N >> K;

        std::vector<std::pair<float, float>> inputs;
        for (size_t j = 0; j < N; j++)
        {
            float P;
            std::cin >> P;
            
            int index = binarySearch(inputs, P);
            inputs.insert(inputs.begin() + index, { P, 1 - P });
        }

        float probTot{};
        for (size_t j = 0; j < K; j++)
        {
            auto item = inputs.back();
            inputs.pop_back();

            probTot += item.first;
            item.first *= item.second;

            int index = binarySearch(inputs, item.first);
            inputs.insert(inputs.begin() + index, item);
        }

        probTot = std::floor(probTot * 1e6f) / 1e6f;
        std::cout << std::fixed << std::setprecision(6) << probTot << std::endl;
    }

    return 0;
}
