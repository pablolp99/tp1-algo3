#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;

int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()-1){
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
            return (res_vect[i]<0 && resistance >= 0 ? res_vect.size() : 0);
        }
        return resistance - tape[cur_elem][WGH_INDEX] >= 0 ? res_vect.size() + 1 : 0;
    } else {
        int dont_add_elem = brute_force(tape, resistance, cur_elem+1, res_vect);

        for(int i = 0; i < res_vect.size(); ++i){
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        int add_elem = brute_force(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect);
        return max(add_elem, dont_add_elem);
    }
}