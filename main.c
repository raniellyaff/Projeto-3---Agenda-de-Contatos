#include <stdio.h> // inclusão de header de input e output
#include "contatos.h" // inclusão das assinaturas de funções 

int main() { // função principal com chamada de funções
  Contato pessoal[TOTAL]; // struct definido
  Contato trabalho[TOTAL];
  int pos = 0; 
  int opcao; 
  ERROS resultado; 

  // faça essas operações até que o input recebido seja diferente de 0
  do {
    printf("\nMenu principal! <3\n");
    printf("");
    printf("\n CONTATOS PESSOAIS ! <3\n");
    printf("1 - Adicionar contato pessoal\n");
    printf("2 - Listar contatos pessoais\n");
    printf("3 - Editar contatos pessoais\n");
    printf("4 - Deletar contato pessoal\n");
    printf("5 - Exportar contatos pessoais para binário\n");
    printf("6 - Carregar contatos pessoais de binário\n");
    printf("");
    printf("\n CONTATOS DE TRABALHO ! <3\n");
    printf("7 - Adicionar contato de trabalho\n");
    printf("8 - Listar contatos de trabalho\n");
    printf("9 - Editar contato de trabalho\n");
    printf("10 - Deletar contato de trabalho\n");
    printf("1 - Exportar contatos de trabalho para binário\n");
    printf("12 - Carregar contatos de trabalho de binário\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");

  // lê o que foi digitado pelo usuário
    scanf("%d", &opcao);
    clearBuffer();
  // entra nos cases com base no que foi digitado e armazena o retorno da função na variável resultado
    switch (opcao) {
      case 1:
        resultado = criarpessoal(pessoal, &pos);
        break;
      case 2:
        resultado = listarpessoal(pessoal, &pos);
        break;
      case 3:
        resultado = editarpessoal(pessoal, &pos);
        break;
      case 4:
        resultado = deletarpessoal(pessoal, &pos);
        break;
      case 5:
        resultado = exportar_binariopessoal(pessoal, pos);
        break;
      case 6:
        resultado = carregar_binariopessoal(pessoal, &pos);
        break;
      case 7:
        resultado = criartrabalho(trabalho, &pos);
        break;
      case 8:
        resultado = listartrabalho(trabalho, &pos);
        break;
      case 9:
        resultado = editartrabalho(trabalho, &pos);
        break;
      case 10:
        resultado = deletartrabalho(trabalho, &pos);
        break;
      case 11:
        resultado = exportar_binariotrabalho(trabalho, pos);
        break;
      case 12:
        resultado = carregar_binariotrabalho(trabalho, &pos);
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
      case EMAIL_INVALIDO:
        printf("\nE-mail inválido! <3\n");
        break;
      case NUMERO_EXISTE:
        printf("\nNúmero já existe! Tente novamente <3\n");
        break;
      default:
        printf("Erro desconhecido! <3");
        break;
    }
  } while (opcao != 0);
}