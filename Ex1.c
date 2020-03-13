#include <stdio.h>

int main(int argc, char **argv) {

	ex1();

	return 0;
}

void ex1 () {
	char op;
	int n1 = 0;
	int n2 = 0;
	int res = 0;
	int control;

	printf("inserire la seguente tupla: operazione primo_numero secondo_numero\n");
	printf("dove: operazione = +,-,*,/\n");
	printf("inserire tupla: ");
	control = scanf("%c %d %d", &op, &n1, &n2);


	if (control == 3) {

		switch(op) {
				case '+':
					res = n1 + n2;
					break;
				case '-':
					res = n1 - n2;
					break;
				case '*':
					res = n1 * n2;
					break;
				case '/':
					res = n1 / n2;
					break;
		}

		printf("%d %c %d = %d", n1, op, n2, res);

	} else {
		printf("scanf ha resituito %d", control);
	}
}
