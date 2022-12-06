#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *vetor, int *vetor_aux, int esq, int dir) {
  if(esq == dir) { //se o elemento da esquerda for igual ao da direita, o vetor possui uma posição
    return;
  }
  if(dir - esq > 10) { //utilizando o insertion sort em arrays com menos de 10 elementos
    insertionSort(vetor, dir-esq);
  } else {
    int meio = (esq + dir) / 2;

    //chama a mesma função para as duas metades do array
    mergeSort(vetor_aux, vetor, esq, meio);
    mergeSort(vetor_aux, vetor, meio+1, dir);

    if(vetor[meio] <= vetor[meio+1]) { //impedir merge caso seja desnecessário
      return;
    }
    //função que combinará dois arrays
    merge(vetor, vetor_aux, esq, meio, dir);
  }

}
void merge(int *vetor, int *vetor_aux, int esq, int meio, int dir) {
  int i, j, k; //contadores
  //=====int *vetor_aux;

  //=====vetor_aux = (int *) malloc(sizeof(int) * dir+1); //alocação de memória para o vetor auxiliar

  //copiando o vetor no vetor auxiliar
  for(i = meio+1; i>esq; i--) { //primeira metade do vetor
    vetor_aux[i-1] = vetor[i-1] ;
  }
  for(j = meio; j<dir; j++) { //segunda metade do vetor
    vetor_aux[dir+meio-j] = vetor[j+1];
  }

  //comparando o elemento menor da primeira metade com o da segunda metade:
  for(k = esq; k<=dir; k++) {
    if(vetor_aux[j] < vetor_aux[i]) {
      vetor[k] = vetor_aux[j];
      j--;
    }
    else {
      vetor[k] = vetor_aux[i];
      i++;
    }
  }
}

void insertionSort(int *arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}



int main() {
  int i;
  int vetor[] = {12, 6, 16, 5, 20, 2, 10, 7, 19, 4, 8, 15, 22};
  int tamanho_vetor = sizeof(vetor) / sizeof(vetor[0]);
  int vetor_aux = (int *) malloc(sizeof(int) * tamanho_vetor); //alocação de memória para o vetor auxiliar

  printf("vetor antes da ordenacao:\n");
  for(i = 0; i<13; i++) {
    printf("%d ", vetor[i]);
  }

  mergeSort(vetor, vetor_aux, 0, tamanho_vetor - 1);

  printf("\n\nvetor apos a ordenacao:\n");
  for(i = 0; i<13; i++) {
    printf("%d ", vetor[i]);
  }
  return 0;
}
