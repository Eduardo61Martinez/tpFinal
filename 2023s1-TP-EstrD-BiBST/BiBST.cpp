#include <iostream>
#include <algorithm>
#include "BiBST.h"
using namespace std;


//==========================================================================
// Invariante de representación
//==========================================================================
/* INV.REP.
   * si el árbol tiene hijos :
   * su hijo[0] cumple que sus claves son mayores que las de la raíz del árbol (kx, ky)
   * su hijo[1] cumple que su primera clave es mayor que la primera de la raíz del árbol (kx), pero la segunda es menor o igual que la segunda clave de la raíz del árbol (ky).
   * su hijo[2] cumple que su primera clave es menor o igual que la primera de la raíz del árbol (kx), pero la segunda es mayor que la de la raíz del árbol (ky).
   * su hijo[3] cumple que alguna de sus dos claves es menor o igual que la correspondiente de la raiz (kx o ky) y la otra es menor.
*/

//==========================================================================
// Implementación
//==========================================================================

bool esDiferenteARaiz(BBNode* nodoB, int x, int y){
  return nodoB->kx !=x || nodoB->ky !=y;
}
bool esNodoVacio(BBNode* nodo){
  return nodo==NULL;
}

BBNode* findBBNode(BBNode* nodo, int x, int y) { 
  BBNode *nodoActual = nodo;
  while(!esNodoVacio(nodoActual) && esDiferenteARaiz(nodoActual, x, y)){
      Cuadrante cuadrante;
      if( x >nodoActual->kx  &&  y > nodoActual->ky  ){
        cuadrante= NE;               // NE
     
      }
      if( x > nodoActual->kx  &&  y <= nodoActual->ky ){
        cuadrante= SE;               //  SE

      }
      if(  x<=nodoActual->kx  &&  y > nodoActual->ky  ){
        cuadrante= NO;               //  NO

      }
      if ( ( x<=nodoActual->kx  &&  y <= nodoActual->ky) ){
        cuadrante= SO;             //    SO
      }
      else{
        return NULL;             //    SO
      }
      nodoActual = nodoActual->hijo[cuadrante];
  }

  return nodoActual;
}

BBNode* insertBBNode(BBNode* nodo, int x, int y) { 
  BBNode* nodoAnterior = NULL;
  BBNode* nodoActual = nodo;

  while (  !esNodoVacio(nodoActual) && esDiferenteARaiz(nodoActual,x,y)){
    nodoAnterior = nodoActual;
    Cuadrante cuadranteASeguir;
    if ( x >nodoActual->kx  &&  y > nodoActual->ky  ){
      cuadranteASeguir= NE;    
    }
    if ( x > nodoActual->kx  &&  y <= nodoActual->ky ){
      cuadranteASeguir= SE;    
    }
    if (x<=nodoActual->kx  &&  y > nodoActual->ky ){
      cuadranteASeguir= NO;    
    }
    
    if ( x<=nodoActual->kx  &&  y <= nodoActual->ky  ){
      cuadranteASeguir= SO;   
    }
    nodoActual = nodoActual->hijo[cuadranteASeguir];

  }
  BBNode* nuevoNodo = new BBNode;
  nuevoNodo->kx = x;
  nuevoNodo->ky = y;

  if ( !esNodoVacio(nodoActual)){ 
    return nodoActual;     // si  el nodo actual no es nulo es porque encontramos el nodo buscado.
  }
  else if( esNodoVacio(nodoAnterior)){
    nodo = nuevoNodo;      // este caso surge solo si el arbol es vacio y no tenemos ningun nodo. Creamos uno.
  }
  //en los siguientes casos agregamos el nuevo nodo como hijo del nodo anterior según corresponda.
  else if( x >nodoAnterior->kx  &&  y > nodoAnterior->ky  ){
    nodoAnterior->hijo[NE] =nuevoNodo;
  }
  else if (x > nodoAnterior->kx  &&  y <= nodoAnterior->ky ){
    nodoAnterior->hijo[SE] =nuevoNodo;
  }
  else if (x<=nodoAnterior->kx  &&  y > nodoAnterior->ky ){
    nodoAnterior->hijo[NO] =nuevoNodo;
  }
  else if ( x<=nodoAnterior->kx  &&  y <= nodoAnterior->ky  ){
    nodoAnterior->hijo[SO] =nuevoNodo;
  }

  return nuevoNodo; //devolvemos el nuevo nodo. 
}

void LiberarBiBST(BiBST t) {
    if (!esNodoVacio(t)) {
        LiberarBiBST(t->hijo[NE]);
        LiberarBiBST(t->hijo[SE]);
        LiberarBiBST(t->hijo[NO]);
        LiberarBiBST(t->hijo[SO]);
        delete t;
    }
    delete t;
}


//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintBBNode(BBNode* t, int tab) {
  if (t == NULL) { return; }
  INDENT(tab)
  cout << "  (" << t->kx << "," << t->ky << "): ";
  PRINTCOLORN(AZUL , t->bolitas[AZUL ]); 
  cout << ", "; PRINTCOLORN(NEGRO, t->bolitas[NEGRO]); 
  cout << ", "; PRINTCOLORN(ROJO , t->bolitas[ROJO ]); 
  cout << ", "; PRINTCOLORN(VERDE, t->bolitas[VERDE]); 
  cout << endl;
  PrintBBNode(t->hijo[NE], ++tab);
  PrintBBNode(t->hijo[SE], tab);
  PrintBBNode(t->hijo[NO], tab);
  PrintBBNode(t->hijo[SO], tab);
}

void PrintBB(BiBST t) {
  cout << "BiBST:" << endl;
  PrintBBNode(t, 0);
}

