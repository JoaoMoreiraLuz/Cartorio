#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //v�riaveis e fun��es, vem dessa biblioteca.
#include <locale.h> //biblioteca que adiona o local e linguagem de onde o arquivo ir� rodar, no nosso caso, adiciona os acentos da linguagem brasileira
#include <string.h> //biblioteca respons�vel pelas strings

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
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //essa linha cria o arquivo para o banco de dados
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //linha respons�vel por salvar o valor da variavel
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
	printf("\tUsu�rio encontrado!\n\n");
	
	if(file == NULL)
	{
		system("cls"); 
		printf("CPF n�o encontrado, usu�rio n�o existe ou alguma falha de digita��o.\n");
		printf("Certifique-se que o CPF est� digitado corretamente.\n");
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
		printf("O usu�rio n�o est� cadastrado.\n");
		system("pause");
	}
	
		else
		{
			printf("Digite novamente o CPF para confirmar a dele��o: ");
			scanf("%s" ,cpf);
			
			FILE *file;
			file = fopen(cpf, "r");
			fclose(file);
			
			if(file == NULL)
			{
				printf("O CPF est� incorreto, cancelando o processo de dele��o.\n");
				system("pause");
			}
			else
			{
				remove(cpf);
				FILE *file;
				file = fopen(cpf, "r");
				fclose(file);
				
				printf("Usu�rio deletado com sucesso!\n");
			}
			
				system("pause");
		}
}

int main()
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			
			system("cls");
		
	
		setlocale(LC_ALL, "Portuguese");
	
	
		printf("--- Cart�rio da EBAC ---\n\n");
		printf("Escolha a op��o do menu:\n\n");
	
		printf("\tol� mundo, ol� tutor! :wave:\n\n"); //vou deixar essa linha s� pelo motivo que eu acho fofo o ol� mundo, se for um problema, depois eu tiro.
	
		printf("\t1 - registrar nomes\n"); //vale lembrar para o eu do futuro \n � um espa�o de linha, quase apertar um bot�o enter no teclado
		printf("\t2 - consultar nomes\n"); //j� o \t � um espa�o de linha, basicamente apertar TAB em uma linha no word!
		printf("\t3 - deletar nomes\n\n\n");
		printf("Op��o: ");
	
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
		
			default:
			printf("Essa op��o n�o existe\n");
			system("pause");
			break;
		}
	}
}					
