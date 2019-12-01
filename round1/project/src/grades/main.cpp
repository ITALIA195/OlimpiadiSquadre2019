#include <iostream>
#include <assert.h>

int main(int argc, char *argv[])
{
    int firstInsufficient = -1;
    int lastSufficient = -1;

    int N;
    assert(1 == scanf("%d", &N));
    for (size_t i = 0; i < N; i++)
    {
        int G;
        assert(1 == scanf("%d", &G));

        if (firstInsufficient < 0 && G < 6)
            firstInsufficient = i;
        else if (G >= 6)
            lastSufficient = i;
    }

    int result = -1;
    if (firstInsufficient != -1 && lastSufficient != -1 && firstInsufficient <= lastSufficient)
        result = lastSufficient - firstInsufficient + 1;
    printf("%d", result);
    return 0;
}
