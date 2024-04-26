// definição de tamanho das variáveis
#define TOTAL 255
#define NOME 25
#define SOBRENOME 50
#define EMAIL 50

// definição do struct que armazena cada contato inserido
typedef struct Contato {
  char nome[NOME];
  char sobrenome[SOBRENOME];
  int numero;
  char email[EMAIL];
} Contato;

// enumera possíveis erros
typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_ENCONTRADO, ESCREVER, ABRIR, LER} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

// assinatura das funções e seus parâmetros feitas em contatos.c
ERROS criar(Contato contatos[], int *pos);
ERROS listar(Contato contatos[], int *pos);
ERROS deletar(Contato contatos[], int *pos);
ERROS exportar_binario(Contato contatos[], int pos);
ERROS carregar_binario(Contato contatos[], int *pos);
void clearBuffer();