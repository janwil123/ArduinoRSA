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

  BigNumber p   = "48112959837082048697";
  BigNumber q   = "54673257461630679457";
  //BigNumber p   = "1104427674207891849286335233";
  //BigNumber q   = "1119416189101109149181191199";
  BigNumber one = 1;
  BigNumber N   = p*q;
  printBignum(N);

  String d = "11111011011"; //2011, a prime
  int dl = d.length();

  BigNumber m = (p-one)*(q-one); //Just a large number a bit less than N
  BigNumber c = N-one; //The initial value should actually be 1, but the first squaring will then be too fast. c^2=1 mod N, too.
  
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
      c = (((c*m)%N)*c)%N;
      time2 = micros();
      Serial.print("Computing time: ");
      Serial.println(time2-time1);
    }
    d.remove(0,1);
  }
  printBignum(c);
}

void loop () { }
