#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

typedef struct {
    double x;
    double y;
} Point;

double dist(Point A, Point B) 
{
    const double diffX = A.x - B.x;
    const double diffY = A.y - B.y;
    return std::sqrt(diffX * diffX + diffY * diffY);
}

int main(int argc, char *argv[])
{
    int T;
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        double x, y, R;

        std::cin >> x >> y;
        Point A{ x, y };

        std::cin >> x >> y;
        Point B{ x, y };

        std::cin >> x >> y;
        Point C{ x, y };

        std::cin >> R;

        double AB = dist(A, B);
        double AC = dist(A, C) - R;
        double BC = dist(B, C) - R;

        if (AC < 0) AC = 0;
        if (BC < 0) BC = 0;

        double bed = AC + BC;
        double result = std::min(AB, bed);

        result = std::floor(result * 1e6) / 1e6;
        std::cout << std::fixed << std::setprecision(6) << result << std::endl;
    }
    return 0;
}
