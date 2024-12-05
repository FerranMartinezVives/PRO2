#ifndef LLISTA_IO_PARINT
#define LLISTA_IO_PARINT

#include <iostream>
#include <list>
#include "ParInt.hh"
using namespace std;

void llegir_llista_ParInt(list<ParInt>& l);
/* Pre: l es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca"  */
/* Post: l esta formada por los elementos leidos antes de "marca", en el
   orden de lectura */ 


void escriure_llista_ParInt(const list<ParInt>& l);
/* Pre: cierto  */
/* Post: el contenido de l se ha escrito en el canal estandar de
   salida (el "begin" primero) */ 

#endif
