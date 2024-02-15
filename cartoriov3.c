#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //váriaveis e funções, vem dessa biblioteca.
#include <locale.h> //biblioteca que adiona o local e linguagem de onde o arquivo irá rodar, no nosso caso, adiciona os acentos da linguagem brasileira
#include <string.h> //biblioteca responsável pelas strings

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
	FILE *file; //essa linha cria o arquivo para o banco de dados
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //linha responsável por salvar o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}
	
int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	printf("\tUsuário encontrado!\n\n");
	
	if(file == NULL)
	{
		system("cls"); 
		printf("CPF não encontrado, usuário não existe ou alguma falha de digitação.\n");
		printf("Certifique-se que o CPF está digitado corretamente.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não está cadastrado.\n");
		system("pause");
	}
	
		else
		{
			printf("Digite novamente o CPF para confirmar a deleção: ");
			scanf("%s" ,cpf);
			
			FILE *file;
			file = fopen(cpf, "r");
			fclose(file);
			
			if(file == NULL)
			{
				printf("O CPF está incorreto, cancelando o processo de deleção.\n");
				system("pause");
			}
			else
			{
				remove(cpf);
				FILE *file;
				file = fopen(cpf, "r");
				fclose(file);
				
				printf("Usuário deletado com sucesso!\n");
			}
			
				system("pause");
		}
}

int main()
{
	
	setlocale(LC_ALL, "Portuguese");

	
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("--- Cartório da EBAC ---\n\n");
	printf("Login de adiminstrador\n\n");
	printf("Digite sua senha:  ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	
	
	
		for(laco=1;laco=1;)
		{
				
				system("cls");
			
		
			setlocale(LC_ALL, "Portuguese");
		
		
			printf("--- Cartório da EBAC ---\n\n");
			printf("Escolha a opção do menu:\n\n");
		
			printf("\thello world :wave:\n\n"); 
		
			printf("\t1 - registrar nomes\n"); //vale lembrar para o eu do futuro \n é um espaço de linha, quase apertar um botão enter no teclado
			printf("\t2 - consultar nomes\n"); //já o \t é um espaço de linha, basicamente apertar TAB em uma linha no word!
			printf("\t3 - deletar nomes\n");
			printf("\t4 - sair do sistema\n\n\n");
			printf("Opção: ");
		
			scanf("%d", &opcao);
		
			system("cls");
			
			switch(opcao)
			{
				case 1:
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("obrigado por utilizar o sistema!");
				return 0;
				break;
			
				default:
				printf("Essa opção não existe\n");
				system("pause");
				break;
			}
		
		}	
	}
	
	else
		printf("Senha incorreta");
}					
