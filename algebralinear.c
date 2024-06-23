#include <stdio.h>
#include <stdlib.h>

// Função para encontrar a raiz quadrada usando o método de Newton-Raphson
double minhaSqrt(double num) {
    double estimativa = 1.0;
    for (int i = 0; i < 10; i++) {
        estimativa = 0.5 * (estimativa + num / estimativa);
    }
    return estimativa;
}

// Função para testar se um fator é uma raiz de uma equação cúbica específica
int testarFator(int a, int b, int c, int d, int fator) {
    int resultado = a * fator * fator * fator + b * fator * fator + c * fator + d;
    return resultado == 0;
}

// Função para calcular autovetores dada uma matriz e autovalores
void calcular_autovetores(int mat[3][3], double lambda1, double lambda2, double lambda3, FILE *saida) {

    // Arrays para armazenar autovetores
    int autovetor1[3];
    int autovetor2[3];
    int autovetor3[3];

    // Loop para encontrar autovetores
    for (int i = -100; i <= 100; i++) {
        for (int j = -100; j <= 100; j++) {
            for (int k = -100; k <= 100; k++) {

                // Verifica se o vetor não é nulo
                if (i != 0 || j != 0 || k != 0) {

                    // Verifica se a matriz * autovetor = lambda * autovetor
                    if (mat[0][0] * i + mat[0][1] * j + mat[0][2] * k == lambda1 * i &&
                        mat[1][0] * i + mat[1][1] * j + mat[1][2] * k == lambda1 * j &&
                        mat[2][0] * i + mat[2][1] * j + mat[2][2] * k == lambda1 * k) {
                        autovetor1[0] = i;
                        autovetor1[1] = j;
                        autovetor1[2] = k;
                    }

                    if (mat[0][0] * i + mat[0][1] * j + mat[0][2] * k == lambda2 * i &&
                        mat[1][0] * i + mat[1][1] * j + mat[1][2] * k == lambda2 * j &&
                        mat[2][0] * i + mat[2][1] * j + mat[2][2] * k == lambda2 * k) {
                        autovetor2[0] = i;
                        autovetor2[1] = j;
                        autovetor2[2] = k;
                    }

                    if (mat[0][0] * i + mat[0][1] * j + mat[0][2] * k == lambda3 * i &&
                        mat[1][0] * i + mat[1][1] * j + mat[1][2] * k == lambda3 * j &&
                        mat[2][0] * i + mat[2][1] * j + mat[2][2] * k == lambda3 * k) {
                        autovetor3[0] = i;
                        autovetor3[1] = j;
                        autovetor3[2] = k;
                    }
                }

            }
        }
    }

    // Normalização dos autovetores
    for (int i = -100; i <= 100; i++) {
        if (i != 0 && autovetor1[0] % i == 0 && autovetor1[1] % i == 0 && autovetor1[2] % i == 0) {
            autovetor1[0] = autovetor1[0] / i;
            autovetor1[1] = autovetor1[1] / i;
            autovetor1[2] = autovetor1[2] / i;
        }

        if (i != 0 && autovetor2[0] % i == 0 && autovetor2[1] % i == 0 && autovetor2[2] % i == 0) {
            autovetor2[0] = autovetor2[0] / i;
            autovetor2[1] = autovetor2[1] / i;
            autovetor2[2] = autovetor2[2] / i;
        }

        if (i != 0 && autovetor3[0] % i == 0 && autovetor3[1] % i == 0 && autovetor3[2] % i == 0) {
            autovetor3[0] = autovetor3[0] / i;
            autovetor3[1] = autovetor3[1] / i;
            autovetor3[2] = autovetor3[2] / i;
        }
    }

    // Escreve os autovetores no arquivo de saída
    fprintf(saida, "\nAutovetores:\n");
    fprintf(saida, "%.2lf:\n", lambda1);
    fprintf(saida, "[(");
    for (int i = 0; i < 3; i++) {
        fprintf(saida, "%d ", autovetor1[i]);
    }
    fprintf(saida, ")]\n");

    fprintf(saida, "%.2lf:\n", lambda2);
    fprintf(saida, "[(");
    for (int i = 0; i < 3; i++) {
        fprintf(saida, "%d ", autovetor2[i]);
    }
    fprintf(saida, ")]\n");

    fprintf(saida, "%.2lf:\n", lambda3);
    fprintf(saida, "[(");
    for (int i = 0; i < 3; i++) {
        fprintf(saida, "%d ", autovetor3[i]);
    }
    fprintf(saida, ")]\n");
}

// Função para calcular autovetores dada uma matriz e autovalores
void autovetores(int matrix[3][3], double lambda1, double lambda2, double lambda3, FILE *arquivo) {
    int **mat, **mat1, **mat2;

    // Alocação dinâmica de matrizes
    mat = calloc(3, sizeof(int*));
    mat1 = calloc(3, sizeof(int*));
    mat2 = calloc(3, sizeof(int*));
    for (int i = 0; i < 3; i++) {
        mat[i] = calloc(3, sizeof(int));
        mat1[i] = calloc(3, sizeof(int));
        mat2[i] = calloc(3, sizeof(int));
        for (int j = 0; j < 3; j++) {
            mat[i][j] = matrix[i][j];
            mat1[i][j] = matrix[i][j];
            mat2[i][j] = matrix[i][j];
        }
    }

    // Subtrai os autovalores da diagonal principal
    for (int i = 0; i < 3; i++) {
        mat[i][i] = mat[i][i] - lambda1;
        mat1[i][i] = mat1[i][i] - lambda2;
        mat2[i][i] = mat2[i][i] - lambda3;
    }

    // Chama a função para calcular autovetores
    calcular_autovetores(matrix, lambda1, lambda2, lambda3, arquivo);
}

// Função para realizar a divisão sintética e encontrar autovalores de uma equação cúbica
void briotRuffini(FILE *saida, int a, int b, int c, int fator, int matrix[3][3]) {
    int novoA = a;
    int novoB = b + fator * a;
    int novoC = c + fator * novoB;

    // Calcula as raízes usando a função minhaSqrt
    int delta = novoB * novoB - 4 * novoA * novoC;
    double raiz1, raiz2;

    if (delta >= 0) {
        raiz1 = (-novoB + minhaSqrt(delta)) / (2 * novoA);
        raiz2 = (-novoB - minhaSqrt(delta)) / (2 * novoA);
    } else {
        // Caso de raízes complexas
        double parteReal = -novoB / (2 * novoA);
        double parteImaginaria = minhaSqrt(-delta) / (2 * novoA);
        raiz1 = parteReal + parteImaginaria;
        raiz2 = parteReal - parteImaginaria;
    }

    // Escreve informações sobre a equação cúbica no arquivo de saída
    fprintf(saida, "Polinomio caracteristico\n");
    fprintf(saida, "(x - %.2lf)(x - %.2lf)(x - %.2lf) = 0\n\nAutovalores:\nlambda1: %.2lf\nlambda2: %.2lf\nlambda3: %.2lf\n", (double)fator, raiz1, raiz2, (double)fator, raiz2, raiz1);
    fprintf(saida, "\nMatriz dos autovalores:\n");

    // Imprime a matriz dos autovalores no arquivo de saída
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0 && j == 0) {
                fprintf(saida, "%.2lf ", (double)fator);
            } else if (i == 1 && j == 1) {
                fprintf(saida, "%.2lf ", raiz2);
            } else if (i == 2 && j == 2) {
                fprintf(saida, "%.2lf ", raiz1);
            } else {
                fprintf(saida, "0 ");
            }
        }
        fprintf(saida, "\n");
    }

    // Chama a função para calcular autovetores
    autovetores(matrix, (double)fator, raiz1, raiz2, saida);
}

// Função para calcular os coeficientes do polinômio
void determinantea(int a, int b, int c, int d, int e, int f, int g, int h, int i, int *a1, int *b1, int *c1, int *d1) {
    *d1 = e * a * i + b * f * g + c * d * h - e * c * g - a * f * h - b * d * i;
    *c1 = f * h + b * d - e * a - a * i - e * i + c * g;
    *b1 = a + e + i;
    *a1 = -1;
}

// Função para transformar uma equação cúbica característica em uma quadrática e resolver
void equacaoCubicaParaSegundoGrau(FILE *saida, int matrix[3][3]) {
    int a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
    int d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
    int g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];
    int a1, b1, c1, d1;

    // Calcula os coeficientes da equação quadrática equivalente
    determinantea(a, b, c, d, e, f, g, h, i, &a1, &b1, &c1, &d1);

    // Se o coeficiente principal é diferente de zero
    if (d1 != 0) {
        // Procura por um fator que é raiz da equação cúbica
        for (int j = 1; j <= abs(d1); j++) {
            if (testarFator(a1, b1, c1, d1, j)) {
                // Se encontrar, chama a função para resolver a equação cúbica
                briotRuffini(saida, a1, b1, c1, j, matrix);
                return;
            }
        }
    }

    // Se não encontrar um fator, imprime mensagem de erro
    fprintf(saida, "Não foi possível resolver a equação cúbica.\n");
}

int main() {
    FILE *entrada, *saida;
    int matrizOriginal[3][3];

    // Abre o arquivo de entrada para leitura
    entrada = fopen("input.txt", "r");
    if (entrada == NULL) {
        printf("Erro\n");
        return 1;
    }

    // Lê a matriz do arquivo de entrada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(entrada, "%d", &matrizOriginal[i][j]);
        }
    }

    // Fecha o arquivo de entrada
    fclose(entrada);

    // Abre o arquivo de saída para escrita
    saida = fopen("analauraerafaelguerra.txt", "w");
    if (saida == NULL) {
        printf("Erro\n");
        return 1;
    }

    // Escreve informações no arquivo de saída
    fprintf(saida, "Ana Laura Machado e Rafael Guerra\n");
    fprintf(saida, "\n");

    // Imprime a matriz no arquivo de saída
    fprintf(saida, "Matriz de Entrada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(saida, "%d\t", matrizOriginal[i][j]);
        }
        fprintf(saida, "\n");
    }
    fprintf(saida, "\n");

    // Chama a função para resolver a equação cúbica no arquivo de saída
    equacaoCubicaParaSegundoGrau(saida, matrizOriginal);

    // Fecha o arquivo de saída
    fclose(saida);

    return 0;
}
