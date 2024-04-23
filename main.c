#include <stdio.h>
#include "contatos.h"

int main() {
    Contato contatos[TOTAL];
    int pos = 0;
    int opcao;
    ERROS resultado;

  do {
    printf("\nMenu principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contatos\n");
    printf("5 - Exportar contatos para binário\n");
    printf("6 - Carregar contatos de binário\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    

    scanf("%d", &opcao);
    clearBuffer();
    switch (opcao) {
      case 1:
        resultado = criar(contatos, &pos);
        break;
      }
    } while (opcao != 0);
}