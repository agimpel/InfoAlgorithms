// // // // // // // // // // // // // // // // // // //
// C++ - Templates für Programmieraufgaben            //
// -------------------------------------------------- //
// basierend auf den Vorlesungs- und Prüfungsinhalten //
// der Vorlesung 529-0001-00L 'Informatik I'          //
// von Prof. P. H. Hünenberger im HS2015              //
//                                                    //
// zusammengestellt von Andreas Gimpel                //
// agimpel@student.ethz.ch                            //
// -------------------------------------------------- //
//                                                    //
// 'Programmierung eines sequential sort'             //
// siehe Vorlesungsskript (alt) S.175                 //
// siehe Vorlesungsskript (neu) S.217                 //
//                                                    //
// // // // // // // // // // // // // // // // // // //

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


//
// BEGINN TEMPLATE
// hier die Funktionsdefinition einfügen
// 
// AUFGABE
// Finde alle Indizes des Arrays a, deren Werte in a mit dem Integer s übereinstimmen, mit einem sequential search.
// Speichere alle gefundenen Indizes in r und die Gesamtzahl an Übereinstimmungen in l.
//
// HINWEISE
// Der Inhalt von Array a geht von 1 bis N, N+1 ist frei.
// s ist der in a gesuchte Integer, der sog. search key. 
// Die gefundenen Indizes sollen in r mit Element 1 beginnen (somit von 1 bis l laufen).
// 

void sequential_search(int N, int a[], int s, int r[], int &l){

}

//
// ENDE TEMPLATE
//


//soll die obige Funktion (noch) nicht verwendet werden, auf 'false' setzen:
bool use_template_function = true; 


// Korrekte Version des zu implementierten Algorithmus hier unten:
// 
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//
// |
// |
// V
//


//
// START REFERENZFUNKTION
//

void reference_sequential_search(int N, int a[], int s, int r[], int &l){   // N ist Länge des Arrays a, s ist der gesuchte integer, r der leere Array für die gefundenen Indizies und l die Anzahl Vorkommnisse
  int i = 1;                                                                // i ist Position innerhalb des Arrays, beginnt bei 1 da der Inhalt des Array bei 1 beginnt
  a[N+1] = s;                                                               // Setze an das Ende von a einen Sentinel
  l = 0;                                                                    // Bisher keine Übereinstimmung gefunden
                                                                            //
  while(i<=N){                                                              // Solange noch nicht bis zum Ende des Arrays gesucht wurde
    while(s != a[i]){                                                       // inkrementiere Position i im Array, bis search key s eine Übereinstimmung hat
      i++;                                                                  // an der Position i ist dann der search key gefunden
    }                                                                       //
                                                                            //
    if(i != N+1){                                                           // Wenn wir nicht den Sentinel an der Position N+1 gefunden haben:
      l++;                                                                  // wir haben eine neue echte Übereinstimmung, inkrementiere l
      r[l] = i;                                                             // die Übereinstimmung war an der Position i, speichere in Indizesarray r
      i++;                                                                  // wir suchen im nächsten Loop des while von der nächsten Position an weiter
    }                                                                       //
  }                                                                         // Am Ende ist der Array r an den Positionen 1 bis l mit den gefundenen Indizes gefüllt
}                                                                           // l ist die Gesamtanzahl der gefundenen Übereinstimmungen

//
// ENDE REFERENZFUNKTION
//




//
// Ab hier Rest des Programms
//

// function declarations
void read_input_file(int &N, int a[], int &s);
bool check_result(int N, int r[], int reference_r[], int l, int reference_l);
void print_result(bool use_template_function, bool correct_result, int N, int s, int original[], int r[], int reference_r[], int l, int reference_l);


// main
int main(){

  int a[10000], original[10000], reference[10000];
  int r[10000], reference_r[10000];
  for(int i=0; i<10000; i++) r[i] = reference_r[i] = 0;

  int N, s, l=0, reference_l=0;
  bool correct_result;

  read_input_file(N, a, s);
  for(int i=0; i<=N; i++) original[i] = reference[i] = a[i];

  reference_sequential_search(N, reference, s, reference_r, reference_l);
  if(use_template_function){
    sequential_search(N, a, s, r, l);
    correct_result = check_result(N, r, reference_r, l, reference_l);
  }

  print_result(use_template_function, correct_result, N, s, original, r, reference_r, l, reference_l);

  return 0;
}


// function definitions
void read_input_file(int &N, int a[], int &s){
  ifstream input("input.txt");
  int i=0;
  input >> s;
  while(input >> a[i+1]) i++;
  N=i;
  input.close();
}

bool check_result(int N, int r[], int reference_r[], int l, int reference_l){
  int i=0;
  while(i<N && r[i+1] == reference_r[i+1]) i++;
  if(i == N && l == reference_l) return true;
  else return false;
}

void print_result(bool use_template_function, bool correct_result, int N, int s, int original[], int r[], int reference_r[], int l, int reference_l){
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "C++ - Template für sequential search" << endl;
  cout << "Referenzalgorithmus basierend auf den Unterlagen von Prof. P. H. Hünenberger" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << endl;

  cout << "search key:        " << s << endl;

  cout << "input array:       ";
  for(int i=1; i<=N; i++) cout << original[i] << " ";
  cout << endl;

  cout << "reference search:  " << reference_l << " occurences at ";
  for(int i=1; i<=reference_l; i++) cout << reference_r[i] << " ";
  cout << endl;

  if(use_template_function) {
    cout << "your search:       " << l << " occurences at ";
    for(int i=1; i<=l; i++) cout << r[i] << " ";
    cout << endl;
    cout << endl;
    cout << "Dein Ergebnis stimmt ";
    if(!correct_result) cout << "nicht ";
    cout << "mit dem Referenzergebnis überein.";
    cout << endl << endl;
  }
}







