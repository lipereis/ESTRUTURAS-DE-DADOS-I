/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: JACSON MATTE
 ALUNO: FILIPE DOS REIS SANTOS
 EMAIL: lips.fr@gmail.com
 COMPILADO COM GCC NO AMBIENTE LINUX MINT KDE 17.3*/
 
						/*LISTA1 - EXERCÍCIO 01 - ALOCAÇÃO DINÂMICA DE MEMÓRIA*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main (){
	int *v;
	int *vv;
	int i = 0, count = TAM;
	
	v = (int*)malloc(TAM*sizeof(int));
	if(v == NULL){//TESTANDO SE A ALOÇÃO FOI BEM SUCEDIDA
		printf("Segmentation fault\n");
		exit(2);
	}
	
	
	printf("Preenchendo o vetor: \n");
	for(; i < count; i++){
		if(scanf("%d", &v[i]) == 0){
			break;
		}
		vv = (int*)realloc(v, count+TAM*sizeof(int));//REALOCANDO O VETOR
		if(vv == NULL){//TESTANDO SE A REALOCAÇÃO OCORREU COM SUCESSO
			printf("Segmentation fault\n");
			exit(2);
		}
		count = count+TAM;//INCREMENTO DO CONTADOR PARA AUXILIAR O PREENCHIMENTO DO VETOR
	}
	int j;
	for(j=0; j<i; j++){//IMPRIMINDO O VETOR
		printf("Posicao %d: %d\n", j+1, v[j]);
	}
	
	return 0;
}
