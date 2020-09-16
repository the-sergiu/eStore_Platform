#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "produs/produsResigilat.h"
#include "produs/produsAlimentar.h"
#include "server/server.h"
#include "user/userPremium.h"
#include "user/userNonPremium.h"
#include "lrucache/lrucache.h"
#include "json.hpp"
#include "objectFactory/objectFactory.h"

#include "../administrativ/TestHelper.cpp"

using namespace std;


string returnClassType(string s);

// Instanta Singleton
Server *Server::instanta = 0;

int main(int argc, char** argv) 
{
 
  // string str = "test";
  // vector<Produs*> vec;
  
  // vec.push_back(new ProdusAlimentar(str, 1, str, 2.22f, str, 9));


  // json jtest = ObjectFactory::getJsonProdus(vec);
  
  // ofstream os("../files/otput/out.json");
  // os << jtest; 

  // ifstream i("../files/input/input.json");
  // json jin;

  // i >> jin;

  // cout << jin <<endl<<endl;

  // vector<Produs*> res = ObjectFactory::getProdusVector(jin);

  // int size = res.size();

  // for(int i = 0; i < size; i++){
  //  vec[i]->afisare();
  // }

  TestHelper p;

  p.Test1(argv[1], argv[2]);

  return 0;
} 

  



// date enunturi clare, date deintrare clare, date de iesire fixe
// modificam functia de getPret si pentru Alimentar/ProdusNealimentar, plus
// calcul reducere Resigilat, Redus 
// static? stoc 
// operatii in functie de id - de cautare; eliminam string categorie