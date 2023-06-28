/*
Aluno: Gustavo S.Alves

SISTEMA GERENCIADOR FINANCEIRO: 
Construir um programa em linguagem de programação C que faça o gerenciamento de contas
a pagar e contas a receber de um grupo de pessoas. O sistema deve armazenar as 
contas a receber (Data da entrada, Descrição, Categoria do Provento , Valor Recebido) 
e as contas a Pagar (Data da conta, descrição, Categoria da Despesa e valor a pagar). 
Para cada pessoa devem ser armazenadas as contas a pagar e a receber em uma estrutura 
separada. O programa deve também apresentar um relatório informando a quantidade 
total de contas a pagar e a quantidade total de contas a receber. Deve gerar um 
relatório do Saldo de Contas de cada Pessoa (Contas a Receber – Contas a Pagar). 
Deve também exibir um relatório de gastos por Categoria. Ex: Gastos com Festa, 
Gastos com Estudo, etc. Para acessar o sistema o usuário deve cadastrar um 
usuário e senha. Apenas o usuário com perfil administrador pode cadastrar outros 
usuários. Assim deve ser criada uma estrutura Usuário, que possui Nome, login, 
senha e contas a pagar e a receber associadas a ele.
*/
//--------------------------------estruturas------------------------------------
#include <stdio.h>
#include <string.h>
int x=0;
typedef struct ScontasRec{
    char rdata[10];
    char rdescricao[50];
    char rcategoria[25];
    float rvalor;
    int rindex;
}S_contasRec;

typedef struct ScontasPag{
    char pdata[10];
    char pdescricao[50];
    char pcategoria[25];
    float pvalor;
    int pindex;
}S_contasPag;

typedef struct Scontas{
    S_contasRec rcontas[10];
    S_contasPag pcontas[10];  
}s_contas;

typedef struct Suser{
    s_contas contas;
    char nome[15];
    char login[15];
    char senha[8];
}s_user;

typedef struct Scategory{
    char classe[25];
    int analise;
}s_category;

typedef struct Ssystem{
    s_user session;
    s_user usuario[10];
    s_category catrec[10];
    s_category catpag[10];
}s_system;

//--------------------------------estruturas------------------------------------
void cleanAll(s_system *system);
void login(s_system *system);
void update(s_system *system);
void contasPag(s_system *system);
void contasRec(s_system *system);
void show(s_system system);
void config(s_system *system);
void cadUser(s_system *sys);
void editUser(s_system* sys);
void delUser(s_system* sys);
//--------------------------------------------main----------------------------------

int main(){
    s_system system;
    int opcao = 0;
    cleanAll(&system);
    strcpy(system.usuario[0].login, "adm");
    strcpy(system.usuario[0].senha, "123");
    printf("\n___Bem vindo ao seu gerenciador financeiro___\n\n");
    while(x==0){
            login(&system);
            if(strcmp(system.session.login, "adm") == 0){
            printf("\n---------ABA ADMIN---------");
        do{
        
        printf("\nEscolha uma opcao:\n");
        printf(" - 1 - Informar conta a pagar\n");
        printf(" - 2 - Informar conta a receber\n");
        printf(" - 3 - Imprimir Relatorio\n");
        printf(" - 4 - Fazer logout\n");
        printf(" - 5 - Configurar usuarios\n");
        printf(" - 6 - Sair\n");
        printf(" - ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao){
        case 1:
            contasPag(&system);
            break;
        case 2:
            contasRec(&system);
            break;
        case 3:
            show(system);
            break;
        case 4:
            opcao=6;
            //login(&system);
            break; 
        case 5:
            config(&system);
            break;
        case 6:
            printf("___Programa encerrado___\n");
            x=1;
            break;           
        default:
            printf("Opcao invalida, tente novamente\n");
            break;
        }
    update(&system);
    }while(opcao!=6); 
    }else{
        printf("\n---------ABA USUARIO---------");
        do{
        printf("\nEscolha uma opcao:\n");
        printf(" - 1 - Informar conta a pagar\n");
        printf(" - 2 - Informar conta a receber\n");
        printf(" - 3 - Imprimir Relatorio\n");
        printf(" - 4 - Fazer logout\n");
        printf(" - 5 - Sair\n");
        printf(" - ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao){
        case 1:
            contasPag(&system);
            break;
        case 2:
            contasRec(&system);
            break;
        case 3:
            show(system);
            break;
        case 4:
            opcao = 5;
            break; 
        case 5:
            printf("___Programa encerrado___\n");
            x=1;
            break;       
        default:
            printf("Opcao invalida, tente novamente\n");
            break;
        }
    update(&system);
    }while(opcao!=5); 
    }
    }
    printf("\n");
    return 0;
}
//--------------------------------------------main----------------------------------

//||||||||||||||||||||||||||||||||||funcoes|||||||||||||||||||||||||||||||||||||

void cleanAll(s_system *system){
    strcpy(system->session.login,"");
    strcpy(system->session.nome,"");
    strcpy(system->session.senha,"");
    for(int i=0;i<10;i++){
        system->session.contas.pcontas[i].pindex = 0;
        system->session.contas.pcontas[i].pvalor = 0;
        strcpy(system->session.contas.pcontas[i].pcategoria, "");
        strcpy(system->session.contas.pcontas[i].pdata, "");
        strcpy(system->session.contas.pcontas[i].pdescricao, "");
        system->session.contas.rcontas[i].rindex = 0;
        system->session.contas.rcontas[i].rvalor = 0;
        strcpy(system->session.contas.rcontas[i].rcategoria, "");
        strcpy(system->session.contas.rcontas[i].rdata, "");
        strcpy(system->session.contas.rcontas[i].rdescricao, "");
        for(int j=0;j<10;j++){
            strcpy(system->usuario[j].login,"");
            strcpy(system->usuario[j].nome,"");
            strcpy(system->usuario[j].senha,"");
            system->usuario[j].contas.pcontas[i].pindex = 0;
            system->usuario[j].contas.pcontas[i].pvalor = 0;
            strcpy(system->usuario[j].contas.pcontas[i].pcategoria, "");
            strcpy(system->usuario[j].contas.pcontas[i].pdata, "");
            strcpy(system->usuario[j].contas.pcontas[i].pdescricao, "");
            system->usuario[j].contas.rcontas[i].rindex = 0;
            system->usuario[j].contas.rcontas[i].rvalor = 0;
            strcpy(system->usuario[j].contas.rcontas[i].rcategoria, "");
            strcpy(system->usuario[j].contas.rcontas[i].rdata, "");
            strcpy(system->usuario[j].contas.rcontas[i].rdescricao, "");
        }
    }
    for(int k=0;k<10;k++){
        strcpy(system->catrec[k].classe,"");
        system->catrec[k].analise=0;
        strcpy(system->catpag[k].classe,"");
        system->catpag[k].analise=0;
    }
}

void login(s_system *system){
    int i,ir = 0;
    char keylogin[15], keysenha[8];
    do{
        fflush(stdin);
        printf("Digite seu login: ");
        fgets(keylogin, sizeof(keylogin), stdin);
        keylogin[strcspn(keylogin, "\n")]='\0';
        printf("Digite sua senha: ");
        fgets(keysenha, sizeof(keysenha), stdin);
        keysenha[strcspn(keysenha, "\n")]='\0';
        for(i=0;i<10;i++){
            if(strcmp(keylogin, system->usuario[i].login) == 0 && strcmp(keysenha, system->usuario[i].senha) == 0){
                strcpy(system->session.login, keylogin);
                strcpy(system->session.senha, keysenha);
                system->session=system->usuario[i];
                ir = 1;
            }
        }
        if(ir==0){printf("\nCredenciais invalidas\n\n");}
    } while (ir == 0);
}

void update(s_system *system){
    for(int i=0;i<10;i++){
        if(strcmp(system->usuario[i].login, system->session.login)==0){
            system->usuario[i] = system->session;
        }
    }
}

void contasPag(s_system *system){
    char keydata[10];
    char keydescricao[50];
    char keycategoria[25];
    float keyvalor;
    int a=0;
    fflush(stdin);
    printf("---------Conta a pagar---------\n\n");
    printf("Digite a data da conta: ");
    fgets(keydata, sizeof(keydata), stdin);
    keydata[strcspn(keydata, "\n")]='\0';
    printf("Escreva a descricao: ");
    fgets(keydescricao, sizeof(keydescricao), stdin);
    keydescricao[strcspn(keydescricao, "\n")]='\0';
    printf("Digite a categoria: ");
    fgets(keycategoria, sizeof(keycategoria), stdin);
    keycategoria[strcspn(keycategoria, "\n")]='\0';
    do{
        printf("Digite o valor: ");
        scanf("%f", &keyvalor);
        fflush(stdin);
        if(keyvalor==0){
            printf("_valor invalido_");
        }else{
            a=1;
        }
    }while (a==0);
    for(int i=0;i<10;i++){
        if(system->session.contas.pcontas[i].pvalor == 0){
            strcpy(system->session.contas.pcontas[i].pdata, keydata);
            strcpy(system->session.contas.pcontas[i].pdescricao, keydescricao);
            strcpy(system->session.contas.pcontas[i].pcategoria, keycategoria);
            system->session.contas.pcontas[i].pvalor = keyvalor;
            system->session.contas.pcontas[i].pindex = system->session.contas.pcontas[i].pindex+1;
            for(int j=0;j<10;j++){
                if(strcmp(system->catpag[j].classe, "")==0){
                    strcpy(system->catpag[j].classe, keycategoria);
                    j=20;
                }
            }
            printf("--Conta a pagar n %d adicionada--",i+1);
            i=10;
        }
    }
}

void contasRec(s_system *system){
    char keydata[10];
    char keydescricao[50];
    char keycategoria[25];
    float keyvalor;
    int a=0;
    fflush(stdin);
    printf("---------Conta a receber---------\n\n");
    printf("Digite a data da conta: ");
    fgets(keydata, sizeof(keydata), stdin);
    keydata[strcspn(keydata, "\n")]='\0';
    printf("Escreva a descricao: ");
    fgets(keydescricao, sizeof(keydescricao), stdin);
    keydescricao[strcspn(keydescricao, "\n")]='\0';
    printf("Digite a categoria: ");
    fgets(keycategoria, sizeof(keycategoria), stdin);
    keycategoria[strcspn(keycategoria, "\n")]='\0';
    do{
        printf("Digite o valor: ");
        scanf("%f", &keyvalor);
        fflush(stdin);
        if(keyvalor<=0){
            printf("_valor invalido_\n\n");
        }else{
            a=1;
        }
    }while (a==0);
    for(int i=0;i<10;i++){
        if(system->session.contas.rcontas[i].rvalor == 0){
            strcpy(system->session.contas.rcontas[i].rdata, keydata);
            strcpy(system->session.contas.rcontas[i].rdescricao, keydescricao);
            strcpy(system->session.contas.rcontas[i].rcategoria, keycategoria);
            system->session.contas.rcontas[i].rvalor = keyvalor;
            system->session.contas.rcontas[i].rindex = system->session.contas.rcontas[i].rindex+1;
            printf("Conta a receber n %d adicionada",i+1);
            i=10;
        }
    }
    for(int j=0;j<10;j++){
                if(strcmp(system->catrec[j].classe,keycategoria)==0){
                    system->catrec[j].analise=1;
                    j=10;
                }else if(strcmp(system->catrec[j].classe,"")==0){
                    strcpy(system->catrec[j].classe, keycategoria);
                    system->catrec[j].analise=0;
                    j=10;
                }

            }
}

void show(s_system system){
    float pag=0,rec=0,diff=0;
    int cr=0,cp=0;
    for(int i=0;i<10;i++){
        pag = system.session.contas.pcontas[i].pvalor + pag;
        rec = system.session.contas.rcontas[i].rvalor + rec;
        if(system.session.contas.pcontas[i].pvalor>0){
            cp=cp+1;
        }
        if(system.session.contas.rcontas[i].rvalor>0){
            cr=cr+1;
        }
    }
    diff = rec-pag;
    printf("---------------Relatorio--------------\n\n");
    if(diff>0){
        printf("O saldo e positivo em %f Reais\n", diff);
    }else if(diff<0){
        printf("O saldo e negativo em %f Reais\n", diff);
    }else{
        printf("O saldo e: 0\n");
    }
    printf("\n_____________________________________");
    for(int i=0;i<10;i++){
        if(strcmp(system.session.contas.pcontas[i].pcategoria, "")!=0){
            //while(a==0){
                for(int j=0;j<10;j++){
                    // if(strcmp(system.session.contas.pcontas[i].pcategoria, system.catpag[j].classe)==0){
                      //  if(system.catpag[j].analise==0){
                            printf("\n|Categoria: %s \n", system.session.contas.pcontas[i].pcategoria);
                            printf("|____________________________________\n");
                            strcpy(system.catpag[j].classe, "");
                            system.catpag[j].analise=system.catpag[j].analise+1;
                            j=10;
                        //}
                        //a=1;
                    }
                //}
            //}
            printf("|Data: %s \n", system.session.contas.pcontas[i].pdata);
            printf("|Descricao: %s \n", system.session.contas.pcontas[i].pdescricao);
            printf("|Valor: %f \n", system.session.contas.pcontas[i].pvalor);
        }
    }
    printf("|____________________________________\n");
    printf("|Ha %d contas a pagar\n", cp);
    printf("\n_____________________________________\n");
    for(int i=0;i<10;i++){
        if(strcmp(system.session.contas.rcontas[i].rcategoria, "")!=0){
            for(int j=0;j<10;j++){                
                //if(system.catrec[j].analise==1 /*&& strcmp(system.catrec[j].classe,system.session.contas.rcontas[i].rcategoria)==0*/){     
                    printf("|Categoria: %s\n", system.catrec[j].classe);
                    printf("|____________________________________\n");   
                    //strcpy(system.catrec[j].classe, system.session.contas.rcontas[i].rcategoria);
                    //for(int k=0;k<10;k++){
                      //  if(strcmp(system.catrec[k].classe, system.catrec[j].classe)==0){
                        //    system.catrec[j].analise=1;
                        //}
                    //}
                //}
                    //xd=j;
                    //while(j==0){
                        printf("|Data: %s \n", system.session.contas.rcontas[i].rdata);
                        printf("|Descricao: %s\n", system.session.contas.rcontas[i].rdescricao);
                        printf("|Valor: %f\n", system.session.contas.rcontas[i].rvalor);
                       // if(j==0){j=1;}
                    //}
                    //j=xd;
                    // j=10;

                    /*if(strcmp(system.session.contas.pcontas[i].pcategoria, system.catrec[j].classe)==0){
                        if(system.catrec[j].analise == 0){
                            printf("\n|Categoria: %s \n", system.session.contas.rcontas[i].rcategoria);
                            printf("|____________________________________\n");
                            strcpy(system.catrec[j].classe, "");
                            system.catrec[j].analise = 1;
                            j=10;
                        }
                        //strcpy(system.catSt[j].classe, "");
                        //b=1;
                    }*/j=10;
                }

        }
    }
    printf("|____________________________________\n");
    printf("|Ha %d contas a receber\n", cr);
    printf("\n-------------------------------------");
}

void config(s_system *system){
    int opcao = 0;
    do{
        printf("\nSupremo ADM, oque deseja fazer?\n");
        printf(" [1] - Cadastrar usuario\n");
        printf(" [2] - Editar usuario\n");
        printf(" [3] - Excluir usuario\n");
        printf(" [4] - voltar\n");
        printf(" [");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao){
        case 1:
            cadUser(system);
            break;
        case 2:
            editUser(system);
            break;
        case 3:
            delUser(system);
        case 4:
            break;
        default:
            printf("Opcao invalida, tente novamente\n");
            break;
        }
    }while(opcao != 4);
}

void cadUser(s_system *sys){
    char keynome[15];
    char keylog[15];
    char keysenha[8];
    fflush(stdin);
    printf("---------Cadastro---------\n\n");
    printf("Digite o nome: ");
    fgets(keynome, sizeof(keynome), stdin);
    keynome[strcspn(keynome, "\n")]='\0';
    printf("Digite o login: ");
    fgets(keylog, sizeof(keylog), stdin);
    keylog[strcspn(keylog, "\n")]='\0';
    printf("Digite a senha: ");
    fgets(keysenha, sizeof(keysenha), stdin);
    keysenha[strcspn(keysenha, "\n")]='\0';
    for(int i=0;i<10;i++){
        if(strcmp(sys->usuario[i].login,"")==0){
            strcpy(sys->usuario[i].login, keylog);
            strcpy(sys->usuario[i].senha, keysenha);
            strcpy(sys->usuario[i].nome, keynome);
            //printf("%s", sys->usuario[i].login);
            i=10;
        }else if(strcmp(sys->usuario[i].login,"")!=0 && i==9){
            printf("__Sem espaco para novos usuarios__");
        }
    }
}

void editUser(s_system* sys){
    char keynome[15];
    char keylog[15];
    char keysenha[8];
    char powerkey[15];
    fflush(stdin);
    printf("---------Edicao---------\n\n");
    printf("Digite o login do usuario a ser modificado: ");
    fgets(powerkey, sizeof(powerkey), stdin);
    powerkey[strcspn(powerkey, "\n")]='\0';
    printf("Digite o novo nome: ");
    fgets(keynome, sizeof(keynome), stdin);
    keynome[strcspn(keynome, "\n")]='\0';
    printf("Digite o novo login: ");
    fgets(keylog, sizeof(keylog), stdin);
    keylog[strcspn(keylog, "\n")]='\0';
    printf("Digite a nova senha: ");
    fgets(keysenha, sizeof(keysenha), stdin);
    keysenha[strcspn(keysenha, "\n")]='\0';
    for(int i=0;i<10;i++){
        if(strcmp(sys->usuario[i].login,powerkey )==0){
            if(strcmp(powerkey,"adm")==0){
                printf("__excecao detectada, login inalterado__");
                strcpy(sys->usuario[i].senha, keysenha);
                strcpy(sys->usuario[i].nome, keynome);
            }else{
                strcpy(sys->usuario[i].login, keylog);
                strcpy(sys->usuario[i].senha, keysenha);
                strcpy(sys->usuario[i].nome, keynome);
                //printf("%s", sys->usuario[i].login);
            }
            i=10;
        }else if(strcmp(sys->usuario[i].login,powerkey)!=0 && i==9){
            printf("__Usuario nao encontrado__");
        }
    }
}
void delUser(s_system* sys){
    char keylog[15];
    fflush(stdin);
    printf("---------Exclusao---------\n\n");
    printf("Digite o login do usuario a excluir: ");
    fgets(keylog, sizeof(keylog), stdin);
    keylog[strcspn(keylog, "\n")]='\0';
    for(int i=0;i<10;i++){
        if(strcmp(sys->usuario[i].login, keylog)==0){
            if(strcmp(sys->usuario[i].login,"adm")==0){
                printf("__Acao invalida__");
            }else{
            printf("--User %s has been deleted--", sys->usuario[i].nome);
                for(int j=0;j<10;j++){
                    strcpy(sys->usuario[i].login,"");
                    strcpy(sys->usuario[i].nome,"");
                    strcpy(sys->usuario[i].senha,"");
                    sys->usuario[i].contas.pcontas[j].pindex = 0;
                    sys->usuario[i].contas.pcontas[j].pvalor = 0;
                    strcpy(sys->usuario[i].contas.pcontas[j].pcategoria, "");
                    strcpy(sys->usuario[i].contas.pcontas[j].pdata, "");
                    strcpy(sys->usuario[i].contas.pcontas[j].pdescricao, "");
                    sys->usuario[i].contas.rcontas[j].rindex = 0;
                    sys->usuario[i].contas.rcontas[j].rvalor = 0;
                    strcpy(sys->usuario[i].contas.rcontas[j].rcategoria, "");
                    strcpy(sys->usuario[i].contas.rcontas[j].rdata, "");
                    strcpy(sys->usuario[i].contas.rcontas[j].rdescricao, "");
                }
                i=10;
            }
        }else if(strcmp(sys->usuario[i].login,keylog)!=0 && i==9){
            printf("__Usuario nao encontrado__");
        }
    }
}
//||||||||||||||||||||||||||||||||||funcoes|||||||||||||||||||||||||||||||||||||