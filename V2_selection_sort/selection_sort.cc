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
// 'Programmierung eines selection sort'              //
// siehe Vorlesungsskript (alt) S.149ff               //
// siehe Vorlesungsskript (neu) S.190ff               //
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
// Sortiere die Integer im Array a nach ihrer Grösse, aufsteigend, mit einem selection sort.
//
// HINWEISE
// Der Inhalt des Arrays a geht von 1 bis N, 0 ist frei.
//

void selection_sort(int N, int a[]){

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

void reference_selection_sort(int N, int a[]){                 // N ist Länge des Integerarrays a, der von 1 bis N läuft (0 ist frei)
  int i, j, jm, at;                                            //
  for(i=1; i<=(N-1); i++){                                     // laufe über alle Elemente, bis auf das letzte (das dann schon sortiert ist)
    jm = i;                                                    // das momentane Element ist das kleinste bekannte Element bis hierhin
    for(j=(i+1); j<=N; j++){                                   // durchlaufe alle Elemente nach dem momentanen Element
      if(a[j] < a[jm]) jm = j;                                 // ist eines kleiner als das bisher kleinste Element, merke das neue kleinste Element
    }                                                          //
    at = a[i];                                                 // am Ende des Loops ist in jm das kleinste Element nach Element i im Array
    a[i] = a[jm];                                              // swappe Positionen i und jm über eine temporäre Variable
    a[jm] = at;                                                // war i das kleinste Element, so ist jm immernoch i
  }                                                            //
}                                                              // füge den momentanen Wert ein und wiederhole für nächsten Eintrag

//
// ENDE REFERENZFUNKTION
//




//
// Ab hier Rest des Programms
//

// function declarations
void read_input_file(int &N, int a[]);
bool check_result(int N, int a[], int reference[]);
void print_result(bool use_template_function, bool correct_result, int N, int original[], int a[], int reference[]);


// main
int main(){

  int a[10000], original[10000], reference[10000];
  int N;
  bool correct_result;

  read_input_file(N, a);
  for(int i=0; i<=N; i++) original[i] = reference[i] = a[i];

  reference_selection_sort(N, reference);
  if(use_template_function){
    selection_sort(N, a);
    correct_result = check_result(N, a, reference);
  }

  print_result(use_template_function, correct_result, N, original, a, reference);

  return 0;
}


// function definitions
void read_input_file(int &N, int a[]){
  ifstream input("input.txt");
  int i=0;
  while(input >> a[i+1]) i++;
  N=i;
  input.close();
}

bool check_result(int N, int a[], int reference[]){
  int i=0;
  while(i<N && a[i+1] == reference[i+1]) i++;
  if(i == N) return true;
  else return false;
}

void print_result(bool use_template_function, bool correct_result, int N, int original[], int a[], int reference[]){
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "C++ - Template für das Programmieren eines selection sort" << endl;
  cout << "Referenzalgorithmus basierend auf den Unterlagen von Prof. P. H. Hünenberger" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << endl;


  cout << "unsorted array:   ";
  for(int i=1; i<=N; i++) cout << original[i] << " ";
  cout << endl;

  cout << "reference sort:   "; 
  for(int i=1; i<=N; i++) cout << reference[i] << " ";
  cout << endl;

  if(use_template_function) {
    cout << "your result:      ";
    for(int i=1; i<=N; i++) cout << a[i] << " ";
    cout << endl;
    cout << endl;
    cout << "Dein Ergebnis stimmt ";
    if(!correct_result) cout << "nicht ";
    cout << "mit dem Referenzergebnis überein.";
    cout << endl << endl;
  }
}
