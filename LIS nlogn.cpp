#include<iostream>
#include<vector>
using namespace std;
int GetPosition(int arr[], vector<int>& T, int left, int right,int key)
{
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (arr[T[mid]] >= key)
            right = mid;
        else
            left = mid;
    }
    return right;
}
int LongestIncreasingSubsequence(int arr[], int n)
{
    vector<int> lastIndexes(n, 0);
    vector<int> firstIndexes(n, -1);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[lastIndexes[0]])
        {
            lastIndexes[0] = i;
        }
        else if (arr[i] > arr[lastIndexes[len - 1]])
        {
            firstIndexes[i] = lastIndexes[len - 1];
            lastIndexes[len++] = i;
        }
        else
        {
            int positon = GetPosition(arr, lastIndexes, -1, len - 1, arr[i]);
            firstIndexes[i] = lastIndexes[positon - 1];
            lastIndexes[positon] = i;
        }
    }
    cout << "Longest Increase Subsequence:" << endl;
    for (int i = lastIndexes[len - 1]; i >= 0; i = firstIndexes[i])
        cout << arr[i] << " ";
    cout << endl;
    cout<<"LIS size:\n";
    return len;
}
int main()
{
    int arr[] = { 1, 4, 7, 2, 9, 6, 12, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< LongestIncreasingSubsequence(arr, n);
    return 0;
}
