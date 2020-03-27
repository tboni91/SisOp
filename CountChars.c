#include <stdio.h>

/* ESERCIZIO Count Chars:
	- leggi da stdin fino a EOF e conta i caratteri: '\n', '\t' e ' ' (spazio)
	- dopo EOF, scrive su stdout il numero di occorrenze di ciascuno dei tre caratteri sopra
*/

int main(void) {
  int c;
  unsigned long counter[3] = { 0 };

  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\n': 
        counter[0]++;
        break;
      case '\t': 
        counter[1]++;
        break;
      case ' ':
        counter[2]++;
        break;
    }
  }

  printf("\nHo letto:\n%lu 'a capo'\n%lu 'tab'\n%lu 'spazio'\n", counter[0],  counter[1],  counter[2]);

  return 0;
}
