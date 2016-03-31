/*UNIVERSIDADE FEDERAL DA FRONTEIRA SUL
 PROFESSOR: JACSON MATTE
 ALUNO: FILIPE DOS REIS SANTOS
 EMAIL: lips.fr@gmail.com
 COMPILADO COM GCC NO AMBIENTE LINUX MINT KDE 17.3
 OBS: Todo o conhecimento, por mim adquirido para este trabalho, tem embasamento nas aulas e no livro
 do Waldemar Celes - Introdução a Estruturas de Dados - 7ª tiragem, da editora Elsevier*/
 
					/*ATIVIDADE DE SALA DE AULA - IMPLEMENTAÇÃO DE LISTA SIMPLES version 1.0*/
					
/*NOTA: As funções de adicionar e remover elementos, são implementadas de forma unificada, ou seja, adicionam ou removem quer seja 
 * no início, meio ou fim.
 * Obs: as inserções ocorrem de forma ordenada tal como as remoções*/					
					
#include <stdio.h>
#include <stdlib.h>

struct list{
	int n1;
	struct list *next;
};
typedef struct list List;

List *list_init(void){ //Inicializando a Lista como sendo vazia
	return NULL;
}

int list_void(List *li){ //Testando se a lista é vazia. Retorna 1 se vazia e 0 caso contrário
	return (li == NULL);
}

List *list_add(List *li, int n1){ //Adicionando elementos
	List *nodo = (List*)malloc(sizeof(List)); //alocação do novo elemento
	if(nodo == NULL){ //testando se a alocação foi bem sucedida
		printf("Segmentation Fault\n");
		exit(5);
	}
	nodo->n1 = n1; //atribuindo informações ao novo elemento
	nodo->next = NULL;
	if(list_void(li)){ //retorna a elemento recém alocado caso a lista seja vazia
		return nodo;
	}else{ //lista não vazia
		List *back = NULL, *front; //variáveis de suporte
		
		for(front = li; front != NULL && front->n1 < n1; front = front->next){
			back = front; //procurando a posição de inserção
		}
		if(back == NULL){ //inserção no início da lista
			nodo->next = li; //ajustes de encadeamento simples
			li = nodo;
		}else{ //inserção no meio ou final da lista
			nodo->next = back->next; //ajustes de encadeamento simples 
			back->next = nodo;
		}
	}
	return li; //retornando a lista com o novo elemento adicionado em ordem crescente
}

List *list_del(List *li, int n1){
	List *go = li; //variável suporte
	
	if(list_void(li)){ //retornando a propria lista caso seja vazia 
		return li;
	}else{ //não sendo vazia
		List *back = NULL; //variável suporte
		
		for(;go != NULL && go->n1 != n1; go = go->next){
			back = go; //procurando posição para remoção
		}
		if(back == NULL){ //remoção no início
			li = go->next; // ajuste de encadeamento simples
			free(go); //liberando a memória
		}else{ //remoção no meio ou final
			back->next = go->next; //ajuste de encadeamento simples
			free(go); //liberando a memória
		}
	}
	return li; //retorna a lista atualizada
}

void list_dest(List *li){ //Deletando todos os elementos da lista
	List *no = li; //variável auxiliar
	
	while(no != NULL){
		List *temp = no->next; //referência temporária ao próximo elemento
		free(no); //liberando elemento atual
		no = temp; //copiando a referência temporária por ser local do laço, enquanto
				//a variável suporte é local da função
	}
	free(li); //liberando a lista
}

void list_print(List *li){ //Imprimindo a lista
	List *go = li; //variável suporte
	
	for(; go != NULL; go = go->next){
		printf("%d\t", go->n1); //printando a informação
		//o "\t" imprime o elemento na mesma linha na próxima tabulação
	}
	printf("\n");
}

int main(){ //Programa cliente
	List *li; //"HEAD" da lista
	/*ESSE PROGRAMA CLIENTE FOI FEITO APENAS PARA TESTAR A EXECUÇÃO DAS FUNÇÕES QUE OPERAM A LISTA COM ENCADEAMENTO SIMPLES.*/
	li = list_init(); //Chamada à função de inicialização
	li = list_add(li, 8); //adicionando elementos
	li = list_add(li, 1);
	li = list_add(li, 5);
	li = list_add(li, 57);
	li = list_add(li, 3);
	li = list_add(li, 9);
	li = list_add(li, 1024);
	li = list_add(li, 512);
	li = list_add(li, 2048);
	li = list_add(li, 256);
	li = list_add(li, 128);
	li = list_add(li, 64);
	li = list_add(li, 22);
	li = list_add(li, 8);
	list_print(li); //imprimindo lista
	li = list_del(li, 512); //removendo elementos
	li = list_del(li, 2048);
	li = list_del(li, 256);
	li = list_del(li, 128);
	li = list_del(li, 64);
	li = list_del(li, 22);
	li = list_del(li, 8);
	list_print(li); //imprimindo lista
	
	if(list_void(li)){ //é vazia?
		printf("Lista vazia\n");
	}else{
		printf("Lista nao vazia\n");
	}
	
	list_dest(li); //Destroindo a lista
	li = list_init();//reinicializando a lista
	
	if(list_void(li)){ //é vazia?
		printf("Lista vazia\n");
	}else{
		printf("Lista nao vazia\n");
	}
		
	return 0; //encerrando execução
}
