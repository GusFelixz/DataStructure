#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct no
{
    int codigo;
    char nome [64];
    struct no *next, *back;
} no;
struct no *corrente, *raiz, *auxiliar;


void Enterdata ()
{
    printf("\nInforme o codigo: ");
    scanf("%d", &raiz-> codigo);
    fflush(stdin);

    printf("\nInforme o nome: ");
    scanf("%s", &raiz-> nome);
    fflush(stdin);
}

void insert_binary(){
    int aloca;

    corrente = (no*)malloc(sizeof(no));
    corrente -> next = NULL;
    corrente -> back = NULL;
    Enterdata();
    aloca = 0;

    if (raiz==NULL){
        raiz = corrente;
        auxiliar = corrente;
        printf("\n Estabelecido a raiz na �rvore");
        system("pause");
    }else{
        auxiliar = raiz;
        while(aloca == 0){
            if(auxiliar ->codigo<corrente->codigo){
                if(auxiliar->next == NULL){
                    auxiliar->next=corrente;
                    printf("\n Alocado o elemento a direita da �rvore");
                    system("pause");
                    aloca = 1;
                    break;
                }else{
                    auxiliar = auxiliar -> next;
                }
            }
            if(auxiliar->codigo>corrente->codigo){
                if(auxiliar->back==NULL){
                    auxiliar->back=corrente;
                    printf("\n Alocado o elemento a esquerda da �rvore");
                    system("pause");
                    aloca = 1;
                    break;
                }else{
                    auxiliar = auxiliar->back;
                }
            }
        }
    }
}


void show_binary(no*root){
    if (root==NULL){
        printf("\n Arvore bin�ria vazia");
        system("pause");
    }else{
        printf("\n --------------Raiz da �rvore-------------");
        printf("\n %d-----------%s", root->codigo, root->nome);
        printf("\n \n");
    }if(root->back !=NULL) show_binary(root->back);
     if(root->next !=NULL) show_binary(root->next);
}


int search_binary(no*root){
    int codigo;
    int achou;
    achou = 0;

    if(root==NULL){
    printf("\n �rvore bin�ria vazia");
    system("pause");
    }else{
        printf("\n Informe o c�digo a ser procurado");
        scanf("%d", &codigo);
        printf("\n ----------%d--------", achou);
        achou = achou_valor(raiz,codigo);
        printf("\n ----------%d--------", achou);
        if(achou==1){
            printf("\n Encontrado c�digo na �rvore");
        }else{
            printf("\n Codigo n�o consta na �rvore");
            system("pause");
            return achou;
        }
    }

        int achou_valor(no*raiz, int key){
            if(key==root->codigo){
               printf("\n %s", root->nome);
               return 1;
            }else{
                if(root->back !=NULL) achou_valor(root->back, key);
                if(root->next !=NULL) achou_valor(root->next, key);
            }
        }
}


int main()
{
    auxiliar = NULL;
    int op = 0;
    char continuar;

    do
    {
        printf("\n[1] - inserir elementos na �rvore");
        printf("\n[2] - pesquisar na �rvore");
        printf("\n[3] - exibir na �rvore");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            insert_binary();
            break;

        case 2:
            search_binary;
            break;

        case 3:
            show_binary;
            break;
        default:
            printf("\nOpcao invalida");
            break;
        }

        printf("\nDeseja fazer outra operacao [S/N]: ");
        scanf("%s", &continuar);
        continuar = toupper(continuar);
        system("cls");
    }

    while (continuar != 'N');
}
