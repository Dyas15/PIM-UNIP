#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>
#include <winuser.h>

void limpar()
{
    system("cls");
}

void cabecalho()
{
    printf("---------Museu DevWorld---------\n");
    printf("         Seja bem-vindo!\n\n");
}

int verificarCPF(char *cpf)
{
    int verificador1 = 0, verificador2 = 0;
    if (strlen(cpf) != 11)
    {
        return 0;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return 0;
        }
    }
    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 || strcmp(cpf, "22222222222") == 0 ||
        strcmp(cpf, "33333333333") == 0 || strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 || strcmp(cpf, "88888888888") == 0 ||
        strcmp(cpf, "99999999999") == 0)
    {
        return 0;
    }
    for (int numero = 0, multiplicador = 10; numero <= 8; numero++, multiplicador--)
    {
        verificador1 += (cpf[numero] - '0') * multiplicador;
    }
    verificador1 %= 11;
    if (verificador1 == 0 || verificador1 == 1)
    {
        verificador1 = 0;
    }
    else
    {
        verificador1 = 11 - verificador1;
    }
    if ((cpf[9] - '0') != verificador1)
    {
        return 0;
    }
    for (int numero = 0, multiplicador = 11; numero <= 9; numero++, multiplicador--)
    {
        verificador2 += (cpf[numero] - '0') * multiplicador;
    }
    verificador2 %= 11;
    if (verificador2 == 0 || verificador2 == 1)
    {
        verificador2 = 0;
    }
    else
    {
        verificador2 = 11 - verificador2;
    }
    if ((cpf[10] - '0') != verificador2)
    {
        return 0;
    }
    return 1;
}

int respG, resp1, resp2, resp3, resp4, resp5;
char cpf[11];
FILE *arquivo;

int main()
{
    system("title PIM - DevWorld");
    setlocale(LC_ALL, "Portuguese");

    while (1 != 0)
    {
        do
        {
            cabecalho();
            wprintf(L"Para encerrar sua visita em nosso museu, temos uma pesquisa de satisfação. Deseja participar?\n");
            wprintf(L"1) Sim\n2) Não\nR: ");
            scanf("%d", &respG);
            if (respG == 1)
            {
                do
                {
                    wprintf(L"Digite seu CPF sem traços ou pontuações: ");
                    scanf("%s", &*cpf);
                    if (verificarCPF(cpf))
                    {
                        limpar();
                        break;
                    }
                    else
                    {
                        limpar();
                        wprintf(L"CPF Inválido!");
                        Sleep(3000);
                        limpar();
                    }
                } while (1);
                wprintf(L"Ótimo, vamos começar.\nResponda as perguntas com 1 a 5 como um grau de satisfação.\nSendo 1 muito ruim e 5 muito bom.\n");
                system("pause");
                limpar();
                do
                {
                    wprintf(L"Em questao das obras, qual foi sua satisfação?\n");
                    scanf("%d", &resp1);
                    if (resp1 < 1 || resp1 > 5)
                    {
                        wprintf(L"Opção Inexistente\n");
                        respG = 2;
                        Sleep(4000);
                        limpar();
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                do
                {
                    wprintf(L"Na sua opinião as informações apresentadas foram úteis?\n");
                    scanf("%d", &resp2);
                    if (resp2 < 1 || resp2 > 5)
                    {
                        wprintf(L"Opção Inexistente\n");
                        Sleep(4000);
                        limpar();
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                do
                {
                    wprintf(L"O sistema foi de facil utilização?\n");
                    scanf("%d", &resp3);
                    if (resp3 < 1 || resp3 > 5)
                    {
                        wprintf(L"Opção Inexistente\n");
                        Sleep(4000);
                        limpar();
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                do
                {
                    wprintf(L"Você voltaria para rever esse tema?\n");
                    scanf("%d", &resp4);
                    if (resp4 < 1 || resp4 > 5)
                    {
                        wprintf(L"Opção Inexistente\n");
                        Sleep(4000);
                        limpar();
                    }
                    else
                    {
                        break;
                    }
                } while (1);

                do
                {
                    wprintf(L"Você indicaria essa exposição a um amigo ou colega?\n");
                    scanf("%d", &resp5);
                    if (resp5 < 1 || resp5 > 5)
                    {
                        wprintf(L"Opção Inexistente\n");
                        Sleep(4000);
                        limpar();
                    }
                    else
                    {
                        break;
                    }
                } while (1);
                limpar();
                printf("Acabou\nObrigado por nos visitar, volte sempre!\n");
                Sleep(4000);
                arquivo = fopen("satisfacao_museu.csv", "a");
                fprintf(arquivo, "%s;%d;%d;%d;%d;\n", cpf, resp1, resp2, resp3, resp4);
                fclose(arquivo);
            }
            else if (respG == 2)
            {
                limpar();
                cabecalho();
                printf("Obrigado por nos visitar, volte sempre!\n");
                Sleep(3000);
                limpar();
                break;
            }
            else
            {
                limpar();
                cabecalho();
                wprintf(L"Opção inexistente\n");
                Sleep(2000);
                limpar();
            }
        } while (1);
    }
}