#include <stdio.h>

// calcula e retorna a média aritmética das três leituras
double calcularMedia(double a, double b, double c){
    double media = (a + b + c) / 3;
    return media; 
}

// Compara as três leituras e retorna a maior delas
double encontrarMaximo(double a, double b, double c){
    double maximo;
    if (a > b){
        maximo = a; // se A e B forem iguais, tanto faz qual passa. Como a = b, o if é falso, e vai direto pro else.
    } else {
        maximo = b;
    }
    if (c > maximo){
        maximo = c;
    }
    return maximo;
}

// Compara as três leituras e retorna a menor delas
double encontrarMinimo(double a, double b, double c){
    double minimo;
    if (a < b){
        minimo = a; // se A e B forem iguais, tanto faz qual passa. Como a = b, o if é falso, e vai direto pro else.
    } else {
        minimo = b;
    }
    if (c < minimo){
        minimo = c;
    }
    return minimo;
}

// Calcula a distância de cada leitura em relação à média. Se for positivo, está acima da média, e se for negativo, está abaixo.
void calcularDesvios(double a, double b, double c, double media){
    double desvioDoPrimeiro = a - media;
    double desvioDoSegundo  = b - media;
    double desvioDoTerceiro = c - media;

    printf("Desvio da leitura 1 em relacao a media: %.2f\n", desvioDoPrimeiro);
    printf("Desvio da leitura 2 em relacao a media: %.2f\n", desvioDoSegundo);
    printf("Desvio da leitura 3 em relacao a media: %.2f\n", desvioDoTerceiro);
}

/*
Pergunta ao usuário um valor minimo e um valor máximo aceitaveis.
Verifica se cada leitura está dentro da faixa definida pelo usuário
Imprime em vermelho se estiver fora da faixa (acima ou abaixo), e em verde se estiver dentro da faixa.*/ 
void verificarFaixa(double a, double b, double c, double minAceito, double maxAceito){

    if (a > maxAceito){
        printf("\033[1;31mLeitura 1 (%.2f): ACIMA DO LIMITE\033[0m\n", a);
    } else if (a < minAceito){
        printf("\033[1;31mLeitura 1 (%.2f): ABAIXO DO LIMITE\033[0m\n", a);
    } else {
        printf("\033[1;32mLeitura 1 (%.2f): OK\033[0m\n", a);
    }

    if (b > maxAceito){
        printf("\033[1;31mLeitura 2 (%.2f): ACIMA DO LIMITE\033[0m\n", b);
    } else if (b < minAceito){
        printf("\033[1;31mLeitura 2 (%.2f): ABAIXO DO LIMITE\033[0m\n", b);
    } else {
        printf("\033[1;32mLeitura 2 (%.2f): OK\033[0m\n", b);
    }

    if (c > maxAceito){
        printf("\033[1;31mLeitura 3 (%.2f): ACIMA DO LIMITE\033[0m\n", c);
    } else if (c < minAceito){
        printf("\033[1;31mLeitura 3 (%.2f): ABAIXO DO LIMITE\033[0m\n", c);
    } else {
        printf("\033[1;32mLeitura 3 (%.2f): OK\033[0m\n", c);
    }
}

// Exibe uma barra gráfica de asteríscos proporcional ao valor inteiro da média. (Máximo de 20)
void exibirBarraGrafica(double media){
    int quantidade = (int) media; // Pega só o valor inteiro
    if (quantidade > 20){
        quantidade = 20; //Limita a 20 asteríscos no máximo
    }
    if (quantidade < 0){ // Evita um loop com número negativo
        quantidade = 0;
    }

    printf("Intensidade media: %.2f\n", media);
    printf("[");
    for (int i = 0; i < quantidade; i++){
        printf("*");
    }
    printf("]\n");
}

// Gera um relatório completo, chamando todas as funções anteriores em sequência.
void exibirRelatorioCompleto(double a, double b, double c){
    double minAceito, maxAceito;

    printf("\033[1;34m=== RELATORIO COMPLETO ===\033[0m\n");

    printf("\nLeitura 1: %.2f\n", a);
    printf("Leitura 2: %.2f\n",   b);
    printf("Leitura 3: %.2f\n",   c);

    double media = calcularMedia(a, b, c);
    printf("\nMedia   : %.2f\n", media);

    printf("Minimo  : %.2f\n", encontrarMinimo(a, b, c));
    printf("Maximo  : %.2f\n", encontrarMaximo(a, b, c));

    printf("\n");
    calcularDesvios(a, b, c, media);

    // Pede os valor mínimo e máximo aceitáveis, para fazer a verificação de faixa+
    printf("\nDigite o minimo aceitavel para o relatorio: ");
    scanf("%lf", &minAceito);
    printf("Digite o maximo aceitavel para o relatorio: ");
    scanf("%lf", &maxAceito);
    printf("\n");
    verificarFaixa(a, b, c, minAceito, maxAceito);

    printf("\n");
    exibirBarraGrafica(media);
}

int main(){
    double val1, val2, val3, minAceito, maxAceito;
    int opcao;
    char continuar, novaSimulacao = 's'; // 's' pra entrar no loop na primeira vez

    printf("\033[1;34m=== IMORTAL-1 - SISTEMA DE BORDO ===\033[0m\n\n");
    // Loop externo: repete a simulação com novos valores se o usuário quiser
    while (novaSimulacao == 's'){
        printf("Digite a leitura 1: ");
        scanf("%lf", &val1);
        printf("Digite a leitura 2: ");
        scanf("%lf", &val2);
        printf("Digite a leitura 3: ");
        scanf("%lf", &val3);

        opcao = -1;
        // Loop interno: menu de operações, repete até o usuário sair (escolher a opção 0)
        while (opcao != 0){
            printf("\n\033[1;33m--- MENU ---\033[0m\n"); // apresenta o menu de operações
            printf("1 - Media\n");
            printf("2 - Max/Min\n");
            printf("3 - Desvios\n");
            printf("4 - Verificacao de faixa\n");
            printf("5 - Barra grafica\n");
            printf("6 - Relatorio completo\n");
            printf("0 - Sair\n");

            printf("\nEscolha uma opcao: "); // pede pro usuário escolher uma opção
            scanf("%d", &opcao);
            printf("\n");

            if (opcao == 1){ // se a opção selecionada for a primeira, invoca a função "calcularMedia", com os três valores digitados pelo usuário como parâmetros
                double media = calcularMedia(val1, val2, val3);
                printf("Media das leituras: %.2f\n", media);
            }
            else if (opcao == 2){ // se a opção selecionada for a segunda, invoca as funções "encontrarMinimo" e "encontarMaximo", também com os três valores como parâmetros
                printf("Minimo: %.2f\n", encontrarMinimo(val1, val2, val3));
                printf("Maximo: %.2f\n", encontrarMaximo(val1, val2, val3));
            }
            else if (opcao == 3){   // se a opção selecionada for a terceira, invoca primeiro a função "calcularMedia", com os três valores como parâmetros,
                                    // e depois invoca a "calcularDesvios", que tem como parâmetros os três valores, e a média
                double media = calcularMedia(val1, val2, val3);
                calcularDesvios(val1, val2, val3, media);
            }
            else if (opcao == 4){ // se a opção escolhida for a quarta, pede que o usuário digite dois valores: O minimo aceitavel e o maximo aceitavel, 
                                  // e armazena eles nas variaveis "minAceito" e "maxAceito", respectivamente.
                                  // depois, invoca a função "verificarFaixa", que tem como parâmetros os três valores, mais o minimo e o maximo aceitaveis.
                printf("Digite o minimo aceitavel: ");
                scanf("%lf", &minAceito);
                printf("Digite o maximo aceitavel: ");
                scanf("%lf", &maxAceito);
                printf("\n");
                verificarFaixa(val1, val2, val3, minAceito, maxAceito);
            }
            else if (opcao == 5){ // se a opção selecionada for a quinta, invoca a função "calcularMedia", com os três valores como parâmetros,
                                  // depois invoca a função "exibirBarraGrafica", com "media", como parâmetro  
                double media = calcularMedia(val1, val2, val3);
                exibirBarraGrafica(media);
            }
            else if (opcao == 6){ // se a opção selecionada for a sexta, chama a função "exibirRelatorioCompleto", que também tem os tres valores como parâmetros.
                exibirRelatorioCompleto(val1, val2, val3);
            }
            else if (opcao == 0){ // e se a opção selecionada for a sétima e última, encerra o loop interno, e volta pro loop externo
                break;
            }
            else {
                printf("\033[1;31mOpcao invalida. Tente novamente.\033[0m\n"); // se o usuário digitar qualquer coisa que não seja uma das opções, aparece essa mensagem de erro
            }

            printf("\nDeseja realizar outra operacao? (s/n): "); // pergunta se o usuário quer realizar outra operação (ainda com os mesmos números)
            scanf(" %c", &continuar); // armazena a resposta na variavel continuar
            if (continuar == 'n'){ // se a resposta for 'n', encerra o loop interno pela condição, sem break.
                opcao = 0;
            }
        }

        printf("\nDeseja iniciar nova simulacao? (s/n): ");
        scanf(" %c", &novaSimulacao);
    }

    printf("\nEncerrando sistema...\n");
    return 0;
}