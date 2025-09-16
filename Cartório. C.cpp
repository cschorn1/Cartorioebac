#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por string


int registro() //Fun��o respons�vel por cadastrar usu�rios

{   
    //in�cio cri���o de v�ri�veis/strings
	char arquivo [40]; 
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final cria�� de vari�veis/strings
	
	printf("Digite o cpf a ser cadatro: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //abrir arquivo / "w" escrever o arquivo
	fprintf(file, cpf); //salvar valor da vari�vel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo / "a" atualizar o arquivo
	fprintf(file, ", "); // escrever no arquivo
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file= fopen(arquivo, "a"); // abrir arquivo / "a" atualizar arquivo
	fprintf(file, nome); //salvar valor da vari�vel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo / "a" atualizar arquivo
	fprintf(file, ", "); //escrever no arquivo
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", sobrenome); //%s referesse a string
	
	file=fopen(arquivo, "a"); //abrir arquivo / "a" atualizar arquivo
	fprintf(file, sobrenome); //salvar valor da vari�vel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo/ "a" atualiza arquivo
	fprintf(file, ", "); // escrever no arquivo
	fclose(file); //fehcar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cargo); //%s referesse a string
	
	file=fopen(arquivo, "a"); //abrir arquivo / "a' atualizar arquivo
	fprintf(file, cargo); //salvar valor da vari�vel
	fclose(file); //fechar arquivo
	
	
	system("pause"); //aguardar resposta do usu�rio
}

int consulta() //fun��o respons�vel por consultar usu�rios

{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	//in�cio cri���o de v�ri�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim cri���o de v�ri�veis/strings
	
	printf("Digite cpf a ser consultado: "); //consultando usu�rio
	scanf("%s", cpf); //%s referesse a string
	
	FILE *file; //criando arquivo
	file = fopen(cpf, "r"); //abrir arquivo / "r" ler arquivo
	
	if(file == NULL) //
	{
		printf("\n Arquivo n�o localizado. \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as infroma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()

{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("\n Arquivo n�o localizado \n\n");
		
	}
	else
		printf("\n CPF deletado com sucesso \n\n");
	
	system("pause");	
}

int main()

{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=10;)
	{
		
		system("cls"); //limpar tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf("\t\t\t\t\t### Cart�rio da EBAC ###\n\n"); // in�cio menu
		printf("Escolha a op��o desejada do menu: \n\n"
			"\t1 - Registrar nome\n"
			"\t2 - Consultar nomes\n" 
			"\t3 - Deletar nomes\n"
			"\t4 - Sair do sistema \n\n");
			
		printf("Op��o:"); // fim menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls");
	
		switch(opcao) //v�ri�vel
		{
			case 1: // in�cio sele��o
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Op��o n�o dispon�vel \n\n");
			system("pause");
			break;
		
		} // fim sele��o
	}
}
