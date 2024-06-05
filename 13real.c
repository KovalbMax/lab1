#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig){
	printf("Signal handler: %d.\n", sig);
}
int main(void){
	void (*f)(int);
	signal(SIGABRT, handler);
	signal(SIGFPE, handler);
	signal(SIGILL, handler);
	signal(SIGINT, handler);
	signal(SIGSEGV, handler);
	signal(SIGTERM, handler);
	int ch;
	printf("Vvedite cifru signala: \n1-SIGABRT\n2-SIGFPE\n3-SIGILL\n4-SIGINT\n5-SIGSEGV\n6-SIGTERM\n");
	scanf("%d", &ch);
	if (ch==1){
		raise(SIGABRT);
	}
	else if (ch == 2){
		raise(SIGFPE);
	}
	else if (ch == 3){
		raise(SIGILL);
	}
	else if (ch == 4){
		raise(SIGINT);
	}
	else if (ch == 5){
		raise(SIGSEGV);
	}
	else if (ch == 5){
		raise(SIGTERM);
	}
	
	
	
	return 0;
}