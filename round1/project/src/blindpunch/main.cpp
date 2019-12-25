#include <iostream>
#include <cmath>
#include <set>
#include <iomanip>

int main(int argc, char *argv[])
{
    int T;
    std::cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        int N, K;
        std::cin >> N >> K;

        std::multiset<std::pair<double, double>, std::greater<std::pair<double, double>>> values;
        for (size_t i = 0; i < N; i++)
        {
            double P;
            std::cin >> P;
            
            values.emplace(P, 1 - P);
        }
        
        double probTot{};
        for (size_t i = 0; i < K; i++)
        {
            auto it = values.begin();
            auto item = *it;

            probTot += item.first;
            item.first *= item.second;

            values.erase(it);
            values.emplace(item);
        }

        probTot = floor(probTot * 1e6) / 1e6;
        std::cout << std::fixed << std::setprecision(6) << probTot << std::endl;
    }

    return 0;
}
