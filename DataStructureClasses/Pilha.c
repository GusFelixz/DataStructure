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
struct no *corrente, *topo, *auxiliar, *auxiliar2, *fim;


void Enterdata ()
{
    printf("\nInforme o codigo: ");
    scanf("%d", &topo -> codigo);
    fflush(stdin);

    printf("\nInforme o nome: ");
    scanf("%s", &topo -> nome);
    fflush(stdin);
}

void Push()
{
    int c;
    if (topo == NULL)
    {
        topo=(no*)malloc(sizeof(no));
        auxiliar = topo;
        topo -> next = NULL;
        topo -> back = NULL;
        Enterdata();
        fflush(stdin);
        c++;
    }
    else
    {
        if(c >= 6)
        {
            printf("\nStack overflow");
            system("pause");
        }
        else
        {
            topo = (no*)malloc(sizeof(no));
            auxiliar -> next =  topo;
            topo -> back = auxiliar;
            auxiliar = topo;
            topo -> next = NULL;
            Enterdata();
            fflush(stdin);
            c++;
        }
    }
}

void Pop()
{
    int c = 0;
    if(topo == NULL)
    {
        printf("\nPilha vazia.");
        system("pause");
    }
    else
    {
        if(topo -> next == NULL && topo -> back == NULL)
        {
            free(topo);
            topo = NULL;
            auxiliar = NULL;
            c = 0;
            printf("\nRemovendo o ultimo elemento da pilha");
            system("pause");
        }
        else
        {
            topo = auxiliar;
            topo -> next = NULL;
            topo -> back = auxiliar;

            free(topo);
            printf("\nRegistro removido com sucesso!");

            topo = auxiliar;
            system("pause");
            c--;
        }
    }
}

void Top()
{
    if(topo == NULL)
    {
        printf("\nStack is empity");
        system("pause");
    }
    else
    {
        printf("\nCodigo => %d", topo->codigo);
        printf("\nNome => %s", topo->nome);
    }
}

int main()
{
    auxiliar = NULL;
    topo = NULL;
    int op = 0;
    char continuar;

    do
    {
        printf("\n[1] - inserir elementos na pilha");
        printf("\n[2] - remover elementos da lista");
        printf("\n[3] - exibir topo da lista");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            Push();
            break;

        case 2:
            Pop();
            break;

        case 3:
            Top();
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


void Polonesa () {
    char equacao [20];
    int c;
    int tamanhoEquacao = sizeof(equacao) / sizeof(equacao[0]);

    printf("\nDigite a equacao desejada: ");
    gets(equacao);

    for(c = 0; c < tamanhoEquacao; c++)
    {
        if(equacao[c] == '+' || equacao[c] == '-' || equacao[c] == '*' || equacao[c] == '/')
        {
            Push(equacao[c]);
        }
        else
        {

        }

    }
}


