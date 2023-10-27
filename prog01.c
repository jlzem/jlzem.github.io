/* 
   Código demonstrativo para a aula de Sistemas Operacionais II,
   Curso de Ciência da Computação e Engenharia da Computação
   EEP.
   
   Exemplo sobre como criar, escrever, ler e remover um espaço mapeado de memória
   Para compilar use cc xxxxx.c -std=gnu99 -o xxxxx
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char * argv[]){
  char *mensagem = "Hello World.";
  int tamanho_mensagem = strlen(mensagem);
  system("clear");
  char *ptr = mmap ( NULL, tamanho_mensagem, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );
  if(ptr == MAP_FAILED){
    printf("\nErro: A criacao do mapeamento de memoria falhou.\n");
    return 1;
  }
  strcpy(ptr,mensagem);
  printf("\n[Pai] Mensagem recuperada: %s\n", ptr);
  printf("[Pai] Elementos da mensagem => ");
  for(int i=0; i < tamanho_mensagem; i++) {
	  printf("[%c] ",ptr[i]);
  }
  printf("\n"); 
  int err = munmap(ptr, tamanho_mensagem);
  if(err != 0){
     printf("\nErro: a remocao do mapeamento de memoria falhou.\n");
     return 1;
  }
  printf("\n"); 
  return 0;
}
