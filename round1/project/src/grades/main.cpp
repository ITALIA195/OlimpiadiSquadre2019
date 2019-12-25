#include <iostream>

int main(int argc, char *argv[])
{
    int firstInsufficient{ -1 };
    int lastSufficient{ -1 };

    int N;
    std::cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int G;
        std::cin >> G;

        if (firstInsufficient < 0 && G < 6)
            firstInsufficient = i;
        else if (G >= 6)
            lastSufficient = i;
    }

    int result{ -1 };
    if (firstInsufficient != -1 && lastSufficient != -1 && firstInsufficient <= lastSufficient)
        result = lastSufficient - firstInsufficient + 1;
    std::cout << result;
    return 0;
}
