#include <stdio.h>
int main(){
    int a[3][3],b[3][3],c[3][3],i,j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("[%d,%d]",i,j);
        }
        printf("\n");
    }

    printf("\nMatriz A\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Digite o valor [%d][%d]: ",i,j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatriz B\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("Digite o valor [%d][%d]: ",i,j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatriz C\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            c[i][j] = a[i][j]*b[i][j];
            printf("[%d] ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}