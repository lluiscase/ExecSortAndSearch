# ExecSortAndSearch
Exercicios referentes a materia de Estrutura de Dados II

- Explique por que a lista deve estar ordenada para que o Binary Search funcione corretamente: Ele precisa da lista ordenada para dividir ao meio e fazer uma comparação entre o meio e os demais
- Identifique casos em que o Interpolation Search é mais eficiente que o Binary Search: Lista de numeros consecutivos ou com intervalos regulares
- Compare o tempo de execução do Jump Search com o Binary Search em listas de diferentes tamanhos: Lista do jump ({1, 3, 5, 7, 9, 11, 13, 15};) = tempo 1424945825;  Lista do binary({11,12,14,15,16,17,18,19};) = tempo 0.000001
- Analise o desempenho do Exponential Search em listas muito grandes e pequenas:Pequena(0,0000001),Grande(0,00001)
- Explique como a escolha da sequência de intervalos afeta a eficiência do algoritmo: Você conquista a redução de passos, o que seria feito em dobro utilizando insertion, será feito pela metade ja que a organização de gaps prevem as repetições de passos(principalmente se for algoritmos com notações cientificas como o knuth)
- Analise o desempenho do Selection Sort em listas pequenas, médias e grandes: Pequena: 0.000001 / Média: 0.000001 / Grande: 0.000001
<<<<<<< HEAD
- Explique como o algoritmo lida com bases diferentes (ex.: base 10 e base 2): 
- Analise o desempenho do Quick Sort em listas quase ordenadas e completamente desordenadas: quase ordenada: 0.000001, desordenada: 0.00000001
- Identifique situações em que o Ternary Search seria mais eficiente que o Binary Search: Otimização é unimodal, redução do intervalo/comparação

| Tamanho da Lista | Binary Search | Interpolation Search | Jump Search | Exponential Search |
|-------------------|---------------|-----------------------|-------------|---------------------|
| 10               | O(log n)      | O(log log n) (se uniforme) | O(√n)      | O(log n)           |
| 100              | O(log n)      | O(log log n) (se uniforme) | O(√n)      | O(log n)           |
| 1.000            | O(log n)      | O(log log n) (se uniforme) | O(√n)      | O(log n)           |
| 10.000           | O(log n)      | O(log log n) (se uniforme) | O(√n)      | O(log n)           |
| 100.000          | O(log n)      | O(log log n) (se uniforme) | O(√n)      | O(log n)           |
- Quick sort: Não estável, Radix sort: Estável, Bucket sort: Estável, Selection sort: Não estável, Merge sort: Estável, Shell sort: Não estável
