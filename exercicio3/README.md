# Exercício 3

Wendrey Lustosa Cardoso
148234

### Introdução

O termo "ciclos por instrução" (CPI), pode ser descrito como o número de ciclos de clock do processador necessários para completar uma instrução, ou ainda, quantas instruções são completadas em um determinado tempo. Considerando que CPI é a razão entre o total de ciclos realizados pela quantidade de instruções completadas (CPI = total ciclos / total instruções), um valor alto de CPI indica um baixo desempenho (*throughput*). O CPI pode ser usado como uma métrica para verificar quantas operações em paralelo o hardware consegue processar, ou seja, é ideal para caracterizar a perfomance de arquiteturas *multi-threading*.

### Metodologia

Foi utilizado um simulador do processador MIPS, feito utilizando ArchC, uma linguagem para descrição de arquiteturas de processadores. Foram utilizadas as ferramentas SystemC e ArchC já compiladas. Utilizando o simulador e compilador do MIPS, é possível escrever programas em C, compilá-los para formato MIPS e os executar com o simulador. Tal procedimento foi realizado para testar o funcionamento da ferramenta, com a utilização de um simples programa como *Hello World*. Os programas susan (coners - small), sha (small) e gsm (coder - large) do pacote de benchmark MiBench foram executados e, através do simulador, foram obtidas estatísticas sobre a quantidade de instruções executadas. Considerando um CPI médio de 10 para instruções de acesso à memória, 3 para instruções de controle e 1 para as demais, pode-se calcular a quantidade de ciclos utilizados pela máquina para execução do programa.

### Resultados

##### Hello World

O programa hello.c (disponível neste repositório) foi compilado e executado no simulador do MIPS. Com o objetivo de contar quantas vezes o instrução *add* era utilizada na execução do programa, foi modificado o arquivo *mips_isa_cpp* (disponível neste repositório): foi criada uma variável *add_counter*, que era zerada na rotina *ac_behavior(begin)*, incrementada na rotina *ac_behavior(add)* e imprimida na saída padrão na rotina *ac_behavior(end)*. O valor do contador sempre foi nulo ao término da execução da simulação. Utilizando o *objdump*, pode-se verificar que na função main do programa hello.c em assembly, há apenas instruções de addu ou addiu. Mesmo quando o programa hello.c foi alterado para realizar somas de números que deveriam resultar em overflow (um "efeito ignorado" quando a soma é realizada com *addu*), nenhuma instrução de *add* foi contabilizada. Isso acontece porque quando os programas em C são compilados, as operações de soma no arquivo em assembly são realizadas através da instrução *addu*, justamente para não haver erros ou exceções devido a ocorrência de overflows em operações de inteiros com sinais. Como consequência direta disso, é possível observar em programas em C que quando um inteiro supera o máximo valor possível dado o tamanho da palavra em bytes e a representação de complemento de 2, ocorre overflow e o número tem seu valor "estourado", de forma a contar então a partir do menor valor possível, em outras palavras, numa arquitetura de 32 bits o número passa de 2^31-1 para -2^31.

##### MiBench

Os programas do benchmark do MIPS foram executados a partir dos scripts disponibilizados com os próprios programas. Como alguns scripts rodavam várias vezes o mesmo programa com diferentes argumentos, estes foram simplesmente modificados para executarem somente uma vez o programa com os argumentos desejados. O susan foi executado com o input referente a coners e small, enquanto o sha foi executado com input refente a small e o gsm foi executado com input de coder e large. As saídas das execuções desses programas estão disponíveis neste repositório).

Pode-se agrupar as instruções em três tipos: acesso à memória (load e store), controle (jump e branch) e outras (add, or, shift, ...). Considerando o CPI médio para cada tipo de instrução, junto às estatísticas de instruções do simulador, pode-se então calcular a quantidade de ciclos utilizados na execução de cada programa. Tendo ainda informações sobre o clock do processador (neste caso 2.20 GHz x 4), pode-se então calcular o tempo de execução do programa: tempo = número de ciclos / frequência do clock. *Comparando o tempo de execução da saída do simulador e o tempo de execução aqui calculado, tem-se resultados coerentes, pois os valores absolutos são relativamente próximos*. As tabelas abaixo mostram os resultados obtidos.

| Instrução | CPI médio |
|:-:|:-:|
| Acesso à memória (load/store) | 10 |
| Controle (jump/branch) | 3 |
| Outras | 1 |

| Programa \ Instrução | Acesso à memória | Controle | Outras |
|:-:|:-:|:-:|:-:|
| susan coners (small) | 910 237 | 457 863 | 1 854 053 |
| sha (small) | 2 579 546 | 606 891 | 9 989 203 |
| gsm coder (large) | 354 667 842 | 91 942 660 | 1 037 866 702 |

| Programa | Ciclos | Tempo da saída do simulador [s] | Tempo calculado pelos ciclos [s] |
|:-:|:-:|:-:|:-:| 		
| susan | 12 330 012 | 0.08 | *0.055* |
| sha | 37 605 336 | 0.22 | *0.205* |
| gsm | 4 860 373 102 | 22.16 | *24.554* |
