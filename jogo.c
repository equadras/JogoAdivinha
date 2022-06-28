#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//criar numero aleatorio
int sorteador(){
  srand(time(NULL));
  return rand() % 1000 + 1;;  
}

int jogo(){
  int tentativas, vida, chute, dificuldade;
  int resposta = sorteador(); 
  int historico[120]
// a cada jogo, o historico vai receber uma lista com as jogadas, o a resposta e a dificuldade, ficando assim no final [[3(diff), 245(resposta), (as jogadas)]]

  
//selecionar dificuldade
  printf("Vc quer jogar em qual dificuldade?\n1- Facil (15 vidas)\n2- Medio (7 vidas)\n3- Dificil (4 vidas)\n -> ");
  scanf("%d", &dificuldade);

  
  switch(dificuldade){
    case 1:{
//brincadeirinha 
      printf("Serio que vc escolheu o facil?? Escolha novamente porem certo desse vez...\n");
      printf("2- Medio (7 vidas)\n3- Dificil (4 vidas)\n -> ");
      scanf("%d", &dificuldade);
      break;
    }
    case 2:{ vida = 7;break;}
    case 3:{ vida = 4;break;}
    }
  switch(dificuldade){
    case 1:{
//eu achei engraçado
      printf("é pegadinha que vc escolheu de novo o facil, agora vai jogar no ultra dificil para aprender\n");
      vida = 3;
      break;
  }
    case 2:{ vida = 7;break;}
    case 3:{ vida = 4;break;}
    }

  tentativas = 0;
  printf("\n vidas -> %d\n",vida);
  do { 
//colocar maximo de tentativas
  if(tentativas >= vida){

//aqui precisa arrumar pra aparecer que era no max. vidas tentativas
    printf("Vc perdeu bobao!\nEram no max 5 tentativas e o numero era %d", resposta);
    break;
  }

//chutar ate achar a resposta
    scanf("%d", &chute);
    if (chute > resposta){
      printf("Numero muito alto, tente mais baixo!\n");
      tentativas = tentativas + 1;
      printf("Tentativas %d\n\n", tentativas);
    } if( chute < resposta){
        printf("Numero muito baixo, tente mais alto!\n");
        tentativas = tentativas + 1;
         printf("Tentativas %d\n\n", tentativas);
    } if (chute == resposta){
      printf("Voce acertou!! Foram %d tentativas\n", tentativas);
    }
    }    while ( chute != resposta);   

    return 1;
}

int main(){
    jogo();
    return EXIT_SUCCESS;
  }
