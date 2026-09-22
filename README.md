# Sistema de Monitoramento de Temperatura

## 1. Identificação
* Nome do aluno: Gustavo Ferreira Rodrigues
* Disciplina: Algoritmos e Pensamento Computacional
* Professora: Profa. Karla Sartin
* Título do projeto: Sistema Automático de Monitoramento e Alerta de Temperatura

## 2. Objetivo
Este projeto tem como finalidade resolver o problema de monitoramento térmico em ambientes controlados. O programa atua como um sistema de segurança que registra leituras contínuas e aciona um encerramento automático caso a temperatura exceda um limite pré-configurado por três vezes consecutivas, prevenindo danos estruturais ou falhas em equipamentos sensíveis.

## 3. Funcionamento do Programa
O sistema foi desenvolvido para operar da seguinte maneira:
* Definição do limite: Ao iniciar, o sistema solicita ao usuário que defina a temperatura máxima permitida, aceitando apenas valores dentro de uma faixa operacional plausível (entre -50.0 e 150.0 graus).
* Realização das leituras: O programa entra em um ciclo contínuo, solicitando a entrada de novas medições térmicas.
* Tratamento de valores inválidos: Caso o usuário insira uma leitura fora da faixa operacional segura, o programa exibe uma mensagem de erro e descarta o valor. Essa leitura inválida não interfere no cálculo da média, na contagem total ou no rastreamento de temperaturas consecutivas.
* Identificação de excessos: Cada leitura válida é comparada ao limite previamente configurado. Se o valor lido for estritamente maior que o limite, o sistema registra a ocorrência.
* Contagem de temperaturas consecutivas: Existe um contador dedicado a registrar medições elevadas. Ele é incrementado em uma unidade sempre que o limite é ultrapassado. No entanto, se uma leitura subsequente retornar a um nível igual ou inferior ao limite, o contador é imediatamente redefinido para zero, garantindo que o alerta crítico considere apenas ocorrências seguidas.
* Condição de encerramento: O monitoramento é encerrado automaticamente no exato momento em que o contador de temperaturas altas atinge três ocorrências consecutivas. Após o encerramento, um relatório estatístico completo é gerado.

## 4. Estruturas de Repetição Utilizadas
Para garantir o fluxo correto do programa, foram adotadas duas estruturas de repetição distintas:

* Estrutura do...while: Utilizada exclusivamente na etapa de configuração do limite de temperatura inicial. 
* Estrutura while: Utilizada para gerenciar o laço principal de leituras de temperatura.

A escolha dessas estruturas foi baseada na necessidade do momento da avaliação da condição. O `do...while` foi escolhido para a configuração inicial porque o programa obrigatoriamente precisa solicitar o limite de temperatura ao menos uma vez antes de poder verificar se o dado digitado é válido. Já o `while` foi escolhido para o laço principal porque a condição de parada (o limite de alertas) deve ser verificada antes de solicitar uma nova leitura, evitando que o sistema peça um novo dado quando já deveria ter sido encerrado.

## 5. Como Executar
O programa foi desenvolvido em linguagem C padrão e pode ser compilado utilizando o compilador GCC. 

Para compilar o código-fonte, utilize o seguinte comando no terminal:
gcc monitoramento.c -o monitoramento

Para iniciar a execução do programa, utilize o comando:
./monitoramento

Caso esteja em uma IDE, faça o seguinte:

Para compilar C na sua IDE, você deve criar um projeto de aplicativo de console, configurar o arquivo com a extensão .c e usar o atalho Ctrl + F5 para rodar o programa, Após instalar o compilador.

## 6. Testes Realizados
O sistema foi submetido aos três cenários de testes exigidos para validação da lógica e estabilidade:

* Teste 1 (Validação de entradas inválidas): Foi inserido um limite inicial de 200, que foi corretamente rejeitado. Após definir o limite válido em 50, inseriu-se uma leitura de -60. O programa identificou a anomalia, exibiu um alerta de erro, ignorou a leitura e prosseguiu o monitoramento sem comprometer as estatísticas.
* Teste 2 (Temperaturas acima do limite, não consecutivas): Com o limite definido em 50, foram inseridas as leituras 60 e 65, elevando o nível de alerta. Em seguida, foi inserida a leitura 40. O sistema registrou o retorno à normalidade e redefiniu o contador de consecutivas para zero, mantendo o programa em execução.
* Teste 3 (Três temperaturas consecutivas e encerramento automático): Com o limite definido em 50, foram inseridas as leituras 55, 60 e 65 sequencialmente. O programa identificou o padrão crítico, interrompeu o laço de imediato e apresentou o relatório final contendo a média, a maior e menor temperatura, o total de leituras válidas e o percentual de ocorrências fora do limite.

---

## Questão Final de Reflexão
Por que você escolheu while, do...while ou uma combinação das duas estruturas? Em qual parte do algoritmo a diferença entre testar a condição antes ou depois da execução foi importante para sua solução?

A escolha por uma combinação de ambas as estruturas mostrou-se a abordagem mais prudente para as diferentes fases do algoritmo. A diferença entre testar a condição antes ou depois da execução foi crucial em duas partes específicas: 

Primeiro, na etapa de validação da entrada do limite. Como não existe um limite prévio carregado na memória, a instrução precisava ser executada ao menos uma vez para coletar o dado do usuário. Nesse caso, testar a condição depois da execução (utilizando do...while) garantiu fluidez e evitou a redundância de ter que escrever a instrução scanf duas vezes (uma fora e outra dentro do laço).

Segundo, no núcleo de monitoramento. A verificação do estado de alerta máximo precisava ocorrer antes de qualquer nova interação com o usuário. Testar a condição antes da execução (utilizando while) foi fundamental para garantir que, assim que a terceira temperatura consecutiva fosse registrada, o laço fosse interrompido instantaneamente, impedindo que o programa solicitasse uma quarta leitura desnecessária.
