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

    int oi;

    printf("CPF:");
    scanf("%d", &oi);
    fgets(Usuario[Id].CPF, 30, stdin);
    Usuario[Id].CPF[strcspn(Usuario[Id].CPF,"\n")] = '\0';


    if(Id != 0)
    {
        for (int i = 0; i < Id ; i++)
        {
            if(strcmp(Usuario[Id-1].CPF, Usuario[Id].CPF) == 0)
            {
                printf("CPF ja Cadastrado.");
                return Id;
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

    printf("CPF:");
    fgets(Usuario[Id].CPF, 30, stdin);
    Usuario[Id].CPF[strcspn(Usuario[Id].CPF,"\n")] = '\0';

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
    for (int i = 0; i <= Id - 1; ++i)
    {
        if(strcmp(Usuario[i].CPF, Usuario[Id].CPF) == 0)
        {

           /* printf("CPF Excluido.");
            Usuario[Id].Name[] = "\0";
            Usuario[Id].email[] = "\0";
            Usuario[Id].Adress[] = "\0";
            Usuario[Id].CPF[] = "\0";
            Usuario[Id].Telefone[] = "\0";
            return 0;*/
        }
    }


    return 0;
}

int edit()
{
    return 0;
}

int print(int Id)
{
    printf("Nome: %s\n", Usuario[Id].Name);
    printf("Endereco: %s\n", Usuario[Id].Adress);
    printf("CPF: %s\n", Usuario[Id].CPF);
    printf("Telefone: %s\n", Usuario[Id].Telefone);
    printf("E-mail: %s\n", Usuario[Id].email);

    return 0;
}

int PrintAll(int id)
{
    for (int i = 0; i < id ; ++i)
    {
        print(i);
    }
    return 0;
}

int order()
{
    return 0;
}

