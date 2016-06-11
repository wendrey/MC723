# Exercício 4

Wendrey Lustosa Cardoso
148234

### Introdução

O objetivo desta atividade é criar uma plataforma multicore com memória compartilhada e um periférico que implementa funcionalidade load-and-increment. Como sabemos, os computadores atuais fazem uso de processadores multicores e vários periféricos. 

O sistema operacional trata cada um dos núcleos de processamento existentes como um processador diferente e divide as tarefas entre eles. Na maioria dos casos, cada unidade possui sua própria cache e processa várias instruções quase simultaneamente. Processadores multicore são necessários devido a dificuldade de resfriar processadore singlecore com clocks muito alto, devido a concentração de transistores e devido ao tempo gasto em processadores singlecore na espera de dados obtidos através do acesso à memória. Outra vantagem do processamento em paralelo é a capacidade de cada núcleo ficar responsável pela execução de um aplicativo. Em outras palavras, processadores multicore possuem melhor desempenho.

Periféricos são equipamentos, acessórios ou aparelhos que enviam ou recebem informações da CPU (impressoras, leitores de CDs e cartões de memória, pen drive, mouses, teclados). Cada periférico tem uma função específica, desempenhada ao enviar e receber tarefas do computador.

### Periférico Básico

O programa **hello_base.c** foi usado para escrever no endereço base do periférico. Quando executado pelo simulador do mips, observamos na saída do mesmo (arquivo de saída **out_base**), o endereço e o valor (big endian) escritos no periférico em hexadecimal. Porém quando realizamos a leitura do valor escrito, recebemos como retorno zero. Para receber o valor escrito no periférico, alteramos o arquivo **ac_tlm_peripheral.cpp** para armazenar o último valor escrito e retorná-lo quando realizada uma leitura.

O ponteiro de acesso ao periférico precisa ser declarado como *volatile*, que indica que a variável pode ser alvo de modificação assíncrona concorrente por parte de outras threads em execução. Isso impede que o compilador faça otimizações em leituras ou escritas e reuse um valor incorreto para leitura ou não realize a escrita, ou seja, evita inconsistências. Variáveis desse tipo são usadas no acesso a hardware, onde leituras e escritas são usadas na comunicação com periféricos.

O programa **hello_read.c** foi usado para ler várias vezes do periférico e imprimir os valores obtidos (arquivo de saída **out_read**). Como não realizamos escritas nem diferenciamos as posições acessadas, o primeiro valor retornado é zero (valor inicial da variável de retorno) e os valores seguintes lidos são todos um (valor de retorno padrão definido em **ac_tlm_peripheral.cpp** caso haja mais de uma leitura após a última escrita), que devido a conversão para big endian e depois para decimal resulta em 16777216 na saída padrão. É interessante notar que a posição do lock mostrada na saída do programa possui passos de 04 unidades, que correspondem ao tamanho de um inteiro em bytes.

### Plataforma Multicore

Antes de fazer uso efetivo da plataforma multicore, tivemos que configurar corretamente os arquivos do simulador: dois processadores mips foram instanciados e conectados no roteador no arquivo **main.c**. Vale notar que os processadores são iniciados da mesma forma através do método _init_ e cada thread tem uma pilha de execução separada. Para separar a execução de cada thread, foi utilizada uma lógica de **lock** fazendo uso do periférico implementado em **ac_tlm_peripheral.cpp**.

A aplicação multicore **hello_multi.c** usa dois processadores para criar matrizes de dimensões 500x500 e opera sobre elas. Usamos o lock para diferenciar os processadores em 0 e 1 e assim dividir a execução do programa entre os cores. Numa primeita etapa, enquanto o **processador 0** cria uma matriz *_M1[i][j] = i+j_* o **processador 1** cria, paralelamente, uma matriz *_M2[i][j] = i-j_*. Em seguida, numa segunda etapa, realizamos uma multiplicação *_M1[i][j] = M1[i][j] * M2[i][j]_* entre os elementos das matrizes, o **processador 0** itera sobre os elementos entre _0 <= i < 500, 0 <= j < 250_, enquanto o **processador 1** itera sobre os elementos _0 <= i < 500, 250 <= j < 500_. A última etapa do programa é a impressão da matriz resultante pelo **processador 1**. Foi usada uma lógica de checkpoint para sincronizar as etapas do programa de forma a não ocorrer inconsistências devido a sobreposição das etapas pelos processadores.

Para compararmos melhor a distribuição de tarefas, foi utilizado o programa **hello_single.c**, que faz a mesma coisa que o programa **hello_multi.c**, porém utiliza apenas um dos cores disponíveis. Podemos ver, de acordo com a tabela abaixo, que a divisão de instruções é quase igual entre os cores no programa multicore, além disso, o total de instruções realizadas pelos dois programas é muito próximo. O ganho no tempo de execução da aplicação multicore é de cerca de 20% em relação a aplicação singlecore.

_Como a impressão da matriz resultante não pode ser paralelizada, e representa grande parte das instruções executadas, retiramos a impressão do programa para obter os valores da tabela_.

| Processador | Cores | Instruções | Time |
|:--:|:--:|:--:|:--:|
|||||
| 0 | singlecore | 6525798 | 0.49 |
| 1 | singlecore | 5803 | 0.49 |
|||||
| 0 | multicore | 3266854 | 0.39 |
| 1 | multicore | 3266855 | 0.39 |
