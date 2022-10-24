#include "agenda_contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _contato{
    char nome[11];  //nome do contatinho
    int numero; //numero de telefone do contatinho
    struct _contato *proximo;   //ponteiro para o próximo contatinho da agenda
} Contato;

typedef struct _agenda{
    Contato *comeco;
} Agenda;


//================================== Crianado um contato/nó
Contato *criar_contato(char nome[], int numero){
    Contato *contato = (Contato*) calloc(1, sizeof(Contato));
    strcpy(contato->nome, nome);
    contato->numero = numero;
    contato->proximo == NULL;

     return contato;
}

//================================== Criando o ponteiro que irá marcar a cabeça da agenda/lista
Agenda *criar_agenda(){
    Agenda *A = (Agenda*) calloc(1, sizeof(Agenda));
    A->comeco = NULL;

    return A;
}

//================================== Inserindo um contato/nó na Agenda
void contato_inserir(Agenda *A, char nome[], int numero){
        Contato *Noh = A->comeco;

    //Enquanto nao chegar ao fim da lista
    while (Noh != NULL){
        //se achar o contato
        if(strcmp(Noh->nome, nome) == 0){
            printf("Contatinho ja inserido\n");
            return;
        }
        Noh = Noh->proximo;
    }
        
        //insere na cabeça
        Contato *C = criar_contato(nome, numero);
        C->proximo = A->comeco;
        A->comeco = C;
}

//================================== Procurando e Imprimindo contato (se existir)
void contato_pesquisar(const Agenda *A, char nome[]){
    Contato *C = A->comeco;

    //Enquanto nao chegar ao fim da lista
    while (C != NULL){
        //se achar o contato
        if(strcmp(C->nome, nome) == 0){
            printf("Contatinho encontrado: telefone %d\n", C->numero);
            return;
        }
        C = C->proximo;
    }
    printf("Contatinho nao encontrado\n");
}

//================================= Procurando e Removendo contato (se existir)
void contato_remover(Agenda *A, char nome[]){
    Contato *C = A->comeco;

    //se a agenda estiver vazia
    if(C == NULL){
        printf("Operacao invalida: contatinho nao encontrado\n");
        return;
    }

    //se a agenda foi unitária ou o contato for o primeiro da lista
    if(strcmp(C->nome, nome) == 0){
        A->comeco == C->proximo;
        free(C);
        return;
    }

    //caso da agenda nao ser vazia nem unitária
    while(C->proximo != NULL){
        if(strcmp(C->proximo->nome, nome) == 0){
            Contato *R = C->proximo;
            C->proximo = R->proximo;
            free(R);
            return;
        }
        C = C->proximo;
    }
    printf("Operacao invalida: contatinho nao encontrado\n");
}

//======================================= Alteral algum contato na agenda
void contato_alterar(Agenda *A, char nome[], int numero){
    Contato *C = A->comeco;

    //Enquanto nao chegar ao fim da lista
    while (C != NULL){
        //se achar o contato
        if(strcmp(C->nome, nome) == 0){
            C->numero = numero;
            return;
        }
        C = C->proximo;
    }
    printf("Operacao invalida: contatinho nao encontrado\n");
}
