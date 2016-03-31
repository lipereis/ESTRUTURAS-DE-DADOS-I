/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: JACSON MATTE
 ALUNO: FILIPE DOS REIS SANTOS
 EMAIL: lips.fr@gmail.com
 COMPILADO COM GCC NO AMBIENTE LINUX MINT KDE 17.3*/
 
						/*TRABALHO 1 - ALOCAÇÃO DINÂMICA DE MEMÓRIA*/
#include <stdio.h>
#include <stdlib.h>

int main (){
	int i, j, linhas, colunas;
	int **p1;
	
	scanf("%d", &linhas); 
	printf("\n");
	
	
	p1 = (int**)malloc(sizeof(int*)*linhas); //ALOCA A ESTRUTURA EXTERNA DA MATRIZ E EM SEGUIDA TESTA A ALOCAÇÃO;
	if(p1 == NULL){
		printf("FALHA DE SEGMENTACAO\n");
		exit(1);
	}
	
	for(i = 0; i < linhas; i++){
		p1[i] = (int*)calloc(colunas = rand()%10,sizeof(int)); //A CADA ITERADA ALOCA-SE A ESTRUTURA MAIS INTERNA DA MATRIZ
															  //CRIANDO COLUNAS DE TAMANHO ALEATÓRIO FORMANDO A MATRIZ E EM SEGUIDA TESTA-SE A ALOCAÇÃO;
		if(p1 == NULL){
			printf("FALHA DE SEGMENTACAO\n");
			exit(1);
		}
		
		printf("%p\t", p1[i]);
		for(j = 0; j < colunas; j++){
			p1[i][j] = rand()%1000;
			printf("%d\t", p1[i][j]);
		}
		printf("\n");
	}
	
	for(i = 0; i < linhas; i++){//LIBERANDO A ESTRUTURA INTERNA DA MATRIZ DE PONTEIROS, OU SEJA, DESCONECTANDO A REFERÊNCIA AO PRIMEIRO
		free(p1[i]); 		//ELEMENTO DA LINHA QUE CONECTA AS COLUNAS;
	}
	free(p1); //LIBERANDO A ESTRUTURA EXTERNA DA MATRIZ;
	
	return 0;
}
