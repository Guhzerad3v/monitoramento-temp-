#include <stdio.h>

int main() {
    float limite_temp;
    float temp_atual;
    
    // Variáveis para os cálculos do relatório final
    float soma_temp = 0.0;
    float maior_temp = -100.0;
    float menor_temp = 200.0;
    
    // Contadores para o controle do sistema
    int total_validas = 0;
    int total_acima_limite = 0;
    int consecutivas_acima = 0;

    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n\n");

    // 1. Configuração do limite (Garante a execução pelo menos uma vez)
    do {
        printf("Digite o limite maximo de temperatura permitido (-50.0 a 150.0): ");
        scanf("%f", &limite_temp);
        
        if (limite_temp < -50.0 || limite_temp > 150.0) {
            printf("[ERRO] Limite invalido! O valor deve estar entre -50.0 e 150.0.\n\n");
        }
    } while (limite_temp < -50.0 || limite_temp > 150.0);

    printf("\nLimite configurado com sucesso para: %.2f graus\n", limite_temp);
    printf("Iniciando monitoramento...\n\n");

    // 2. Laço principal de monitoramento
    while (consecutivas_acima < 3) {
        printf("Digite a leitura da temperatura: ");
        scanf("%f", &temp_atual);

        // 3. Validação da leitura (Substitui o uso de 'continue')
        if (temp_atual >= -50.0 && temp_atual <= 150.0) {
            
            // Atualização dos dados 
            total_validas++;
            soma_temp += temp_atual;

            if (temp_atual > maior_temp) {
                maior_temp = temp_atual;
            }
            if (temp_atual < menor_temp) {
                menor_temp = temp_atual;
            }

            // 4. Controle de temperaturas
            if (temp_atual > limite_temp) {
                total_acima_limite++;
                consecutivas_acima++;
                printf("--> ALERTA CRITICO: Temperatura acima do limite! (%d/3 consecutivas)\n\n", consecutivas_acima);
            } else {
                // Redefine o contador se a leitura voltar a um nível seguro
                consecutivas_acima = 0; 
                printf("--> Temperatura normal. Sistema operando dentro dos limites seguros.\n\n");
            }

        } else {
            // Tratamento de leituras fora da faixa operacional
            printf("[ERRO] Leitura invalida! Valor fora da faixa de -50.0 a 150.0. Dado ignorado.\n\n");
        }
    }

    // 5. Relatório Final de Execução
    printf("================ RELATORIO FINAL ================\n");
    printf("ALERTA DE SEGURANCA: 3 leituras consecutivas acima do limite detectadas!\n");
    printf("O monitoramento foi encerrado automaticamente para prevencao de danos.\n\n");

    // Evita a divisão por zero caso o programa encerre inesperadamente sem dados
    if (total_validas > 0) {
        float media = soma_temp / total_validas;
        float percentual_acima = ((float)total_acima_limite / total_validas) * 100.0;

        printf("Total de leituras validas registradas: %d\n", total_validas);
        printf("Temperatura media do periodo: %.2f graus\n", media);
        printf("Pico de temperatura (Maior): %.2f graus\n", maior_temp);
        printf("Temperatura minima (Menor): %.2f graus\n", menor_temp);
        printf("Leituras acima do limite: %d ocorrencia(s) (%.2f%% do total valido)\n", total_acima_limite, percentual_acima);
    }
    printf("=================================================\n");

    return 0;
}