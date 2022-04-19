h// C++ program to check if a string is of
// the form a^nb^n.
#include <iostream>

using namespace std;
 
// Returns true str is of the form a^nb^n.

bool isAnBn(string str)
{

    int n = str.length();
 

    // After this loop 'i' has count of a's

    int i;

    for (i = 0; i < n; i++)

        if (str[i] != 'a')

            break;
 

    // Since counts of a's and b's should

    // be equal, a should appear exactly

    // n/2 times

    if (i * 2 != n)

        return false;
 

    // Rest of the characters must be all 'b'

    int j;

    for (j = i; j < n; j++)

        if (str[j] != 'b')

            return false;
 

    return true;
}
 
// Driver code

int main()
{

    string str = "abab";

   

    // Function call

    isAnBn(str) ? cout << "Yes" : cout << "No";

    return 0;
}
