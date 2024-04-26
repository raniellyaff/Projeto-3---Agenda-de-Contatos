#include <stdio.h> // inclusão de header de input e output
#include "contatos.h" // inclusão das assinaturas de funções 

int main() { // função principal com chamada de funções
  Contato contatos[TOTAL]; // struct definido
  int pos = 0; 
  int opcao; 
  ERROS resultado; 

  // faça essas operações até que o input recebido seja diferente de 0
  do {
    printf("\nMenu principal! <3\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("4 - Exportar contatos para binário\n");
    printf("5 - Carregar contatos de binário\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");

  // lê o que foi digitado pelo usuário
    scanf("%d", &opcao);
    clearBuffer();
  // entra nos cases com base no que foi digitado e armazena o retorno da função na variável resultado
    switch (opcao) {
      case 1:
        resultado = criar(contatos, &pos);
        break;
      case 2:
        resultado = listar(contatos, &pos);
        break;
      case 3:
        resultado = deletar(contatos, &pos);
        break;
      case 4:
        resultado = exportar_binario(contatos, pos);
        break;
      case 5:
        resultado = carregar_binario(contatos, &pos);
        break;
      case 0:
        printf("Saindo, tchaaauuu! <3...\n");
        resultado = OK;
        break;
      default:
        printf("A opção inserida é inválida!\n");
        resultado = OK;
        break;
    }
  // entra nos cases com base no retorno das funções, para printar caso os erros sejam encontrados
    switch (resultado) {
      case OK:
        break;
      case SEM_CONTATOS:
        printf("Não há contatos a serem listados! <3");
        break;
      case MAX_CONTATOS:
        printf("O número máximo de contatos foi atingido! <3");
        break;
      case NAO_ENCONTRADO:
        printf("O contato inserido não foi encontrado! <3");
        break;
      case ESCREVER:
        printf("Não foi possível escrever os dados no arquivo! <3");
        break;
      case ABRIR:
        printf("Não foi possível abrir o arquivo! <3");
        break;
      case LER:
        printf("Não foi possível ler o arquivo! <3");
        break;
      default:
        printf("Erro desconhecido! <3");
        break;
    }
  } while (opcao != 0);
}