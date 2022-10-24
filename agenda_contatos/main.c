#include "agenda_contatos.h"
#include <stdio.h>
#include <string.h>

int main(){
    Agenda *A = criar_agenda();
    char opcao;
    char nome[11] = "NULO";
    int numero = 0;

    do{
        scanf("%c ",&opcao);

        switch (opcao){
        //remover
        case 'R':
            scanf("%s",nome);
            contato_remover(A, nome);
            break;

        //inserir
        case 'I':
            scanf("%s %d",nome, &numero);
            contato_inserir(A, nome, numero);
            break;
        
        //pesquisar
        case 'P':
            scanf("%s",nome);
            contato_pesquisar(A, nome);
            break;
        
        //alterar
        case 'A':
            scanf("%s %d",nome, &numero);
            contato_alterar(A, nome, numero);
            break;

        case '0':
            return 0;
        }
        
    } while (1);
}