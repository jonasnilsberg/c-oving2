#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  
  // Oppgave 1a
  int i = 3;
  int j = 5;
  int *p = &i; // p er en peker som refererer til adressen til i
  int *q = &j; // q er en peker som refererer til adressen til j
  
  
  cout << "i: " << i << " Adresse: " << &i << endl;
  cout << "j: " << j << " Adresse: " << &j << endl;
  cout << "p: " << *p << " Adresse: " << p << endl;
  cout << "q: " << *q << " Adresse: " << q << endl;
  
  //Oppgave 1b
  
  *p = 7; // p peker på i. p = i = 7
  *q += 4; // q peker på j. q = j = 9
  *q = *p + 1; // *q = 7 + 1 = 8
  p = q; // p = q = 8
  cout << *p << " " << *q << endl; // Skriver ut 8 8
  
  /* Oppgave 2 ------------------------------------------------------------------------------
    char *linje = nullptr; // eller char *linje = 0;
    strcpy(linje, "Dette er en tekst");
    
    Ingenting vil skje siden *linje ikke refererer til en annen adresse.
  
  */
  // Oppgave 3 --------------------------------------------------------------------------------
  
  char tekst[5];
  char *pekeren = tekst;
  char letEtter = 'e';
  cin >> tekst;
  while (*pekeren != letEtter) {
     *pekeren = letEtter;
     pekeren++;
  }
  cout << tekst << endl;
  cout << pekeren << endl;
  
  /*
    Vist ikke "e" blir skrevet får vi stackoverflow error aka. stack smashing detected
    Uansett hva man skriver før e blir omgjort til e, slik at inputen nesten ikke har noe og si.
    pekeren peker på tekst, så når "pekeren" blir endret blir også tekst endret.
  */
  
  
  // Oppgave 4 ----------------------------------------------------------------------------------
  
  int a = 4;
  int b;
  b = 2;
  int *c;
  c = &b;
  a = b + *c;
  
  
  
  /*
  1. error: ‘b’ declared as reference but not initialized int &b; - Må deklarere b før den får en adresse
  2. error: invalid type argument of unary ‘*’ (have ‘int’) *a = *b + *c; - *a er ikke deklarert
  3. error: invalid type argument of unary ‘*’ (have ‘int’) *a = *b + *c; - *b er ikke deklarert og peker ikke på noen verdi
  4. error: lvalue required as left operand of assignment &b = 2; - Kan ikke deklarere en adresse til en tallverdi
  */
  
  // Oppgave 5 -------------------------------------------------------------------------------------
  
  double tall;
  double *peker = &tall;
  double &ref = tall;
  
  tall = 2;
  cout << tall << endl;
  
  *peker = 4;
  cout << tall << endl;
  
  ref = 6;
  cout << tall << endl;
  
}
