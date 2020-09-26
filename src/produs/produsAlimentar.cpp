#include "produsAlimentar.h"

ProdusAlimentar::ProdusAlimentar()
{
	this->leiPerKg = -1;
	this->taraOrigine = placeHolder;
}

ProdusAlimentar::ProdusAlimentar(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Produs(categorie, id, nume, cantitate)
{
	this->leiPerKg = leiPerKg;
	this->taraOrigine = taraOrigine;
}

ProdusAlimentar::ProdusAlimentar(const ProdusAlimentar &pa) : Produs(pa)
{
	this->leiPerKg = pa.leiPerKg;
	this->taraOrigine = pa.taraOrigine;
}

void ProdusAlimentar::afisare()
{
	cout << "Produs alimentar" << endl;
	cout << "Nume produs: " << this->nume << endl;
	cout << "Categorie : " << this->categorie << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->cantitate << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->taraOrigine << endl
		 << endl;
}
// SET-eri
void ProdusAlimentar::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg = leiPerKg;
}

void ProdusAlimentar::setTaraDeOrigine(const string &taraOrigine)
{
	this->taraOrigine = taraOrigine;
}

// GET-eri
float ProdusAlimentar::getLeiPerKg()
{
	return this->leiPerKg;
}

string &ProdusAlimentar::getTaraDeOrigine()
{
	return this->taraOrigine;
}

// OPERATORI
bool ProdusAlimentar::operator==(const ProdusAlimentar &obj) const
{
	return (this->leiPerKg == obj.leiPerKg) ? true : false;
}

bool ProdusAlimentar::operator<(const ProdusAlimentar &obj) const
{
	return (this->leiPerKg < obj.leiPerKg) ? true : false;
}

bool ProdusAlimentar::operator>(const ProdusAlimentar &obj) const
{
	return (this->leiPerKg > obj.leiPerKg) ? true : false;
}

const ProdusAlimentar &ProdusAlimentar::operator=(const ProdusAlimentar &a)
{
	this->nume = a.nume;
	this->categorie = a.categorie;
	this->id = a.id;
	this->cantitate = a.cantitate;
	this->leiPerKg = a.leiPerKg;
	this->taraOrigine = a.taraOrigine;
	return *this;
}

string ProdusAlimentar::getProdusType()
{
	return "alimentar";
}

json ProdusAlimentar::toJSON()
{
	return json(*this);
}
