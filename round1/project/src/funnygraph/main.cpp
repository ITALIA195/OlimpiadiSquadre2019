#include <iostream>

int main(int argc, char *argv[])
{
    int N, M;
    std::cin >> N >> M;
    for (int K = 0; K < M; K++)
    {
        int a, b, z;
        std::cin >> a >> b >> z;

        if (a - b != z)
        {
            std::cout << K;
            return 0;
        }
    }

    std::cout << M;
    return 0;
}
