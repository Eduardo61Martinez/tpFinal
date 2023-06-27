#include <iostream>
#include <iomanip>
#include <algorithm>
#include "TiposBasicos.h"
#include "TableroInfinito.h"
#include "BiBST.h"
using namespace std;

//==========================================================================
// Implementación de TableroInfinito
//==========================================================================
struct TableroInfinitoHeader {
  BiBST *celdas;
  int posX;
  int posY;

}; 
/* INV.REP.:
  *Ninguna
*/

//--------------------------------------------------------------------------
TableroInfinito TInfInicial(){
  TableroInfinito  t = new TableroInfinitoHeader;
  BBNode * nodoI =new BBNode;
  t->posX = 0;
  t->posY = 0;
  t->celdas =nodoI;
  return t;
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n){
  // PRECOND: el color es válido
  insertBBNode(t->celdas, t->posX, t->posY)->bolitas[color] = n; // pongo las bolitas de ese color.
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n){
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t

  BBNode  *nodoActual = findBBNode(t->celdas, t->posX, t->posY); // lo saco del if solo para una mejor lectura.
  if ( nodoActual == EMPTYBB  ||  nodoActual->bolitas[color] < n  ){
    BOOM("No hay suficientes bolitas de ese color en la posición actual");
  }
  else{
    nodoActual->bolitas[color]-=n;
  }
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  
  if( dir == NORTE){
     t->posY += n;
  }
  else if ( dir == ESTE){
    t->posX += n;
  }else if (dir == OESTE){
    t->posX -= n;
  }else if (dir == SUR){
    t->posY -= n;
  }
  //insertBBNode(t->celdas, t->posX, t->posY);
  findBBNode(t->celdas, t->posX, t->posY);
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color) {
  // PRECOND: el color es válido

  BBNode  *nodoActual = findBBNode(t->celdas, t->posX, t->posY); // lo saco del if solo para una mejor lectura.
  if ( nodoActual == EMPTYBB){
    return 0;
  }
  else{
    return nodoActual->bolitas[color];
  }
}

//--------------------------------------------------------------------------
void LiberarTInf(TableroInfinito t){
  LiberarBiBST(t->celdas);
  delete t;
}

//==========================================================================
// Impresión para verificaciones
//==========================================================================
void PrintRepTInf(TableroInfinito t) {
  // PISTA: utilizar PrintBB de BiBST
  cout << "Celda actual:" << " (" <<t->posX << "," << t->posY<< ")" << endl;   
  PrintBB(t->celdas);
}
