#include "algorithms.h"
#include <vector>
#include <array>

using namespace std;


int brute_force(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()) {
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        return max(brute_force(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1),
                   brute_force(tape, resistance, cur_elem+1, cant_elem));
    }
}

int backtracking_factibilidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()){
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if (resistance < 0) {
            return 0;
        }
        return max(backtracking_factibilidad(tape, resistance, cur_elem+1, cant_elem),
                   backtracking_factibilidad(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
    }
}

int MAX_SOLUTION = 0;

int backtracking_optimalidad(vector<array<int, 2>>& tape, int resistance, int cur_elem, int cant_elem){
    if(cur_elem == tape.size()){
        if (resistance < 0){
            return 0;
        }
        return cant_elem;
    } else {
        if (cur_elem == 0){
            MAX_SOLUTION = 0;
        }
        // Si la resistencia sin agregar el elemento se rompe, entonces este camino no es factible
        if(resistance < 0) {
            return 0;
        }

        MAX_SOLUTION = MAX_SOLUTION > cant_elem ? MAX_SOLUTION : cant_elem;
        // Optimalidad
        if(cant_elem + (tape.size()-cur_elem) <= MAX_SOLUTION){
            // calculo si agregando los elementos hasta el final superaria mi maximo
            // En caso negativo, significa que no encontrare una solucion mejor a la que ya tengo
            return 0;
        }
        return max(backtracking_optimalidad(tape, resistance, cur_elem+1, cant_elem),
                   backtracking_optimalidad(tape, min(resistance-tape[cur_elem][WGH_INDEX], tape[cur_elem][RES_INDEX]), cur_elem+1, cant_elem+1));
    }
}

int dynamic_programming_noFuncional(vector<array<int, 2>>& tape, int resistance){
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

int dynamic_programming(vector<array<int, 2>>& tape, int resistance) {
    pair<int,int> m[tape.size()+1][resistance+1];
    pair<int,int> aux;
    /*for(int i = 0; i < resistance+1; i++) {
        m[0][i] = {0, 0};
    }
    for(int i = 0; i < tape.size()+1; i++) {
        m[i][0] = {0, 0};
    }*/
    for(int elem = 1; elem < tape.size()+1; elem++) {
        for(int res = 1; res < resistance+1; res++) {
            if(tape[elem-1][WGH_INDEX] > res) {
                m[elem][res] = m[elem-1][res];
            } else {
                if (m[elem - 1][res - tape[elem-1][WGH_INDEX]].first == 0) {
                    m[elem][res] = {1, tape[elem-1][RES_INDEX]};
                } else {
                    aux = m[elem - 1][res - tape[elem-1][WGH_INDEX]];
                    if(aux.second >= tape[elem-1][WGH_INDEX]){
                        m[elem][res] = {aux.first + 1, min(aux.second - tape[elem-1][WGH_INDEX], tape[elem-1][RES_INDEX])};
                    } else {
                        m[elem][res] = m[elem-1][res];
                    }
                }
            }
        }
    }

    int max_cant = 0;
    for(int elem = 0; elem < tape.size()+1; elem++){
        max_cant = max(max_cant, m[elem][resistance].first);
    }
    return max_cant;
}