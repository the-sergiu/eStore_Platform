#pragma once
#include <string>
#include <list>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"
#include "../User/PremiumUser.h"
#include "../User/BasicUser.h"
#include "../ShoppingCart/ShoppingCart.h"
#include "../../utils/objectFactory/objectFactory.h"

using namespace std;

class Server
{
  private:
    
    static Server *instance;

    int usersCapacity;
    list<User*> usr;
    list<Product*> prod;

    // map UserID : ProductsCart
    map<int, ShoppingCart*> __UserID__ProductsCart__;

    // Singleton
    Server();
  public:
    static Server* ServerInit();
    ~Server();

    map<int, ShoppingCart*> get__UserID__ProductsCart__();

    void populateProducts(const json&);
    void populateUsers(const json&);

    void set__UserID__ProductsCart__();

    list<Product*>& getProductsList();
    list<User*>& getUsersList();

    bool requestAddProduct(int, int, int);
    bool requestDeleteProduct(int, int, int);



};