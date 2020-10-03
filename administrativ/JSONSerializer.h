#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "../src/json.hpp"
#include "../src/Product/ResealedProduct.h"
#include "../src/Product/FoodProduct.h"
#include "../src/user/userPremium.h"
#include "../src/user/userNonPremium.h"
#include "../src/cosproduse/cosProduse.h"

using namespace std;
using json = nlohmann::json;


class JSONSerializer 
{
    public:
        static json fromProductMap(const unordered_map<int, Product*> products)
        {
            json result;

            for (auto& it: products)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }

        static json FromUserMap(const unordered_map<int, CosProduse*>& cartsOfProducts)
        {
            json result;

            for (auto& it : cartsOfProducts)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }
};