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

