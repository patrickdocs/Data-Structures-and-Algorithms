#include <stdio.h>

// Structure is a data type can store different data-type variables
typedef struct Point
{
    int x, y;
} Point;

typedef struct Circle
{
    Point center; // Circle has a field as Point type
    double radius;
} Circle;

int main()
{
    Point p1;
    p1.x = 10;
    p1.y = 20;

    printf("%d %d\n", p1.x, p1.y);

    Circle c1;
    c1.center = p1;
    c1.radius = 5.5;

    double circumfence = 2 * 3.14 * c1.radius;
    double area = 3.14 * c1.radius * c1.radius;
    printf("%.2f\n", circumfence);
    printf("%.2f\n", area);
}
