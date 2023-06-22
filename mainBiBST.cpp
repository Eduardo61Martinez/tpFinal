#include <iostream>
using namespace std;
#include <iomanip>
#include "TiposBasicos.h"
#include "TableroInfinito.h"
#include "BiBST.h"

int main(){
    BBNode* p =cabezal(1,1);
    /*
    insertBBNode(p,20,4);
    insertBBNode(p,11,4);
    insertBBNode(p,11,15);
    insertBBNode(p,10,5);
    insertBBNode(p,1,30);
    insertBBNode(p,1,10);
    insertBBNode(p,20,30);
    insertBBNode(p,0,0);
    insertBBNode(p,3,2);
    insertBBNode(p,1,1);
    //LiberarBiBST(p);
    PrintBB(p);*/
    
    BBNode* n = findBBNode(p,1,1); // lo encontró
    BBNode* q  = findBBNode(p,2,2); //está en el cuadrante NE
    BBNode* m = findBBNode(p,0,2); // está en el cuadrante NO
    BBNode* r = findBBNode (p,3, 1); //está en el cuadrante SE
    //BBNode* z = findBBNode (p,-1, -1); //está en el cuadrante SO
    PrintBB(n);
    PrintBB(q);
    PrintBB(m);
    PrintBB(r);
    //PrintBB(z);

}
