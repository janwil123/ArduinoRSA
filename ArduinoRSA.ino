//Arduino RSA
#include "BigNumber.h"

int i;
unsigned long time1, time2;

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
  BigNumber q = 3;
  

  BigNumber N = p.pow(137)-one; //Mersenne number 2^137-1 = 32032215596496435569*5439042183600204290159
  printBignum(N);

  String d = "11111011011"; //2011, a prime
  int dl = d.length();

  BigNumber m = q.pow(86); //Just a large number a bit less than N
  BigNumber c = 1;
  
  for(i=0; i<dl; i++){
    if (d[0] == '0'){
      Serial.println("Null");
      time1 = micros();
      c = (c*c)%N;
      time2 = micros();
      Serial.print("Computing time: ");
      Serial.println(time2-time1);
    }
    else {
      Serial.println("Yks");
      time1 = micros();
      c = (((c*c)%N)*m)%N;
      time2 = micros();
      Serial.print("Computing time: ");
      Serial.println(time2-time1);
    }
    d.remove(0,1);
  }
  printBignum(c);
}

void loop () { }
