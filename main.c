// Inclusão de bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do limite de saque
#define LIMITE_SAQUE 1000.0

// Declaração da função da caixa eletronica
void exibirMenu();
void consultarSaldo(float saldo);
float realizarDeposito(float saldo);
float realizarSaque(float saldo);

// Função principal
int main() {
    float saldo = 1000.00;
    int opcao;

    do {
        system("cls");
        exibirMenu();

        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch(opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarDeposito(saldo);
                break;
            case 3:
                saldo = realizarSaque(saldo);
                break;
            case 0:
                printf("\nExterminando o Sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
        }

    } while (opcao != 0);

    printf("\nObrigado por utilizar nosso Mega Ultra Caixa Eletronico!\n");
    return 0;
}

// Função de print do Menu
void exibirMenu() {
    printf("\n============================\n");
    printf("    ULTRA CAIXA ELETRONICO\n");
    printf("============================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Deposito\n");
    printf("3 - Realizar Saque\n");
    printf("0 - Sair\n");
    printf("============================\n");
    printf("Escolha uma opcao: ");
}

// Função para consultar o saldo
void consultarSaldo(float saldo) {
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", saldo);
}

float realizarDeposito(float saldo) {
    float valor;
    printf("\nDigite o valor do deposito: ");
    scanf("%f", &valor);

    if (valor > 0) {
        saldo += valor;
        printf("Deposito realizado!\n");
    } else {
        printf("Valor invalido!\n");
    }

    return saldo;
}

float realizarSaque(float saldo) {
    float valor;
    printf("\nDigite o valor do saque: ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor invalido!\n");
        delay(1000);
    } else if (valor > LIMITE_SAQUE) {
        printf("Limite diario excedido!\n");
        delay(1000);
    } else if (valor > saldo) {
        printf("Saldo insuficiente!\n");
        delay(1000);
    } else {
        saldo -= valor;
        printf("Saque realizado!\n");
        delay(1000);
    }

    return saldo;
}