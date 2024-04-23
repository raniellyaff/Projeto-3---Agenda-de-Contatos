#define TOTAL 255
#define NOME 25
#define SOBRENOME 50
#define EMAIL 50


typedef struct Contato {
  char nome[NOME];
  char sobrenome[SOBRENOME];
  int numero;
  char email[EMAIL];
} Contato;

typedef enum {OK} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

ERROS criar(Contato contatos[], int *pos);

void clearBuffer();