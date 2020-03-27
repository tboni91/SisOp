#include <stdio.h>
#include <stdlib.h>

/* ESERCIZIO Getchar Reverse:
  scrivere il seguente programma:

	- legge e salva (in memoria) tutti i dati provenienti da stdin fino a EOF

	- poi scrive su stdout i dati accumulati ma all'incontrario (dall'ultimo al primo)

	- suggerimenti: utilizzare getchar(), calloc(), realloc()
*/

int main(int argc, char *argv[]) {
  
  int c;
  int index = 0;
  unsigned long size = 1;
  
  char *char_array;
  
  char_array = calloc(size, sizeof(char));

  if (char_array == NULL) {
		perror("calloc error!");
		exit(EXIT_FAILURE);
	}

  while ((c = getchar()) != EOF) {
    char_array[index] = c;
    index++;
    size++;
    char_array = realloc(char_array, size*sizeof(char));
    
    if (char_array == NULL) {
		  perror("realloc error!");
		  exit(EXIT_FAILURE);
    }
  }

  printf("\nInserimento rovesciato:\n");

  for (int i=0; i<index; i++) {
    printf("%c",char_array[(index-1)-i]);
  }

	return 0;
}
