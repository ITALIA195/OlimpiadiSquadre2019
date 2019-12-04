#include <iostream>
#include <vector>

constexpr auto MAXN = 100000000;
constexpr auto MAX_BASE2 = 16384;
constexpr auto MAX_BASE3 = 19683;

std::vector<int> base2(MAX_BASE2 + 1);
std::vector<int> base3(MAX_BASE3 + 1);  

int main(int argc, char *argv[])
{
    for (size_t i = 1; i <= MAX_BASE2; i++)
        base2[i] = base2[i / 2] + i % 2;

    for (size_t i = 1; i <= MAX_BASE3; i++)
        base3[i] = base3[i / 3] + i % 3;

    uint32_t T;
    std::cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        uint32_t N;
        std::cin >> N;

        uint32_t count{};
        for (int i = 1; i <= N; i++)
        {
            int bits2 = base2[i / MAX_BASE2] + base2[i % MAX_BASE2];
            int bits3 = base3[i / MAX_BASE3] + base3[i % MAX_BASE3];
            if (bits2 == bits3)
                ++count;
        }

        std::cout << count << ' ';
    }

    return 0;
}
