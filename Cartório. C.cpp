#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h>  // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por string


int registro() //Função responsável por cadastrar usuários

{   
    //início criáção de váriáveis/strings
	char arquivo [40]; 
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final criaçã de variáveis/strings
	
	printf("Digite o cpf a ser cadatro: "); //coletando informações do usuário
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //abrir arquivo / "w" escrever o arquivo
	fprintf(file, cpf); //salvar valor da variável
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo / "a" atualizar o arquivo
	fprintf(file, ", "); // escrever no arquivo
	fclose(file); //fechar arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file= fopen(arquivo, "a"); // abrir arquivo / "a" atualizar arquivo
	fprintf(file, nome); //salvar valor da variável
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo / "a" atualizar arquivo
	fprintf(file, ", "); //escrever no arquivo
	fclose(file); //fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", sobrenome); //%s referesse a string
	
	file=fopen(arquivo, "a"); //abrir arquivo / "a" atualizar arquivo
	fprintf(file, sobrenome); //salvar valor da variável
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a"); //abrir arquivo/ "a" atualiza arquivo
	fprintf(file, ", "); // escrever no arquivo
	fclose(file); //fehcar arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cargo); //%s referesse a string
	
	file=fopen(arquivo, "a"); //abrir arquivo / "a' atualizar arquivo
	fprintf(file, cargo); //salvar valor da variável
	fclose(file); //fechar arquivo
	
	
	system("pause"); //aguardar resposta do usuário
}

int consulta() //função responsável por consultar usuários

{
	setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
	//início criáção de váriáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim criáção de váriáveis/strings
	
	printf("Digite cpf a ser consultado: "); //consultando usuário
	scanf("%s", cpf); //%s referesse a string
	
	FILE *file; //criando arquivo
	file = fopen(cpf, "r"); //abrir arquivo / "r" ler arquivo
	
	if(file == NULL) //
	{
		printf("\n Arquivo não localizado. \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as infromações do usuário: ");
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
		printf("\n Arquivo não localizado \n\n");
		
	}
	else
		printf("\n CPF deletado com sucesso \n\n");
	
	system("pause");	
}

int main()

{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=10;)
	{
		
		system("cls"); //limpar tela
		
		setlocale(LC_ALL, "Portuguese"); // definindo linguagem
	
		printf("\t\t\t\t\t### Cartório da EBAC ###\n\n"); // início menu
		printf("Escolha a opção desejada do menu: \n\n"
			"\t1 - Registrar nome\n"
			"\t2 - Consultar nomes\n" 
			"\t3 - Deletar nomes\n"
			"\t4 - Sair do sistema \n\n");
			
		printf("Opção:"); // fim menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls");
	
		switch(opcao) //váriável
		{
			case 1: // início seleção
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
			printf("Opção não disponível \n\n");
			system("pause");
			break;
		
		} // fim seleção
	}
}
