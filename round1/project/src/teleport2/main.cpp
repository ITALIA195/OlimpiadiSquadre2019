#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

typedef struct {
    float x;
    float y;
} Point;

float dist(Point A, Point B) 
{
    const float diffX = A.x - B.x;
    const float diffY = A.y - B.y;
    return std::sqrt(diffX * diffX + diffY * diffY);
}

int main(int argc, char *argv[])
{
    int T;
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        float x, y, R;

        std::cin >> x >> y;
        Point A{ x, y };

        std::cin >> x >> y;
        Point B{ x, y };

        std::cin >> x >> y;
        Point C{ x, y };

        std::cin >> R;

        float AB = dist(A, B);
        float AC = dist(A, C);
        float BC = dist(B, C);

        float bed = AC + BC;
        if (AC > R) bed -= R;
        if (BC > R) bed -= R;

        float result = std::min(AB, bed);

        result = std::floor(result * 1e6f) / 1e6f;
        std::cout << std::fixed << std::setprecision(6) << result << std::endl;
    }
    return 0;
}
