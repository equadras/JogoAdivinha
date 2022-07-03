#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int numero_jogos = 0;
int historico[5];

int sorteador(){
  srand(time(NULL));
  return rand() % 100 + 1;  
}

void limpar_hist(){
  if (numero_jogos == 0){
    printf("\n-----NAO TEMOS JOGOS PARA LIMPAR-----\n");
    return;
  }
  for(int i=0; i <= 4; i ++){
    historico[i] = 0;
  }
  numero_jogos = 0;
  printf("\n-----HISTÓRICO LIMPO-----\n");
}

void mostrar_historico(){
  if (numero_jogos == 0){
    printf("\n-----NAO TEMOS JOGOS PARA MOSTRAR-----\n");
    return;
  }
  printf("\n-----HISTORICO DOS ULTIMOS 5 JOGOS-----\n");
  for (int i = 0; i < 5; i++) {
    printf("%d - tentativas %d\n", i + 1, historico[i]);
    if (i == numero_jogos - 1) {
      return;
    }
  }
}

int jogo(){
  int numero_sorteado = sorteador();
  int tentativa = 0; //numero de tentativas
  int escolha; //numero escolhido pelo usuario
  
  while (tentativa != 10) {  
    if (tentativa == 0) {
      printf("\nA maquina ja escolheu o numero dela entre 1 e 100, sera que vc consegue acertar ?\n");
      }
      printf("sua escolha -> ");
      scanf("%d", &escolha);

    if (escolha > numero_sorteado) {
      tentativa++;
      printf("%d é maior que o numero escolhido pela maquina, te restam %d vidas\n", escolha, (10 - tentativa));
    }
    if (escolha < numero_sorteado) {
      tentativa++;
      printf("%d é menor que o numero escolhido pela maquina, te restam %d vidas\n", escolha, (10 - tentativa));
    }
    if (escolha == numero_sorteado) {
      printf("\n-----%d É O NUMERO ESCOLHIDO PELA MAQUINA, VOCE VENCEU PAULO TORRENS-----\n", escolha);
      break;
    }
  }
  
  if(tentativa == 10) {
    printf("\n-----VOCE PERDEU BOBAO, ERA O NUMERO %d-----\n", numero_sorteado); 
  }
  
  numero_jogos++;

  if (numero_jogos > 5) {
  historico[0] = historico[1];
  historico[1] = historico[2];
  historico[2] = historico[3];
  historico[3] = historico[4];  
  }
  historico[numero_jogos - 1] = tentativa;

  return 1;
}
    

int main(){
  
  while(1){
  int opcao;
  printf("\n1-> Novo jogo\n2-> Ver ultimos 5 jogos\n3-> Limpar historico\n4-> Sair\nSua opção -> ");
  scanf("%d", &opcao);

  switch(opcao){
    case 1:{printf("\n-----INICIANDO O JOGO-----\n"); jogo(); break;};
    case 2:{mostrar_historico(); break;};
    case 3:{limpar_hist(); break;};
    case 4:{printf("desligando...\n"); return EXIT_SUCCESS;};
    default:{printf("\n-----OCORREU UM ERRO TENTE NOVAMENTE-----\n");}
  }
}
}
