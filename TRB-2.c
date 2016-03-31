/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: JACSON MATTE
 ALUNO: FILIPE DOS REIS SANTOS
 EMAIL: lips.fr@gmail.com
 COMPILADO COM GCC NO AMBIENTE LINUX MINT KDE 17.3*/
 
						/*TRABALHO 2 - IMPLEMENTAÇÃO DA ESTRUTURA PILHA USANDO VETOR*/
#include <stdio.h>
#include <stdlib.h>
#define LIM 31

struct pilha{ //ESTRUTURA QUE DEFINE A PILHA
	int topo;
	char pil[LIM];
};
typedef struct pilha PILHA;

PILHA *pilha_init(){ //INICIALIZANDO A PILHA COMO VETOR USANDO ALOCAÇÃO DINÂMICA
	PILHA *p;
	p = (PILHA*)malloc(sizeof(PILHA));
	if(p == NULL){
		printf("SEGMENTATION FAULT\n");
		exit(1);
	}
	p->topo = -1;
	return p;
}
void pilha_dell(PILHA *p){ //DESTRUINDO A PILHA
	free(p);
}

void pilha_push(PILHA *p, char c){ //FUNÇÃO QUE ADICIONA UM ELEMENTO NA PILHA
	if(p->topo == LIM){ //TESTANDO O LIMITE DA PILHA
		printf("ESTOURO DA PILHA\n");
		exit(1);
	}
	p->topo = p->topo+1;
	p->pil[p->topo] = c;
	
}

char pilha_pop(PILHA *p){ //FUNÇÃO QUE RETORNA O TOPO DA PILHA
	char c;
	if(p->topo == -1){
		printf("PILHA VAZIA\n");
		exit(1);
	}
	c = p->pil[p->topo];
	p->topo = p->topo-1;	
	return c;
}

void pilha_print(PILHA *p){ //FUNÇÃO QUE IMPRIME A PILHA
	int i;
	
	for(i = 0; i < p->topo; i++){
		printf("%c", p->pil[i]);
	}
	printf("\n");
}

int main(){
	PILHA *p = pilha_init();
	char vet[] = {"ESTE EXERCICIO EH MUITO FACIL"}, sup[LIM];
	int cont = 0, i, l , stop = -1;

	for(i = 0; ; i++){
		if(vet[i] == ' ' || vet[i] == '\0'){
			for(l = i-1; l > stop-1; l--){
				sup[cont] = vet[l]; //INVERTENDO AS PALAVRAS SEM ALTERAR SUA POSIÇÃO
				cont++;
			}
			sup[i] = vet[i];
			stop = i;
		}
		if(vet[i] == '\0'){
			break; //INTERROMPENDO O LOOPING AO ENCONTRAR O \0, POIS TALVEZ NÃO SE UTILIZE TODAS AS POSIÇÕES DO VETOR
		}
	}
	for(l = 0; l <= i; l++){
		pilha_push(p, sup[l]); //TRANSPORTANDO PARA A PILHA
	}
	/*OBS: Considere como sendo o topo da pilha o elemento mais a direita*/
	pilha_print(p);
	pilha_pop(p); //TESTANDO A FUNÇÃO POP
	pilha_pop(p);
	pilha_pop(p);
	pilha_pop(p);
	pilha_print(p);
	printf("TOPO DA PILHA: %d\n", p->topo);
	pilha_dell(p);
	return 0;
}
