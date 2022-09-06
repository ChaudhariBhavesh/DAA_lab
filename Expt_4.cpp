#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value, weight;
};
bool cmp_weight(struct Item a, struct Item b)
{
    double r1 = (double)a.weight;
    double r2 = (double)b.weight;
    return r1 < r2;
}
bool cmp_value(struct Item a, struct Item b)
{
    double r1 = (double)a.value;
    double r2 = (double)b.value;
    return r1 > r2;
}
double fractionalKnapsack_weight(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp_weight);

    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}
double fractionalKnapsack_value(int W, struct Item arr[], int n)
{

    sort(arr, arr + n, cmp_value);

    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}
bool cmp_ratio(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack_ratio(int W, struct Item arr[], int n)
{

    sort(arr, arr + n, cmp_ratio);

    double finalvalue = 0.0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main()
{

    int W;
    int n;
    cout << "\n\nEnter the maximum Weight of knapsack " << endl;
    cout << "Enter : ";
    cin >> W;
    cout << "Enter the number of items " << endl;
    cin >> n;
    Item j[n];
    cout << "Enter the items details " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the item weight " << endl;
        cin >> j[i].weight;
        system("cls");
        cout
            << "Enter the item value " << endl;
        cin >> j[i].value;
    }
    cout << "Maximum value we can obtain by sortinging value = "
         << fractionalKnapsack_value(W, j, n) << endl;
    cout << "Maximum value we can obtain by sortinging weight = "
         << fractionalKnapsack_weight(W, j, n) << endl;
    cout << "Maximum value we can obtain by sorting by ratios = "
         << fractionalKnapsack_ratio(W, j, n) << endl;
    return 0;
}