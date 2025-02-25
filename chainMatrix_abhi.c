#include <stdio.h>
#include <limits.h>


void matrixChainOrder(int p[], int n) {
    int m[n][n]; 

    
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    
    for (int l = 2; l < n; l++) { 
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1; 
            m[i][j] = INT_MAX; 

            for (int k = i; k < j; k++) { 
                
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    
    printf("Minimum number of multiplications is %d\n", m[1][n - 1]);
}

int main() {
    
    
    int p[] = {5,4,6,2,7}; 
    int n = sizeof(p) / sizeof(p[0]); 

    matrixChainOrder(p, n); 

    return 0;
}

