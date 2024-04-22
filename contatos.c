#include "tarefas.h"
#include <stdio.h>
#include <string.h>

ERROS criar(Contato contatos[], int *pos) {
  if (*pos >= TOTAL)

  printf("Digite o nome do contato: ");
  scanf("%d", &contatos[*pos].nome);
  
  clearBuffer();
  printf("Entre com a categoria: ");/
  fgets(tarefas[*pos].categoria, CATEGORIA, stdin);


  printf("Entre com a descricao: ");
  fgets(tarefas[*pos].descricao, DESCRICAO, stdin);
  
  *pos = *pos + 1;
  printf("Tarefa criada com sucesso.\n");

  return OK;
}