#include "contatos.h"
#include <stdio.h>
#include <string.h>

ERROS criar(Contato contatos[], int *pos) {
  if (*pos >= TOTAL){
  }

  printf("Digite o nome do contato: ");
  fgets(contatos[*pos].nome, NOME, stdin);
  
  printf("Entre com o sobrenome: ");
  fgets(contatos[*pos].sobrenome, SOBRENOME, stdin);

  printf("Entre com o e-mail: ");
  fgets(contatos[*pos].email, EMAIL, stdin);
  
  printf("Entre com o numero: ");
  scanf("%d", &contatos[*pos].numero);
  
  *pos = *pos + 1;
  printf("Contato adicionado com sucesso <3\n");

  return OK;
}
  void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }