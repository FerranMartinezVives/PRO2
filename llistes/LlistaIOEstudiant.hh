#ifndef LLISTA_IO_ESTUDIANT
#define LLISTA_IO_ESTUDIANT

#include <iostream>
#include <list>
#include "Estudiant.hh"
using namespace std;

void LlegirLlistaEstudiant(list<Estudiant>& l);
/* Pre: l es vacia, en el canal estandar de entrada hay 0 o mas enteros 
   antes de "marca"  */
/* Post: l esta formada por los elementos leidos antes de "marca", en el
   orden de lectura */ 


void EscriureLlistaEstudiant(const list<Estudiant>& l);
/* Pre: cierto  */
/* Post: el contenido de l se ha escrito en el canal estandar de
   salida (el "begin" primero) */ 

#endif
