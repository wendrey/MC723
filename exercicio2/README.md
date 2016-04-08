# Exercício 1

Wendrey Lustosa Cardoso
148234

### Introdução

A cache é um dispositivo de rápido acesso, serve de intermediário entre o processador e a memória principal. Sua vantagem consiste em evitar acessos à memória principal, que apesar de ter um tamanho muito maior para armazenamento, possui tempo de acesso muito maior. Para atingir esse objetivo e evitar *misses* existem vários parâmetros que podem ser configurados na cache, como tamanho da cache, tamanho do bloco e associatividade. Uma cache maior significa menor (capacity) miss rate e mais tempo de acesso. Um bloco maior significa menor (compulsory) miss rate e maior miss penalty. Maior associatividade significa menor (conflict) miss rate e maior tempo de acesso. 

### Metodologia

Com o objetivo de achar uma configuração ótima de cache L1 de instruções e dados, dentre certas especificações, foram escolhidos para a simulação através do software [dinero](https://www.ece.cmu.edu/~ece548/tools/dinero/man/dinero.htm) os seguintes traces nas configurações de m2b: twolf, equake, art e swim. Durante os testes, alguns parâmetros foram constantes, como busca por demanda (*demand fetch*) e política de substituição por último uso recente (*last recente used replace policy*). Os parâmetros variados nos experimentos foram tamanho da cache em KB (16, 32, 64, 128, 256 e 512), tamanho do bloco em B e associatividade (ambos variados em 1, 2, 4, 8, 16 ou 32). Como não é medido o tempo de acesso ao cache para obtenção de dados ou instruções, essencialmente tem-se que uma melhor cache neste escopo significa uma cache maior. Mais é importante notar que o tempo de acesso é fundamental e, assim como um baixo miss rate, um baixo tempo de acesso representa a essência de uma boa cache.

*As saídas das execuções do software dinero, assim como os scripts de execução do software e de manipulação dos dados, estão no repositório.*

### Resultados

Foram feitos gráficos para cada trace utilizado. Os gráficos de um mesmo trace variam na associatividade da cache. Em cada gráfico tem-se diferentes curvas, onde se varia o tamanho do bloco. Nos eixo Y dos gráficos tem-se a porcentagem de miss rate em relação a quantidade de acessos na cache. No eixo X tem-se o tamanho da cache. *De acordo com a variação observada no miss rate pela variação de cada parâmetro da cache, foram feitas tabelas indicando a ocorrência de cada tipo de miss.*

Em todos os traces o miss rate relacionado a instruções teve apenas dois valores contabilizados na saída da execução do dinero: 0 e 1e-6 (a precisão da saída e portanto o menor valor positivo possível). Por esse motivo, não são apresentados gráficos neste relatório referente a miss rate de instruções, já que não teria-se dados suficientes para analisar como os parâmetros estão relacionados à essa cache e e sua miss rate. *Mas os gráficos foram disponibilizados no repositório.*

##### Twolf
 
Os gráficos deste trace mostram que maior o tamanho da cache, maior o tamanho dos blocos ou maior a associatividade significam um menor miss rate. O interessante é notar o quanto cada parâmetro afeta o miss rate. O tamanho da cache é o que mais influencia na redução de miss rate, diminui o miss rate entre 0,05 e 0,15%. Para caches pequenas, o tamanho do bloco do bloco diminui em até 0,1% o miss rate, como pode-se ver comparando as curvas de *block 1* e *block 32* de associatividade 32 com 16~32 KB de cache. Porém para altos valores de cache, as curvas tendem ao mesmo limiar de miss rate e pouco influencia o tamanho dos blocos. O aumento da associatividade mostra uma queda no decrescimento das curvas (mais visível para pequenos valores de cache) e uma mais rápida aproximação da assíntota de miss rate entre as curvas com diferentes tamanho de blocos, mas pouco influencia o miss rate quando a cache possui 64KB (tamanho comum de caches L1).

Capacity misses > compulsory misses > conflict misses

![Twolf](/exercicio2/twolf_data.png )

##### Equake

É visível que neste trace o tamanho do bloco é o fator que mais influencia na redução de miss rate: o bloco de tamanho 16B chega a um mínimo de miss rate de 0,23% contra 0,12% do bloco de tamanho 32B. O tamanho da cache influencia mais as caches com menor associativade, mas logo chega no limite: mesmo no menor valor de associatividade quase não se percebe diferença entre os miss rate das caches de 256 e 512KB. Novamente a associatividade reduz a inclinação das curvas, que convergem para um limiar de miss rate dependente do tamanho do bloco da cache: para a maior associatividade, as curvas são quase constantes. 

Compulsory miss > conflict miss ~~ capacity miss

![Equake](/exercicio2/equake_data.png)

##### Art

Neste trace, novamente a associatividade reduz o decrescimento das cruvas, ou seja, dimimui a influência do tamanho do cache na porcentagem de miss rate. Porém, neste caso, a influência deste parâmetro é muito maior na redução da declividade do que na redução do miss rate, de forma que para o maior tamanho de cache (512KB), uma maior associatividade significa maior miss rate: a redução de conflict misses não compensa o aumento de capacity misses que a associativade ocasiona. Uma observação geral permite perceber que, para este trace, o tamanho do bloco é o melhor parâmetro a ser variado (aumentado) para obter uma maior redução de miss. 

Compulsory miss > conflict miss > capacity miss

*As curvas estão suavizadas, por isso em alguns (poucos) trechos indica um aumento de miss rate com o aumento da cache, mas o cache miss rate é sempre não-crescente para os pontos explícitos obtidos no experimento.*

![Art](/exercicio2/art_data.png)

##### Swim

Neste trace, para todos os casos, um cache acima de 256 KB tamanho já não ocaciona uma queda de miss rate satisfatória: há um pequeno aumento de miss rate nas curvas quando o tamanho da cache passa de 256 a 512 KB. Aumentar a associatividade para qualquer valor de cache também não reduz o miss rate, as curvas dos gráficos praticamente não mudam, com exceção dos pontos de tamanho de cache de 64 KB e 128 KB que chegam a ser um pico no miss rate quando se tem uma associatividade de 4 vias. O tamanho dos blocos se destaca como parâmetro mais importante na taxa de miss rate, o maior bloco chega a ter 0,15% de miss rate contra 0,55% de blocos muito pequenos.

Compulsory miss > capacity miss > conflict miss

![Swim](/exercicio2/swim_data.png)
