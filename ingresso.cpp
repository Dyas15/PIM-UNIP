// Importa as bibliotecas
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <windows.h>

// Define o valor dos ingressos como constantes
// Não necessario definir o valor do ingresso de Isento pois é 0
#define inteira 30
#define meia 15

// Função assincrona que se acionada, executa o comando para limpar tela
void limparTela()
{
    // Envia o comando para limpar o terminal
    system("cls");
}

void cabecalho()
{
    printf("---------Museu DevWorld---------\n");
    printf("         Seja bem-vindo!\n\n");
}

// Função para verificar o CPF
int verificarCPF(char *cpf)
{
    // Declaração de variaveis para guardar os numeros verificadores
    // São os numeros finais xxx.xxx.xxx-VV
    int verificador1 = 0, verificador2 = 0;
    // Se o tamanho do CPF for diferente de 11, então ele retorna inválido
    if (strlen(cpf) != 11)
    {
        return 0;
    }

    // Irá fazer um laço para cada digito
    for (int i = 0; i < 11; i++)
    {
        // Função isdigit serve para verificar se todos os valores do CPF são numeros e não outros caracteres.
        if (!isdigit(cpf[i]))
        {
            return 0;
        }
    }

    // Função strcmp serve para comparar uma string com outra string
    // Nesse caso é necessario pois o calculo do CPF não cobre numeros repetidos e deixa passar
    // Caso seja digitado algum CPF dessa lista, retornará falso
    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 || strcmp(cpf, "22222222222") == 0 ||
        strcmp(cpf, "33333333333") == 0 || strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 || strcmp(cpf, "88888888888") == 0 ||
        strcmp(cpf, "99999999999") == 0)
    {
        return 0;
    }

    // Calculo do 1 digito verificador
    // O calculo se resume a você multiplicar de 10 ao 1 cada numero do cpf em sequencia
    // Ex: CPF: 837.735.680 com os digitos verificadores 53
    // 8*10 + 3*9 + 7*8 + 7*7 + 3*6 + 5*5 + 6*4 + 8*3 + 0*2 == 303
    for (int numero = 0, multiplicador = 10; numero <= 8; numero++, multiplicador--)
    {
        verificador1 += (cpf[numero] - '0') * multiplicador;
    }

    // Após calcular a soma de todas as multiplicações, fazemos a divisão pelo total de numeros do cpf e recebemos o resto da divisão
    verificador1 %= 11;
    // Caso o resto da divisão for 0 ou 1, então o digito verificador será automaticamente 0
    if (verificador1 == 0 || verificador1 == 1)
    {
        verificador1 = 0;
    }
    else
    {
        // Caso o resto da divisão seja maior que 1, então é feito a conta da quantidade de numeros em um cpf
        // menos o resultado do resto da divisão
        // Nesse exemplo, resultando em 5, que está correto
        verificador1 = 11 - verificador1;
    }

    // Verificação necessaria para comparar se o primeiro digito verificador do cpf é igual ao calculado
    // Caso não seja, retornará falso
    if ((cpf[9] - '0') != verificador1)
    {
        return 0;
    }

    // Calculo do 2 digito verificador
    // O calculo se resume a você multiplicar de 11 ao 1 cada numero do cpf em sequencia
    // A diferença desse para o primeiro digito verificador é que agora usamos o primeiro digito verificador na conta
    // 8*11 + 3*10 + 7*9 + 7*8 + 3*7 + 5*6 + 6*5 + 8*4 + 0*3 + 5*2  == 360
    for (int numero = 0, multiplicador = 11; numero <= 9; numero++, multiplicador--)
    {
        verificador2 += (cpf[numero] - '0') * multiplicador;
    }

    // Após calcular a soma de todas as multiplicações, fazemos a divisão pelo total de numeros do cpf e recebemos o resto da divisão
    verificador2 %= 11;

    // Caso o resto da divisão for 0 ou 1, então o digito verificador será automaticamente 0
    if (verificador2 == 0 || verificador2 == 1)
    {
        verificador2 = 0;
    }
    else
    {
        // Caso o resto da divisão seja maior que 1, então é feito a conta da quantidade de numeros em um cpf
        // menos o resultado do resto da divisão
        // Nesse exemplo, resultando em 3, que está correto

        verificador2 = 11 - verificador2;
    }

    // Verificação necessaria para comparar se o primeiro digito verificador do cpf é igual ao calculado
    // Caso não seja, retornará falso
    if ((cpf[10] - '0') != verificador2)
    {
        return 0;
    }
    // Caso a validação não for interrompida por nenhum erro, ele retorna true
    return 1;
}

// Inicio
int main()
{
    FILE *arquivo;

    // A função setLocale serve para tratar o problema referente as acentuções não permitidas
    setlocale(LC_ALL, "Portuguese");

    // Seta o titulo do console como 'PIM - DevWorld'
    system("title PIM - DevWorld");

    // Função para fazer o mouse ficar desativado devido ao inutilização dele no console
    // Evitando problemas com clicks indevidos
    ShowCursor(FALSE);

    // Devido a compra de ingressos estar sempre disponivel, não será necessario o script terminar. Por isso ficará em looping infinito
    while (1)
    {
        // Declara as variaveis tipo para a escolha do ingresso
        // E quantidade para a quantidade de ingressos
        int tipo = 0, quant = 0, escolha = 0, tema = 0, cont = 0, idade = 0, valor = 0;
        bool tema1 = 0, tema2 = 0, tema3 = 0, tema4 = 0;
        char nome[60], cpf[11];

        limparTela();
        // LGDP
        wprintf(L"Prezado(a) usuário(a),\nRespeitamos a sua privacidade e estamos comprometidos em proteger os seus dados pessoais.\n\n");
        wprintf(L"De acordo com a Lei Geral de Proteção de Dados (LGPD), precisamos da sua autorização para coletar, armazenar e utilizar as suas informações pessoais.\n\n");
        wprintf(L"Essas informações serão usadas exclusivamente para melhorar a sua experiência em nossa plataforma e garantir que nossos serviços atendam às suas necessidades da melhor maneira possível.\n\n");
        wprintf(L"Ao aceitar os termos, você concorda com a coleta e uso de suas informações conforme descrito acima.\n\n");
        wprintf(L"Você pode retirar seu consentimento a qualquer momento.\n\n");
        wprintf(L"Você aceita?\n1)Sim\n2)Não\nR:");
        scanf("%1d", &escolha);
        // Se a pessoa aceitar os termos, irá seguir com a compra dos ingressos
        if (escolha == 1)
        {
            limparTela();
            cabecalho();
            printf("Digite seu nome: ");
            scanf(" %99[^\n]", nome);

            limparTela();

            // Irá ficar repetindo até a pessoa colocar um CPF valido
            do
            {
                cabecalho();
                wprintf(L"Digite seu CPF sem traços ou pontuações: ");
                scanf("%s", cpf);
                // Chama a função verificarCPF passando o cpf escrito pela pessoa.
                // Uma função IF sempre retornara apenas valores booleanos
                // Então, quando colocamos a função verificarCPF sem verificação de valores (EX: verificarCPF(cpf) == true)
                // automaticamente irá verificar se é verdadeiro ou falso o resultado da função

                if (verificarCPF(cpf))
                {
                    // Sai do loop
                    break;
                }
                else
                {
                    // Limpa a tela
                    limparTela();
                    wprintf(L"CPF Inválido!");
                    // Espera por 3 segundos
                    Sleep(3000);
                    // Auto-explicativo
                    limparTela();
                }
                // O loop é infinito até a pessoa colocar o CPF corretamente
            } while (1);

            // Auto-explicativo
            limparTela();

            do
            {
                cabecalho();
                printf("Digite sua idade: ");
                scanf("%d", &idade);

                if ((idade < 1) || (idade > 99))
                {
                    wprintf(L"Idade inválida!\n");
                }
                else
                {
                    break;
                }
            } while (1);

            // Auto-explicativo
            limparTela();

            tipo = 0;

            if (idade < 60)
            {
                do
                {
                    cabecalho();
                    printf("Escolha seu ingresso:\n\n");
                    printf("1) Inteiro\n");
                    printf("2) Meio\n\n");
                    printf("Digite o tipo de ingresso: ");
                    scanf("%d", &tipo);
                    if (tipo != 1 && tipo != 2)
                    {
                        limparTela();
                        wprintf(L"Opção inexistente!\n");
                        Sleep(1000);
                        limparTela();
                    }
                } while (tipo != 1 && tipo != 2);
            }
            do
            {
                if (tema1 != 1 || tema2 != 1 || tema3 != 1 || tema4 != 1)
                {
                    // Auto-explicativo
                    limparTela();
                    cabecalho();
                    printf("Temas\n\n");
                    printf("1)100 anos da semana de arte moderna\n");
                    printf("2)150 anos de Santos Dumont\n");
                    wprintf(L"3)Jogos olímpicos de París 2024\n");
                    wprintf(L"4)Arte Periférica\n");
                    wprintf(L"\nDigite qual tema você irá ver: ");
                    scanf("%d", &tema);
                    if (tema < 1 || tema > 4)
                    {
                        wprintf(L"Opção inexistente!\n");
                        // Faz esperar por 1 segundo
                        Sleep(1000);
                        // Limpa a tela
                        limparTela();
                        escolha = 1;
                    }
                    else if ((tema == 1 && tema1 == 1) || (tema == 2 && tema2 == 1) || (tema == 3 && tema3 == 1) || (tema == 4 && tema4 == 1))
                    {
                        // Auto-explicativo
                        limparTela();
                        printf("Tema repetido!\nPor favor, escolha outro tema!\n");
                        Sleep(3500);
                        limparTela();
                    }
                    else
                    {
                        cont++;
                        switch (tema)
                        {
                        case 1:
                            tema1 = 1;
                            break;
                        case 2:
                            tema2 = 1;
                            break;
                        case 3:
                            tema3 = 1;
                            break;
                        case 4:
                            tema4 = 1;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
                if (tema1 != 1 || tema2 != 1 || tema3 != 1 || tema4 != 1)
                {
                    wprintf(L"\nDeseja escolhar outro tema?\n1)Sim\n2)Não\nR: ");
                    scanf("%d", &escolha);
                }
            } while (escolha != 2);
            // Limpa a tela
            limparTela();

            cabecalho();
            printf("Digite a quantidade de ingressos desejados para cada tema: ");
            scanf("%d", &quant);

            limparTela();

            cabecalho();
            if (tipo == 1 && idade <= 60)
            {
                wprintf(L"Você escolheu o ingresso com valor inteiro!\n");
                valor = inteira * cont * quant;
                printf("O total de %d ingresso(s) com valores inteiros com %d tema(s) ficou: R$%d\n", quant, cont, valor);
                Sleep(10000);
            }
            else if (tipo == 2 && idade <= 60)
            {
                wprintf(L"Você escolheu o ingresso com meio valor!\n");
                valor = meia * cont * quant;
                printf("O total de %d ingresso(s) com metade do valor com %d tema(s) ficou: R$%d\n", quant, cont, valor);
                wprintf(L"Apresente seu documento no caixa para validar seu ingresso!\n");
                Sleep(10000);
            }
            else
            {
                wprintf(L"Você escolheu o ingresso isento!\n");
                wprintf(L"Vá ao caixa e apresente seu RG para validar sua isenção!");
                Sleep(20000);
            }

            arquivo = fopen("registro_museu.csv", "a");
            fwrite(cpf, sizeof(char), sizeof(cpf), arquivo);
            fprintf(arquivo, ";%s;%d;%d;%d;%d;%d;%d;%d;%d\n", nome, idade, tipo, quant, valor,tema1, tema2, tema3, tema4);
            fclose(arquivo);
        }
        else
        {
            limparTela();
            cabecalho();
            wprintf(L"Você só poderá usar o sistema caso aceitar os termos de uso.\n\n");
            printf("Obrigado por usar os sistemas da DevWorld!");
            Sleep(3500);
            limparTela();
        }
    }
}