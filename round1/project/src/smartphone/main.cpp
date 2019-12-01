#include <iostream>
#include <assert.h>

int main(int argc, char *argv[])
{
    int currentCost{};
    int totalCost{};

    int N;
    assert(1 == scanf("%d", &N));
    for (size_t i = 0; i < N; i++)
    {
        int P;
        assert(1 == scanf("%d", &P));
        
        if (currentCost < P)
        {
            totalCost += P;
            currentCost = P;
        }
    }

    printf("%d", totalCost);
    return 0;
}
