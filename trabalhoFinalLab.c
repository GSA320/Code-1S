#include <stdio.h>
#include <string.h>
int x = 0;
/*
SISTEMA DE CONTROLE DE EMPRÉSTIMOS: 
Construir um programa em linguagem de programação C que gerencie o empréstimo 
de Obras de uma pessoa. Uma pessoa tem vários tipos de Obras, como livros, 
CD’s, DVD’s, e outras. Essas obras devem ser cadastradas para posterior empréstimo. 
Além disso uma pessoa tem uma lista de amigos os quais ela pode emprestar as obras. 
Quando a pessoa empresta algo, este deve constar no sistema como emprestado, e 
quando não está emprestado, consta como disponível. Ao realizar o empréstimo, 
deve ser cadastrada a data do empréstimo, devolução prevista e os dados do item 
emprestado. O programa deve gerar um relatório de obras que estão emprestadas, 
quais as obras que tiveram mais empréstimos e também deve possibilitar adicionar 
e remover obras. Para acessar o sistema o usuário deve cadastrar um usuário e senha.
*/

//aluno: Gustavo S.Alves

typedef struct Sobra{
    int uso,condicao;
    char nome[20];
} s_obra;

typedef struct Samigos{
    s_obra obraEmp[10];
    char nome[20];
} s_amigos;

typedef struct Suser{
    char login[10];
    char senha[10];
    s_amigos amigo[2];
    s_obra obra[10];
} s_user;

typedef struct Semprestimo{
    s_obra obraEmp;
    char data[10],dev[10];
    int indicador;
}s_emp;

void inicio(s_emp *pseudoEmp);
void cad(s_user *usuario);
void del(s_user *user, char obj[20]);
void adic(s_emp *emp, s_user *user);
void back(s_emp *emp, s_user *user);
void see(s_emp empre);

int main(){
    char keylogin[10],keysenha[10],item[20],obj[20];
    int opcao = 0, ir=0, obrasDisp=0, validar=0, con=0;
    s_obra topseller;
    s_user user;
    s_emp emprestimo[25];
    s_emp pseudoEmp;
    //obra[x].condicao(0)=disponivel
    //obra[x].condicao(1)=emprestado
    topseller.uso=0;
    strcpy(user.amigo[0].nome,"neymar");
    strcpy(user.amigo[1].nome,"junior");
    for(int i=0;i<10;i++){
        user.amigo[0].obraEmp[i].condicao=0;
        user.amigo[0].obraEmp[i].uso=0;
        strcpy(user.amigo[0].obraEmp[i].nome," ");
        user.amigo[1].obraEmp[i].condicao=0;
        user.amigo[1].obraEmp[i].uso=0;
        strcpy(user.amigo[1].obraEmp[i].nome,"");
    }
    for(int i=0;i<10;i++){
        strcpy(user.obra[i].nome, "");
        user.obra[i].condicao = 0;
        user.obra[i].uso = 0;
        for(int j=0; j<10; j++){
            strcpy(user.amigo[0].obraEmp[j].nome, "");
            user.amigo[0].obraEmp[j].uso = 0;
            user.amigo[0].obraEmp[j].condicao = 0;
            strcpy(user.amigo[1].obraEmp[j].nome, "");
            user.amigo[1].obraEmp[j].uso = 0;
            user.amigo[1].obraEmp[j].condicao = 0;  
        }
    }
    for(int i=0;i<25;i++){
        strcpy(emprestimo[i].obraEmp.nome, "");
        emprestimo[i].obraEmp.condicao = 0;
        emprestimo[i].obraEmp.uso = 0;
        strcpy(emprestimo[i].data, "");
        strcpy(emprestimo[i].dev, "");
        emprestimo[i].indicador = 0;
    }
    inicio(&pseudoEmp);
    printf("----------Bem vindo a Top emprestimos----------\n");
     do{
        printf("Digite seu login: ");
        fgets(keylogin, sizeof(keylogin), stdin);
        keylogin[strcspn(keylogin, "\n")]='\0';
        printf("Digite sua senha: ");
        fgets(keysenha, sizeof(keysenha), stdin);
        keysenha[strcspn(keysenha, "\n")]='\0';
        if(strcmp(keylogin, "adm") == 0 && strcmp(keysenha, "123") == 0){
            ir = 1;
        }else if(ir==0){printf("\n--Credenciais invalidas--\n\n");}
    } while (ir == 0);
    do{
        printf("\nEscolha uma opcao: \n");
        printf(" - 1 - Cadastrar obra\n");
        printf(" - 2 - Deletar obra\n");
        printf(" - 3 - Informar emprestimo\n");
        printf(" - 4 - Retirar emprestimo\n");
        printf(" - 5 - Mostrar relatorio\n");
        printf(" - 6 - Sair\n");
        printf(" - ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao){
        case 1:
            for(int i=0;i<10;i++){
                if(strcmp(user.obra[i].nome,"")==0){
                    i=11;
                    cad(&user);
                }else if(i==9 && strcmp(user.obra[i].nome,"")!=0){
                    printf("--Sem mais lugares no arsenal--");
                }
            }
            break;
        case 2:
            printf("O que sera deletado? ");
            fgets(obj, sizeof(obj), stdin);
            obj[strcspn(obj,"\n")]='\0';
            fflush(stdin);
            for(int i=0;i<25;i++){
                if(strcmp(emprestimo[i].obraEmp.nome,obj)==0){
                printf("--Acao invalida, obra realocada ou nao existe--");
                i=25;
                }else{
                   del(&user, obj); 
                i=25;
                }
            }
            break;
        case 3:
        inicio(&pseudoEmp);
            if(obrasDisp>0){
                printf("___Ha %d obras disponiveis___\n", obrasDisp);
                adic(&pseudoEmp, &user);
                //obrasDisp--;
                for(int i=0;i<25;i++){
                    if(emprestimo[i].obraEmp.condicao==0){
                        emprestimo[i]=pseudoEmp;
                        i=25;
                    }
                }
            }else{printf("--Nao ha obras para emprestimo--\n");}
            
            break;
        case 4:
            do{
                printf("Digite o que foi devolvido: ");
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")]='\0';
                if(strcmp(item, "cancel")==0){
                    validar=1;
                }else{
                    for(int i=0;i<10;i++){
                    if(strcmp(emprestimo[i].obraEmp.nome,item)==0){
                        back(&emprestimo[i], &user);
                        validar=1;
                        i=10;
                    }else if(i==9 && strcmp(emprestimo[i].obraEmp.nome,item)!=0){
                        printf("--item nao existe ou nao foi emprestado--\n");
                    }
                    }
                }    
            }while(validar == 0);
                inicio(&pseudoEmp);
            break;
        case 5:
            printf("-|-Obra(s) mais emprestada(s)-|-\n");
            for(int i=0;i<10;i++){
                if(topseller.uso<user.obra[i].uso){
                    topseller.uso = user.obra[i].uso;
                    strcpy(topseller.nome, user.obra[i].nome);
                }
            }
            if(topseller.uso>0){
                printf("_[%s]_\nTotal de emprestimos: %d", topseller.nome, topseller.uso);
            }else{
                printf("--Nada foi emprestado--\n");
            }
            printf("\n-|-Obras em emprestimo-|-\n");
            for(int i=0;i<25;i++){
                if(strcmp(emprestimo[i].data,"")!=0){
                see(emprestimo[i]);
                con=con+1;
                }else if(con==0){
                    printf("--Nada em emprestimo--\n");
                    i=25;
                }
            }
            break; 
        case 6:
            break;           
        default:
            printf("--Opcao invalida, tente novamente--\n");
            break;
        }
    obrasDisp=0;
    for(int i=0;i<10;i++){
                obrasDisp = user.obra[i].condicao + obrasDisp;
            }
    }while(opcao != 6);

    printf("\n");
    return 0;
}

void inicio(s_emp *pseudoEmp){
    strcpy(pseudoEmp->obraEmp.nome, "");
    pseudoEmp->obraEmp.condicao = 0;
    pseudoEmp->obraEmp.uso = 0;
    strcpy(pseudoEmp->data, "");
    strcpy(pseudoEmp->dev, "");
    pseudoEmp->indicador = 0;
}

void cad(s_user *usuario){
    int sim=0;
    char keynome[20];
    fflush(stdin);
    printf("Informe o nome do objeto: ");
    fgets(keynome, sizeof(keynome), stdin);
    keynome[strcspn(keynome, "\n")]='\0';
    fflush(stdin);
    for(int i=0;i<10;i++){
        if(strcmp(usuario->obra[i].nome, keynome)==0){
            printf("--Nao aceita a clonagem--");
            i=10;
            sim=1;
        }
    }
    if(sim==0){
        for(int j=0;j<10;j++){
            if(strcmp(usuario->obra[j].nome, "")==0){
                strcpy(usuario->obra[j].nome, keynome);
                usuario->obra[j].condicao=1;
                printf("___Objeto adicionado na posicao %d___\n",j);
                j=11;
            }
        }    
    }
}

void del(s_user *user, char obj[20]){
    for(int i=0;i<10;i++){
        if(strcmp(user->obra->nome, obj)==0){
            printf("__%s foi deletado__", obj);
            strcpy(user->obra[i].nome, "");
            user->obra[i].condicao = 0;
            user->obra[i].uso = 0;
        }
    }
}

void adic(s_emp *emp, s_user *user){
    char keynome[20];
    char keydata[10];
    char keydev[10];
    char amigo[20];
    int validar=0;
    fflush(stdin);
    printf("Digite a data de emprestimo: ");
    fgets(keydata, sizeof(keydata), stdin);
    keydata[strcspn(keydata, "\n")]='\0';
    fflush(stdin);
    printf("Digite a data de devolucao: ");
    fgets(keydev, sizeof(keydev), stdin);
    keydev[strcspn(keydev, "\n")]='\0';
    fflush(stdin);
    do{
        printf("Digite o que esta sendo emprestado: ");
        fgets(keynome, sizeof(keynome), stdin);
        keynome[strcspn(keynome, "\n")]='\0';
        printf("Digite quem vai receber: ");
        fgets(amigo, sizeof(amigo), stdin);
        amigo[strcspn(amigo, "\n")]='\0';
        if(strcmp(amigo, user->amigo[0].nome)!=0 && strcmp(amigo, user->amigo[1].nome)!=0){
            printf("--Voce nao tem esse amigo--\n");
        }else if(strcmp(keynome, "cancel")==0){
            validar=1;
        }else{
            for(int j=0;j<10;j++){
                if(strcmp(emp->obraEmp.nome,"")==0 && strcmp(user->obra[j].nome, keynome)==0){
                    emp->indicador = emp->indicador+1;
                    strcpy(emp->data, keydata);
                    strcpy(emp->dev, keydev);
                    strcpy(emp->obraEmp.nome, keynome);
                    emp->obraEmp.condicao = 1;
                    emp->obraEmp.uso = emp->obraEmp.uso+1;
                    user->obra[j].condicao = 0;
                    user->obra[j].uso = user->obra[j].uso +1;
                    for(int i=0;i<2;i++){
                        if(strcmp(user->amigo[i].nome,amigo)==0){
                            for(int k=0;k<10;k++){
                                if(strcmp(user->amigo[i].obraEmp[k].nome,"")==0){
                                    strcpy(user->amigo[i].obraEmp[k].nome, keynome);
                                    strcpy(user->amigo[i].nome, amigo);
                                    user->amigo[i].obraEmp->condicao=1;
                                    printf("___obra n %d foi emprestada para %s___\n",j,user->amigo[i].nome);
                                   // printf("isso-%d-",i);
                                    k=10;
                                }
                            }
                        }
                    }
                    //strcpy(user->obra[j].nome, "");
                    j=10;
                    validar=1;
                }
            }
        }
    }while(validar == 0);
}

void back(s_emp *emp, s_user *user){
    for(int j=0;j<10;j++){
        //printf("a%s",user->amigo[0].obraEmp[0].nome);
        //printf("b%s",emp->obraEmp.nome);
        //printf("c%s",user->obra[j].nome);
        for(int i=0;i<2;i++){
            if(strcmp(user->amigo[i].obraEmp[j].nome, emp->obraEmp.nome)==0){
                strcpy(emp->obraEmp.nome, "");
                emp->obraEmp.condicao = 0;
                strcpy(emp->data,"");
                strcpy(emp->dev,"");
                user->obra[j].condicao = 1;
                printf("___%s devolveu %s___\n",user->amigo[i].nome,user->amigo[i].obraEmp[j].nome);
                strcpy(user->amigo[i].obraEmp[j].nome, "");
                user->amigo[i].obraEmp[j].condicao=0;
                //printf("\n%d",i);
                i=2;                
                j=10;
            }else if(j==9 && strcmp(user->amigo[i].obraEmp[j].nome, emp->obraEmp.nome)!=0){
            printf("--puts, tem isso nao--");
            }
        }   
    }
}

void see(s_emp empre){
    printf("\n|Obra: %s\n",empre.obraEmp.nome);
    printf("|Data de emprestimo: %s\n",empre.data);
    printf("|Data de devolucao: %s\n",empre.dev);
}