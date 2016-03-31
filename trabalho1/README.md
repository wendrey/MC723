# Trabalho 1

Wendrey Lustosa Cardoso
148234

### Resumo

Para avaliar o desempenho das máquinas, vários computadores foram testados usando-se diferentes benchmarks. Os benchmarks usados que são destacados neste relatórios fazem referência ao [FFmpeg](https://github.com/RodolfoSeki/MC723/tree/master/projeto1), [Convolução](https://github.com/yugo4k/2016s1.mc723a.projeto1.parte1) e [ImageMagick](https://github.com/FelipeEmos/mc723/tree/master/projeto1/benchmark1). Todos computadores testados em cada benchmark são analisados comparativamente em relação às suas configurações e resultados nos tópicos subsequentes. Em seguida, segue uma comparação mais geral sobre os computadores específicos e comuns aos três benchmarks aqui destacados. 

Como não havia um padrão a seguir sobre que configurações deveriam ser disponibilizadas sobre as máquinas, há várias divergências de contéudo, então tentou-se simplificar as informações dadas e analisar apenas as configurações comumente apresentadas. 

### FFmpeg

FFmpeg é uma coleção de bibliotecas e ferramentas para processar conteúdo multimídia. Foi utlizado para converter uma amostra de vídeo do formato mp4 para o formato avi. As medidas escolhidas foram: tempo de execução, quantidade de page fault, quantidade de stalls e quantidade de cache misses. As máquinas utilizadas neste benchmark e os dados obtidos seguem nas duas tabelas abaixo.

Espera-se que numa máquina com maior memória RAM, a quantidade e page faults seja menor, assim como espera-se que numa máquina com maior cache, a quantidade de misses seja menor. Tanto a quantidade de page faults como a quantidade de cache misses, dependem diretamente das aplicações sendo executadas na máquina, além de outras configurações que não foram apresentadas, ainda assim é curioso notar que a menor quantidade de page faults é da máquina 3, que possui a menor quantidade de memória principal dentre todas (4GB). Ainda nesse sentido, a máquina 2, que apresenta um buffer de 32MB se mostra coerente ao possuir uma quantidade de cache misses que é menor que a metade da quantidade de cache misses de quase todas as outras máquina. Não pode-se deixar de notar que a quantidade de stalls desta máquina também é muito menor, podendo ser uma consequência direto da baixa quantidade de cache misses, já que desta forma esta máquina poupa muitos acessos à memória principal, operação que gasta muitos ciclos se comparados com o acesso ao cache. As melhores máquinas no que diz respeito aos cache misses são as máquinas 2 (918), 12 (1234) e 3 (2120), as piores são as máquinas 11 (2608), 10 (2482) e 4 (25320).

O menor tempo de execução é da máquina 10 (14,84 segundos), seguida pelas máquinas 5 (16,64 segundos), 8 (18,19 segundos). E os piores tempos são das máquinas 3 (69,65 segundos), 9 (32,83 segundos) e 2 (32,58 segundos). O processador intel core i7 4700HQ da máquina 10 apresentou o melhor desempenho na execução, confirmando a eficiência esperada do processador. As máquinas 5 e 8 possuem o mesmo processador (intel core i7 3612QM), sendo então coerente afirmar a eficiência do processador, já que essas máquinas obtiveram o segundo e terceiro melhores tempos. Fato semelhante ocorre com os piores tempos das máquinas 3 e 9: ambas possuem processadores da família intel core2. Apesar da máquina 9 ter o dobro de cores da máquina 3 (e cerca de metade do tempo de execução), o fato de possuírem os piores tempos torna verossímel a baixa eficiência desses processadores. 

| Computer | Rank | Core | Clock | Cache Memory Disk |
|:--------:|:----:|:-----:|:-----------------:|
| 1 | | Intel Core i7 3610QM x 4 | 2.30 GHz | L1 256KB |
| 2 | -- | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 3 | --- |Intel Core2 Duo T6500 x 2 | 2.10 GHz | 4GB RAM |
| 4 | | Intel Core i7 4702MQ x 4 | 2.20 GHz | 8GB RAM |
| 5 | *** | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 32GB HDD 1TB 5400rpm |
| 6 | | Intel Core i7 4510U x 2 | 2.00 GHz | 8GB RAM | HD 5400rpm |
| 7 | | Intel Core i7 3740QM x 2 | --- | --- |
| 8 | * | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 240GB |
| 9 | -- | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 10 | *** | Intel Core i7 4700HQ x 4 | 2.40 GHz | 16GB RAM HDD SATA III 7200rpm |
| 11 | | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB 8GB RAM HDD 1TB |
| 12 | | Intel Core i5 4590 x 4 | 3.30 GHz | 8GB RAM HDD 216.9 GB |

| Computer | Time [s] | Page Faults | Stalled Cycles [G] | L1 Cache Load Misses [M] |
|:--------:|:--------:|:-----------:|:------------------:|:------------------------:|
| 1 | 29,60 | 29 618 | 149 800 | 2 377 |
| 2 |	32,58 | 16 470 | 17 251 | 918 |
| 3 | 69,65 |	12 112 | --- | 2 120 |
| 4 |	27,70 |	25 000 | --- | 2 532 |
| 5 | 16,64 |	29 942 | 151 896 |	2 316 |
| 6 | 31,49	| 16 509 | --- | 2 358 |
| 7 | 29,73 | 14 145 | --- | --- |
| 8 | 18,19 | 25 168 | 148 667 | 2 307 |
| 9 |	32,83 | 21 057 | --- | 2 157 |
| 10 | 14,84 | 25 172 | --- |	2 482 |
| 11 | 30,86 | 16 225	| --- | 2 608 |
| 12 | 19,88 | 20 475	| --- |	1 234 |

### Convolução

O script deste benchmark (disponível na página do mesmo) processa convoluções em images tridimensionais, uma operação fundamental em processamento de imagens. A imagem do teste é um cubo com lado de 150 voxels. As medidas escolhidas foram: o tempo de execução, tempo médio de escrita em disco e tempo médio de leitura do disco. As máquinas utilizadas neste benchmark e os dados obtidos (através de uma média de 20 operações) seguem nas duas tabelas abaixo.

Os melhores tempos de execução são da máquina 10 (com processador intel core i7 2630QM e tempo de 7,01 segundos), máquina 7 (com processador intel core i7 3612QM e tempo de 7,60 segundos) e máquina 3 (7com processador intel core i7 e tempo de 90 segundos). Os piores tempos são das máquinas 8 (com processador intel core2 Quad Q8400 e tempo de 123,70 segundos), 6 (89,60 segundos) e 4 (com processador intel core i7 3612QM e tempo de 36,30 segundos). É interessante notar que o processador intel core i7 3612QM da máquina 7 também tem uma avaliação positiva no benchmark do FFmpeg por estar em duas das três máquinas com melhores tempos de execução, porém neste benchmark de convolução o processador também se encontra na máquina 4, que possui um dos piores tempos. Novamente, o processador intel core2 Quad Q8400 está entre as máquinas de pior tempo de execução.

A máquina com melhor eficiência não possui a maior taxa de escrita nem de leitura. A melhor taxa de escrita (4031 MB/s) é da máquina 7, que contém SSD, como seria esperado, já que SSDs têm tempo de acesso menor que HDDs, porém essa máquina possui apenas a terceira maior taxa de leitura (1758 MB/s). A melhor taxa de leitura é da máquina 5 (1840MB/s), que possui um HDD de 5400 rpm, seguida das máquinas 1 (1780 MB/s) e 7 (1758 MB/s) e as piores são das máquinas 8 (11 MB/s), 2 (14 MB/s) e 11 (82 MB/s). As melhores e piores taxas de escrita são, respectivamente, das máquinas 7 (4031 MB/s), 3 (3703 MB/s) e 5 (3144 MB/s) e das máquinas 2 (92 MB/s), 8 (878 MB/s) e 4 (2021 MB/s). O grande problema deste benchmark está na sua confiabilidade, pois os valores de escritas e leituras (supostamentes no disco) estão muito elevados, essas taxas deveriam estar em 300 a 500 MB/s, porém a maioria das taxas de leitura calculadas estão acima de 1000 MB/s e as de escrita estão acima de 2000 MB/s. É provável, portanto, que esses valores de escrita e leitura estejam relacionados também à memória principal. Além disso, nota-se que não necessariamente uma maior taxa de escrita e leitura determina um menor tempo de execução, por exemplo, a máquina 4 leva quase o triplo de tempo da máquina 2, mesmo tendo taxas de leitura e escritas muito melhores.

| Computer | Rank | Core | Clock | Cache Memory Disk |
|:--------:|:----:|:---:|:-----:|:-----------------:|
| 1 | | Intel Core i7 3610QM x 4 | 2.30 GHz | L1 256KB |
| 2 | | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 3 | * | Intel Core i7 × 4 | --- | 8GB RAM | --- |;
| 4 | - | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 32GB HDD 1TB 5400rpm |
| 5 | | Intel Core i7 4510U x 2 | 2.00 GHz | 8GB RAM | HD 5400rpm |
| 6 | -- | Intel Core i7 3740QM x 2 | --- | --- |
| 7 | ** | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 240GB |
| 8 | --- | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 9 | | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB 8GB RAM HDD 1TB |
| 10 | *** | Intel Core i7 2630QM | 2.00 GHz | 4GB RAM |
| 11 | | Intel Core i7 | 2.30 GHz | 8GB RAM |

| Computer | Time [s] | Read Rate [MB/s] | Write Rate [MB/s] |
|:--------:|:--------:|:----------------:|:-----------------:|
| 1 | 7,98 | 1 780 | 2 360 |
| 2 | 13,70 | 14 | 92 |
| 3 | 7,90 | 1 627 | 3 703 |
| 4 | 36,30 | 1 085 | 2 021 |
| 5 | 10,46 |	1 840 | 3 144 | 
| 6 | 89,60 | 641 | 2 781 |
| 7 | 7,60	 | 1 758 | 4 031 |
| 8 | 123,70	| 11 | 878 |
| 9 | 14,18 | 1 426 | 2 413 |
| 10 | 7,01 | 1 103 |	2 742 |
| 11 | 25,31 | 82 |	2 066 |

### ImageMagick

O programa realiza um benchmarking de processamento de imagens que envolve manipulação de arquivos, multithreading tempo de processamento. Foram realizados quatro operações de geração de imagens e aplicação de filtros no script disponibilizado neste benchmark. As máquinas utilizadas neste benchmark e os dados obtidos seguem nas duas tabelas abaixo. O tempo de execução é a soma das quatro operações, as demais medidas - numéro de CPUs utilizadas, frequência dos ciclos e instruções por ciclo -, apresentam valores que são uma média das operações.

Os melhores tempos de execução são das máquinas 8 (com processador intel core i5 4590 e tempo de 107,79 segundos), 2 (com processador inter core i7 e tempo de 110,42 segundos) e 7 (com processador intel core i5 5200U e tempo de 126,05 segundos).
O pior tempo de execução é da máquina 9 (com processador intel atom e tempo de 766,77 segundos), em seguida tem-se as máquinas 5 (311,06 segundos), 6 (291,57 segundos) e 3 (288,37 segundos), todas com processador intel core2 Quad Q8400.

É coerente que a máquina 8 tenha o menor tempo de execução, visto que possui a maior frequência de ciclos (3,427 GHz) e a maior taxa de instruções por ciclo (1,793 IPC). A maior quantidade de ciclos segue com as máquinas 2 (com processador intel core i7 e 2,913 GHz) e 4 (com processador intel core i7 3612QM e 2,821 GHz), enquanto a maior taxa de instruções por ciclo segue com as máuqinas 7 (com processador intel core i5 5200U e 1,358 IPC) e 4 (1,270 IPC).

Com a quantidade de CPUs utilizadas, pode-se ter uma noção do paralelismo do processador. A maior média de CPUs é da máquina 1 (com processador AMD PhenonII e 1,779 CPUs), seguida das máquinas 2 (1,684 CPUs) e 4 (1,449 CPUs). A menor média de CPUs é da máquina 9 (com processador intel atom e 1,165 CPUs), seguida das máquinas 6 (1,204 CPUs) e 5 (1,232 CPUs), ambas com processador intel core2 Quad Q8400. No geral, este benchmark também avalia de forma ruim o processador intel core2 Quad Q8400, e destaca positivamente os processadores intel core i7 3612QM, i5 5200U e i5 4590.

| Computer | Rank | Core | Clock | Cache Memory Disk |
|:--------:|:----:|:----:|:-----:|:-----------------:|
| 1 | | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 2 | ** | Intel Core i7 × 4 | --- | 8GB RAM | --- |
| 3 | | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 4 | | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 240GB |
| 5 | -- | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 6 | - | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 7 | * | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB 8GB RAM HDD 1TB |
| 8 | *** | Intel Core i5 4590 x 4 | 3.30 GHz | 8GB RAM HDD 216.9 GB |
| 9 | --- | Intel Atom Processor | --- | --- |

| Computer | Time [s] | CPU | Cycles [GHz] | IPC |
|:--------:|:--------:|:---:|:------------:|:---:|
| 1 | 129,45 | 1,779 | 2,523 | 1,154 |
| 2 | 110,42 | 1,684 | 2,913 | 1,200 |
| 3 | 288,37 | 1,279 | 2,658 | 1,165 |
| 4 | 193,75 | 1,449 | 2,821 | 1,270 |
| 5 | 311,06 | 1,232 | 2,657 | 1,120 |
| 6 | 291,57 | 1,204 | 2,657 | 1,198 |
| 7 | 126,05 | 1,445 | 2,591 | 1,358 |
| 8 | 107,79 | 1,260 | 3,427 | 1,793 |
| 9 | 766,77 | 1,165 | 1,653 | 0,483 |

### Conclusão

Infelizmente, algumas máquinas têm poucas informações disponíveis acerca de sua configuração para avaliação. Por exemplo, a máquina mostrado como número 2 no benchmark do ImageMagick e número 3 no benchmark de convolução, que foi bem avaliada nos dois testes não especifica o processador intel core i7 que possui. Ainda assim, como foram disponibizadas várias máquinas nos dois teste, pode-se ter uma boa avaliação geral das máquinas e mais espeficamente dos processadores, visto que o clock e memória principal das máquinas pouco diferem uma das outras.

Analizando os processadores, destacan-se positivamente os processadores 
