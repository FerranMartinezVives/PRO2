#include "Estudiant.hh"

/* Constants */

const char *ER1 = "No te nota";
const char *ER2 = "Valor de la nota entre 0 a 10";
const char *ER3 = "Ja te nota";
const char *ER4 = "El DNI es incorrecte";

Estudiant::Estudiant(){
  dni=0;
  nota = -1;
}

Estudiant::Estudiant(int dni)
{
  if (dni<0) throw PRO2Excepcio(ER4);
  this->dni = dni;
  nota = -1;
}

void Estudiant::operator=(const Estudiant& est) {
    dni = est.dni;
    nota = est.nota;
}

Estudiant::Estudiant(const Estudiant& est) {
    dni = est.dni;
    nota = est.nota;
}

Estudiant::~Estudiant() {}

void Estudiant::afegir_nota(double nota)
{
  if (this->nota >= 0 and this->nota <= MAX_NOTA) 
    throw PRO2Excepcio(ER3);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2); 
  
  this->nota = nota;
}

void Estudiant::modificar_nota(double nota)
{ 				
  if (this->nota < 0 or this->nota > MAX_NOTA) 
    throw PRO2Excepcio(ER1);
  if (nota<0 or nota>MAX_NOTA)
    throw PRO2Excepcio(ER2);
  this->nota = nota;
}

bool Estudiant::te_nota() const
{
  return nota >= 0 and nota <= MAX_NOTA;
}

double Estudiant::consultar_nota() const
{
  if (nota < 0 or nota > MAX_NOTA) throw PRO2Excepcio(ER1);
  return nota;
}

int Estudiant::consultar_DNI() const
{
  return dni;
}

double Estudiant::nota_maxima()
{
  return MAX_NOTA;
}

bool Estudiant::comp(const Estudiant& est1, const Estudiant& est2)
{
    return est1.dni < est2.dni;
}

void Estudiant::llegir()
{
  cin >> dni;
  if (dni<0) throw PRO2Excepcio(ER4);
  double x;
  cin >> x;
  nota = x;
}

void Estudiant::escriure() const
{
  if (nota >= 0 and nota <= MAX_NOTA)
    cout << dni << " " << nota << endl;
  else
    cout << dni <<" NP" << endl;
}
