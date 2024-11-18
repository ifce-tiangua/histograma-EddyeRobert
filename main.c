#include <stdio.h> 
#include <stdlib.h>

void imprime_histograma(int* vendas[], int num_categorias) {
    for (int i = 0; i < num_categorias; i++) {
        printf("%d ", *vendas[i]);
        for (int j = 0; j < *vendas[i]; j++) {
            printf("*");
        }
        if (i < num_categorias - 1) {
            printf("\\n"); 
        }
    }
}

int main() {
    int num_categorias;
    scanf("%d", &num_categorias);

    if (num_categorias == 0) {
        printf("vazio");
        return 0;
    }

    int** vendas = (int**)malloc(num_categorias * sizeof(int*));
    if (vendas == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (int i = 0; i < num_categorias; i++) {
        vendas[i] = (int*)malloc(sizeof(int));
        if (vendas[i] == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }
        scanf("%d", vendas[i]);
    }

    imprime_histograma(vendas, num_categorias);

    for (int i = 0; i < num_categorias; i++) {
        free(vendas[i]);
    }
    free(vendas);

    return 0;
}
