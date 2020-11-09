#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

void menu();
void randomkey();
void manualkey();
void xor();
char messaggio[129];
char key[129];
char m_output[129];

int main (){

  printf("Inserisci una stringa NON piu lunga di 128 caratteri:\n");  //richiesta stringa
  fgets(messaggio, 129, stdin);    // memorizzazo solamente i primi 128 caratteri

  printf("Messaggio iniziale: %s", messaggio);  //ristampo il messaggio iniziale
  int s;

      do{
          menu();  // invoco il metodo menu dove si potra scegleire
          xor(); // parte il metodo xor che lavora sulle variabili ormai riempite
          printf("\033[0;31m1- Menu\n!1- Esci\n"); //output con colore...
          scanf("%d", &s);
    }while(s==1);  // ripete la richiesta per le chiavi

return 0;
}

void menu(){
  printf("\033[0;31m"); // colore rosso per output
    int s;
    printf("**********************************************\n");
    printf("* 1- Inserire chiave per cifrare manualmente *\n");    // chiedo in che modo vuole riempire le variabili
    printf("* 2- Chiave randomica                        *\n");
    printf("**********************************************\n");
    scanf("%d", &s);
    if(s==1){
        manualkey();  // invoco il metodo manuale
    }else {
        randomkey();  // (altrimenti) invoco il metodo randomico
    }
}

void randomkey(){

  memset(key, 0, sizeof(key)); // pulisco la variabile
  int l= strlen(messaggio);
  time_t t;
  srand((unsigned) time(&t));
  for(int i =0; i< l; i++){        // faccio un ciclo lungo quanto il messaggio
    key[i]= rand()%128 ;   // aggiungo ad A un valore randomico fino a 26
  }
  printf("\033[1;32mChiave randomica: %s\n", key);

}

void xor(){
int l = strlen(messaggio);
for (int i=0; i<l; i++){              // ciclo lungo quanto il Messaggio
  m_output[i]=key[i]^messaggio[i];    // faccio la combinazione messaggio key
}
  printf("Messaggio cifrato: %s\n", m_output);

  char m;
  for (int i=0; i<l; i++){       // ciclo lungo quanto il Messaggio
    m=m_output[i]^key[i];        // metto su una variabile d'appoggio la combinazione cifrato e chiave
    m_output[i]=m;              // metto il risultato sulla sua cella...
  }
    printf("Messaggio decifrato: %s\n", m_output);

}

void manualkey(){

  memset(key, 0, sizeof(key)); // svuoto la key
  do{
      printf("\033[0;34mInserisci una chiave di Max 128 caratteri e NON piu corta del Messaggio:\n");
      fflush(stdin);   // pulisco il buffer
      fgets(key, 129, stdin);
  }while(strlen(key)<strlen(messaggio));  // ripeto l'input fino a che la key sara maggiore o uguale al messaggio
  printf("Chiave manuale: %s\n", key);

}
// author @andim
