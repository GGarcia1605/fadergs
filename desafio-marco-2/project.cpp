#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
typedef struct{
	char word[100];
}INFORMACAO;

typedef struct arv{
	INFORMACAO info;
	struct arv* sube;
	struct arv* subd;
}ARVORE;

FILE open_file(int cod)
{
	FILE *question;	
	char text[100];
	switch(cod)
	{
		case 1:
			question = fopen("q1.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 2:
			question = fopen("q2.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 3:
			question = fopen("q3.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 4:
			question = fopen("q4.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 5:
			question = fopen("q5.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 6:
			question = fopen("q6.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 7:
			question = fopen("q7.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 8:
			question = fopen("q8.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		case 9:
			question = fopen("q9.txt","r");
			while(fgets(text,100,question)!=NULL)
				printf("%s",text);
			fclose(question);
			break;
		default:
			printf("Saindo");
			break;
	}
}

void cria_ARVORE( ARVORE** r ){
    *r = NULL; // arvore criada, raiz nao aponta
}

//FUN��O CONCATENA A ESCOLHA COM A RESPOSTA GRAVADA EM ARQUIVO

char* concatena(int n)
{
	char resposta[10] = "r.txt"; 		//digito da resposta
	char IntToStr[30];  		//resultado da concatenacao
	sprintf(IntToStr,"%d",n);	// converte o n em string
	strcat(IntToStr,resposta);	//junta o n�mero da resposta com r.txt = (numero)r.txt
	
	return IntToStr;		//retorno 
}

//ENTRADA DE DADOS

void entrada_dados( ARVORE* aux )
{  
    aux->subd = NULL;    // n�o aponta
    aux->sube = NULL;    // n�o aponta
}

//FUN��O INSERE = Insere os valores das respostas em �rvore
int insere( ARVORE** r,int codigo){
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p
    FILE* f; 
    int i;
	char resposta[100];
    p = *r;                            // posiciona ponteiro auxiliar
	ARVORE* no = (ARVORE*) malloc (sizeof(ARVORE));
		if(no !=NULL)
		{
			open_file(codigo);	//ABRE A PRIMEIRA PERGUNTA DA FUNCAO OPEN_FILE
			printf("\nResposta: ");
			scanf("%i",&i); //Op��o escolhida
			strcpy(resposta,concatena(i)); //copia para resposta o valor de retorno da fun��o concatena
			f = fopen(resposta,"r");	//abrindo arquivo (numero)r.txt 			 
			while(fgets(no->info.word,50,f)!=NULL)
			{
				entrada_dados( no );  // entrada do usu�rio
			 	if(*r == NULL)
			 		*r = no;	
				else 
				{
					if (i%2==1)
					{
						(*r)->subd = no; // insere a direita do registro folha
						printf("armazenou na folha");
					}
                    else
                         (*r)->sube = no; // insere a esquerda do registro folha		
				}
                    
			 	printf("Valor de word: %s\n",no->info.word);
			 	fclose(f);	//Fecha arquivo	
			}		
		}
		return i;
}

int main (void)
{
	ARVORE *r;			//ARVORE *r
	int codigo=1,res, viagem;		//c�digo inicia em 2 para a pergunta; 
	cria_ARVORE(&r);
	printf("Voc� quer viajar?\n 2 - 'Sim!'\n 0 - 'Nao'");
		scanf("%i", &viagem);
		if(viagem == 0)
			printf("Adeus! Estamos � sua disposi��o!\n");
		else
		  if(viagem == 2)	
			while(codigo != 0)		//enquanto for diferente de 0 continua o la�o
			{
				res = insere(&r,codigo); 	//res recebe o retorno da fun��o insere (i)
				switch(res)					//dependendo do retorno da fun��o insere, a pr�xima pergunta da �rvore � puxada, conforme a escolha indicada
				{
					case 2:
						codigo = 2;
						break;
					case 3:
						codigo = 3;
						break;
					case 4:
						codigo = 4;
						break;
					case 5:
						codigo = 5;
						break;
					case 6:
						codigo = 6;
						break;
					case 7:
						codigo = 7;
						break;
					case 8:
						codigo = 8;
						break;
					case 9:
						codigo = 9;
						break;
					case 10:
						codigo = 10;
						break;
					default:
						printf("Resposta inv�lida");
						break;					
				}
			}	  
		else
			printf("Volte mais tarde!\n");	
}	
