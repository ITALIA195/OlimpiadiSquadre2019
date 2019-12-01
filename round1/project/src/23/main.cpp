#include <iostream>
#include <cassert>
#include <vector>

#define MAXN 100000000
#define MAX_BASE2 27 // 2 ** MAX_BASE2 > MAXN
#define MAX_BASE3 17 // 3 ** MAX_BASE3 > MAXN

std::vector<int> base2{ 0 };
std::vector<int> base3{ 0 };

bool isSpecialNumber(int num)
{
    int bits2 = base2[num / MAX_BASE2] + base2[num % MAX_BASE2];
    int bits3 = base3[num / MAX_BASE3] + base3[num % MAX_BASE3];
    return bits2 == bits3;
}

int countSpecialNumbers(int max)
{
    int count{};
    for (int i = 1; i <= max; i++)
        count += isSpecialNumber(i);
    return count;
}

void init()
{
    base2.reserve(MAX_BASE2);
    for (size_t i = 1; i <= MAX_BASE2; i++)
        base2.push_back(base2[i / 2] + i % 2);

    base3.reserve(MAX_BASE3);
    for (size_t i = 1; i < MAX_BASE3; i++)
        base3.push_back(base3[i / 3] + i % 3);
}

int main(int argc, char *argv[])
{
    init();
    int T;
    assert(1 == scanf("%d", &T));
    for (size_t i = 0; i < T; i++)
    {
        int N; 
        assert(1 == scanf("%d", &N));

        printf("%d ", countSpecialNumbers(N));
    }

    return 0;
}
