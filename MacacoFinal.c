#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TAM 4
#define TAM_C 5
#define qtd_P 500 

typedef struct{ //Registro Paciente
    int resultado;
} Paciente;

void carregaMatrizCompleta(char dna_C[][TAM_C])//Declara matriz manual
{
	char l, k;
	char a = 'a'; 
	char t = 't'; 
	char c = 'c'; 
	char g = 'g'; 
	
	for(l=0; l<TAM_C; l++){
		for(k=0; k<TAM_C; k++){
			printf("Informe o valor para dna[%i][%i]: ", l, k);
			scanf("%s", &dna_C[l][k]);
			
			if(dna_C[l][k] != a && dna_C[l][k] != t && dna_C[l][k] != c && dna_C[l][k] != g) //Verifica DNA
			{
				printf("\n Valor informado invalido");
				exit(0);
			}
		}
	}
}

void carregaMatrizAleatoria(char dna_C[][TAM_C])//Declara matriz aleatorio
{
	char l, k;
	srand(time(NULL));
	char sequencia[4]="atcg";
	for(l=0; l<TAM_C; l++){
		for(k=0; k<TAM_C; k++){
			dna_C[l][k] = sequencia[rand() % (sizeof(sequencia) - 1)];
		}
	}
}

void escreveMatriz(char dna_C[][TAM_C])//Escreve Matriz
{
	char l, k;
	for(l=0; l<TAM_C; l++){
		for(k=0; k<TAM_C; k++){
			printf("%c\t", dna_C[l][k]);
		}
		printf("\n");
	}
}

int verifica_horizontal(char dna[][TAM])//Linha horizotal
{
	int macaco = 0;
	int conce_letra= 0;
	int i=0;
	int j=0;
	for(i=0; i<TAM; i++)//Percore matriz
	{
		for(j=0; j<TAM; j++)
		{
			if(conce_letra+1 ==TAM)
			{
				break;
			}
			if(dna[i][j] == dna[i][j+1])//Verifica DNA
			{
				conce_letra += 1; 
			}else
			{			
				conce_letra= 0;
				break;
			}
		}	
	} 
	if(conce_letra+1 == TAM)
	{
		macaco = 1; 
	}
	return(macaco);
}

int verifica_vertical(char dna[][TAM])//Linha vertical
{
	int macaco = 0;
	int conce_letra= 0;
	int i=0;
	int j=0;
	for(i=0; i<TAM; i++)//Percore matriz
	{
		for(j=0; j<TAM; j++)
		{
			
			if(conce_letra+1 ==TAM)
			{
				break;
			}
			if(dna[j][i] == dna[j+1][i])//Verifica DNA
			{
				conce_letra += 1; 
				
			}else
			{			
				conce_letra= 0;
				break;
			}
		}		
	} 
	if(conce_letra+1 ==TAM)
		{
			macaco = 1; 
		}
	return(macaco);
}


int princDiag(char dna[][TAM])//Diagonais
{
	int macaco = 0;
	int conce_letra= 0;
	int i=0;
	for (i=0; i<TAM ; i++)
	{
		if(conce_letra+1 ==TAM)
		{
			break;
		}
			if(dna[i][i] == dna[i+1][i+1])//Verifica DNA
			{
				conce_letra += 1; 
			}else
			{			
				conce_letra= 0;
				break;
			}
		}	
		 if(conce_letra+1 ==TAM)
	{
			macaco = 1; 
	}

		return(macaco);
}
	

int segunDiag(char dna[][TAM])//Diagonais-2
{
	int macaco = 0;
	int conce_letra= 0;
	int i=0;
	int j=0;
	for (i=TAM-1; i>=0 ; i--)//Percore matriz
	{

		if(conce_letra+1 ==TAM)
		{
			break;
		}
	
		if(dna[i][j] == dna[i-1][j+1])//Verifica DNA
		{
			conce_letra += 1; 
		}else
		{			
			conce_letra= 0;
			break;
		}
		
		j+=1;
		}
			
		
	
	if(conce_letra+1 ==TAM)
	{
			macaco = 1; 
	}
		return(macaco);
}


int percorreMatriz(char dna_C[][TAM_C], char dna[][TAM])//percorre e analisa a matriz
{
	int l = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	int macaco = 0;
	
	for(l=0; l < TAM_C-3; l++)
	{	
			if(macaco == 1)
			{
				break;
			}
			for(k=0; k < TAM_C-3; k++)
			{
				for(i=0; i<TAM; i++){
					for(j=0; j<TAM; j++){		
						dna[i][j] = dna_C[l+i][k+j];				
					}	
				}
				
				//verificações	
				if(verifica_horizontal(dna) == 1 || verifica_vertical(dna) == 1 || princDiag(dna) == 1|| segunDiag(dna) == 1)				
				{
					macaco = 1;
					break;
				}
				else
				{				
					macaco = 0;
				}			
			}
			
		}
		return(macaco);
	}	


int main(){
	Paciente pacientes[qtd_P];
	int macaco = 0, i, modo, rodar;
	char dna[TAM][TAM];
	char dna_C[TAM_C][TAM_C];
	
	
	for(i=0; i<qtd_P; i++){
		printf("Adicionar paciente[Digite 1 para sim e 0 para nao]: ");
		scanf("%i", &rodar);
		if(rodar == 0)
		{
			exit(0);
		}
		
		printf("\nInforme o modo de receber o dna[Digite 0 para manual e 1 para aleatorio]: ");
		scanf("%i", &modo);
		if(modo == 0)
		{
			carregaMatrizCompleta(dna_C);
		}
		else
		{
			carregaMatrizAleatoria(dna_C);
		}
		
		printf("\n");
		escreveMatriz(dna_C);
		pacientes[i].resultado = percorreMatriz(dna_C, dna);
		printf("\n");
	 	if(	percorreMatriz(dna_C, dna) == 1 )
		{	
			printf("Resultado paciente[%i]:  Simio", i);
		}
		else
		{
			printf("Resultado paciente[%i]:  Humano", i);
		}	
		printf("\n");
	}
	
}
