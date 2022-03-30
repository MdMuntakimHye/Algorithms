#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char transition_table[50][10];
    char states[50], alphabets[10], fstates[50], String[100];
    int s, fs, alph, i, j, k;
    char temp_state;

    cout << "Enter the number of states :";
    cin >> s;

    temp_state = states[0];
    cout << "States :";
    for (int i = 0; i < s; i++)
        cin >> states[i];
	for (int i = 0; i < s; i++)
        cout<< states[i]<<" ";

    cout << "Enter the number of final states :";
    cin >> fs;

    cout << "Final States : ";
    for (int i = 0; i < fs; i++)
        cin >> fstates[i];

    cout << "Enter the number of alphabets :";
    cin >> alph;

    cout << "Alphabets :";
    for (int i = 0; i < alph; i++)
        cin >> alphabets[i];

    cout << "Transition table : " << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < alph; j++)
        {
            cin >> transition_table[i][j];
        }
    }
    cout << "Transition table : " << endl;
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < alph; j++)
        {
            // cout<<transition_table[i][j]<< " ";
        }
        cout << endl;
    }

    cout << "Enter the string:";
    cin >> String;
    int current_index = 0;
    cout << "Transition_Search";
    for (int j = 0; String[j]; j++)
    {

        /*for (k = 0; k < alph; k++)
        {
            if (alphabets[k] == String[j]) // k==column
                break;
        }*/
        int k = String[j] - '0';
        for (i = 0; i < s; i++)
        {
            // cout<<states[i]<<" ";

            if (states[i] == transition_table[current_index][k])
            {
                current_index = i;
                break;
            }
        }
        temp_state = states[i];

        cout << " -> " << temp_state;
    }
    cout << endl;
    // Final states..

    for (int i = 0; i < fs; i++)
    {
        if (temp_state == fstates[i])
        {
            cout << "Acceptance" << temp_state << endl;
        }
        else
        {
            cout << "Rejectance";
        }
    }
}
