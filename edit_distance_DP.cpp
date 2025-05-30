#include <iostream>
#include <vector>
#include <string>
using namespace std;

int editDistanceDP(const string& S, const string& T) {
    int n = S.length();
    int m = T.length();

    // Crear una matriz (n+1) x (m+1)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Inicializar bordes
    for (int i = 0; i <= n; ++i) dp[i][0] = i; // eliminar todo
    for (int j = 0; j <= m; ++j) dp[0][j] = j; // insertar todo

    // Llenar la tabla
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // sin operación
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // eliminar
                    dp[i][j - 1],     // insertar
                });
            }
        }
    }

    return dp[n][m];
}

//NOTA PARA OPTIMIZAR: La matriz dp[n+1][m+1] ocupa O(n·m) espacio, pero sólo se necesitan la fila actual y la anterior para calcular 
//los valores. Por lo tanto se puede reducir el espacio a O(min(n, m))