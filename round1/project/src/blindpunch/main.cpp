#include <iostream>
#include <cmath>
#include <set>
#include <iomanip>

int main(int argc, char *argv[])
{
    int T;
    std::cin >> T;
    while (T--)
    {
        int N, K;
        std::cin >> N >> K;

        std::multiset<std::pair<double, double>, std::greater<std::pair<double, double>>> values;
        while (N--)
        {
            double P;
            std::cin >> P;
            
            values.emplace(P, 1 - P);
        }
        
        double probTot{};
        while (K--)
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
