#include <iostream>
#include <algorithm>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {

            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    int total_profit = 0;
    for (int i = 0; i < n; i++)
        if (slot[i])
        {
            cout << "\nMaximum profit  ";
            cout << arr[result[i]].id << " ";
            cout << arr[result[i]].profit << " ";
            total_profit += arr[result[i]].profit;
        }
    cout << "\nTotal profit = " << total_profit;
}

int main()
{
    Job arr[] = {{'1', 2, 40}, {'2', 1, 100}, {'3', 3, 20}, {'4', 2, 60}, {'5', 1, 20}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum profit sequence of jobs \n";

    printJobScheduling(arr, n);
    return 0;
}