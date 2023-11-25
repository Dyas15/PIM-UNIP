#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int pesq, res[4], temas[4];
char cpf[11], nome[50];

// Função assincrona que, se acionada, executa o comando para limpar a tela
void limparTela()
{
    // Envia o comando para limpar o terminal
    system("cls");
}

void pergunta(const wchar_t *texto)
{
    // Printa o cabeçalho
    printf("---------Museu DevWorld---------\n");
    // Verificar se "nome" não está vazio antes de imprimir. Serve para imprimir o cabeçalho com o nome caso exista
    if (*nome != '\0')
    {
        printf("  Seja bem-vindo, %s!\n\n", nome);
    }
    else
    {
        printf("         Seja bem-vindo!\n\n");
    }

    wprintf(L"%s", texto);
}

void aviao()
{
    limparTela();
    pergunta(L"");

    printf("     ____                              \n");
    printf("     \\\\  `.                            \n");
    printf("      \\\\   `.                          \n");
    printf("       \\ \\   `.                        \n");
    printf("        \\\\    `.                       \n");
    printf("        :. . . . `._______________________.-~|~~-._ \n");
    printf("        \\                                 ---'-----`-._\n");
    printf("         /\"\"\"\"\"\"/             _...---------..         ~-._________\n");
    printf("        //     .`_________  .-`           \\ .-~           /\n");
    printf("       //    .'       ||__.~             .-~_____________/\n");
    printf("      //___.`           .~            .-~\n");
    printf("                      .~           .-~\n");
    printf("                    .~         _.-~\n");
    printf("                    `-_____.-~'\n");

    system("Pause");

    Sleep(1000);
    limparTela();
    pergunta(L"Tema relacionado a 1\n");
    system("pause");
}

void periferia()
{
    limparTela();
    pergunta(L"");
    setlocale(LC_ALL, "");

    wprintf(L"                                         ,______________,\n");
    wprintf(L"                                     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n");
    wprintf(L"                                 ,¦¦¦¯¯                  ¯¯¦¦_\n");
    wprintf(L"                                _¦¦¯                        ¦¦¦\n");
    wprintf(L"                               ¦¦¦¯                          ¦¦¦\n");
    wprintf(L"              ,___¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¬  ¦¦¦¦¦¦¦¦¦¦,\n");
    wprintf(L"           ,¦¦¦¦¦¯¯¯¯`¯¦¦¦   ¦¦¯                             ¯¦¦\n");
    wprintf(L"           ¦¦¦         ¦¦¦___¦¦¦                               -¦¦\n");
    wprintf(L"           ¦¦¦___¦¦¦¦¦¦¦¦¦¦¯¯¦¦¦   __________     __________   _¦¦\n");
    wprintf(L"  ,¦¦¦¦¦¦¦¦¦¦¯¯¯¯¯`          ¦¦¦_¦¦¦¯¯¯¯¯¯¯¦¦__¦¦¦¯¯¯¯¯¯¯¦¦_¦¦¦\n");
    wprintf(L" ¦¦¦¯¯¯¦¦                    _¦¦¦¦¦¦        ¦¦¦¦¦¦¦        ¦¦¦¦¦¦¦\n");
    wprintf(L" ¦¦¦   ¦¦¦      ¦¦¦¦¦¦¦¦,  ¦¦¦  ¦¦        ¦¦   ¦¦        ¦¦  ,¦¦\n");
    wprintf(L"  ¦¦¦  ¦¦¦    ,¦¦¦¯'¦¦¦_¦¦¦¦ ¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯\n");
    wprintf(L"  ¦¦¦  ¦¦¦    ¦¦¦¦_ ,¦¦¦¦¦¦¦¦   ¦¦¦¦¦                     ¦¦¦`\n");
    wprintf(L"  ¦¦¦   ¦¦¦   ¦¦¦¦¦¦¦¦¯¯¦¦¦¦¦    ¦¦¦¦,                    ¦¦¦\n");
    wprintf(L"   ¦¦¦  ¦¦¦   ¯¦¦¦¦¦¦¦_  ¦¦¦¦    ¦¦¦¦¦_     ¦¦_¦¦     _¦¦¯\n");
    wprintf(L"   ¦¦¦  ¦¦¦    ¯¦¦¦¦¦¦¦¦¦¦¦`     ¦¦¦_¦¦¦_     ¯¯¯     _¦¦¦¦\n");
    wprintf(L"   ¦¦¦   ¦¦¦      ¯¯¯¯¯¯¯        ,¦¦¦¦¯¯¦¦¦¦______¦¦¦¦¯¯¦¦¦\n");
    wprintf(L"    ¦¦¦  ¦¦¦           ,____¦¦¦¦¦¦¦¦    ¦¦¦¯¯¦¦¦¦¯¦¦¦    ¦¦¦¦_\n");
    wprintf(L"    ¦¦¦  ¦¦¦___¦¦¦¦¦¦¦¦¦¦¯¯¯¦¦¦¦¦¦¦¦    ¦¦¦       ¦¦¦    _¦¦¯¯¦¦¦,\n");
    wprintf(L"     ¯¦¦¦¦¦¦¦¯¯¯¯¯¦¦_    _¦¦¦¦¯   ¯¦¦¦  ¦¦¦_   ,¦¦¦  ¦¦¦¦'    ¯¦¦¦\n");
    wprintf(L"         ¦¦¦_     `¦¦¦¦¦¦¦¯¯-        ¯¯¦¦¦_¯¦¦¦_¦¦¦¯_¦¦¦¯¯         `¯¦¦_\n");
    wprintf(L"          ¦¦¦       ¦¦¦¯        ,_       ¯¦¦¦¦¦¦¦¦¦¦¦¯`      __       ¯¦¦_\n");
    wprintf(L"           ¦¦¦       ¦¦¦        ¯¦¦         ¦¦¯`¯¦¦¦        ¦¦¦        `¦¦¦\n");
    wprintf(L"           ¦¦¦        ¯¯-        ¦¦¦        ¦¦¦_¦¦`       ¦¦¦           ¯¦¦\n");
    wprintf(L"            ¦¦¦                 ,¦¦¦        '¯¦¦¦¯          ¦¦¦           ¦¦¦_\n");
    wprintf(L"             ¦¦¦_            __¦¦¦¦           ¦¦¦           ¦¦¦            ¦¦¦µ\n");
    wprintf(L"              ¯¦¦¦__,, ,,__¦¦¦¯¦¦¦            ¦¦¦            ¦¦¦            ¦¦¦\n");
    wprintf(L"                 ¯¯¦¦¦¦¦¦¦¯¯-  ¦¦¦            ¦¦¦            ¦¦¦__¦¦¦¦¦     ¦¦¦\n");
    wprintf(L"                              ¦¦¦             ¦¦¦           __¦¦¦¦¯¯-      ,¦¦¦\n");
    wprintf(L"                             ¦¦¦¦¦¦¦¦¦¦¦_     ¦¦¦      ¦¦¦¦¦¦¦¦¦          _¦¦¯\n");
    wprintf(L"                             ¦¦¦       ¦¦     ¦¦¦       ¦¦¦  `¦¦¦      ,_¦¦¦¯\n");
    wprintf(L"                             ¦¦¦       ¦¦     ¦¦¦        ¦¦¦  ¦¦¦,__¦¦¦¦¯'\n");
    wprintf(L"                            ¯¦¦,      ¦¦     ¦¦¦         ¦¦¦,_¦¦¦¦¦¯¯\n");
    wprintf(L"                             ¯¦¦¦____¦¦___¦¦¦_________¦¦¦¦¦¯`\n");
    wprintf(L"                             '¯¯¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¯¯¯							\n");
    system("pause");

    setlocale(LC_ALL, "Portuguese");

    Sleep(1000);
    limparTela();
    pergunta(L"Tema relacionado a 2\n"); // informações importadas do arquivo txt para esse tema
    system("pause");
}

int procurarCSV(char *pesquisa, int *temas)
{
    FILE *arquivo = fopen("registro_museu.csv", "r");

    char linha[100];

    while (fgets(linha, sizeof(linha), arquivo))
    {
        char *cpf = strtok(linha, ";");
        if (strstr(cpf, pesquisa) != NULL)
        {
            strncpy(nome, strtok(NULL, ";"), sizeof(nome) - 1);
            nome[sizeof(nome) - 1] = '\0';
            for (int i = 0; i < 8; i++)
            {
                if (i < 4)
                {
                    atoi(strtok(NULL, ";"));
                }
                else
                {
                    temas[i - 4] = atoi(strtok(NULL, ";"));
                }
            }
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

void restricaoAcesso(char *cpf)
{

    FILE *arquivo;
    char linha[1000];
    arquivo = fopen("registro_museu.csv", "r+");

    // Percorre cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Verifica se a linha contém o CPF procurado
        if (strstr(linha, cpf) != NULL)
        {
            // Encontramos o CPF, agora substituímos os últimos quatro números
            int tamanho = strlen(linha);
            for (int i = tamanho - 8; i < tamanho; i++)
            {
                if (linha[i] >= '0' && linha[i] <= '9')
                {
                    linha[i] = '9';
                }
            }

            // Move o cursor para o início da linha no arquivo
            fseek(arquivo, -tamanho, SEEK_CUR);

            // Escreve a linha modificada de volta no arquivo
            fputs(linha, arquivo);

            break; // Como encontramos o CPF, podemos sair do loop
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
}

int main()
{
    // A função setLocale serve para tratar o problema referente às acentuações não permitidas
    setlocale(LC_ALL, "Portuguese");
    do
    {
        do
        {
            limparTela();
            pergunta(L"Insira o seu CPF, por favor!\n");
            scanf(" %11[^\n]", cpf); // Limitar a entrada do CPF para 11 caracteres

            if (procurarCSV(cpf, temas))
            {
                break;
            }
            else
            {
                limparTela();
                wprintf(L"CPF inválido ou não cadastrado!");
                Sleep(3500);
            }
        } while (1);

        if (temas[0] == 1) // utilizado para valização dos ingressos 1 verdadeiro 0 falso
        {
            aviao();
        }

        if (temas[1] == 1) // utilizado para valização dos ingressos 1 verdadeiro 0 falso
        {
            periferia();
        }

        if (temas[2] == 1)
        { // utilizado para valização dos ingressos 1 verdadeiro 0 falso
            limparTela();
            pergunta(L"Tema relacionado a 3\n"); // informações importadas do arquivo txt para esse tema
            system("pause");
        }

        if (temas[3] == 1)
        { // utilizado para valização dos ingressos 1 verdadeiro 0 falso
            limparTela();
            pergunta(L"Tema relacionado a 4\n"); // informações importadas do arquivo txt para esse tema
            system("pause");
        }

        restricaoAcesso(cpf);
        limparTela();
        if (temas[0] == 9 && temas[1] == 9 && temas[2] && temas[3] == 9)
        {
            pergunta(L"Você não tem temas disponiveis para serem visualizados!\nObrigado por visitar o nosso museu!");
        }
        else
        {
            pergunta(L"\nObrigado por visitar o nosso museu!");
        }

        Sleep(7000);
    } while (1);
}
