#include <iostream>
#include <assert.h>

int main(int argc, char *argv[])
{
    int N, M;
    assert(2 == scanf("%d %d", &N, &M));
    for (int K = 0; K < M; K++)
    {
        int a, b, z;
        assert(3 == scanf("%d %d %d", &a, &b, &z));

        if (a - b != z)
        {
            printf("%d", K);
            return 0;
        }
    }

    printf("%d", M);
    return 0;
}
