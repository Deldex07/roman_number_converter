#include <stdio.h>
#include <string.h>

int valor(char c);
int converter(char roman[]);
void intParaRomano(int num, char *res);

int main()
{
    int opcao;
    do
    {
        printf("\nEscolha a opção:\n");
        printf("1 - Romano para Inteiro\n");
        printf("2 - Inteiro para Romano\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 0)
            break;

        switch (opcao)
        {
        case 1:
        {
            char roman[20];
            printf("Digite o número romano: ");
            scanf("%s", roman);
            int numero = converter(roman);
            printf("Número: %d\n", numero);
            break;
        }
        case 2:
        {
            int numero;
            char resultado[20] = "";
            printf("Digite o número inteiro (1-3999): ");
            scanf("%d", &numero);
            if (numero < 1 || numero > 3999)
            {
                printf("Valor fora do intervalo!\n");
                break;
            }
            intParaRomano(numero, resultado);
            printf("Romano: %s\n", resultado);
            break;
        }
        default:
            printf("Opção inválida!\n");
        }
    } while (1);
    return 0;
}

int valor(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
    return 0;
}

int converter(char roman[])
{
    int i, total = 0;
    for (i = 0; roman[i] != '\0'; i++)
    {
        int atual = valor(roman[i]);
        int proximo = valor(roman[i + 1]);
        if (atual < proximo)
            total -= atual;
        else
            total += atual;
    }
    return total;
}

void intParaRomano(int num, char *res)
{
    struct Romano
    {
        int valor;
        const char *simbolo;
    } tabela[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    int i = 0;
    while (num > 0)
    {
        if (num >= tabela[i].valor)
        {
            strcat(res, tabela[i].simbolo);
            num -= tabela[i].valor;
        }
        else
        {
            i++;
        }
    }
}