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
  // COMPLETAR
  BBNode *celdas;
  BBNode *cabezal;
}; 
/* INV.REP.:
  * COMPLETAR
*/

//--------------------------------------------------------------------------
TableroInfinito TInfInicial(){
  TableroInfinito  t = new TableroInfinitoHeader;
  BBNode* celdaInicial = new BBNode;
  celdaInicial->kx = 0;
  celdaInicial->ky = 0;
  t->celdas = celdaInicial;
  t->cabezal =celdaInicial;
  
  return t;
}

//--------------------------------------------------------------------------
void PonerNTInf(TableroInfinito t, Color color, int n){
  // PRECOND: el color es válido
  //t->celdas->bolitas[color]= n;
  t->cabezal->bolitas[color]= n;
}

//--------------------------------------------------------------------------
void SacarNTInf(TableroInfinito t, Color color, int n){
  // PRECOND:
  //  * el color es válido
  //  * hay al menos n bolitas en la celda actual en t
  if (   n <=   t->cabezal->bolitas[color]){
    t->cabezal->bolitas[color] -=n;
  }
  else{
    BOOM("No hay suficientes bolitas de ese color en la posición actual");
  }
}

//--------------------------------------------------------------------------
void MoverNTInf(TableroInfinito t, Dir dir, int n){
  // PRECOND: la dirección dada es válida
  
  int posX = t->cabezal->kx;
  int posY = t->cabezal->ky;
  if( dir == NORTE){
    posY += n;
  }
  else if ( dir == ESTE){
    posX += n;
  }else if (dir == OESTE){
    posX -= n;
  }else if (dir == SUR){
    posY -= n;
  }
  t->cabezal = insertBBNode(t->celdas, posX, posY);
}

//--------------------------------------------------------------------------
int nroBolitasTInf(TableroInfinito t, Color color) {
  // PRECOND: el color es válido

  return t->cabezal->bolitas[color];
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
  cout << "Celda actual:" << " (" <<t->cabezal->kx << "," << t->cabezal->ky<< ")" << endl;   
  PrintBB(t->celdas);
}
