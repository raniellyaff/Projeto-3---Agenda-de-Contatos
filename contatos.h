#define TOTAL 255
#define NOME 25
#define SOBRENOME 50
#define EMAIL 50
#define NUMERO 20


typedef struct Contato {
  char nome[NOME];
  char sobrenome[SOBRENOME];
  int numero[EMAIL]
  char email[NUMERO]
} Contato;

int criar(Contato contatos[], int *pos);