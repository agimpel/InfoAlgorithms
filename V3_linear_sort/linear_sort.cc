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
// 'Programmierung eines linear sort'                 //
// siehe Vorlesungsskript (alt) S.155ff               //
// siehe Vorlesungsskript (neu) S.196ff               //
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
// Sortiere die Integer im Array a nach ihrer Grösse, aufsteigend, mit einem linear sort.
// Die Keys der Elemente sind sequentiell von 1 bis 9.
//
// HINWEISE
// Der Inhalt des Arrays a geht von 1 bis N, 0 ist frei.
//

void linear_sort(int N, int a[]){

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

void reference_linear_sort(int N, int a[]){                    // N ist Länge des Integerarrays a, der von 1 bis N läuft (0 ist frei), die Keys gehen von 1 bis 9
  int n[9+1], b[N+1];                                          // initialisiere zwei Hilfsarrays, n für die Anzahl an Einträgen für jeden Key, b für das Einfüllen
                                                               //
  for(int k=1; k<=9; k++){                                     // setze alle Einträge in n auf 0
    n[k] = 0;                                                  // 
  }                                                            //
                                                               //
  for(int i=1; i<=N; i++){                                     // laufe durch a durch und erhöhe für jeden Key von a die Anzahl an Vorkommnissen
    n[a[i]]++;                                                 //
  }                                                            //
                                                               //
  n[0] = 1;                                                    // Fülle den Hilfsarray b bei Position 1 statt 0
                                                               //
  for(int k=1; k<=9; k++){                                     // Die Startposition von Key k ist der Wert von k-1 im Array n 
    n[k] += n[k-1];                                            // 
  }                                                            //
                                                               //
  for(int i=1; i<=N; i++){                                     // a[i] liefert Key k, Position von Key k im Array n ist k-1 (siehe oben), kopiere Wert von a[i]
    b[n[a[i]-1]++] = a[i];                                     // an diese Position im Array b, nächstes Mal muss derselbe Key k an die nächsthöhere Position
  }                                                            //
                                                               //
  for(int i=1; i<=N; i++){                                     // kopiere alle Werte aus dem Hilfsarray b zurück in den eigentlichen Array a
    a[i] = b[i];                                               //
  }                                                            //
}                                                              // 

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

  reference_linear_sort(N, reference);
  if(use_template_function){
    linear_sort(N, a);
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
  cout << "C++ - Template für das Programmieren eines linear sort" << endl;
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
