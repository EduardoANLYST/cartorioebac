#include <stdio.h>//biblioteca de comunicaçao com o usuario
#include <stdlib.h>//biblioteca alocaçao de espaço em memoria 
#include <locale.h>//biblioteca de alocomoçao de texto por regiao 
#include <string.h>// biblioteca responsavel por cuidar das string



    int registro()// finçao responsavel por cadastrar os usuarios no sistema 
{   // criaçao de variaveis / strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criaçao de variaves 
	
	printf("digite o cpf a ser cadastrado: \t");// coletando informaçoes do usuario
	scanf("%s,", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");
	fprintf (file, cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf(" digite o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf(" digite o sobrenome:");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s" , cargo);
	
	file = fopen (arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");
    

}
    int consultar()
    {
    	
		setlocale(LC_ALL, "Portugueses");// definindo  linguagem
		
		char cpf[40];
    	char conteudo[200];
    	
    	printf("digite o cpf  a ser consultado:");
    	scanf("%S" ,cpf);
    	
    	FILE *file;
    	file = fopen(cpf, "r");
    	
    	if(file == NULL)
    	{
    		printf (" nao foi possivel abrir o arquivo, nao localizado!.\n");
		}
        while(fgets(conteudo, 200, file)!=NULL)
        {
        	printf("\nEssas sao as informaçoes do usuario");
        	printf("%s", conteudo);
        	printf("\n\n");	
		}
		system("pause");
	}
	
	int deletar()
	{
		char cpf[40];
		
		printf("digite o cpf do usuario a ser deletado");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE * file;
		file =fopen (cpf, "r");
		
		if(file == NULL)
		{
			printf("usuario nao se encontra no sistema.\n");
			system("pause");
		}
	
	
	}
	
	
   int main()
   {	
   int opcao=0;// definindo as variaveis 
   int laco=1;
   
   for(laco=1;laco=1;)
   {
    system("cls"); // responsavel por limpara tela 
    
    setlocale(LC_ALL, "Portugueses");// definindo  linguagem
    
    printf("### cartorio da EBAC ###\n\n");//inicio do menu
    printf("escolha a opcao desejada do menu:\n\n");
    printf("\t1- registrar nome\n");
    printf("\t2- consultar nomes\n");
    printf("\t3- deletar nomes\n\n");//final de menu 
    printf("\t4- sair do sistema\nn");
	printf("opcao:");
    
	scanf ("%d", &opcao);//amrazenando escolha dos usuarios 

    system("cls");
    
    switch(opcao) //inicio da seleçao do menu 
{
	    case 1:
		registro();// chmaada de funçoes 
        break;
        
        case 2:
        consultar();
        break;
        
        case 3:
        deletar();
        break;
        
		case 4:
		printf("obrigado por ultilizar o sistema\n");
      	return 0;
      	break;
      	
        default:
        printf("essa opcao nao esta disponivel\n");
        system("pause");	
        break;

}

}

}

