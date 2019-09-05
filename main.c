/**
 * @authot: Rodrigo Andrade
 * @verion: 04/set/2019
 *
 * Jogo da forca para a disciplina de lógica de programação.
 *
 * Sistema operacional: ubuntu (linux);
 * Versão do compilador: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
 * Codificação do arquivo: Unicode-UTF-8
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Método mais eficaz para limpar o buffer do teclado
 * */
void clbuffer(void)
{
  char c = getchar();
  while(c != '\0' && c != '\n' && c != EOF);
}

/*
 * Inicia o estado da palavra, atribuindo a ela
 * o underline em todas as posições.
 * @param w_attempts string que vai armazenar a palavra de
 * tentativas.
 * @param word palavra original
 * */
void start_state(char *w_attempts, char *word)
{
  int i;
  for(i = 0; word[i] != '\0'; i++)
  {
    if(word[i] == ' ')
      w_attempts[i] = ' ';
    else
      w_attempts[i] = '_';
  }

  w_attempts[i] = '\0';
}

/**
 * Retorna a quantidade de ocorrências de uma
 * dada letra na string word;
 * @param letter letra a ser verificada
 * @param word palavra que contém a possivel letra
 * */
int exist_letter(char letter, char *word)
{
  int i = 0, quantity = 0;
  while(word[i] != '\0')
  {
    if(letter == word[i])
    {
      quantity++; 
    }
    i++;
  } 

  return quantity;
}

/**
 * Caso a ocorrência de letras seja maior que 1
 * retorna para um vetor de inteiros, as posições em 
 * que se encontra cada letra
 * @param letter letra a ser procurada
 * @param word palavra orignal que contém a letra
 * @param v_positions referência para um vetor de posições.
 * */
void positions(char letter, char *word, int *v_positions)
{
  int i = 0, index = 0;
  while(word[i] != '\0')
  {
    if(letter == word[i])
    {
      v_positions[index++] = i;
    }
    i++;
  }
}

/**
 * Retorna uma posição e somente uma posição da
 * primeira ocorrência de uma letra.
 * @param letter letra da ocorrência
 * @param word string original onde se encontra as ocorrências
 * */
int one_position(char letter, char *word)
{
  int i = 0;
  while(word[i] != '\0')
  {
    if(letter == word[i])
    {
      return i;
    }
    i++;
  }
   return -1;
}

/**
 * Atualiza a string de tentativas
 * @param w caracter a ser atualizado.
 * @param position posição do vetor que o caracter vai ser inserido.
 * @param w_attempts string de tetativas
 * */
void update_state(char w, int position, char *w_attempts)
{
  w_attempts[position] = w; 
}

/*
 * Desenha o personagem na tela conforme cada turno
 * de erro.
 * @param turn turno errado
 * */
void draw_sticker(int turn)
{
  switch(turn)
  {
    case 0:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|\n");
      printf("|\n");
      printf("|\n");
      printf("|\n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
    case 1:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|\n");
      printf("|\n");
      printf("|\n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
    case 2:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|\n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
    case 3:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|         / | \n");
      printf("|           |\n");
      printf("|\n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
  case 4:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|         / | \\\n");
      printf("|           |\n");
      printf("|           \n");
      printf("|           \n");
      printf("|\n");
      printf("-\n");
      printf("+\n");

   break;
   case 5:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|         / | \\\n");
      printf("|           |\n");
      printf("|          / \n");
      printf("|         /  \n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
    case 6:
      printf("|------------\n");
      printf("|           |\n");
      printf("|           |\n");
      printf("|          ---\n");
      printf("|           O\n");
      printf("|         / | \\\n");
      printf("|           |\n");
      printf("|          / \\\n");
      printf("|         /   \\\n");
      printf("|\n");
      printf("-\n");
      printf("+\n");
    break;
  }
}


int main(void)
{
  system("clear");

  //TODO Validar letras digitadas (aceitar, maisculas e minusculas).
  //TODO As palavras já digitadas.
  //TODO Dicas
  //TODO Impedir que o programa quebre caso digite dois caracteres seguidos. (validação da entrada).
  //TODO Permitir digitar a palavra completa caso já saiba.
  //TODO Recuperar palavras de um arquivo de forma aleatória.
  //TODO Tela de fim do jogo: (Ganhou e perdeu).


  // strings: Original e de tentativas 
  char word[] = "prefiro java mas tem que c";
  char w_attempts[strlen(word)];

  // Armazena a letra certa já digitada para não ter repetições
  char letter_buffers[strlen(word)];

  char letter;
  int occurrences;

  // Inicia o vetor de tentativas
  start_state(w_attempts, word);

  // Quantidade de vezes que errou
  int times = 0;

  // Game loop
  while(1)
  {
    system("clear");
 
    // Critério de derrota
    if(times == 6)
    {
      draw_sticker(6); // Desenha o sticker antes de sair do loop
      break;
    }

    // Critério de vitória
    if(strcmp(w_attempts, word) == 0)
    {
      draw_sticker(times); // Desenha o sticker no estado atual antes de sair do jogo
      printf("Palavra: %s\n", w_attempts); // Mostra o último estado da palavra antes de sair do loop
      break;
    }

    // Desenha na tela 
    draw_sticker(times);    
     
    printf("Palavra: %s\n", w_attempts);
    printf("Letra: ");
    scanf("%c", &letter);
    clbuffer();

    // Armazena a quantidade de posições encontradas
    occurrences= exist_letter(letter, word);

    if(occurrences == 0)
    {
      times++;
    } // Fim do if externo
    else
    {
      if(occurrences == 1)
      {
        // Atualiza apenas uma letra na string de tentativas
        int p = one_position(letter, word);
        update_state(letter, p, w_attempts);
      } // Fim do if interno
      else
      {
        // Vetor de posições
        int v_positions[occurrences];
        positions(letter, word, v_positions);

        // Pega cada ocorrência do vetor position e coloca a letra na posição da tentativa:
        for(int t = 0; t < occurrences; t++)
        {
          update_state(letter, v_positions[t], w_attempts);
        } // Fim do for
      } // Fim do else interno
    } // Fim do else externo
  } // Fim do Game loop

  return 0;
}

