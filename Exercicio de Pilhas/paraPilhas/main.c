#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Variavel Global

double valores[30]; //pilha dos numeros
char operadores[30]; //pilha dos operadores
int contValor=0; //contador para contar os numeros da pilha valores

//Codigo do Nava

//retorna true ou false caso o Operador no momento tenha maior importancia
bool mesmaOuMaiorPrecedencia(char op1, char op2) {
    if(op2 == '(' || op2 == ')')
    {
        return false;
    }
    if((op1 == '*' || op1 == '/') &&
       (op2 == '+' || op2 == '-'))
    {
        return false;
    }
    else
    {
        return true;
    }
}

//encontra uma função expecifica
bool find(char letra, char *str)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == letra)
        {
            return true;
        }
    }
    return false;
}

//trasforma a string em um vetor. ps: numeros com 2 casas decimais vão para uma oposição do vetor
void stringParaVetor(char *line, char vec[][20], int tamanho)
{
    char trab[tamanho];
    char operacoes[] = "+-*/()";
    char letra;
    bool numero = false;
    bool str = false;
    int vecI = 0;
    int aux = 0;
    strcpy(trab, "");

    for(int i = 0; i < tamanho; i++)
    {
        letra = line[i];
        if((isdigit(letra) || letra=='.')  && !str)
        {
            if(!numero)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                }
                numero = true;
                str = false;
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
        }
        else if(letra == ' ')
        {
            if(!str)
            {
                if(strlen(trab)!=0)
                {
                    strcpy(vec[vecI++],trab);
                    strcpy(trab, "");
                    numero = false;
                    str = false;
                }
            }
        }
        else if(find(letra, operacoes) != 0)
        {
            if(strlen(trab)!=0)
            {
                strcpy(vec[vecI++],trab);
                strcpy(trab, "");
            }
            aux = strlen(trab);
            trab[aux] = letra;
            trab[aux+1] = '\0';
            strcpy(vec[vecI++],trab);
            strcpy(trab, "");
            numero = false;
            str = false;
        }
    }
    if(strlen(trab)!=0)
    {
        strcpy(vec[vecI++],trab);
    }
}

//funão criada para limpar o vetor
void limpaVetor(char v[][20], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        strcpy(v[i], "");
    }
}

//codigo feito por nos

//função usada para retornar o tamanha do vetor Valores
int tamanhoValores()
{
    int contador = 0;
    for (int i = 0; i < 30; ++i)
    {
        if(valores[i] != 0)
        {
            contador++;
        }
    }
    return contador;
}

//função criada para verificar de o vetor(pilha) valores esta vazia ou não
bool checarPilhaValor(double TbValores[30])
{
    if(strlen(TbValores) == 0)
    {
        return  true;
    }
    else
    {
        return  false;
    }
}

//função criada para verificar de o vetor(pilha) operadores esta vazia ou não
bool checarPilhaOperadores(char Tboperadores[30])
{
    if(strlen(Tboperadores) == 0)
    {
        return  true;
    }
    else
    {
        return  false;
    }
}

//função criada para retonar o ultima valor do vetor(pilha) Operadores
char ultimaCharOperadores(char Tboperadores[30])
{
    int ultimoCaracter;
    ultimoCaracter = strlen(Tboperadores)-1;
    return Tboperadores[ultimoCaracter];
}

//função criada para retonar o ultima valor do vetor(pilha) valores
double ultimaDoubleValores()
{
    int ultimoCaracter;
    ultimoCaracter = contValor-1;
    return valores[ultimoCaracter];
}


//função criada para retornar o resustado do calculo dos valores com a operador
void calcular()
{
    char Operador = '\0';
    double n1 = 0;
    double n2 = 0;
    Operador = ultimaCharOperadores(operadores);
    int qtdOperadores = strlen(operadores);
    operadores[qtdOperadores-1] = '\0';
    //int qtdValores = strlen(valores);
    n1 = ultimaDoubleValores();
    valores[contValor - 1] = 0;
    contValor--;
    n2 = ultimaDoubleValores();
    valores[contValor  - 1] = 0;
    contValor--;

    double resultado = 0;

    switch(Operador)
    {
        case '+':
            resultado = n2 + n1;
            break;
        case '-':
            resultado = n2 - n1;
            break;
        case '*':
            resultado = n2 * n1;
            break;
        case '/':
            resultado = n2 / n1;
            break;

    }

    valores[contValor] = resultado;
    contValor++;

}

//função criada para verificar se a string é um numero
bool isNumeric(const char *str)
{
    bool hasDecimalPoint = false;
    bool hasDigits = false;

    if (*str == '\0')
    {
        return false;
    }
    while (*str)
    {
        if (*str == '.')
        {
            if (hasDecimalPoint)
            {
                return false;
            }
            hasDecimalPoint = true;
        }
        else if (isdigit(*str))
        {
            hasDigits = true;
        }
        else
        {
            return false;
        }
        str++;
    }
    return hasDigits;
}

//O codigo começa por aqui
int main()
{
    char *endptr;
    char exp[100] = "";
    char vec[100][20] = {'\0'};
    limpaVetor(vec, 100);
    printf("Digite qualquer operacao ex:'(( 22 + 5 ) * 2 ) / 3' retorna resposta: \n");
    fgets(exp, sizeof(exp), stdin);
    stringParaVetor(exp, vec, 100);

    //Partir daqui seguen o passo a passo do professor nos slides
    for(int i = 0; i < 100 && (strcmp(vec[i], "") !=  0); i++)
    {
        if(isNumeric(vec[i]))
        {
            valores[contValor] =  strtod(vec[i], &endptr);
            contValor++;
        }
        else if(vec[i][0] == '(')
        {
            operadores[strlen(operadores)] = vec[i][0];
        }
        else if(vec[i][0] == ')')
        {
            while (ultimaCharOperadores(operadores) != '(')
            {
                calcular();
            }
            operadores[strlen(operadores)-1] = '\0';
        }
        else
        {
            while (checarPilhaOperadores(operadores) == false && mesmaOuMaiorPrecedencia(vec[i][0], operadores[strlen(operadores)-1]))
            {
                calcular();
            }
            operadores[strlen(operadores)] = vec[i][0];
        }
    }
    while (checarPilhaOperadores(operadores) == false)
    {
        calcular();
    }
    printf("\n%.2f\n",valores[0]); //sobrou apenas uma variavel na pilha valores e ela sera mostrada;
    return 0;
}
