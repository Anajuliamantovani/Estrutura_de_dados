#include <stdio.h>
#include <string.h>
#include "informacoes.h"

int Id = 0;
char opcao02[30];

//Hoje é domingo pé de cachimbo

//Maqueicou

//ado ado quem tiver lendo é viado
//birrento
int main()
{
    int opcao;
    int escolha;


    printf("\nEscolha uma das opcoes:\n");
    printf("=======================================================================");
    printf("\n 1. Adicionar \n 2. Excluir \n 3. Alterar \n 4. Imprimir\n 5. Imprimir Todos\n 6. Ordenar\n 7. Sair\n ");
    printf("=======================================================================\n");
    printf("Digite sua opcao: ");
    fgets(opcao02, 30, stdin);
    sscanf(opcao02, "%d", &opcao);

    switch (opcao)
    {
        case 1:
            Id = Add(Id);
            break;

        case 2:
            printf("Qual usuario deseja deletar ? \n");
            scanf("%d", &escolha);
            Delete(escolha);
            break;

        case 3:

            break;

        case 4:
            printf("Qual usuario deseja visualizar ? \n");
            print(Id);
            break;
        case 5:
            PrintAll(Id);
            break;

        case 6:
            break;

        case 7:
            return 0;

        default:
            //main();
            //return 0;
            opcao = 0;
    }
    main();
    return 0;
}
