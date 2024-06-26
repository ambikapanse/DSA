//https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if (n > m)
        {
            swap(arr1, arr2);
        }

        int n1 = n;
        int n2 = m;
        int s = max(0, k - n2), e = min(k, n1);
        int left = k;

        while (s <= e)
        {
            int mid1 = s + (e - s) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
            {
                r1 = arr1[mid1];
            }
            if (mid2 < n2)
            {
                r2 = arr2[mid2];
            }
            if (mid1 - 1 >= 0)
            {
                l1 = arr1[mid1 - 1];
            }
            if (mid2 - 1 >= 0)
            {
                l2 = arr2[mid2 - 1];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                return max(l1, l2);
            }
            else if (l1 > r2)
            {
                e = mid1 - 1;
            }
            else
            {
                s = mid1 + 1;
            }
        }
        return 0;
    }
};