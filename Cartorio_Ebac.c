#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // bibliote das strings

int registro()
{
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser registrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar o valor das strings
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salva valor variavel
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file =  fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
	
}

int consultar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf [40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não localizado.");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove (cpf);
	
	printf("O usuário foi deletado com sucesso!\n");
	system("pause");
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!");
		system("pause");	
	}
}


int main ()
{
    
    int laco=1;
    
    for(laco=1;laco=1;)
    {
       int opcao=0;
	   
	   system("cls");
	   
	   setlocale(LC_ALL, "portuguese");
	   
	   
	
	   printf ("\tCartório Ebac \n\n");
	   printf ("Como deseja continuar: \n\n");
       printf ("1 - Registrar nomes \n");
  	   printf ("2 - Consultar nomes \n");
	   printf ("3 - Deletar nomes \n");
	   printf ("4 - Sair do sistema\n\n");
	   printf ("Opção: ");
	   
	   scanf("%d", &opcao);

	
	   system("cls");
	   
	   switch(opcao)
	   {
	   	    case 1:
	   	    registro();
	   	    break;
	   	    
	   	    case 2:
	   	    consultar();
	   	    break;
	   	    
	   	    case 3:
	   	    deletar();
	   	    break;
	   	    
	   	    case 4:
	   	    printf("Obrigado por utilizar o sistema!\n");
	   	    return 0;
	   	    break; 
	   	    
	   	    default:
	   	    printf("Essa opção não está disponível!\n");
	   	    system("pause");
	   	    break;
	   	
	   }
    }	
}

