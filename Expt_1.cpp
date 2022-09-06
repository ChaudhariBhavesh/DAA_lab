#include <iostream>
using namespace std;
int count1 = 0;
int count2 = 0;
void merge(int arr[], int l, int mid, int r)
{
   int n1 = mid - l + 1;
   int n2 = r - mid;
   int a[n1];
   int b[n2];

   for (int i = 0; i < n1; i++)
   {
      count1++;
      a[i] = arr[l + i];
   }
   for (int i = 0; i < n2; i++)
   {
      count2++;
      b[i] = arr[mid + 1 + i];
   }

   int i = 0;
   int j = 0;
   int k = l;

   while (i < n1 && j < n2)
   {

      if (a[i] < b[j])
      {
         arr[k] = a[i];
         k++;
         i++;
      }
      else
      {
         arr[k] = b[j];
         k++;
         j++;
      }
   }

   while (i < n1)
   {
      arr[k] = a[i];
      k++;
      i++;
   }
   while (j < n2)
   {
      arr[k] = b[j];
      k++;
      j++;
   }
}

void mergeSort(int arr[], int l, int r)
{

   if (l < r)
   {
      int mid = (l + r) / 2;
      mergeSort(arr, l, mid);
      mergeSort(arr, mid + 1, r);
      merge(arr, l, mid, r);
   }
}

int main()
{
   int n;
   cout << "\nNumber of elements : ";
   cin >> n;

   int arr[n];
   cout << "\nEnter " << n << " elements : ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   mergeSort(arr, 0, n - 1);
   cout << "\nSorted array : ";
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << "\t";
   }
   cout << endl;

   cout << "\nComplexity of the merge sort : " << (count1 + count2) << endl
        << "\n\n";

   return 0;
}
