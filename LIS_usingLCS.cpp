#include <bits/stdc++.h>
using namespace std;
 
//function to return size of array without duplicates
int removeDuplicates(vector<int> &arr)
{
    int k = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[k]) {
            arr[++k] = arr[i];
        }
    }
    return k + 1;
}
// Function to return the size of the
// longest increasing subsequence
int LISusingLCS(vector<int>& seq)
{
    int n = seq.size();
 
    // Create an 2D array of integer
    // for tabulation
    vector<vector<int> > L(n + 1, vector<int>(n + 1));
 
    // Take the second sequence as the sorted
    // sequence of the given sequence
    vector<int> sortedseq(seq);
 
    sort(sortedseq.begin(), sortedseq.end());
    //remove duplicates
      int m = removeDuplicates(sortedseq)
    // Classical Dynamic Programming algorithm
    // for Longest Common Subsequence
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (seq[i - 1] == sortedseq[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
 
    // Return the ans
    return L[n][m];
}
 
// Driver code
int main()
{
 
    vector<int> sequence{ 12, 34, 1, 5, 40, 80 };
 
    cout << LISusingLCS(sequence) << endl;
 
    return 0;
}
