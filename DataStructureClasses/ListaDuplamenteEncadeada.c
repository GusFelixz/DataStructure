#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct no
{
    int codigo;
    char nome [64];
    struct no *next, *back;
//Fim e back são ponteiros novos, back é um ponteiro dinamico como next e fim é um ponteiro estático que sempre
//vai ficar na última posição da lista
} no;
struct no *corrente, *inicio, *auxiliar, *auxiliar2, *fim;

void Enterdata ()
{

    printf("\nInforme o codigo: ");
    scanf("%d", &corrente -> codigo);

    printf("\nInforme o nome: ");
    scanf("%s", &corrente -> nome);
}

void insert ()
{
    if (inicio == NULL)
    {
        corrente =(no*)malloc(sizeof(no));
        inicio = corrente;
        auxiliar = corrente;
        fim = corrente; //Fim segue o corrente sempre que corrente criar um novo registro
        corrente -> next = NULL;
        Enterdata();
    }
    else
    {
        corrente=(no*)malloc(sizeof(no));
        auxiliar -> next = corrente;
        corrente -> back = auxiliar;
        auxiliar = corrente;
        fim = corrente;
        corrente -> next = NULL;
        Enterdata();
    }
}

void Exibir()
{
    char xnome [64];
    int xcodigo;

    if(inicio == NULL)
    {
        printf("\nNão ha dados na lista. ");
        system("pause");
    }
    else
    {
        if(auxiliar)
        {
            auxiliar = inicio;

            do{

            printf("\nNome: %s", auxiliar -> nome);
            printf("\ncodigo: %i", auxiliar -> codigo);
            fflush(stdin);
            auxiliar = auxiliar -> next;


        }while(auxiliar != NULL);

            }
    }
}

//FEITO DIA 27_08 METODO CLASSIFICAR OS ELEMENTOS DA LISTA
void Class ()
{
    corrente =(no*)malloc(sizeof(no));
    Enterdata();
    auxiliar = inicio;
    int achou = 0;

    if(inicio == NULL)
    {
        inicio = corrente;
        auxiliar = corrente;
        fim = corrente;
        corrente -> next = NULL;
        corrente -> back = NULL;
        achou = 1;

        printf("\nInstalando o primeiro nome na lista. ");
        system("pause");

    }
    else
    {
        if(strcmp(corrente -> nome, auxiliar -> nome) <= 0)
        {
            corrente -> next = auxiliar;
            inicio = corrente;
            corrente -> back = NULL;
            auxiliar -> back = corrente;
            achou = 1;
            printf("\nElemento precede o primeiro da lista");
            system("pause");
        }
        else
        {
            auxiliar2 = auxiliar -> next;

            while(auxiliar2 != NULL)
            {
                if(strcmp(corrente -> nome, auxiliar -> nome) >= 0 && strcmp(corrente-> nome, auxiliar2 -> nome) <= 0)
                {
                    corrente -> back = auxiliar;
                    corrente -> next = auxiliar -> next;
                    auxiliar -> next = corrente;
                    auxiliar2 -> back = corrente;
                    achou = 1;
                    printf("\nElemento inserido no meio da lista");
                    system("pause");
                }
                else
                {
                    auxiliar = auxiliar -> next;
                    auxiliar2 = auxiliar2 -> next;
                }
            }
        }
    }
    if(strcmp(corrente -> nome, auxiliar2 -> nome) >= 0 && achou == 0)
    {
        fim -> next = corrente;
        corrente -> back = fim;
        fim = corrente;
        achou = 1;
        corrente -> next = NULL;
        printf("\nElemento inserido com sucesso no final da lista");
        system("pause");
    }
}


void Pesquisar()
{
    char xnome[20];
    int achou, k;

    if(inicio == NULL)
    {
        printf("\nLista vazia");
        system("pause");

    }
    else
    {
        printf("\nInforme o nome a ser consultado: ");
        scanf("%s", &xnome);
        achou = 0;
        k = 0;
        auxiliar = inicio;
        while (auxiliar != NULL)
        {
            k++;
            if(strcmp(xnome, auxiliar -> nome) == 0)
            {
                printf("\nRegistro encontrado na posicao: %d", k);
                system("pause");
                achou = 1;
                //break;
            }
            else
            {
                auxiliar = auxiliar -> next;
            }
        }
        if (achou == 0)
        {
            printf("\nRegistro nao consta na lista.");
            system("pause");
        }
    }
}

void Remover()
{
    char xnome[20];
    int achou;

    if(inicio == NULL)
    {
        printf("\nLista vazia");
        system("pause");
    }
    else
    {

        printf("\nInforme o nome a ser consultado: ");
        scanf("%s", &xnome);
        achou = 0;

        auxiliar = auxiliar -> back;


        if(strcmp (xnome, auxiliar -> nome) == 0)
        {
            inicio = inicio -> next; //SALTAR
            free(auxiliar);
            achou = 1;
            printf("\nRemovido com sucesso o registro <<iniciodalista>>");
            system("pause");
        }
        else
        {
            corrente = auxiliar -> next; //SINCRONIZAR
            while (corrente != NULL)
            {
                if(strcmp(xnome, corrente -> nome) == 0)
                {
                    auxiliar -> next = corrente -> next;
                    corrente -> back = auxiliar -> back;
                    corrente = corrente -> back;
                    corrente -> next = auxiliar -> next;
                    free(corrente);

                    printf("\nRemovido com sucesso o registro da lista <<meio da lista>>");
                    achou = 1;
                    system("pause");
                    break;
                }
                else
                {
                    auxiliar = auxiliar -> next;
                }
            }
            if (achou == 0)
            {
                printf("\nRegistro nao consta na lista.");
                system("pause");
            }
        }
    }
}

int main ()
{
    auxiliar = NULL;
    corrente = NULL;
    inicio = NULL;
    fim = NULL;
    int op = 0;
    char continuar;

    do
    {
        printf("\n[1] - inserir elemento na lista");
        printf("\n[2] - exibir os elementos da lista");
        printf("\n[3] - pesquisar elementos da lista");
        printf("\n[4] - remover elementos da lista");
        printf("\n[5] - alterar elementos da lista");

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            Class();
            break;

        case 2:
            Exibir();
            break;

        case 3:
            Pesquisar();
            break;

        case 4:
            Remover();
            break;

        case 5:
            printf("\nMetodo a ser desenvolvido");
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

