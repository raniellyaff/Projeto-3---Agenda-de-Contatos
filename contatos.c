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
  }

  printf("\nContatos listados com sucesso! <3\n");
  return OK;
}

ERROS deletar(Contato contatos[], int *pos) {
  if (*pos == 0)
    return SEM_CONTATOS;

  int num_deletar;
  printf("Digite o número do contato a ser deletado: ");
  scanf("%d", &num_deletar);

  int encontrado = 0;
  for (int i = 0; i < *pos; i++) {
    printf("ola");
    if (contatos[i].numero == num_deletar || encontrado) {
      strcpy(contatos[i].nome, contatos[i + 1].nome);
      strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
      strcpy(contatos[i].email, contatos[i + 1].email);
      contatos[i].numero = contatos[i + 1].numero;
      encontrado = 1;
    }
  }
  if (encontrado)
    *pos = *pos - 1;
  printf("Contato deletado com sucesso! <3\n");
  return OK;
}

ERROS exportar_binario(Contato contatos[], int pos) {
  FILE *arquivo =
    fopen("contatos.bin", "wb");

  if (arquivo == NULL) {
    return ABRIR;
  }
  int qtd = fwrite(contatos, sizeof(Contato), pos, arquivo);

  if (qtd != pos) {
    fclose(arquivo);
    return ESCREVER;
  }

  fclose(arquivo);
  printf("Contatos exportados para arquivo binário com sucesso! <3\n");
  return OK;
}

ERROS carregar_binario(Contato contatos[], int *pos) {
  FILE *arquivo =
    fopen("contatos.bin", "rb");

  if (arquivo == NULL) {
    return ABRIR;
  }

  int qtd = fread(contatos, sizeof(Contato), TOTAL, arquivo);

  if (qtd <= 0) {
    fclose(arquivo);
    return LER;
  }
  *pos = qtd;

  fclose(arquivo);
  printf("Contatos salvos de arquivo binário com sucesso! <3\n");
  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}