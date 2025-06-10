#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int editDistanceDP(const std::string& S, const std::string& T) {
    int m = S.length();
    int n = T.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));  // creamos la tabla DP

    // Caso base: convertir S[0..i-1] a cadena vacía requiere i eliminaciones
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;

    // Caso base: convertir cadena vacía a T[0..j-1] requiere j inserciones
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Rellenar tabla DP
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Si los caracteres son iguales, no hacemos ninguna operación
            } else {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;  // definimos como dp[i][j] como el mínimo entre eliminar S[i-1] o insertar T[j-1] (+1)
            }
        }
    }

    return dp[m][n];  // entrega la tabla de número de operaciones necesarias para convertir S en T
}
