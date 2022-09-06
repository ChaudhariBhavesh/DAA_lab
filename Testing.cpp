#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

void MergeY(vector<pair<double, double>> &arr, int low, int mid, int high)
{
    vector<pair<double, double>> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i].second < arr[j].second)
        {
            temp.push_back(arr[i++]);
        }
        else if (arr[i].second == arr[j].second && arr[i].first < arr[j].first)
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= high)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSortY(vector<pair<double, double>> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSortY(arr, low, mid);
        MergeSortY(arr, mid + 1, high);
        MergeY(arr, low, mid, high);
    }
}

void MergeX(vector<pair<double, double>> &arr, int low, int mid, int high)
{
    vector<pair<double, double>> temp;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i].first < arr[j].first)
        {
            temp.push_back(arr[i++]);
        }
        else if (arr[i].first == arr[j].first && arr[i].second < arr[j].second)
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= high)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void MergeSortX(vector<pair<double, double>> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSortX(arr, low, mid);
        MergeSortX(arr, mid + 1, high);
        MergeX(arr, low, mid, high);
    }
}

double find_distance(pair<double, double> p1, pair<double, double> p2, pair<double, double> &min1, pair<double, double> &min2)
{
    if (sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)) < sqrt((min1.first - min2.first) * (min1.first - min2.first) + (min1.second - min2.second) * (min1.second - min2.second)))
    {
        min1 = p1;
        min2 = p2;
    }
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double find_smallest_distance(vector<pair<double, double>> sorted_x, vector<pair<double, double>> sorted_y, pair<double, double> &min1, pair<double, double> &min2)
{

    int n = sorted_x.size();

    if (n <= 1)
    {
        return DBL_MAX;
    }

    pair<double, double> p1, p2, p3, p4 = {DBL_MAX, DBL_MAX};
    vector<pair<double, double>> left_x;
    vector<pair<double, double>> right_x;

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            left_x.push_back(sorted_x[i]);
        }
        else
        {
            right_x.push_back(sorted_y[i]);
        }
    }
    int middle = left_x.back().first;
    vector<pair<double, double>> left_y, right_y;

    for (auto x : sorted_y)
    {
        if (x.first <= middle)
        {
            left_y.push_back(x);
        }
        else
        {
            right_y.push_back(x);
        }
    }

    double d1 = find_smallest_distance(left_x, left_y, p1, p2);
    double d2 = find_smallest_distance(right_x, right_y, p3, p4);

    if (d1 < d2)
    {
        min1 = p1;
        min2 = p2;
    }
    else
    {
        min1 = p3;
        min2 = p4;
    }

    double d = min(d1, d2);

    vector<pair<double, double>> band;

    for (auto x : sorted_y)
    {
        if (x.first > middle - d)
            band.push_back(x);
    }

    for (int i = 0; i < band.size(); i++)
    {
        for (int j = i + 1; j < band.size() && band[j].second < band[i].second + d; j++)
        {
            if (find_distance(band[i], band[j], p1, p2) < d)
            {
                min1 = band[i];
                min2 = band[j];
                d = find_distance(band[i], band[j], p1, p2);
            }
        }
    }

    return d;
}

int main()
{
    int n;
    vector<pair<double, double>> vec;
    cout << "How many points are there on the 2D plane?  : ";
    cin >> n;
    if (n <= 1)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cout << "Enter the coordinates of Point " << i << endl;
        cout << "x" << i << ": ";
        cin >> x;
        cout << "y" << i << ": ";
        cin >> y;
        vec.push_back({x, y});
    }
    cout << endl;
    MergeSortX(vec, 0, vec.size() - 1);
    vector<pair<double, double>> sorted_x = vec;

    MergeSortY(vec, 0, vec.size() - 1);
    vector<pair<double, double>> sorted_y = vec;

    pair<double, double> min1 = {DBL_MAX, DBL_MAX};
    pair<double, double> min2 = {DBL_MAX, DBL_MAX};

    double x = find_smallest_distance(sorted_x, sorted_y, min1, min2);

    cout << "The closest pair of points are (" << min1.first << "," << min1.second << ") "
         << "and "
         << "(" << min2.first << "," << min2.second << ") " << endl;
    cout << "The distance between them is " << x << " units" << endl;
    return 0;
}