#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int valor, palpite, errou, contador, menor, maior;
	char nome[50];
	
	printf("Lembrete: Após terminada uma etapa, aperte enter!!");
	getch();
	system("cls");
	printf("Seja bem vindo, você está em um jogo de palpite. \nMas para começar, qual o seu nome?\n\nNome: ");
	scanf("%s", nome);
	
	printf("\n\nEscolha a faixa de números que você terá que acertar, %s. \nDe qual número a qual número você deseja que varie seu jogo?\nMenor número: ", nome);
	scanf("%d", &menor);
	printf("Maior número: ");
	scanf("%d", &maior);	
	
	srand((unsigned)time(NULL));
	valor = (menor+1) + (rand()%(maior-menor));

	system("cls");
	printf("Então vamos começar, %s, tente acertar um número que está entre %d e %d!\n", nome, menor, maior);
		
	errou = 1;
	contador = 0;
	while(errou)
	{
		contador++;
		printf("Chute um valor: ");
		scanf("%d", &palpite);
		if(palpite==valor)
		{
			printf("\nParabéns, %s, você acertou!!\n\n", nome);
			errou=0;
		}
		else
			(palpite<valor)?printf("Desculpe, mas você errou, o valor desejado é MAIOR que esse.\n"):printf("Desculpe, mas você errou, o valor desejado é MENOR que esse.\n");
	}

	if(contador==1)
	printf("Você precisou de apenas %d tentativa. O valor �: %d", contador, valor);
	if(contador!=1)
	printf("Você precisou de %d tentativas. O valor é: %d", contador, valor);
	getch();

	return 0;
}
