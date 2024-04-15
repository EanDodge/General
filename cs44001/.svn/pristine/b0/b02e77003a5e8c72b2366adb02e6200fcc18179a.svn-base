//Ean Dodge
//making a coffee shop
//CS3

#include "drink.hpp"


int main(){
    cout << "Welcome to Coffee Shack, can I get you [l]arge, [m]edium, or [s]mall coffee?";
    char decision;
    cin >> decision;
    int price = 0;
    auto type = DrinkType::large;
    switch(decision){
    case 'l':
        price = 10;
        type = DrinkType::large;
        break;
    case 'm':
        type = DrinkType::medium;
        price = 7;
        break;
    case 's':
        price = 5;
        type = DrinkType::small;
        break;
    default:
        cout << "not a size, exitting...";
        exit(1);
    }
    Drink* myDrink = new Drink(type,price);

    char addon = '*';
    cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?";
    cin >> addon;
    int totalPrice = myDrink->getPrice();
    //vector<std::string> addons;
    while(addon != 'd'){
        if(addon == 's'){
            Sugar sugar(myDrink);
            sugar.addIngredient();
            totalPrice += sugar.getPrice();
        }
        if(addon == 'c'){
            Cream cream(myDrink);
            cream.addIngredient();
            totalPrice += cream.getPrice();
        }
        if(addon == 'h'){
            Honey honey(myDrink);
            honey.addIngredient();
            totalPrice += honey.getPrice();
        }
        cout << "Would you like to add [s]ugar, [c]ream, [h]oney, or [d]one?";
        cin >> addon;
    }
    myDrink->getName();
    myDrink->setPrice(totalPrice);
    myDrink->printDrink();
}