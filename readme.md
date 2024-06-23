# Trabalho de Álgebra Linear - Autovalores e autovetores

### Introdução: 

Dada uma matriz quadrada de ordem $n$, $A$, estaremos entendendo por _autovalor_ e _autovetor_ de $A$, autovalor e autovetor da transformação linear $T_A:\mathbb{R}^n \rightarrow \mathbb{R}^n$, associada à matriz $A$ em relação à base canônica, isto é, $T_A (v) = A \cdot v$ (na forma coluna). Assim, um autovalor $\lambda \in \mathbb{R}$ de $A$, e um autovetor $v \in \mathbb{R}^n$, são soluções da equação $A \cdot v = \lambda v, v \neq 0$.


### Orientações gerais:
O objetivo deste trabalho é proporcionar aos alunos uma experiência prática na implementação de um algoritmo para a extração de autovalores e autovetores de uma matriz $3x3$. A implementação deve ser realizada em linguagem C, utilizando apenas as bibliotecas padrão `stdio.h` e `stdlib.h`.

1. Utilize somente as bibliotecas padrão `stdio.h` e `stdlib.h`.
2. Implemente funções modulares para cálculos específicos, facilitando a compreensão e manutenção do código.
3. Comente o código de forma adequada, explicando o propósito de cada seção e a lógica por trás das operações realizadas.
4. Poderá ser feito em **até** duas pessoas.


### Entrada
A entrada do algoritmo será fornecida em formato textual (.txt), seguindo a estrutura exemplificada abaixo. Cada linha do arquivo representa uma linha da matriz 3x3, e os valores dentro de cada linha são separados por espaços. Neste exemplo, a matriz é representada da seguinte forma:
```
3 0 -4
0 3 5
0 0 -1
```
Cada número corresponde a um elemento da matriz, organizado de maneira que a primeira linha do arquivo representa a primeira linha da matriz, a segunda linha do arquivo representa a segunda linha da matriz, e assim por diante. Este formato facilita a leitura dos dados da matriz durante a execução do programa, permitindo que o algoritmo processe corretamente a informação fornecida.

### Saída
A saída do programa será gerada em formato textual (.txt) e deve seguir a mesma estrutura exemplificada abaixo. Os nomes "Fulano" e "Beltrano" devem ser substituidos pelos nomes dos alunos da dupla (ou do aluno, caso faça individualmente). A saída incluirá a matriz de entrada, o polinômio característico, os autovalores encontrados, a matriz dos autovalores associados a cada autovalor, e os autovetores correspondentes. No exemplo fornecido:

```
Fulano e Beltrano

Matriz de entrada:
3 0 -4
0 3 5
0 0 -1

Polinomio caracteristico:
(x-3)^2 * (x+1) = 0

Autovalores:
lambda1 = 3
lambda2 = -1

Matriz dos autovalores:
3 0 0
0 3 0
0 0 -1

Autovetores associados a cada autovalor:
3:
[(1,0,0), (0,1,0)]

-1:
[(1,-5/4,1)]
```
