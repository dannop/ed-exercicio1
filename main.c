#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* cria_lista (void) {
    return NULL;
}

void imprime (TLista* li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}


TLista* insere_inicio (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = li;
    return novo;
}

TLista* insere_fim (TLista* li, int i){
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    
    if (li == NULL) li = novo;
    else {
        TLista* li_aux = li;
        while (li_aux->prox != NULL) li_aux = li_aux->prox;
        li_aux->prox = novo;
    }

    return li;
}

TLista* insere_ordenado (TLista* li, int i){
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    
    if (li == NULL) li = novo;
    else {
        TLista* aux = li;
        while (aux->info <= i && aux->prox != NULL) aux = aux->prox;
            if (aux->prox->prox != NULL) novo->prox = aux->prox->prox;
            aux->prox = novo;
    }

    return li;
}

TLista* exclui(TLista* li, int i){
    if (li == NULL) return li;
    else {
        TLista* li_aux = li;
        
        while(li_aux->prox != NULL && li_aux->info == i) li_aux = li_aux->prox;
        TLista* no_aux;
        no_aux = li_aux;
        li = li->prox;
        free(no_aux); 
    }
}

TLista* altera(TLista* li, int vantigo, int vnovo){
    if (li == NULL) return li;
    else {
        TLista* li_aux = li;
        
        while(li_aux->prox != NULL && li_aux->info == vantigo) li_aux = li_aux->prox;
        li_aux->info = vnovo;
    }
}

int main (){
    TLista* l1;
    TLista* l2;
    TLista* l3; /* declara listas não inicializadas */
    /* Insere elementos no inicio da lista */
    l1 = cria_lista(); /* cria e inicializa lista como vazia */
    l1 = insere_inicio(l1, 2);
    l1 = insere_inicio(l1, 3);
    l1 = insere_inicio(l1, 5);
    l1 = insere_inicio(l1, 4);
    l1 = altera(l1, 3, 10);
    //l1 = exclui(l1, 3);
    printf("Lista 1:\n");
    imprime(l1);

    /* Insere elementos no final da lista*/
    l2 = cria_lista(); /* cria e inicializa lista como vazia */
    l2 = insere_fim(l2, 2);
    l2 = insere_fim(l2, 3);
    l2 = insere_fim(l2, 5);
    l2 = insere_fim(l2, 4);
    printf("Lista 2:\n");
    imprime(l2);

    /* Insere elementos de forma que a lista esteja sempre ordenada */
    l3 = cria_lista(); /* cria e inicializa lista como vazia */
    l3 = insere_ordenado(l3, 2);
    l3 = insere_ordenado(l3, 5);
    l3 = insere_ordenado(l3, 3);
    l3 = insere_ordenado(l3, 4);
    l3 = insere_ordenado(l3, 1);
    printf("Lista 3:\n");
    imprime(l3);

    return 0;
}