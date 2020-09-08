#include "userNonPremium.h"

using namespace std;

UserNonPremium::UserNonPremium(){}

  UserNonPremium::UserNonPremium(const string& judet, const string& localitate, const string& stradaf, int nr_stradaf, const string& blocf, int apartamentf, const string& stradal, int nr_stradal, const string& blocl, int apartamentl, int id, const string& nume, const string& prenume, const string& email, float costTransport) : User(judet, localitate, stradaf, nr_stradaf, blocf, apartamentf, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
  {
    this->costTransport = costTransport;
  }
  
  void UserNonPremium::setCostTransport(int cost)
  {
    costTransport = cost;
  }

  int UserNonPremium::getCostTransport()
  {
    return this->costTransport;
  }



  void UserNonPremium::vizualizareUser()
  {
    cout << "----------" << "USER NON-PREMIUM: " << this->UserId << "----------" << endl;
    cout<<"Nume: "<<this->nume<<endl;
    cout<<"Prenume: "<<this->prenume<<endl;
    cout<<"Email: "<<this->email<<endl;
    cout<<"Date Facturare: "<<this->dateFacturare;
    cout<<"Date Livrare: "<<this->dateLivrare;
    cout<<"Cost transport standard: "<<this->costTransport << endl;

  }

  json UserNonPremium::toJSON(){
    return json(*this);
  }