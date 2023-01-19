#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //espaco da memoria biblioteca de alocacao
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int registro () // fun��o responsavel por cadastrar os usuarios no sistema

{
	//inicio cria��o de variaveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/string

    printf("Por favor, digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
    scanf("%s", cpf); //%s refere-se a strings

    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings

    FILE *file; 
    file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
    fprintf(file,cpf); //salva o valor da var
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite um nome a ser cadastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a"); 
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");

}

int consulta ()

{
    setlocale (LC_ALL, "portuguese"); //definicao do idioma/linguagem

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("N�o foi poss�vel abrir o arquivo. Dados n�o localizados. \n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\n Essas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}


int deletar ()
    
{
    char  cpf [40];
	
	printf("Por favor, digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	
	{ 
		printf("O usu�rio n�o consta em sistema. \n");
		system("pause");
	}
	
      
}

int main ()
	{
   int opcao=0; //definindo as variaveis
   int laco=1;
   char senhadigitada[10]="a";
   int comparacao;

   
   printf("### Cart�rio da EBAC ### \n \n");
   printf("Login de admnistrador! \n \n Digite sua senha: ");
   scanf("%s",senhadigitada);
	comparacao = strcmp(senhadigitada, "admin");

   
   if(comparacao == 0)

   {
   			system("cls"); 
	   		for (laco=1;laco=1;)
	   		{		
	    
			    setlocale (LC_ALL, "portuguese"); //definicao do idioma
			   
			    printf("### Cart�rio da EBAC ### \n \n"); //inicio do menu
			    printf("Escolha a op��o desejada do menu: \n \n");
			    printf("\t1 - Registrar nomes\n");
			    printf("\t2 - Consultar nomes\n");
			    printf("\t3 - Deletar nomes\n "); 
				printf("\t4 - Sair do sistema \n \n");
			    printf("Digite a op��o: "); //fim do menu
			    
			    scanf("%d", &opcao); //armazenamento da escolha do usuario
			
			    system("cls"); 
	
	        switch(opcao) //inicio da sele��o do menu
		        {
		                case 1:
		                registro(); //chamada de fun��es
		                break;
		
		                case 2:
		                consulta();
		                break;
		
		                case 3:
		                deletar();
		                break;
		                
		                case 4:
		                printf("Obrigadx por utilizar nosso sistema! \n At� logo! :) \n");
		                return 0;
		                break;
		
		                default: 
		                printf("Essa op��o n�o est� disponivel");
		                system("pause");
		                break;
		        }//fim da sele��o
    		}
     }
     
     else
     	printf("Senha incorreta!");
}

