
typedef struct _contato Contato;
typedef struct _agenda Agenda;

//==================================== INTERFACE ========================================
Agenda *criar_agenda();
Contato *criar_contato(char nome[], int numero);
void contato_inserir(Agenda *A, char nome[], int numero);
void contato_pesquisar(const Agenda *A, char nome[]);
void contato_remover(Agenda *A, char nome[]);
void contato_alterar(Agenda *A, char nome[], int numero);
//=======================================================================================