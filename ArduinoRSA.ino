//Arduino RSA
#include "BigNumber.h"

int i;

// function to display a big number and free it afterwards
void printBignum (BigNumber & n)
{
  char * s = n.toString ();
  Serial.println (s);
  free (s);
}  // end of printBignum


void setup ()
{
  Serial.begin (9600);
  BigNumber::begin ();  // initialize library

  //BigNumber p   = 48112959837082048697;
  //BigNumber q   = 54673257461630679457;
  BigNumber one = 1;
  //BigNumber N   = p*q-one;

  BigNumber p = 2;
  

  BigNumber N = p.pow(137)-one; //Mersenne number 2^137-1 = 32032215596496435569*5439042183600204290159
  printBignum(N);

  //BigNumber d = 58021664585639791181184025950440248398226136069516938232493687505822471836536824298822733710342250697739996825938232641940670857624514103125986134050997697160127301547995788468137887651823707102007839;
  String d = "101";
  int dl = d.length();

  BigNumber m = 3;
  BigNumber c = 1;
  
  for(i=0; i<dl; i++){
    if (d[0] == '0'){
      c = (c*c)%N;
      Serial.println("Null");
      printBignum(c);
    }
    else {
      c = (c*c*m)%N;
      Serial.println("Yks");
      printBignum(c);
    }
    d.remove(0,1);
  }
  printBignum(c);
}

void loop () { }
