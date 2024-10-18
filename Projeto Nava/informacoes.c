#include <stdio.h>
#include <string.h>
#include "informacoes.h"

#define TAM 10
struct Pessoa
{
    char Name[80];
    char Adress[100];
    char CPF[30];
    char Telefone[30];
    char email[80];
};

typedef struct Pessoa User;
User Usuario [TAM];

int Add (int Id)
{

    printf("CPF:");
    fgets(Usuario[Id].CPF, 30, stdin);
    Usuario[Id].CPF[strcspn(Usuario[Id].CPF,"\n")] = '\0';

    if(Id != 0)
    {
        for (int i = 0; i < Id ; i++)
        {
            if(i != Id)
            {
                if(strcmp(Usuario[i].CPF, Usuario[Id].CPF) == 0)
                {
                    printf("CPF ja Cadastrado.");
                    return Id;
                }
            }
        }
    }

    printf("Preencha as informacoes a seguir:\n");

    printf("Nome:");
    fgets(Usuario[Id].Name, 80, stdin);
    Usuario[Id].Name[strcspn(Usuario[Id].Name,"\n")] = '\0';

    printf("Endereco:");
    fgets(Usuario[Id].Adress, 100, stdin);
    Usuario[Id].Adress[strcspn(Usuario[Id].Adress,"\n")] = '\0';

    printf("Telefone:");
    fgets(Usuario[Id].Telefone, 30, stdin);
    Usuario[Id].Telefone[strcspn(Usuario[Id].Telefone,"\n")] = '\0';

    printf("E-mail:");
    fgets(Usuario[Id].email, 100, stdin);
    Usuario[Id].email[strcspn(Usuario[Id].email,"\n")] = '\0';

    Id++;
    printf("\n%d EXEMPLO\n", Id);
    return Id;
}

int Delete(int Id)
{

    char cpfdigitado[30];

    printf("Digite o cpf:");
    fgets(cpfdigitado, 30, stdin);
    cpfdigitado[strcspn(cpfdigitado,"\n")] = '\0';

    for (int i = 0; i < Id; ++i)
    {
        if(strcmp(Usuario[i].CPF, cpfdigitado) == 0)
        {
            printf("Usuario excluido com sucesso!.");
            strcpy(Usuario[i].Name," ");
            strcpy(Usuario[i].email," ");
            strcpy(Usuario[i].Adress," ");
            strcpy(Usuario[i].CPF," ");
            strcpy(Usuario[i].Telefone," ");
        }
    }


    return 0;
}

int edit(int Id)
{
    char cpfdigitado[30];
    int boleano = 0;
    int escolha;
    char string[30];
    char opcao = 'z';

    printf("Digite o cpf:");
    fgets(cpfdigitado, 30, stdin);
    cpfdigitado[strcspn(cpfdigitado,"\n")] = '\0';
    
    for (int i = 0; i < Id; ++i)
    {
        if(strcmp(Usuario[i].CPF, cpfdigitado) == 0)
        {
            while (strcmp(string, "\n") != 0)
            {

                boleano = 1;
                printf("\n\nusuario encontrado \n");
                printf("1 - Nome: %s\n", Usuario[i].Name);
                printf("2 - Endereco: %s\n", Usuario[i].Adress);
                printf("3 - CPF: %s\n", Usuario[i].CPF);
                printf("4 - Telefone: %s\n", Usuario[i].Telefone);
                printf("5 - E-mail: %s\n", Usuario[i].email);
                //printf("6 - Sair\n");

                printf("Pressione 'Enter' Para sair\n\n");

                fgets(string, 30, stdin);
                //string[strcspn(Usuario[i].Name,"\n")] = '\0';
                opcao = string[0];

                //scanf("%s",&opcao);
                //sscanf(opcao, "%d", &escolha);

                switch (opcao)
                {
                    case '1':
                        printf("Novo nome: ");
                    fgets(Usuario[i].Name, 80, stdin);
                    Usuario[i].Name[strcspn(Usuario[i].Name,"\n")] = '\0';
                    break;

                    case '2':
                        printf("Novo Endereco: ");
                    fgets(Usuario[i].Adress, 80, stdin);
                    Usuario[i].Adress[strcspn(Usuario[i].Adress,"\n")] = '\0';
                    break;

                    case '3':
                        printf("Novo CPF: ");
                    fgets(Usuario[i].CPF, 80, stdin);
                    Usuario[i].CPF[strcspn(Usuario[i].CPF,"\n")] = '\0';
                    break;

                    case '4':
                        printf("Novo Telefone: ");
                    fgets(Usuario[i].Telefone, 80, stdin);
                    Usuario[i].Telefone[strcspn(Usuario[i].Telefone,"\n")] = '\0';
                    break;

                    case '5':
                        printf("Novo E-mail: ");
                    fgets(Usuario[i].email, 80, stdin);
                    Usuario[i].email[strcspn(Usuario[i].email,"\n")] = '\0';
                    break;

                   // case '6':
                       // return 0;

                }

                if(strcmp(string, "\n") == 0)
                {
                    return 0;
                }
            }
        }
    }

    if(boleano == 0)
    {
        printf("cpf nao encontrado:");
    }

    return 0;
}

int print(int Id)
{

    printf("\n");

    int escolha = 1000;
    char cpfPesquisa[30];

    printf("CPF:");
    fgets(cpfPesquisa, 30, stdin);
    cpfPesquisa[strcspn(cpfPesquisa,"\n")] = '\0';

    for (int i = 0; i < Id; ++i)
    {
        if(strcmp(Usuario[i].CPF, cpfPesquisa) == 0)
        {
           escolha = i;
        }
    }
    if(escolha == 1000)
    {
        printf("CPF nao cadastrado.");
        return Id;
    }

    printarEscolha(escolha);

    printf("\n");

    return 0;
}

int printarEscolha(int Id)
{
    if(strcmp(Usuario[Id].CPF, " ") != 0)
    {
        printf("\n");
        printf("Nome: %s\n", Usuario[Id].Name);
        printf("Endereco: %s\n", Usuario[Id].Adress);
        printf("CPF: %s\n", Usuario[Id].CPF);
        printf("Telefone: %s\n", Usuario[Id].Telefone);
        printf("E-mail: %s\n", Usuario[Id].email);
        printf("\n");
    }


    return 0;
}

int PrintAll(int id)
{
    for (int i = 0; i < id ; ++i)
    {
        printarEscolha(i);
    }
    return 0;
}

int order()
{

    return 0;
}

