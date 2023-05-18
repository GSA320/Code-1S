#include <stdio.h>

typedef struct jogador
{
    char nPlayer[10], sPlayer;
} jogador;

char matriz[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int end,i,j,n,a,b,ver,da0,da1,ca0,ca1,db0,db1,cb0,cb1;

int main(){

    jogador player[2];

    do{
        printf("Jogador 1: ");
        fflush(stdin);
        gets(player[0].nPlayer);
        printf("Digite o simbolo: ");
        fflush(stdin);
        scanf("%c", &player[0].sPlayer);
            if(player[0].sPlayer == 'x'){
                player[0].sPlayer ='X';
                player[1].sPlayer ='O';
            }else if(player[0].sPlayer == 'o'){
                player[1].sPlayer ='X';
                player[0].sPlayer ='O';
            }
    } while(player[0].sPlayer !='X' && player[0].sPlayer !='O');
        printf("Jogador 2: ");
        fflush(stdin);
        gets(player[1].nPlayer);

    /*for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("|%d,%d| ", i, j);
        }
        printf("\n");
    };
*/
printf("\n");
n=0;
ver=0;
//gameloop begin

 printf("\n   1   2   3\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j==0){printf("%d ", i+1);}
            printf("[%c] ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

do{
    if(n % 2 == 0){
        do{
            printf("%s(%c),\nDigite a posicao:\n", player[0].nPlayer,player[0].sPlayer);
            scanf("%d",&a);
            scanf("%d",&b);
            a=a-1;
            b=b-1;
            if(matriz[a][b]!=player[1].sPlayer){matriz[a][b]=player[0].sPlayer;}else{n=n-1;}
        }while (matriz[a][b]== ' ');
    }else{
        do{
            printf("%s(%c),\nDigite a posicao:\n", player[1].nPlayer,player[1].sPlayer);
            scanf("%d",&a);
            scanf("%d",&b);
            a=a-1;
            b=b-1;
            if(matriz[a][b]!=player[0].sPlayer){matriz[a][b]=player[1].sPlayer;}else{n=n-1;}
        } while (matriz[a][b]== ' ');
    }

//matriz begin
    printf("\n   1   2   3\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j==0){printf("%d ", i+1);}
            printf("[%c] ",matriz[i][j]);
            /*
            if(i==j && matriz[i][j]==player[0].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                da0=da0+1;
            } if(i==j && matriz[i][j]==player[1].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                da1=da1+1;
            }if(i+j==3 && matriz[i][j]==player[0].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                db0=db0+1;
            } if(i+j==3 && matriz[i][j]==player[1].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                db1=db1+1;
            } if(i==0||i==1||i==2 && matriz[i][j]==player[0].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                ca0=ca0+1;
            } if(i==0||i==1||i==2 && matriz[i][j]==player[1].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                ca1=ca1+1;
            } if(j==0||j==1||j==2 && matriz[i][j]==player[0].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                cb0=cb0+1;
            } if(j==0||j==1||j==2 && matriz[i][j]==player[1].sPlayer){
                if(matriz[i][j]=='X' && player[0].sPlayer=='X'){matriz[i][j]='x';}else{matriz[i][j]='o';}
                cb1=cb1+1;
            }
            */
        }
        printf("\n");
    }
    printf("\n");
//matriz end
/*
printf("da0--%d--", da0);
printf("da1--%d--", da1);
printf("db0--%d--", db0);
printf("db1--%d--", db1);
printf("ca0--%d--", ca0);
printf("ca1--%d--", ca1);
printf("cb0--%d--", cb0);
printf("cb1--%d--", ca1);
*/

 if(player[0].sPlayer == matriz[0][0] && player[0].sPlayer == matriz[0][1] && player[0].sPlayer == matriz[0][2]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[0].sPlayer == matriz[1][0] && player[0].sPlayer == matriz[1][1] && player[0].sPlayer == matriz[1][2]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[0].sPlayer == matriz[2][0] && player[0].sPlayer == matriz[2][1] && player[0].sPlayer == matriz[2][2]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][0] && player[1].sPlayer == matriz[0][1] && player[1].sPlayer == matriz[0][2]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[1][0] && player[1].sPlayer == matriz[1][1] && player[1].sPlayer == matriz[1][2]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[2][0] && player[1].sPlayer == matriz[2][1] && player[1].sPlayer == matriz[2][2]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}

 if(player[0].sPlayer == matriz[0][0] && player[0].sPlayer == matriz[1][0] && player[0].sPlayer == matriz[2][0]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[0].sPlayer == matriz[0][1] && player[0].sPlayer == matriz[1][1] && player[0].sPlayer == matriz[2][1]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[0].sPlayer == matriz[0][2] && player[0].sPlayer == matriz[1][2] && player[0].sPlayer == matriz[2][2]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][0] && player[1].sPlayer == matriz[1][0] && player[1].sPlayer == matriz[2][0]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][1] && player[1].sPlayer == matriz[1][1] && player[1].sPlayer == matriz[2][1]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][2] && player[1].sPlayer == matriz[1][2] && player[1].sPlayer == matriz[2][2]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}

 if(player[0].sPlayer == matriz[0][0] && player[0].sPlayer == matriz[1][1] && player[0].sPlayer == matriz[2][2]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[0].sPlayer == matriz[0][2] && player[0].sPlayer == matriz[1][1] && player[0].sPlayer == matriz[2][0]){printf("%s venceu\n", player[0].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][0] && player[1].sPlayer == matriz[1][1] && player[1].sPlayer == matriz[2][2]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}
 if(player[1].sPlayer == matriz[0][2] && player[1].sPlayer == matriz[1][1] && player[1].sPlayer == matriz[2][0]){printf("%s venceu\n", player[1].nPlayer);end=end+1;}

if(n>6){printf("Empate\n");end=end+1;}

/*
printf("%d", ca0);
printf("%d", ca1);
printf("%d", cb0);
printf("%d\n", cb1);
*/

n++;
if(da0==3||db0==3||ca0==3||cb0==3){
    printf("\n%s venceu\n", player[0].nPlayer);
    end=end+1;
}else if(da1==3||db1==3||ca1==3||cb1==3){
    printf("\n%s venceu\n",player[1].nPlayer);
    end=end+1;
}
//scanf("%d", &end);//control
} while (end==0);
//gamelopp end

printf("stop");
return 0;
}