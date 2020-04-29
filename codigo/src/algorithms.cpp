#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;


int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()){
        bool was_broken = false;
        for(int i = 0; i < res_vect.size(); ++i){
            if(res_vect[i]<0){
                was_broken = true;
            }
        }
//      Hacemos esta molestia de los bools para que se ejecute la ultima iteracion entera y sea mas brute force
        if (resistance < 0 || was_broken){
            return 0;
        } else {
            return res_vect.size();
        }
    } else {
        vector<int> res_vect_sin_elem_actual;
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect_sin_elem_actual.push_back(res_vect[i]);
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        return max(brute_force(tape, resistance, cur_elem+1, res_vect_sin_elem_actual),
                brute_force(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect));
    }
}

int backtracking_factibilidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()){
        for(int i = 0; i < res_vect.size(); ++i){
            if(res_vect[i]<0){ // aca hay que ver si no se rompe el vector res_vect
                return 0;
            }
        }
        return resistance >= 0 ? res_vect.size() : 0;
    } else {
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if(resistance < 0){
            return 0;
        }
        vector<int> res_vect_sin_elem_actual;
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect_sin_elem_actual.push_back(res_vect[i]);
            // Si ya rompi la bolsa agregando el elemento anteriormente agregado podo
            if(res_vect[i] < 0) {
                return 0;
            }
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        return max(backtracking_factibilidad(tape, resistance, cur_elem+1, res_vect_sin_elem_actual),
                backtracking_factibilidad(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect));
    }
}

int MAX_SOLUTION = 0;

int backtracking_optimalidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, vector<int> res_vect){
    if(cur_elem == tape.size()-1){
        for(int i = 0; i < res_vect.size(); ++i){
            if(res_vect[i]<0){ // aca hay que ver si no se rompe el vector res_vect
                return 0;
            }
        }
        return resistance >= 0 ? res_vect.size() : 0;
    } else {
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if(resistance < 0) {
            return 0;
        }

        vector<int> res_vect_sin_elem_actual;
        for(int i = 0; i < res_vect.size(); ++i){
            res_vect_sin_elem_actual.push_back(res_vect[i]);
            // Si ya rompi la bolsa agregando el elemento anteriormente agregado podo
            if(res_vect[i] < 0) {
                return 0;
            }
            res_vect[i]-=tape[cur_elem][WGH_INDEX];
        }

        MAX_SOLUTION = MAX_SOLUTION > res_vect.size() ? MAX_SOLUTION : res_vect.size();
        // Optimalidad
        if(res_vect.size() + (tape.size()-cur_elem) <= MAX_SOLUTION){
            // calculo si agregando los elementos hasta el final superaria mi maximo
            // En caso negativo, significa que no encontrare una solucion mejor a la que ya tengo
            return 0;
        }
        res_vect.push_back(tape[cur_elem][RES_INDEX]);

        return max(backtracking_optimalidad(tape, resistance, cur_elem+1, res_vect_sin_elem_actual),
                backtracking_optimalidad(tape, resistance-tape[cur_elem][WGH_INDEX], cur_elem+1, res_vect));
    }
}

int dynamic_programming(vector<array<int, 2>>& tape, int resistance){
    // Creamos una matriz de NxR donde N es la cantidad de elementos en la cinta
    int m[tape.size()+1][resistance+1];
    // Luego llenamos la primer fila y primer columna con la max resistencia de la cinta
    int max_res=0;
    for(int me=0;me<tape.size();++me){
        if(tape[me][RES_INDEX]>=max_res){
            max_res = tape[me][RES_INDEX]+1;
        }
    }
    for(int i=0; i<=resistance; ++i){
        m[0][i] = max_res;
    }
    for(int j=0; j<=tape.size(); ++j){
        m[j][0] = max_res;
    }

    for(int p=1; p<=tape.size(); ++p){
        for(int r=0; r<=resistance; ++r){
            if(r>=tape[p-1][WGH_INDEX]){ // Si la bolsa actual resiste al elemento actual
                if(m[p-1][r-tape[p-1][WGH_INDEX]] >= tape[p-1][WGH_INDEX]){ // Si la minima resistencia anterior resiste al elemento actual
                    m[p][r] = m[p-1][r-tape[p-1][WGH_INDEX]] <= tape[p-1][RES_INDEX] ? m[p-1][r-tape[p-1][WGH_INDEX]] - tape[p-1][WGH_INDEX] : tape[p-1][RES_INDEX];
                } else {
                    m[p][r] = m[p-1][r];
                }
            } else {
                m[p][r] = m[p-1][r];
            }
        }
    }

    int p=tape.size()+1,r=resistance+1,elems=0;
    while(r > 0 && p > 0){
        if(m[p][r] == m[p-1][r]){
            --p;
        } else {
            --p;
            r-=tape[p][WGH_INDEX];
            ++elems;
        }
    }

    return elems;
}