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
// 'Programmierung eines insertion sort'              //
// siehe Vorlesungsskript (alt) S.153ff               //
// siehe Vorlesungsskript (neu) S.193ff               //
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
// Sortiere die Integer im Array a nach ihrer Grösse, aufsteigend, mit einem insertion sort.
//
// HINWEISE
// Der Inhalt des Arrays a geht von 1 bis N, 0 ist frei.
//

void insertion_sort(int N, int a[]){

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

void reference_insertion_sort(int N, int a[]){                 // N ist Länge des Integerarrays a, der von 1 bis N läuft (0 ist frei)
  int i, j;                                                    // 
                                                               //
  for(i=2; i<=N; i++){                                         // laufe über alle Einträge von 2 bis N:
    a[0] = a[i];                                               // setze den Wert des momentanen Eintrags als Sentinel und Speicher an Stelle 0
    j = i;                                                     // setze die Startposition des zweiten Loops auf die momentane Position
    while(a[0] < a[j-1]){                                      // solange der Wert an der vorigen Position grösser als der betrachtete Wert ist:
      a[j] = a[j-1];                                           // setze den vorigen Wert eins nach hinten; Position j-1 ist jetzt frei
      j--;                                                     // schaue nächste Position (sprich ehemals j-1) an; j ist jetzt das ehemalige j-1
    }                                                          // Der Loop terminiert, sobald der Wert an der Position j-1 >= dem betrachteten Wert
    a[j] = a[0];                                               // 
  }                                                            // an der Stelle, ab der der vorige Wert grösser gleich dem momentanen ist:
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

  reference_insertion_sort(N, reference);
  if(use_template_function){
    insertion_sort(N, a);
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
  cout << "C++ - Template für das Programmieren eines insertion sort" << endl;
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
