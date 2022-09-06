#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

struct Point // A structure to represent a Point in 2D plane
{
    int x, y;
};

int compareX(const void *a, const void *b) // Needed to sort array of points according to X coordinate
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) // Needed to sort array of points according to Y coordinate
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2) // function to find the distance between two points
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n) // A method to return the smallest distance between two points
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y) // function to find a minimum of two float values
{
    return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d; // Initialize the minimum distance as d

    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestUtil(Point P[], int n)
{

    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);
    return closestUtil(P, n);
}

int main()
{

    Point P[] = {{4, 5}, {11, 20}, {4, 50}, {50, 1}, {19, 10}, {8, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("\n_____________________________________________________________________________________________________________________________________________\n\n");
    printf("Minimum distance is :  %f \n\n", closest(P, n));
    return 0;
}