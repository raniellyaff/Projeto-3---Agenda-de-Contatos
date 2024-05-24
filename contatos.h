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
typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_ENCONTRADO, ESCREVER, ABRIR, LER, EMAIL_INVALIDO, NUMERO_EXISTE} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

// assinatura das funções e seus parâmetros feitas em contatos.c
ERROS criarpessoal(Contato pessoal[], int *pos);
ERROS criartrabalho(Contato trabalho[], int *pos);
ERROS listarpessoal(Contato pessoal[], int *pos);
ERROS listartrabalho(Contato trabalho[], int *pos);
ERROS deletarpessoal(Contato pessoal[], int *pos);
ERROS deletartrabalho(Contato trabalho[], int *pos);
ERROS exportar_binariopessoal(Contato pessoal[], int pos);
ERROS exportar_binariotrabalho(Contato trabalho[], int pos);
ERROS carregar_binariopessoal(Contato pessoal[], int *pos);
ERROS carregar_binariotrabalho(Contato trabalho[], int *pos);
ERROS validarEmailpessoal(const char *email);
ERROS validarEmailtrabalho(const char *email);
ERROS numeroExistepessoal(Contato pessoal[], int pos, int numero);
ERROS numeroExistetrabalho(Contato trabalho[], int pos, int numero);
void clearBuffer();