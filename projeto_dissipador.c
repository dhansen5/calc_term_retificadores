#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Arquivos de texto
char arquivo[80];
char *PastaArquivo 		= "tmp/";    // NOME DA PASTA
char *ArquivoPackages	= "encapsulamentos";
char *ArquivoFinale	= arquivo;
char *ExtensaoArquivos 	= ".txt";
char *mode; 						//= "r";
char NomeArquivo[80];
char tipoPackage[80];
char Package[15];					// TABELA DE ENCAPSULAMENTOS
char jc[4];
char ja[4];
FILE *tfp;							// ARQUIVO DE ENCAPSULAMENTOS
FILE *efp;							// ARQUIVO DE RESULTADOS
char SelTipoArq;


// variaveis dos calculos
float vto,itmed,rt,itrms,P,				// Potencia
	  tamax,tjmax,rjc,rcd,rjd,rja,rda,	// Dissipador
	  tj_sem,tj_com,rja_sem,rja_com;
	  

char GeraNomeArquivoPack(int tipoArquivo){		// CAMINHO DO ARQUIVO DE ENCAPSULAMENTOS
	strcpy(NomeArquivo, "");
	strcat(NomeArquivo, PastaArquivo);
	strcat(NomeArquivo, ArquivoPackages);
	strcat(NomeArquivo, ExtensaoArquivos);
return(*NomeArquivo);}


AdicionaArquivoPack(char SelTipoArqModifica){	// ADICIONA ENCAPSULAMENTO � TABELA
GeraNomeArquivoPack(1);	
	printf("\n-> Encapsulamento:");
	scanf("%s",&Package);
	printf("\n-> Juncao-capsula [C/Watt]");
	scanf("%s",&jc);
	printf("\n-> Juncao-ambiente [C/Watt]");
	scanf("%s",&ja);
	
	mode = "a";
	tfp = fopen(NomeArquivo, mode);
	fprintf(tfp,"%s","\n");
	fprintf(tfp,"%s",Package);
	fprintf(tfp,"\t\t\t%s",jc);
	fprintf(tfp,"\t\t\t\t%s",ja);
	fclose(tfp);
}


void LeArquivo(char SelTipoArqLe){				// LE O ARQUIVO DE ENCAPSULAMENTOS
	GeraNomeArquivoPack(1);	
	char A;
	system("CLS");
	mode = "r";
	tfp = fopen(NomeArquivo, mode);
  		if (tfp == NULL) {
    	fprintf(stderr, "\n--> ERRO ARQUIVO NAO LIDO: %s.", NomeArquivo);
    	exit(1);}
	tfp = fopen(NomeArquivo, mode);    
	int c; c = getc(tfp);
   		while (c!= EOF) {putchar(c); c = getc(tfp);}
	fclose(tfp);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("[V]oltar ao Menu\n");
	printf("[A]dicionar encapsulamento\n");
	scanf("%c",&A);
	scanf("%c",&A);
  	A=toupper(A);
	switch(A) {
       case 'V' :
          break;
       case 'A' :
          AdicionaArquivoPack(SelTipoArq);
          break;
 
   		 }}
   		 
   		 
char GeraNomeArquivoFinal(int tipoArquivo){			// NOME DO ARQUIVO GERADO PELO USUARIO COM OS DADOS CALCULADOS
	strcpy(NomeArquivo, "");
	strcat(NomeArquivo, PastaArquivo);
	strcat(NomeArquivo, ArquivoFinale);
	strcat(NomeArquivo, ExtensaoArquivos);
return(*NomeArquivo);}
   		 
void ArquivoFinal(char SelTipoArqEscreve){

	system("CLS");	
	printf("\n-> Nome do Componente: ");
	scanf("%s",&arquivo);
	printf("\n-> Tipo de Encapsulamento: ");
	scanf("%s",&tipoPackage);
	
	GeraNomeArquivoFinal(1);	
	
mode = "w"; 	
efp = fopen(NomeArquivo, mode);						// ESCREVE NO ARQUIVO FINAL
fprintf(efp, "Nome do Componente: %s \n",arquivo);
fprintf(efp, "Tipo de Encapsulamento: %s \n",tipoPackage);
fprintf(efp, "Potencia Dissipada: %.3f Watts \n",P);
fprintf(efp, "Dissipador Recomendado: abaixo de %.3f C/Watt \n",rda);
fclose(efp);
printf("\n Arquivo Gerado com Sucesso.\n\n");
system("PAUSE");
}
   		 
	



void welcome(){
	printf("\n   ||========================================||\n");
	printf("   ||                             	     ||\n");
	printf("   ||   Calculo Termico para Retificadores   ||\n");
	printf("   ||                                        ||\n");
	printf("   ||  	 Criado por Douglas Hansen           ||\n");
	printf("   ||                                        ||\n");
	printf("   ||========================================||\n");	
	
}


void calc_junc(){
	
	char C;
	float rca;
	system("CLS");
	printf(" Para o calculo da temperatura de juncao sem o dissipador, informe");
	printf("\n a resistencia termica entre capsula e ambiente[C/Watt]: ");
	scanf("%f",&rca);
	rja_sem = rjc + rca;
	tj_sem = P * rja_sem + tamax;							// temperatura de jun��o sem dissipador
	rja_com = rda + rjd;
	tj_com = P * rja_com + tamax;							// temperatura de jun��o com dissipador
	printf("\n\n-> Temperatura de Juncao SEM o dissipador: %.2f C",tj_sem);
	printf("\n\n-> Temperatura de Juncao COM o dissipador: %.2f C",tj_com);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n\n-> Gostaria de imprimir um arquivo de texto?\n\n");
	printf("[S]im ou [N]ao?");
	scanf("%c",&C);	
	scanf("%c",&C);					
	C=toupper(C);
     if(C=='S')
     {
       ArquivoFinal(SelTipoArq);
 } 
else if (C=='N'){

	}	
}

void calc_D(){
	
	char C;
	system("CLS");
	printf("-> Informe os dados abaixo\n\n");
	if (P==0){
		printf("\n-> Potencia Dissipada[W] ");
		printf("\n\n--------------------------------------------------------------\n\n");
		scanf("%f",&P);
	}
	printf("\n-> Temperatura ambiente maxima[C]: ");
	scanf("%f",&tamax);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Temperatura maxima de juncao[C]: ");
	scanf("%f",&tjmax);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Resistencia termica entre juncao e capsula[C/Watt]: ");
	scanf("%f",&rjc);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Resistencia termica entre capsula e dissipador[C/Watt]: ");
	scanf("%f",&rcd);
	printf("\n\n--------------------------------------------------------------\n\n");
	rjd = rjc+rcd;												// calcula resistencia termica entre juncao e dissipador
	rja = (tjmax - tamax)/P;									// calcula resistencia termica entre juncao e ambiente
	rda = rja - rjd;											// calcula o dissipador 
	printf("\n-> Dissipador recomendado abaixo de %.3f C/Watt",rda);
	printf("\n\n-> Gostaria de calcular a temperatura de juncao do componente \n com e sem o dissipador?\n\n");
	printf("[S]im ou [N]ao?");
	scanf("%c",&C);	
	scanf("%c",&C);					
	C=toupper(C);
     if(C=='S')
     {
        calc_junc();
 } 
else if (C=='N'){
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n\n-> Gostaria de imprimir um arquivo de texto?\n\n");
	printf("[S]im ou [N]ao?");
	scanf("%c",&C);	
	scanf("%c",&C);					
	C=toupper(C);
     if(C=='S')
     {
       ArquivoFinal(SelTipoArq);
 } 
else if (C=='N'){

	}
	}	
}

void calc_P(){
	
	char C;
	system("CLS");
	printf("-> Informe os dados abaixo\n\n");
	printf("-> Queda de tensao sobre o componente[V]:");
	scanf("%f",&vto);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Corrente media que passa pelo componente[A]:");
	scanf("%f",&itmed);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Resistencia interna do componente[R]:");
	scanf("%f",&rt);
	printf("\n\n--------------------------------------------------------------\n\n");
	printf("\n-> Corrente eficaz que passa pelo componente[A]:");
	scanf("%f",&itrms);
	printf("\n\n--------------------------------------------------------------\n\n");
	P = vto * itmed + rt * pow(itrms,2);				// C�lculo da pot�ncia
	printf("\n-> Potencia dissipada: %.2f Watts\n\n",P);
	printf(" Gostaria de calcular o dissipador para este componente?\n\n");
	printf(" [S]im ou [N]ao?");
	scanf("%c",&C);	
	scanf("%c",&C);						
	C=toupper(C);
     if(C=='S')
     {
        calc_D();
 } 
else if (C=='N'){

	}	
}

void menu(){
	
	char C,A;

	do{	
	system("CLS");	
	welcome();	
	printf("\n   Digite [1] para calcular a potencia dissipada\n");
	printf("   Digite [2] para calcular o dissipador termico\n");
	printf("   Digite [3] para acessar a tabela com alguns dados de encapsulamentos\n");	
	printf("   Digite [S] para sair\n\n");
	if (A==1){
		printf("\n Opcao invalida!!\n");
	}
	A=2;
	scanf("%c",&C);
  	C=toupper(C);
  	
	switch(C) {
       case '1' :
          calc_P();
          break;
       case '2' :
          calc_D();
          break;
       case '3' :
          LeArquivo(SelTipoArq);
          break;
       case 'S' :
       	  printf(" Programa encerrado.\n" );
          exit(0);					// Encerra o Programa
          break;
       default :
	     A=1;
   		 }
	}while(A==1);
}

int main(void)
{
while(1){
menu();
}	
	system("PAUSE");
}
