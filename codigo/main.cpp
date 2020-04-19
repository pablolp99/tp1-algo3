#include <bits/stdc++.h>
//#include <iostream>
#include "src/algorithms.h"

using namespace std;

int test(int **param){
    return param[0][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int elem_count, max_weight;
    cin >> elem_count >> max_weight;
    int tape[elem_count][2];

    for(int i = 0; i < elem_count; ++i){
        cin >> tape[i][0] >> tape[i][1];
    }

    cout << test(tape) << endl;

    return 0;
}