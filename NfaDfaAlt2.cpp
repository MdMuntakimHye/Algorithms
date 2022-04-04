#include<bits/stdc++.h>
#define N 100

using namespace std;

int linear_search(string array1[], string searchState, int s, int e);

int main()
{
    string  str, str1, check, nfa[N][N]={}, dfa[N][N]={}, dfa_states[N]={}, nfa_states[N]={};
    int end_states, states, alphabets;
    char ALPHABETS[N]={}, END_STATES[N]={};

    freopen("nfa-dfa.txt", "r", stdin);
    cin>>states;

    cin>>alphabets;
    for(int i=1; i<=alphabets; i++) cin>>ALPHABETS[i];

    cin>>end_states;
    for(int i=1; i <= end_states; i++) cin>>END_STATES[i];

    for(int i=1; i<=states; i++){
        cin>>nfa_states[i];
        for(int j=1; j<= alphabets; j++) cin>>nfa[i][j];
    }
    dfa_states[1] = nfa_states[1];


//    Printing the nfa
    cout<<"NFA states: ";
    for(int i=1; i<=states; i++){
        cout<<nfa_states[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"Alphabets(NFA): ";
    for(int i=1; i<=alphabets; i++) cout<<ALPHABETS[i]<<" ";
    cout<<endl;
    cout<<endl;

    cout<<"End states(NFA): ";
    for(int i=1; i<=end_states; i++) cout<<END_STATES[i]<<" ";
    cout<<endl;
    cout<<endl;

    cout<<"NFA Table: "<<endl;
    for(int i=1; i<=states; i++){
        for(int j=1; j<=alphabets; j++) cout<<nfa[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;

    int k = states+1;

    int dfaStates = 1, index;

//    Making dfa table
    for(int i=1; i<=dfaStates; i++){
        str = dfa_states[i];
        for(int j=1;j<=alphabets;j++){
            string union_states;
            for( k=0;k<str.length();k++){
                str1 = str[k];
                index = linear_search(nfa_states, str1, 1, states);

//                Removing 0 states
                if(nfa[index][j] != "0") union_states = union_states + nfa[index][j];
            }

//            Taking union states & removing duplicate values
            union_states.erase( unique( union_states.begin(), union_states.end() ), union_states.end());

            dfa[i][j]=union_states;
            if(linear_search(dfa_states, dfa[i][j], 1, dfaStates)<0) dfa_states[dfaStates+1]=dfa[i][j], dfaStates++;
        }
    }

//    Placing 0 in null cell
    for(int i=1; i<=dfaStates; i++){
        if(dfa_states[i]=="") dfa_states[i]="0";
    }

    for(int i=1; i<=dfaStates; i++){
        for(int j=1; j<=alphabets; j++){
            if(dfa[i][j]=="") dfa[i][j]="0";
        }
    }

//    Printing dfa
    cout<<"DFA table: "<<endl;
    for(int i=1; i<=dfaStates; i++){
        cout<<dfa_states[i]<<"-> ";
        for(int j=1; j<=alphabets; j++){
            cout<<dfa[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

//    Searching & Printing accepting states
    int flag=0;

    cout<<"Accepting states(DFA): ";
    for(int i=1; i <= dfaStates; i++){
        flag=0;
        str= dfa_states[i];
        for(int j=1; j<=end_states; j++){
            for(k=0; k<str.length(); k++){
                if(str[k]==END_STATES[j]){
                    flag= 1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==1) cout<<dfa_states[i]<<" ";
    }
}

int linear_search(string array1[], string searchState, int s, int e)
{
    for(int i=s; i<=e; i++){
        if(array1[i]==searchState) return i;
    }
    return -1;
}
