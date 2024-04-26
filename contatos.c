// inclusão das assinaturas de função, header de input e output, e header de strings
#include "contatos.h"
#include <stdio.h>
#include <string.h>

// função criar contato
ERROS criar(Contato contatos[], int *pos) { 

  if (*pos >= TOTAL) { // caso o ponteiro da posição for maior ou igual o número total de contatos, retorna o erro MAX_CONTATOS
    return MAX_CONTATOS;
  }
  // solicita as informações do usuário armazenando no struct contatos na posição 0, com o tamanho determinado pelas variáveis determinadas no contatos.h, pegando input do teclado
  printf("Digite o nome do contato: ");
  fgets(contatos[*pos].nome, NOME, stdin);

  printf("Entre com o sobrenome: ");
  fgets(contatos[*pos].sobrenome, SOBRENOME, stdin);

  printf("Entre com o e-mail: ");
  fgets(contatos[*pos].email, EMAIL, stdin);

  printf("Entre com o número: ");
  scanf("%d", &contatos[*pos].numero);


  *pos = *pos + 1; //posição passa a ser posição atual + 1
  printf("\nContato adicionado com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função listar contatos
ERROS listar(Contato contatos[], int *pos) {
  if (*pos == 0) { // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;
  }

  for (int i = 0; i < *pos; i++) { // loop que irá percorrer os structs e printar um por um
    printf("\nNome: %s", contatos[i].nome);
    printf("Sobrenome: %s", contatos[i].sobrenome);
    printf("E-mail: %s", contatos[i].email);
    printf("Número: %d\n", contatos[i].numero);
  }

  printf("\nContatos listados com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função deletar
ERROS deletar(Contato contatos[], int *pos) {
  if (*pos == 0) // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;

  int num_deletar; // define a variável que irá armazenar o número a ser deletado
  printf("Digite o número do contato a ser deletado: "); // pede variável e armazena no endereço dessa variável anterior
  scanf("%d", &num_deletar);


  int encontrado = 0; // define uma variável que irá verificar se o número foi encontrado na memória, encontrado = false

  for (int i = 0; i < *pos; i++) { // loop que percorre os structs criados
    if (contatos[i].numero == num_deletar || encontrado) { // caso o contato do struct i seja igual ao número a ser deletado, ou o número já foi encontrado
      strcpy(contatos[i].nome, contatos[i + 1].nome); // copia as informações do próximo struct para o atual, sobrescrevendo  que vai ser deletado
      strcpy(contatos[i].sobrenome, contatos[i + 1].sobrenome);
      strcpy(contatos[i].email, contatos[i + 1].email);
      contatos[i].numero = contatos[i + 1].numero;
      encontrado = 1; // número foi encontrado = true, logo, entra no loop e termina de copiar as próximas posições
    }
    else { // caso não entre no if anterior, o número não foi encontrado, logo, retorna o erro de que o número não foi registrado
      return NAO_ENCONTRADO;
    }
  }
  if (encontrado) // caso o número tenha sido encontrado, diminui 1 posição do array, pois um registro foi sobrescrito
    *pos = *pos - 1;
  printf("\nContato deletado com sucesso! <3\n"); // //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função de exportar
ERROS exportar_binario(Contato contatos[], int pos) {
  FILE *arquivo = fopen("contatos.bin", "wb"); // arquivo contatos.bin será criado para escrita e excluirá o arquivo já existente

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }
  int qtd = fwrite(contatos, sizeof(Contato), pos, arquivo); // define uma variável qtde que será o tamanho do array de structs

  if (qtd != pos) { // caso o tamanho seja diferente da posição atual, siginifica que houve problemas na escrita do arquivo, logo ele será fechado e retornará o erro ESCREVER
    fclose(arquivo);
    return ESCREVER;
  }

  fclose(arquivo); // fecha o arquivo pois todos os contatos foram exportados
  printf("\nContatos exportados para arquivo binário com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função carregar binário
ERROS carregar_binario(Contato contatos[], int *pos) {
  FILE *arquivo = fopen("contatos.bin", "rb"); // abre arquivo contatos.bin que já existe na pasta para leitura

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }

  int qtd = fread(contatos, sizeof(Contato), TOTAL, arquivo); // define uma variável qtde que será o tamanho do array de structs lidos

  if (qtd <= 0) { // caso o tamanho do array seja diferente da quantidade de contatos lidos, siginifica que houve problemas na leitura do arquivo, logo ele será fechado e retornará o erro LER
    fclose(arquivo);
    return LER;
  }
  *pos = qtd; 

  fclose(arquivo); // fecha o arquivo pois todos os contatos foram lidos
  printf("\nContatos salvos de arquivo binário com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

void clearBuffer() { // função que limpa lixo de memória
  int c;
  while ((c = getchar()) != '\n' && c != EOF) 
    ;
}