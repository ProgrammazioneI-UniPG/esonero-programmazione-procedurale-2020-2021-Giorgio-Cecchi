#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char M[128]="";
char K[128]="";
char C[128]="";
char M2[128]="";
int scelta=0;
int lunghezzaM=0;
int lunghezzaK=0;
int i=0;

int main()
{
  printf("Digitare una stringa di max 128 caratteri: ");
  fgets(M, 129, stdin);//per aquisire max 128 caratteri (cioè fino al 129esimo escluso)
  lunghezzaM = strlen (M);
  //il buffer deve essere svuotato degli eventuali caratteri in eccedenza rispetto ai max 128
  //acquisiti in M solo se i caratteri in M sono 128 e il 128esimo non è EOF
  if (lunghezzaM==128 && M[127] != '\n')
    while( getchar() != '\n');//elimino dal buffer i caratteri fino a EOF compreso
  printf("Digitare (1) se si vuole inserire manualmente la chiave di cifratura.\nDigitare (2) se si vuole far generare casualmente la chiave: ");
 do
   {
   scanf("%d", &scelta);
   while( getchar() != '\n');
   switch(scelta) //con lo switch si analizza il contenuto di scelta
     {
     case 1: //scelta=1 (chiave manuale)
       do
         { //blocco che verrà eseguito fino a quando la lunghezza K sarà inferiore a quella d M
         printf("Inserire la chiave di cifratura di lunghezza non inferiore alla stringa da cifrare (max 128 caratteri): \n");
         fgets(K, 129, stdin);
         lunghezzaK = strlen (K);
         if (lunghezzaK==128 && K[127] != '\n')// solo se i caratteri in K sono 128 e il 128esimo non è EOF
            while( getchar() != '\n');//elimino dal buffer i caratteri fino a EOF compreso
         } while(lunghezzaK < lunghezzaM);
     break;
     case 2: //scelta=2 (chiave generata casualmente)
       srand(time(NULL));//inizializzazione generazione numeri casuali
       for(i=0; i<lunghezzaM; i++)
         {
         K[i] = rand() % 96 + 32;//per evitare i caratteri 'speciali'
         }
         printf("La chiave generata è: %s\n", K);
     break;
     default: printf("Comando non valido\n Valori ammessi: 1 = chiave manuale, 2 = chiave generata casualmente\n");
     }
   } while(scelta != 1 && scelta != 2);//per valori diversi da 1 e 2 rimane nel loop

for(i=0; i<lunghezzaM; i++)//cifratura tramite XOR di M con K in C
  {
  C[i]= M[i] ^ K[i];
  }
printf("La stringa cifrata è:%s\n", C);

for(i=0; i<lunghezzaM; i++)//cifratura inversa tramite XOR di C con K in M2
  {
  M2[i] = C[i] ^ K[i];
  }
printf("La stringa ridecifrata è:%s\n", M2);
return 0;

}
