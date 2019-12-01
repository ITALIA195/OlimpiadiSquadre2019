#include <iostream>
#include <assert.h>
#include <math.h>
#include <algorithm>

typedef struct {
    float x;
    float y;
} Point;

float dist(Point A, Point B) 
{
    const float diffX = A.x - B.x;
    const float diffY = A.y - B.y;
    return sqrt(diffX * diffX + diffY * diffY);
}

int main(int argc, char *argv[])
{
    int T;
    assert(1 == scanf("%u", &T));
    for (size_t i = 0; i < T; i++)
    {
        float x1, y1, x2, y2, x3, y3, R;
        assert(7 == scanf("%f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &R));

        Point A{ x1, y1 };
        Point B{ x2, y2 };
        Point C{ x3, y3 };

        float AB = dist(A, B);
        float AC = dist(A, C);
        float BC = dist(B, C);

        float bed = AC + BC;
        if (AC > R) bed -= R;
        if (BC > R) bed -= R;

        float result = std::min(AB, bed);
        result = floor(result * 1000000) / 1000000;
        printf("%.6f", result);
    }
    return 0;
}
