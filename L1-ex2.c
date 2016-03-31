/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: JACSON MATTE
 ALUNO: FILIPE DOS REIS SANTOS
 EMAIL: lips.fr@gmail.com
 COMPILADO COM GCC NO AMBIENTE LINUX MINT KDE 17.3*/
 
						/*LISTA1 - EXERCÍCIO 02 - ALOCAÇÃO DINÂMICA DE MEMÓRIA*/
#include <stdio.h>
#include <stdlib.h>

int *uniao (int *v1, int n1, int *v2, int n2){ //FUNÇÃO QUE EFETUA A UNIÃO SEM EXCLUSÃO DE ELEMENTOS REPETIDOS
	int *p = (int*)malloc((n1+n2)*sizeof(int));
	if(p == NULL){//TESTANDO SE A ALOCAÇÃO FOI BEM SUCEDIDA
		printf("Segmentation failed\n");
		exit(1);
	}
	
	int i;
	for(i=0; i< n1+n2; i++){
		if(i < n1){
			p[i] = v1[i];
		}else{
			p[i] = v2[i-n1];
		}
	}
	return p;
}
	
int main (){
	int *v3, i, n1, n2;
	int v1[] = {11,13,45,7}, v2[] = {24,4,16,81,10,12};
	
	n1 = 4;
	n2 = 6;
	v3 = uniao(v1,n1,v2,n2);
	
	for(i = 0; i < n1+n2; i++){ //IMPRIMINDO O TERCEIRO VETOR
		printf("%d\t", v3[i]);
	}
	printf("\n");
	
	return 0;
}
	
