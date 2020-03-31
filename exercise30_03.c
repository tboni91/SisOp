#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

unsigned long fibonacci(unsigned int n);
unsigned long * fibonacci_array(unsigned int n);
unsigned long * make_copy_of_array(unsigned long * src_array, unsigned int array_dimension);
void swap_long(unsigned long *x, unsigned long *y);
unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j);
unsigned long * complete_reverse(unsigned long * array, unsigned int array_len);
void bubble_sort(unsigned long * array, unsigned int array_dimension);
int equals(unsigned long * array1, unsigned long * array2);

/* esercizio 2020-03-30*** (deve risultare un unico programma in C, scrivete tutto il codice sorgente in src/esercizio20200330.c)

A - scrivere la seguente funzione:

implementare una funzione che calcola la serie di Fibonacci:

unsigned long fibonacci(unsigned int n);

dove:
fibonacci(0) = 0
fibonacci(1) = 1
fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)  per n > 1

provare a scoprire quale è il valore massimo di n per cui fibonacci(n) restituisce un valore della serie corretto


B - scrivere la seguente funzione:

unsigned long * fibonacci_array(unsigned int n);

questa funzione restituisce un array di unsigned long di dimensione n+1 (n è l'argomento della funzione)
dove la cella i-ma contiene il valore di fibonacci(i).


C - main() fa queste operazioni:

calcola fibonacci_array(39) e lo assegna alla varibile 'fibonacci_result'  // fibonacci(39) = 63245986

fare una copia dell'array fibonacci_result in 'fibonacci_result_copy' (i due array devono avere aree di memoria distinte)

fibonacci_result_copy: fare il 'reverse' dell'array ('copiare' da esempio 004.1arrays-operations)

su fibonacci_result_copy: applicare bubble_sort ('copiare' da esempio 004.1arrays-operations)

confrontare fibonacci_result e fibonacci_result_copy, verificare che i due array siano uguali (scrivere su stdout il risultato).
*/


int main(int argc, char *argv[]) {
//	*** Test exercise A ***
//	unsigned int n = 0;
//	unsigned long r = 0;
//	unsigned long MAX_VALUE = 4294967295;
//
//	while (1) {
//		r = fibonacci(n);
//		if (r <= MAX_VALUE) {
//			printf("fibonacci(%u) = %lu\n", n, r);
//			n++;
//		} else
//			break;
//	}
//
//	printf("Overflow!\nMax fibonacci(%u)!!!", n-1);

//	*** Test exercise B ***
//	unsigned int n = 10;
//	unsigned long * fibo_array;
//
//	fibo_array = fibonacci_array(n);
//
//	printf("Fibonacci array = {\n");
//
//	for (int i = 0; i <= n;i++) {
//		printf("fibonacci(%u) = %lu\n", i, fibo_array[i]);
//		if (i != n)
//			printf(", ");
//	}
//
//	printf("}\n");
//
//	free(fibo_array);

//	*** Test exercise C ***
	unsigned int n = 39;
	unsigned long * fibonacci_result;
	unsigned long * fibonacci_result_copy;

	fibonacci_result = fibonacci_array(n);

	printf("fibonacci_result = { ");
	for (int i = 0; i <= n;i++) {
		printf("%lu", fibonacci_result[i]);
		if (i != n)
			printf(", ");
	}
	printf("}\n");

	fibonacci_result_copy = make_copy_of_array(fibonacci_result, n+1);

	if (fibonacci_result_copy == NULL) {
		perror("make_copy_of_array() ERROR");
		exit(EXIT_FAILURE);
	}

	printf("fibonacci_result_copy = { ");
	for (int i = 0; i <= n;i++) {
		printf("%lu", fibonacci_result_copy[i]);
		if (i != n)
			printf(", ");
	}
	printf("}\n");

	complete_reverse(fibonacci_result_copy, n+1);

	printf("fibonacci_result_copy (reverse) = { ");
	for (int i = 0; i <= n;i++) {
		printf("%lu", fibonacci_result_copy[i]);
		if (i != n)
			printf(", ");
	}
	printf("}\n");

	bubble_sort(fibonacci_result_copy, n+1);

	printf("fibonacci_result_copy (bubble_sort) = { ");
	for (int i = 0; i <= n;i++) {
		printf("%lu", fibonacci_result_copy[i]);
		if (i != n)
			printf(", ");
	}
	printf("}\n");

	printf("The two arrays are: \n");
	if (equals(fibonacci_result, fibonacci_result_copy))
		printf("EQUALS\n");
	else
		printf("NOT EQUALS\n");


	free(fibonacci_result);
	free(fibonacci_result_copy);

	return 0;
}


unsigned long fibonacci(unsigned int n) {
	unsigned long fn_2 = 0;
	unsigned long fn_1 = 1;
	unsigned long result = 0;

	switch (n) {
	case 0:
		result = fn_2;
		break;
	case 1:
		result = fn_1;
		break;
	default:
		for (int i = 1; i < n; i++) {
			result = fn_1 + fn_2;
			fn_2 = fn_1;
			fn_1 = result;
		}
		break;
	}

	return result;
}

unsigned long * fibonacci_array(unsigned int n) {
	unsigned long * result;

	result = calloc(n+1, sizeof(unsigned long));

	if (result == NULL) {
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i <= n; i++) {
		result[i] = fibonacci(i);
	}

	return result;
}

unsigned long * make_copy_of_array(unsigned long * src_array, unsigned int array_dimension) {

	if (src_array == NULL)
		return NULL;

	unsigned long * result;

	result = calloc(array_dimension, sizeof(unsigned long));

	if (result == NULL) {
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

	memcpy(result, src_array, array_dimension * sizeof(long));

	return result;
}

void swap_long(unsigned long *x, unsigned long *y) {
	unsigned long t = *x;
	*x = *y;
	*y = t;
}

unsigned long * reverse(unsigned long * array, unsigned int i, unsigned int j) {
	while (i < j)
		swap_long(&array[i++], &array[--j]);

	return array;
}

unsigned long * complete_reverse(unsigned long * array, unsigned int array_len) {
	return reverse(array, 0, array_len);
}

void bubble_sort(unsigned long * array, unsigned int array_dimension) {
  for (int i=0; i<array_dimension-1; i++) {
    for (int j=0; j<array_dimension-i-1; j++) {
      if (array[j] > array[j+1]) {
        swap_long(&array[j], &array[j+1]);
      }
    }
  }
}

int equals(unsigned long * array1, unsigned long * array2) {
	// mi segnala che sizeof(array1) / sizeof(unsigned long) non ritorna il numero di celle
  unsigned int dim1 = sizeof(array1) / sizeof(unsigned long);
	unsigned int dim2 = sizeof(array2) / sizeof(unsigned long);

	if (dim1 == dim2) {
		for (int i = 0; i <= dim1; i++) {
			if (array1[i] != array2[i])
				return 0;
		}
	} else
		return 0;

	return 1;
}

