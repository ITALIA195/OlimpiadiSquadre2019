#include <iostream>
#include <vector>

constexpr auto CACHE_INTERVAL = 10;
constexpr auto MAXN = 100000000;
constexpr auto MAX_BASE2 = 16384;
constexpr auto MAX_BASE3 = 19683;

int base2[MAX_BASE2 + 1];
int base3[MAX_BASE3 + 1];
uint32_t cache[MAXN / CACHE_INTERVAL];
size_t maxIndex = 0;

int countSpecialNumbers(uint32_t N)
{
    size_t count;
    uint32_t i;
    if (maxIndex > N / CACHE_INTERVAL)
    {
        count = cache[N / CACHE_INTERVAL];
        i = N / CACHE_INTERVAL * CACHE_INTERVAL + 1;
    }
    else
    {
        count = cache[maxIndex];
        i = maxIndex * CACHE_INTERVAL + 1;
    }

    for (; i <= N; i++)
    {
        int bits2 = base2[i / MAX_BASE2] + base2[i % MAX_BASE2];
        int bits3 = base3[i / MAX_BASE3] + base3[i % MAX_BASE3];
        if (bits2 == bits3)
            ++count;

        if (i % CACHE_INTERVAL == 0)
        {
            cache[i / CACHE_INTERVAL] = count;
            maxIndex = i / CACHE_INTERVAL;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    for (size_t i = 1; i <= MAX_BASE2; i++)
        base2[i] = base2[i / 2] + i % 2;

    for (size_t i = 1; i <= MAX_BASE3; i++)
        base3[i] = base3[i / 3] + i % 3;

    uint32_t T;
    std::cin >> T;
    while (T--)
    {
        uint32_t N;
        std::cin >> N;

        std::cout << countSpecialNumbers(N) << ' ';
    }

    return 0;
}
