# Exercício 2

Wendrey Lustosa Cardoso
148234

*As saídas das execuções do software dinero, assim como os scripts de execução do software e de manipulação dos dados, estão no repositório. Dentro de cada trace há: cache.sh (executa o dinero com parâmetros variado), trace_W_cache_X_block_Y_ass_Z.out (saída da simulação, W é um número para o trace, X é o tamanho da cache, Y é o tamanho do bloco, Z é o número de vias), trata_dados.sh (extrai dados da saída da simulação), traceX.csv (saída para geração de gráficos, X é um número para o trace).

### Introdução

A cache é um dispositivo de rápido acesso, serve de intermediário entre o processador e a memória principal. Sua vantagem consiste em evitar acessos à memória principal, que apesar de ter um tamanho muito maior para armazenamento, possui tempo de acesso muito maior. Para atingir esse objetivo e evitar *misses* existem vários parâmetros que podem ser configurados na cache, como tamanho da cache, tamanho do bloco e associatividade. Uma cache maior significa menor (capacity) miss rate e mais tempo de acesso. Um bloco maior significa menor (compulsory) miss rate e maior miss penalty. Maior associatividade significa menor (conflict) miss rate e maior tempo de acesso. 

### Metodologia

Com o objetivo de achar uma configuração ótima de cache L1 de instruções e dados, dentre certas especificações, foram escolhidos para a simulação através do software [dinero](https://www.ece.cmu.edu/~ece548/tools/dinero/man/dinero.htm) os seguintes traces nas configurações de m2b: twolf, equake, art e swim. Durante os testes, alguns parâmetros foram constantes, como busca por demanda (*demand fetch*) e política de substituição por último uso recente (*last recente used replace policy*). Os parâmetros variados nos experimentos foram tamanho da cache em KB (16, 32, 64, 128, 256 e 512), tamanho do bloco em B e associatividade (ambos variados em 1, 2, 4, 8, 16 ou 32). Como não é medido o tempo de acesso ao cache para obtenção de dados ou instruções, essencialmente tem-se que uma melhor cache neste escopo significa uma cache maior. Mais é importante notar que o tempo de acesso é fundamental e, assim como um baixo miss rate, um baixo tempo de acesso representa a essência de uma boa cache.

### Resultados

Foram feitos gráficos para cada trace utilizado. Os gráficos de um mesmo trace variam na associatividade da cache. Em cada gráfico tem-se diferentes curvas, onde se varia o tamanho do bloco. Nos eixo Y dos gráficos tem-se a porcentagem de miss rate em relação a quantidade de acessos na cache. No eixo X tem-se o tamanho da cache.

Em todos os traces o miss rate relacionado a instruções teve praticamente dois valores contabilizados na saída da execução do dinero: 0 e 1e-6 (a precisão da saída e portanto o menor valor positivo possível). Por esse motivo, não são apresentados gráficos neste relatório referente a miss rate de instruções, já que não teria-se dados suficientes para analisar como os parâmetros estão relacionados à essa cache e e sua miss rate. *Mas os gráficos foram disponibilizados no repositório.*

##### Twolf
 
Os gráficos deste trace mostram que maior o tamanho da cache, maior o tamanho dos blocos ou maior a associatividade significam um menor miss rate. O interessante é notar o quanto cada parâmetro afeta o miss rate. O tamanho da cache é o que mais influencia na redução de miss rate, diminui o miss rate entre 0,05 e 0,15%. Para caches pequenas, o tamanho do bloco do bloco diminui em até 0,1% o miss rate, como pode-se ver comparando as curvas de *block 1* e *block 32* de associatividade 32 com 16~32 KB de cache. Porém para altos valores de cache, as curvas tendem ao mesmo limiar de miss rate e pouco influencia o tamanho dos blocos, ou seja, a redução de capacity misses vai se igualando ao aumento de conflict e compulsory misses. O aumento da associatividade mostra uma queda no decrescimento das curvas (mais visível para pequenos valores de cache) e uma mais rápida aproximação da assíntota de miss rate entre as curvas com diferentes tamanho de blocos, mas pouco influencia o miss rate quando a cache possui 64KB (tamanho comum de caches L1).

Levando em conta que o aumento nos parâmetros de tamanho de cache, tamanho do bloco e associatividade podem aumentar o tempo de acesso e o miss penalty, para o trace twolf, uma boa configuração seria um tamanho de cache de 256 KB e tamanho do bloco de 32 B com 4 ou vias de acesso. Aumentar os parâmetros além disso não diminui satisfatoriamente o miss rate e possivelmente piora os fatores acima citados que não foram avaliados.

![Twolf](/exercicio2/twolf_data.png )

##### Equake

É visível que neste trace o tamanho do bloco é o fator que mais influencia na redução de miss rate: o bloco de tamanho 16B chega a um mínimo de miss rate de 0,23% contra 0,12% do bloco de tamanho 32B. O tamanho da cache influencia mais as caches com menor associativade, mas logo chega no limite: mesmo no menor valor de associatividade quase não se percebe diferença entre os miss rate das caches de 256 e 512KB. Novamente a associatividade reduz a inclinação das curvas, que convergem para um limiar de miss rate dependente do tamanho do bloco da cache: para a maior associatividade, as curvas são quase constantes. Nesse trace apenas a redução de compulsory miss compensa o aumento dos outros dois tipos de miss.

Levando novamente em conta as desvantagens do aumento dos parâmetros aqui avaliados, uma boa configurção de cache para o trace equake seria um bloco de 32 B. Respectivamente, o tamanho da cache e a quantidade de vias podem ser por exemplo: 256 KB e 2 vias, 128 KB e 8 vias. Há várias combinações destes dois parâmetros que melhora o miss rate para um bloco de 32 B.

![Equake](/exercicio2/equake_data.png)

##### Art

Neste trace, novamente a associatividade reduz o decrescimento das cruvas, ou seja, dimimui a influência do tamanho do cache na porcentagem de miss rate. Porém, neste caso, a influência deste parâmetro é muito maior na redução da declividade do que na redução do miss rate, de forma que para o maior tamanho de cache (512KB), uma maior associatividade significa maior miss rate: a redução de conflict misses não compensa o aumento de capacity misses que a associativade ocasiona. Uma observação geral permite perceber que, para este trace, o tamanho do bloco é o melhor parâmetro a ser variado (aumentado) para obter uma maior redução de miss. 

Neste trace, é bem visível a melhor configuração de cache dentre todos os testes feitos. O menor miss rate se dá quando a cache tem 512 KB, com tamanho de bloco de 32 B e apenas 1 via. Claramente a redução de capacity miss é bem maior que qualquer aumento de conflict miss e compulsory miss que possam ser causados pelo aumento do tamanho da cache.

*As curvas estão suavizadas, por isso em alguns (poucos) trechos indica um aumento de miss rate com o aumento da cache, mas o cache miss rate é sempre não-crescente para os pontos explícitos obtidos no experimento.*

![Art](/exercicio2/art_data.png)

##### Swim

Neste trace, para todos os casos, um cache acima de 256 KB tamanho já não ocaciona uma queda de miss rate satisfatória: há um pequeno aumento de miss rate nas curvas quando o tamanho da cache passa de 256 a 512 KB. Aumentar a associatividade para qualquer valor de cache também não reduz o miss rate, as curvas dos gráficos praticamente não mudam, com exceção dos pontos de tamanho de cache de 64 KB e 128 KB que chegam a ser um pico no miss rate quando se tem uma associatividade de 4 vias. O tamanho dos blocos se destaca como parâmetro mais importante na taxa de miss rate, o maior bloco chega a ter 0,15% de miss rate contra 0,55% de blocos muito pequenos.

Novamente, apenas a redução de compulsory miss reduz satisfatoriamente o miss rate quaisquer que sejam os valores dos outros dois parâmetros. A vantagem da redução de conflict miss não compensa. A redução de capacity miss também não é significativa a partir de um tamanho de cache de 256 KB. Portanto uma boa cache teria um tamanho de bloco de 32 B, com capacidade total de 256 KB e associatividade de 1 via. 

![Swim](/exercicio2/swim_data.png)



