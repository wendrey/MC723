# Trabalho 1

Wendrey Lustosa Cardoso
148234

### Resumo

Para avaliar o desempenho das máquinas, vários computadores foram testados usando-se diferentes benchmarks. Os benchmarks usados que são destacados neste relatórios fazem referência ao [FFmpeg](https://github.com/RodolfoSeki/MC723/tree/master/projeto1), [Convolução](https://github.com/yugo4k/2016s1.mc723a.projeto1.parte1) e [ImageMagick](https://github.com/FelipeEmos/mc723/tree/master/projeto1/benchmark1). Todos computadores testados em cada benchmark são analisados comparativamente em relação às suas configurações e resultados nos tópicos subsequentes. Em seguida, segue uma comparação mais geral sobre os computadores específicos e comuns aos três benchmarks aqui destacados.

### FFmpeg

| Computer | Core | Clock | Cache Memory Disk |
|:---------------:|:----:|:-----:|:------:|
| 1 | Intel Core i7 3610QM x 4 | 2.30 GHz | L1 256KB L2 1024KB L3 6144KB |
| 2 | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 3 | Intel Core2 Duo T6500 x 2 | 2.10 GHz | 4GB RAM |
| 4 | Intel Core i7 4702MQ x 8 | 2.20 GHz |  8GB RAM |
| 5 | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 32GB HDD 1TB 5400rpm |
| 6 | Intel Core i7 4510U x 2 | 2.00 GHz | 8GB RAM | HD 5400rpm |
| 7 | Intel Core i7 3740QM x 2 | --- | --- |
| 8 | Intel Core i7 3612QM x 8 | 2.10 GHz | 8GB RAM SSD 240GB |
| 9 | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 10 | Intel Core i7 4700HQ x 4 | 2.40 GHz | 16GB RAM HDD SATA III 7200rpm |
| 11 | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB L2 256KB L3 3MB 8GB RAM HDD 1TB |
| 12 | Intel Core i5 4590 x 4 | 3.30 GHz | 8GB RAM HDD 216.9 GB |

| Computer | Time [s] | Page Faults | Stalled Cycles [G] | L1 Cache Load Misses [M] |
|:--------:|:--------:|:-----------:|:--------------:|:------------------------:|
| 1 | 29,60 | 29 618 | 149 800 | 2 377 |
| 2 |	32,58 | 16 470 | 17 251 | 918 |
| 3 | 69,65 |	12 112 | --- |	2 120 |
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

| Computer | Core | Clock | Cache Memory Disk |
|:---------------:|:----:|:-----:|:------:|
| 1 | Intel Core i7 3610QM x 4 | 2.30 GHz | L1 256KB L2 1024KB L3 6144KB |
| 2 | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 3 | Intel Core i7 × 4 | --- | 8GB RAM | --- |;
| 4 | Intel Core i7 3612QM x 4 | 2.10 GHz | 8GB RAM SSD 32GB HDD 1TB 5400rpm |
| 5 | Intel Core i7 4510U x 2 | 2.00 GHz | 8GB RAM | HD 5400rpm |
| 6 | Intel Core i7 3740QM x 2 | --- | --- |
| 7 | Intel Core i7 3612QM x 8 | 2.10 GHz | 8GB RAM SSD 240GB |
| 8 | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 9 | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB L2 256KB L3 3MB 8GB RAM HDD 1TB |
| 10 | Intel Core i7 2630QM | 2.00 GHz | 4GB RAM |
| 11 | Intel Core i7 | 2.30 GHz | 8GB RAM |

| Computer | Time [s] | Read Rate [MB/s] | Write Rate [MB/s] |
|:--------:|:--------:|:----------------:|:-----------------:|
| 1 | 7,98 | 1 780 | 2 360 |
| 2 | 13,70 | 14 | 92 |
| 3 | 7,90 | 1 627 | 3 703 |
| 4 | 36,30 | 1 085 | 2 021 |
| 5 | 10,46 |	1 840 | 3 144 | 
| 6 | 89,60 | 641 | 2781 |
| 7 | 7,60	 | 1 758 | 4031 |
| 8 | 123,70	| 11 | 878 |
| 9 | 14,18 | 1 426 | 2 413 |
| 10 | 7,01 | 1 103 |	2 7423 |
| 11 | 25,31 | 82 |	2 066 |

### ImageMagick

| Computer | Core | Clock | Cache Memory Disk |
|:---------------:|:----:|:-----:|:------:|
| 1 | AMD PhenonII x 4 | 3.2 MHz | 32MB Buffer 10GB RAM HDD SATA III 7200rpm |
| 2 | Intel Core i7 × 4 | --- | 8GB RAM | --- |
| 3 | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 4 | Intel Core i7 3612QM x 8 | 2.10 GHz | 8GB RAM SSD 240GB |
| 5 | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 6 | Intel Core2 Quad Q8400 x 4 | 2.66 GHz | 4GB |
| 7 | Intel Core i5 5200U x 4 | 2.20 GHz | L1 32KB L2 256KB L3 3MB 8GB RAM HDD 1TB |
| 8 | Intel Core i5 4590 x 4 | 3.30 GHz | 8GB RAM HDD 216.9 GB |
| 9 | Intel Atom Processor | --- | --- |

| Computer | Time [s] | CPU | Cycles [GHz] | IPC |
|:--------:|:--------:|:---:|:------------:|:----:|
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

