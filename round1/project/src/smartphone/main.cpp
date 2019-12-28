#include <iostream>

int main(int argc, char *argv[])
{
    int currentCost{};
    uint64_t totalCost{};

    int N;
    std::cin >> N;
    while (N--)
    {
        int P;
        std::cin >> P;
        
        if (currentCost < P)
        {
            totalCost += P;
            currentCost = P;
        }
    }

    std::cout << totalCost;
    return 0;
}
