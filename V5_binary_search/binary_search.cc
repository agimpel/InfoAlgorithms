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
// 'Programmierung eines binary sort'                 //
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
// Finde den Index des Arrays a, dessen Wert in a mit dem Integer s übereinstimmt, mithilfe eines binary sort.
// Gebe den gefundenen Index als return zurück. Bei keiner Übereinstimmung soll -1 zurückgegeben werden.
//
// HINWEISE
// Der Inhalt von Array a geht von 1 bis N, N+1 ist frei.
// s ist der in a gesuchte Integer, der sog. search key, und kommt nur einmal vor. 
// 

int binary_search(int N, int a[], int s){

  return 0;
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

int reference_binary_search(int N, int a[], int s){      // N ist die Länge des Arrays a, in dem der search key s gesucht ist
  int left = 1, right = N, middle;                       // Deklariere Positionen des Subintervalls und initialisiere sie auf das gesamte Intervall
                                                         //
  while(left <= right){                                  // Solange das Intervall mehr oder gleich eine Position umfasst
    middle = (left+right)/2;                             // Der neue Mittelpunkt ist die Mitte des Intervalls (Integerdivision!)
    if(s < a[middle]) right = middle-1;                  // Wenn der search key links der Mitte liegt, beginnt das neue Intervall eins rechts von der Mitte
    else if(s > a[middle]) left = middle+1;              // Wenn der search key rechts der Mitte liegt, beginnt das neue Intervall eins links von der Mitte
    else return middle;                                  // Wenn der search key genau in der Mitte liegt, gebe die Mitte als gefundener Index zurück
  }                                                      //
  return -1;                                             // Wenn der search key für links=rechts nicht in der Mitte liegt, terminiert der Loop
}                                                        // gebe den Fehlercode -1 aus, der für keine Übereinstimmung festgelegt wurde

//
// ENDE REFERENZFUNKTION
//




//
// Ab hier Rest des Programms
//

// function declarations
void read_input_file(int &N, int a[], int &s, int &s2);
bool check_result(int N, int r, int reference_r, int l, int reference_l);
void print_result(bool use_template_function, bool correct_result, int N, int s, int s2, int original[], int r, int reference_r, int l, int reference_l);


// main
int main(){

  int a[10000], original[10000], reference[10000];
  int r, reference_r, l, reference_l;
  r = reference_r = l = reference_l = 0;

  int N, s, s2;
  bool correct_result;

  read_input_file(N, a, s, s2);
  for(int i=0; i<=N; i++) original[i] = reference[i] = a[i];

  reference_r = reference_binary_search(N, reference, s);
  reference_l = reference_binary_search(N, reference, s2);
  if(use_template_function){
    r = binary_search(N, a, s);
    l = binary_search(N, a, s2);
    correct_result = check_result(N, r, reference_r, l, reference_l);
  }

  print_result(use_template_function, correct_result, N, s, s2, original, r, reference_r, l, reference_l);

  return 0;
}


// function definitions
void read_input_file(int &N, int a[], int &s, int &s2){
  ifstream input("input.txt");
  int i=0;
  input >> s;
  input >> s2;
  while(input >> a[i+1]) i++;
  N=i;
  input.close();
}

bool check_result(int N, int r, int reference_r, int l, int reference_l){
  if(r == reference_r && l == reference_l) return true;
  else return false;
}

void print_result(bool use_template_function, bool correct_result, int N, int s, int s2, int original[], int r, int reference_r, int l, int reference_l){
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "C++ - Template für binary search" << endl;
  cout << "Referenzalgorithmus basierend auf den Unterlagen von Prof. P. H. Hünenberger" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << endl;

  cout << "search key #1:     " << s << endl;
  cout << "search key #2:     " << s2 << endl;

  cout << "input array:       ";
  for(int i=1; i<=N; i++) cout << original[i] << " ";
  cout << endl;

  cout << "reference search:  " << "occurence at " << reference_r << " for key #1 and " << reference_l << " for key #2" << endl;

  if(use_template_function) {
    cout << "your search:       " << "occurence at " << r << " for key #1 and " << l << " for key #2" << endl;
    cout << endl;
    cout << endl;
    cout << "Dein Ergebnis stimmt ";
    if(!correct_result) cout << "nicht ";
    cout << "mit dem Referenzergebnis überein.";
    cout << endl << endl;
  }















}







