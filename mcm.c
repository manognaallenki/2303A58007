#include <stdio.h>
void printOrder(int i, int j, int bracket[30][30], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printOrder(i, bracket[i][j], bracket, name);
    printOrder(bracket[i][j] + 1, j, bracket, name);
    printf(")");
}
int main() {
    int n,i,L,j,k;
    int p[30];
    int m[30][30];      
    int bracket[30][30]; 
    int INF = 1000000000; 
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions (p[0] p[1] ... p[n]):\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (L=2;L<=n;L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INF;
            for (k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name='A';
    printf("Optimal Parenthesization: ");
    printOrder(1,n,bracket,&name);
    printf("\nMinimum number of multiplications:%d\n",m[1][n]);
    return 0;
}

