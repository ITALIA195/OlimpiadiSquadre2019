#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

int binarySearch(std::vector<std::pair<double, double>> vec, double num)
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

        std::vector<std::pair<double, double>> inputs;
        for (size_t i = 0; i < N; i++)
        {
            double P;
            std::cin >> P;
            
            int index = binarySearch(inputs, P);
            inputs.insert(inputs.begin() + index, { P, 1 - P });
        }
        
        double probTot{};
        for (size_t i = 0; i < K; i++)
        {
            auto item = inputs.back();
            inputs.pop_back();

            probTot += item.first;
            item.first *= item.second;

            int index = binarySearch(inputs, item.first);
            inputs.insert(inputs.begin() + index, item);
        }

        probTot = floor(probTot * 1e6) / 1e6;
        std::cout << std::fixed << std::setprecision(6) << probTot << std::endl;
    }

    return 0;
}
