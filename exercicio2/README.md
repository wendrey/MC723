# Exercício 1

Wendrey Lustosa Cardoso
148234

### Metodologia

Com o objetivo de achar uma configuração ótima de cache L1 de instruções e dados, dentre certas especificações, foram escolhidos para a simulação através do software [dinero](https://www.ece.cmu.edu/~ece548/tools/dinero/man/dinero.htm) os seguintes traces nas configurações de m2b: twolf, equake, art e swim. Durante os testes, alguns parâmetros foram constantes, como busca por demanda (*demand fetch*) e política de substituição por último uso recente (*last recente used replace policy*). Os parâmetros variados nos experimentos foram tamanho da cache em KB (16, 32, 64, 128, 256 e 512), tamanho do bloco em KB e associatividade (ambos variados em 1, 2, 4, 8, 16 ou 32).

!!! As saídas das execuções do software dinero, assim como os scripts de execução do software e de manipulação dos dados, estão no repositório. !!!

### Resultados

![Twolf](/exercicio2/twolf_data.png)

![Equake](/exercicio2/twolf_data.png)

![Art](/exercicio2/twolf_data.png)

![Swim](/exercicio2/twolf_data.png)
