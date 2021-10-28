#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

  char palavra[30];

  printf(" - - JOGO DA FORCA - -\n\n");
  
  printf("Digite a palavra para o seu adversário adivinhar: ");
  fgets(palavra, 30, stdin);
  palavra[strcspn(palavra, "\n")] = 0;
  getchar();
  

  int numerocaracteres = strlen(palavra);

  char acertadas[numerocaracteres];

  for (int i = 0; i < numerocaracteres; i++)
  {
    acertadas[i] = '_';
  }

  int letrascertas = 0;
  int vidas = 5;

  do
  {
    printf("\n\nPalavra secreta: ");

    for (int i = 0; i < numerocaracteres; i++)
    {

      printf("%c", acertadas[i]);

    }

    char letra;
    printf("\n\nLetra>: ");
    scanf("%c", &letra);
    getchar();

  int acerto = 0;

    for(int i = 0; i < numerocaracteres; i++)
    {

      if(letra == palavra[i])
      {

        acertadas[i] = letra;


        acerto = 1;
      }

    }
    if(acerto == 0)
    {
      
      vidas--;
      printf("Você errou! Cuidado, te restam agora %i vidas.", vidas);
    }
      else
    {

      letrascertas++;

    }
    printf("\n\n-------------------------------------------------");
  }
  while((letrascertas < numerocaracteres) && vidas > 0) ;

  if(letrascertas == numerocaracteres)
  {
  
    printf("\n\nVocê venceeeeu! Parabéns! E te restava %i vidas.", vidas);

  }
  else
  {

    printf("\n\nSinto muito... você perdeu. :(");

  }

  return 0;
}