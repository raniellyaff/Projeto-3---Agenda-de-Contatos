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
  printf("Contato adicionado com sucesso! <3\n");

  return OK;
}

ERROS listar(Contato contatos[], int *pos) {
  if (*pos == 0) {
    return SEM_CONTATOS;
  }

  for (int i = 0; i < *pos; i++) {
    printf("\nNome: %s", contatos[i].nome);
    printf("Sobrenome: %s", contatos[i].sobrenome);
    printf("E-mail: %s", contatos[i].email);
    printf("Número: %d\n", contatos[i].numero);
    i++;
  }

  printf("Contatos listados com sucesso! <3\n");
  
  return OK;
}
  void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    }