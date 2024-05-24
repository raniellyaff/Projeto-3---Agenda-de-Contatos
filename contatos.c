// inclusão das assinaturas de função, header de input e output, e header de strings
#include "contatos.h"
#include <stdio.h>
#include <string.h>

// Função para validar o email
ERROS validarEmailpessoal(const char *email) {
  const char *at = strchr(email, '@');  // Procura o caractere '@' no email
  if (at == NULL) {                     // Se não encontrar '@', o email é inválido
    return 0;  // Retorna EMAIL_INVALIDO para email inválido
  }

  const char *dot = strrchr(at, '.');   // Procura o último '.' após o '@'
  if (dot == NULL || dot <= at + 1 || *(dot + 1) == '\0') {  // Verifica se '.' está em uma posição válida
    return 0;  // Retorna EMAIL_INVALIDO se '.' não estiver depois de '@' ou for o último caractere
  }

  return 1;  // Retorna OK para email válido
}

// Função para verificar se o número já está em uso
ERROS numeroExistepessoal(Contato pessoal[], int pos, int numero) {
  for (int i = 0; i < pos; i++) {
    if (pessoal[i].numero == numero) {
      return NUMERO_EXISTE; // Número já existe
    }
  }
  return OK; // Número não existe
}

ERROS validarEmailtrabalho(const char *email) {
  const char *at = strchr(email, '@');  // Procura o caractere '@' no email
  if (at == NULL) {                     // Se não encontrar '@', o email é inválido
    return 0;  // Retorna EMAIL_INVALIDO para email inválido
  }

  const char *dot = strrchr(at, '.');   // Procura o último '.' após o '@'
  if (dot == NULL || dot <= at + 1 || *(dot + 1) == '\0') {  // Verifica se '.' está em uma posição válida
    return 0;  // Retorna EMAIL_INVALIDO se '.' não estiver depois de '@' ou for o último caractere
  }

  return 1;  // Retorna OK para email válido
}

// Função para verificar se o número já está em uso
ERROS numeroExistetrabalho(Contato trabalho[], int pos, int numero) {
  for (int i = 0; i < pos; i++) {
    if (trabalho[i].numero == numero) {
      return NUMERO_EXISTE; // Número já existe
    }
  }
  return OK; // Número não existe
}

// função criar contato
ERROS criarpessoal(Contato pessoal[], int *pos) { 

  if (*pos >= TOTAL) { // caso o ponteiro da posição for maior ou igual o número total de contatos, retorna o erro MAX_CONTATOS
    return MAX_CONTATOS;
  }
  // solicita as informações do usuário armazenando no struct contatos na posição 0, com o tamanho determinado pelas variáveis determinadas no contatos.h, pegando input do teclado
  printf("Digite o nome do contato: ");
  fgets(pessoal[*pos].nome, NOME, stdin);

  printf("Entre com o sobrenome: ");
  fgets(pessoal[*pos].sobrenome, SOBRENOME, stdin);

  printf("Entre com o e-mail: ");
  fgets(pessoal[*pos].email, EMAIL, stdin);

  // Remover o '\n' no final da string email
  pessoal[*pos].email[strcspn(pessoal[*pos].email, "\n")] = '\0';

  // Validar o email
  if (!validarEmailpessoal(pessoal[*pos].email)) {
    return EMAIL_INVALIDO;
  }
  
  printf("Entre com o número: ");
  scanf("%d", &pessoal[*pos].numero);

  ERROS numeroStatus = numeroExistepessoal(pessoal, *pos, pessoal[*pos].numero);
  if (numeroStatus == NUMERO_EXISTE) {
    return NUMERO_EXISTE;
  }

  *pos = *pos + 1; //posição passa a ser posição atual + 1
  printf("\nContato adicionado com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS criartrabalho(Contato trabalho[], int *pos) { 

  if (*pos >= TOTAL) { // caso o ponteiro da posição for maior ou igual o número total de contatos, retorna o erro MAX_CONTATOS
    return MAX_CONTATOS;
  }
  // solicita as informações do usuário armazenando no struct contatos na posição 0, com o tamanho determinado pelas variáveis determinadas no contatos.h, pegando input do teclado
  printf("Digite o nome do contato: ");
  fgets(trabalho[*pos].nome, NOME, stdin);

  printf("Entre com o sobrenome: ");
  fgets(trabalho[*pos].sobrenome, SOBRENOME, stdin);

  printf("Entre com o e-mail: ");
  fgets(trabalho[*pos].email, EMAIL, stdin);

  // Remover o '\n' no final da string email
  trabalho[*pos].email[strcspn(trabalho[*pos].email, "\n")] = '\0';

  // Validar o email
  if (!validarEmailtrabalho(trabalho[*pos].email)) {
    return EMAIL_INVALIDO;
  }

  printf("Entre com o número: ");
  scanf("%d", &trabalho[*pos].numero);

  ERROS numeroStatus = numeroExistetrabalho(trabalho, *pos, trabalho[*pos].numero);
  if (numeroStatus == NUMERO_EXISTE) {
    return NUMERO_EXISTE;
  }
  
  *pos = *pos + 1; //posição passa a ser posição atual + 1
  printf("\nContato adicionado com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função listar contatos
ERROS listarpessoal(Contato pessoal[], int *pos) {
  if (*pos == 0) { // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;
  }

  for (int i = 0; i < *pos; i++) { // loop que irá percorrer os structs e printar um por um
    printf("\nNome: %s", pessoal[i].nome);
    printf("Sobrenome: %s", pessoal[i].sobrenome);
    printf("E-mail: %s\n", pessoal[i].email);
    printf("Número: %d\n", pessoal[i].numero);
  }

  printf("\nContatos listados com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS listartrabalho(Contato trabalho[], int *pos) {
  if (*pos == 0) { // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;
  }

  for (int i = 0; i < *pos; i++) { // loop que irá percorrer os structs e printar um por um
    printf("\nNome: %s", trabalho[i].nome);
    printf("Sobrenome: %s", trabalho[i].sobrenome);
    printf("E-mail: %s\n", trabalho[i].email);
    printf("Número: %d\n", trabalho[i].numero);
  }

  printf("\nContatos listados com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS editarpessoal(Contato pessoal[], int *pos) {
  if (*pos == 0) // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;

  int num_editar; // define a variável que irá armazenar o número a ser deletado
  printf("Digite o número do contato a ser editado: "); // pede variável e armazena no endereço dessa variável anterior
  scanf("%d", &num_editar);

  int encontrado = 0; // define uma variável que irá verificar se o número foi encontrado na memória, encontrado = false

  for (int i = 0; i < *pos; i++) { // loop que percorre os structs criados
    if (pessoal[i].numero == num_editar) { // caso o contato do struct i seja igual ao número a ser deletado, ou o número já foi encontrado
      clearBuffer();
      printf("Digite o nome do contato: ");
      fgets(pessoal[i].nome, NOME, stdin);
      printf("Entre com o sobrenome: ");
      fgets(pessoal[*pos].sobrenome, SOBRENOME, stdin);

      strcpy(pessoal[i].sobrenome, pessoal[*pos].sobrenome);

      printf("Entre com o e-mail: ");
      fgets(pessoal[*pos].email, EMAIL, stdin);

      // Remover o '\n' no final da string email
      pessoal[*pos].email[strcspn(pessoal[*pos].email, "\n")] = '\0';

      // Validar o email
      if (!validarEmailpessoal(pessoal[*pos].email)) {
        return EMAIL_INVALIDO;
      }

      strcpy(pessoal[i].email, pessoal[*pos].email);
      
      printf("Entre com o número: ");
      scanf("%d", &pessoal[*pos].numero);

      ERROS numeroStatus = numeroExistepessoal(pessoal, *pos, pessoal[*pos].numero);
      if (numeroStatus == NUMERO_EXISTE) {
        return NUMERO_EXISTE;
      }
      encontrado = 1; // número foi encontrado = true, logo, entra no loop e termina de copiar as próximas posições
      pessoal[i].numero = pessoal[*pos].numero;

    }
    else { // caso não entre no if anterior, o número não foi encontrado, logo, retorna o erro de que o número não foi registrado
      return NAO_ENCONTRADO;
    }
    
  }
  printf("\nContato editado com sucesso! <3\n"); // //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS editartrabalho(Contato trabalho[], int *pos) {
  if (*pos == 0) // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;

  int num_editar; // define a variável que irá armazenar o número a ser deletado
  printf("Digite o número do contato a ser editado: "); // pede variável e armazena no endereço dessa variável anterior
  scanf("%d", &num_editar);

  int encontrado = 0; // define uma variável que irá verificar se o número foi encontrado na memória, encontrado = false

  for (int i = 0; i < *pos; i++) { // loop que percorre os structs criados
    if (trabalho[i].numero == num_editar) { // caso o contato do struct i seja igual ao número a ser deletado, ou o número já foi encontrado
      clearBuffer();
      printf("Digite o nome do contato: ");
      fgets(trabalho[i].nome, NOME, stdin);
      printf("Entre com o sobrenome: ");
      fgets(trabalho[*pos].sobrenome, SOBRENOME, stdin);

      strcpy(trabalho[i].sobrenome, trabalho[*pos].sobrenome);

      printf("Entre com o e-mail: ");
      fgets(trabalho[*pos].email, EMAIL, stdin);

      // Remover o '\n' no final da string email
      trabalho[*pos].email[strcspn(trabalho[*pos].email, "\n")] = '\0';

      // Validar o email
      if (!validarEmailpessoal(trabalho[*pos].email)) {
        return EMAIL_INVALIDO;
      }

      strcpy(trabalho[i].email, trabalho[*pos].email);

      printf("Entre com o número: ");
      scanf("%d", &trabalho[*pos].numero);

      ERROS numeroStatus = numeroExistepessoal(trabalho, *pos, trabalho[*pos].numero);
      if (numeroStatus == NUMERO_EXISTE) {
        return NUMERO_EXISTE;
      }
      encontrado = 1; // número foi encontrado = true, logo, entra no loop e termina de copiar as próximas posições
      trabalho[i].numero = trabalho[*pos].numero;

    }
    else { // caso não entre no if anterior, o número não foi encontrado, logo, retorna o erro de que o número não foi registrado
      return NAO_ENCONTRADO;
    }

  }
  printf("\nContato editado com sucesso! <3\n"); // //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função deletar
ERROS deletarpessoal(Contato pessoal[], int *pos) {
  if (*pos == 0) // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;

  int num_deletar; // define a variável que irá armazenar o número a ser deletado
  printf("Digite o número do contato a ser deletado: "); // pede variável e armazena no endereço dessa variável anterior
  scanf("%d", &num_deletar);

  int encontrado = 0; // define uma variável que irá verificar se o número foi encontrado na memória, encontrado = false

  for (int i = 0; i < *pos; i++) { // loop que percorre os structs criados
    if (pessoal[i].numero == num_deletar || encontrado) { // caso o contato do struct i seja igual ao número a ser deletado, ou o número já foi encontrado
      strcpy(pessoal[i].nome, pessoal[i + 1].nome); // copia as informações do próximo struct para o atual, sobrescrevendo  que vai ser deletado
      strcpy(pessoal[i].sobrenome, pessoal[i + 1].sobrenome);
      strcpy(pessoal[i].email, pessoal[i + 1].email);
      pessoal[i].numero = pessoal[i + 1].numero;
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

ERROS deletartrabalho(Contato trabalho[], int *pos) {
  if (*pos == 0) // caso o valor do ponteiro da posição for 0, não houve criação de contatos, logo, não há contatos a serem exibidos, então retorna erro SEM_CONTATOS
    return SEM_CONTATOS;

  int num_deletar; // define a variável que irá armazenar o número a ser deletado
  printf("Digite o número do contato a ser deletado: "); // pede variável e armazena no endereço dessa variável anterior
  scanf("%d", &num_deletar);


  int encontrado = 0; // define uma variável que irá verificar se o número foi encontrado na memória, encontrado = false

  for (int i = 0; i < *pos; i++) { // loop que percorre os structs criados
    if (trabalho[i].numero == num_deletar || encontrado) { // caso o contato do struct i seja igual ao número a ser deletado, ou o número já foi encontrado
      strcpy(trabalho[i].nome, trabalho[i + 1].nome); // copia as informações do próximo struct para o atual, sobrescrevendo  que vai ser deletado
      strcpy(trabalho[i].sobrenome, trabalho[i + 1].sobrenome);
      strcpy(trabalho[i].email, trabalho[i + 1].email);
      trabalho[i].numero = trabalho[i + 1].numero;
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
ERROS exportar_binariopessoal(Contato pessoal[], int pos) {
  FILE *arquivo = fopen("contatos_pessoais.bin", "wb"); // arquivo contatos.bin será criado para escrita e excluirá o arquivo já existente

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }
  int qtd = fwrite(pessoal, sizeof(Contato), pos, arquivo); // define uma variável qtde que será o tamanho do array de structs

  if (qtd != pos) { // caso o tamanho seja diferente da posição atual, siginifica que houve problemas na escrita do arquivo, logo ele será fechado e retornará o erro ESCREVER
    fclose(arquivo);
    return ESCREVER;
  }

  fclose(arquivo); // fecha o arquivo pois todos os contatos foram exportados
  printf("\nContatos exportados para arquivo binário com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS exportar_binariotrabalho(Contato trabalho[], int pos) {
  FILE *arquivo = fopen("contatos_trabalho.bin", "wb"); // arquivo contatos.bin será criado para escrita e excluirá o arquivo já existente

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }
  int qtd = fwrite(trabalho, sizeof(Contato), pos, arquivo); // define uma variável qtde que será o tamanho do array de structs

  if (qtd != pos) { // caso o tamanho seja diferente da posição atual, siginifica que houve problemas na escrita do arquivo, logo ele será fechado e retornará o erro ESCREVER
    fclose(arquivo);
    return ESCREVER;
  }

  fclose(arquivo); // fecha o arquivo pois todos os contatos foram exportados
  printf("\nContatos exportados para arquivo binário com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

// função carregar binário
ERROS carregar_binariopessoal(Contato pessoal[], int *pos) {
  FILE *arquivo = fopen("contatos_pessoais.bin", "rb"); // abre arquivo contatos.bin que já existe na pasta para leitura

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }

  int qtd = fread(pessoal, sizeof(Contato), TOTAL, arquivo); // define uma variável qtde que será o tamanho do array de structs lidos

  if (qtd <= 0) { // caso o tamanho do array seja diferente da quantidade de contatos lidos, siginifica que houve problemas na leitura do arquivo, logo ele será fechado e retornará o erro LER
    fclose(arquivo);
    return LER;
  }
  *pos = qtd; 

  fclose(arquivo); // fecha o arquivo pois todos os contatos foram lidos
  printf("\nContatos salvos de arquivo binário com sucesso! <3\n"); //retorna mensagem de sucesso e OK pois não encontrou erros
  return OK;
}

ERROS carregar_binariotrabalho(Contato trabalho[], int *pos) {
  FILE *arquivo = fopen("contatos_trabalho.bin", "rb"); // abre arquivo contatos.bin que já existe na pasta para leitura

  if (arquivo == NULL) { // caso valor do arquivo seja igual a NULL, significa que não foi possível abrir
    return ABRIR;
  }

  int qtd = fread(trabalho, sizeof(Contato), TOTAL, arquivo); // define uma variável qtde que será o tamanho do array de structs lidos

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