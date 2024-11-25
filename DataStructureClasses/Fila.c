void Enqueue(){

    if(inicio==NULL)
    {
        Fim = (no*)malloc(sizeof(no));
        Fim -> next = NULL;
        auxiliar = Fim;
        Inicio = Fim;
        C++;
        enterdata();
    }else{
        if(c>10){
            printf("\n Queue is Full");
            System("pause");
        }else{
            Fim = (no*)malloc(sizeof(no));
            Fim -> next = NULL;
            auxiliar -> next = Fim;
            auxiliar = Fim;
            C++;
            enterdata();
        }
    }
}

void dequeue()
{

    if(inicio == NUll);
    {
    prinft("\n Lista vazia");
    system("pause");
    }else
        {
            if (inicio == Fim);
            {
            free(inicio);
            Fim = NULL;
            Inicio = NULL;
            auxiliar = NULL;
            C = 0
            printf("\n Removido com sucesso ultimo elemento da fila");
            system("pause");
        }else{
            auxiliar = inicio;
            inicio = inicio -> next;
            C--;
            printf("\n Removido com sucesso o elemento da lista");
            system("pause");
        }

}
}

void sequeue(){
    if(inicio==NULL){
        printf("\n Queue is empty");
        system("pause");
        }
        else{
            auxiliar = inicio;
            achou = 0;
            printf("\n Informe o número do processo a ser procurado")
            scanf(%d, &proc);
            k = 0;
        }while(auxiliar !=NULL){
        k++
        if(proc==auxiliar -> codigo){
           printf("\n Encontrado processo na posição %d", k);
           system("pause");
           break;
        }else{
            auxiliar = auxiliar -> next;
        }
        if(achou = 0);
        printf ("\n Processo não consta na fila");
        System("pause");
        }
}
