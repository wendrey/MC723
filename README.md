# Exercício 1

Wendrey Lustosa Cardoso  
148234

## Flags de otimização

Foram realizados seis diferentes tipos de compilação para testar o programa **primo.c**. Compilação sem nenhuma opção extra,
com as flags de otimização -O0, -O1, -O2, -O3 e com a flag -mtune=native.  
* Flag -O0: apenas reduz o tempo de compilação e melhora o processo de depuração, é a flag padrão, logo não mostra mudança no
tempo de execução do programa.  
* Flag -O1: faz com que o compilador reduza o tamanho do código e o tempo de execução, mas sem fazer mudanças que demandem muito
tempo na compilação.  
* Flag -O2: o compilador faz quase todas as otimizações que não envolvam uma troca de espaço por velocidade. Melhora o tempo de
compilação e performance do código.  
* Flag -O3: realiza todas as otimizações feitas pela flag -O2 e inclui outras mais.  
* Flag -mtune=native: otimiza o código na compilação baseado no tipo do processador da máquina local.  

Podemos ver na tabela abaixo que o tempo de execução melhorou com o uso das flags para otimização, sendo o melhor tempo o do
programa compilado com a flag -O3. É interessante notar que apesar das otimizações de tempo do programa, ao juntar a flag -mtune
com a -O3, o tempo de execução do programa foi pior do que se utilizando apenas a flag -O3. Apesar dos valores de tempo serem
uma média de 10 amostras, não podemos ignorar as variações de tempo causadas devido à outros processos e otimizações do sistema
operacional, principalmente se considerarmos que o tempo de execução do programa é muito curto.

| Flag | Real Time [s] | User Time [s] | System Time [s] |
|:----:|:-------------:|:-------------:|:---------------:|
| None | 0.415 | 0.412 | 0.002 |
| O0 | 0.384 | 0.381 | 0.001 |
| O1 | 0.375 | 0.372 | 0.001 |
| O2 | 0.303 | 0.299 | 0.001 |
| O3 | 0.287 | 0.285 | 0.000 |
| mtune | 0.308 | 0.306 | 0.000 |
| mtune + O3 | 0.295 | 0.293 | 0.000 |

## Arquivos separados

Após alterações para separar o programa primo.c em **main.c** e **calc_primo.c**, foram feitos novos testes no programa. Segue
na tabela abaixo o tempo de execeção de cada um deles sem e com a flag com melhor tempo de execução verificado anteriormente. O
tempo de execução do programa separado, nos dois casos, foi um pouco menor, como no todo o programa ainda executa as mesmas
instruções, de fato, o tempo não deveria mudar muito.

| Code | Flag | Real Time [s] | User Time [s] | System Time [s] |
|:----:|:----:|:-------------:|:-------------:|:---------------:|
| primo.c | None | 0.415 | 0.412 | 0.002 |
| primo.c | O3 | 0.287 | 0.285 | 0.000 |
| main.c + calc_primo.c | None | 0.358 | 0.353 | 0.002 |
| main.c + calc_primo.c | O3 | 0.258 | 0.255 | 0.001 |

## Quantidade de primos

Os programas foram modificados para verificar a quantidade de número primos no intervalo de 0 a _n_. Para realizar os testes,
usou-se _n = 100000_. O tempo de execução seguiu conforme esperado, sendo menor para a compilação realizada com as flags de
otimização e para os programas separados.

| Code | Flag | Real Time [s] | User Time [s] | System Time [s] |
|:----:|:----:|:-------------:|:-------------:|:---------------:|
| primo.c | None | 1.401 | 1.397 | 0.002 |
| primo.c | O3 | 1.134 | 1.132 | 0.000 |
| main.c + calc_primo.c | None | 1.242 | 1.238 | 0.002 |
| main.c + calc_primo.c | O3 | 1.123 | 1.121 | 0.000|

## Descarte dos pares

Mudando o laço da função _primo_, para varrer apenas os números ímpares e fazendo novos testes, pode-se ver que o tempo de
execução caiu pela metade, visto que o tempo do programa executando os laços, trecho onde o programa gasta mais tempo, também
foi reduzido pela metade.

| Code | Flag | Real Time [s] | User Time [s] | System Time [s] |
|:----:|:----:|:-------------:|:-------------:|:---------------:|
| primo.c | None | 0.634 | 0.632 | 0.000 |
| primo.c | O3 | 0.584 | 0.582 | 0.002 |
| main.c + calc_primo.c | None | 0.605 | 0.603 | 0.001 |
| main.c + calc_primo.c | O3 | 0.570 | 0.568 | 0.001 |

## Gprof

Como já era esperado, o maior tempo de execução do programa se dá na função _primo_, isso é confirmado pelos dados da ferramenta
_gprog_ que indica que 100 % do tempo foi gasto na função primo, como demonstrado abaixo.

| Index | Time [%] | Self | Children | Called | Name |
|:-----:|:--------:|:----:|:--------:|:------:|:----:|
| - | - | 0.55 | 0.00 | 99997 / 99997 | main [2] |
| [1] | 100 | 0.55 | 0.00 | 99997 | primo [1]|
|---|---|---|---|---|---|
| [2] | 100 | 0.00 | 0.55 | - | main [2] |
| - | - | 0.55 | 0.00 | 99997 / 99997 | primo [1] |

## Paralelismo

Como a maior parte do tempo gasto na execução do programa é gasto nas _n_ chamadas da função primo, uma boa estratégia é
paralelizar as diversas chamadas dessa função. Feito essa mudança com OpenMP, foram realizados mais testes, cujos tempos
de execução seguem abaixo.

| Code | Flag | Real Time [s] | User Time [s] | System Time [s] |
|:----:|:----:|:-------------:|:-------------:|:---------------:|
| primo.c | None | 0.321 | 0.836 | 0.004 |
| primo.c | O3 | 0.282 | 0.673 | 0.000 |
| main.c + calc_primo.c | None | 0.255 | 0.980 | 0.005 |
| main.c + calc_primo.c | O3 | 0.214 | 0.823 | 0.003 |

## Outras otimizações

Para melhorar o desempenho, pode-se diminuir a quantidade de testes realizados no laço da função _primo_ procurando um divisor
até a raiz do número _n_ a ser testado. Podemos ainda guardar num vetor todos os números primos já verificados e menores
que _n_ para testar apenas estes como possíveis divisores. Devido a paralelização, a ideia dessa última abordagem pode ser complicada. 
