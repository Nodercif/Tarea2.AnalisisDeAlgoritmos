#include "edit_distance_memo.h"

using namespace std;

int editDistanceMemo(const string& S, const string& T, int i, int j, vector <vector<int>>& memo){

    //Si ya se calculo, lo devolvemos
    if(memo[i][j] != -1){
        return memo[i][j];
    }

    //Caso base
    if(i == 0){
        return memo[i][j] = j;
    }
    if(j == 0){
        return memo[i][j] = i;
    }

    //Si los caracteres finales coinciden continuamos
    if(S[i-1] == T[j-1]){
        return memo[i][j] = editDistanceMemo(S,T,i-1,j-1,memo);
    }

    //Si no coinciden probamos borrando e insertando
    return memo[i][j] = 1 + min(
        editDistanceMemo(S,T,i-1,j,memo),   //Borrar
        editDistanceMemo(S,T,i,j-1,memo)    //insertar
    );
}

int editDistanceMemo(const string& S, const string& T){

    int n = S.length(), m = T.length();

    //Tabla de memoria con -1 de valor inicial
    vector<vector<int>> memo(n+1, vector<int>(m+1,-1));

    return editDistanceMemo(S,T,n,m,memo);

}