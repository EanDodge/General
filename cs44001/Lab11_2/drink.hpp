// drink class to be used in Coffee Shack lab
// Mikhail Nesterenko
// 11/7/2022

#include <string>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

enum class DrinkType
{
    small,
    medium,
    large
};

class Drink
{
public:
    Drink(DrinkType type = DrinkType::small, int price = 5) : type_(type), price_(price) {}
    virtual int getPrice() const { return price_; };
    void setPrice(int price) { price_ += price; };
    void getName()
    {
        cout << "Can I get your name? ";
        cin >> name_;
    };
    virtual void addIngredient(){};
    void putAddon(const std::string &addon) { addons_.push_back(addon); };
    vector<std::string> getAddons() const { return addons_; };
    void printDrink()
    {
        cout << name_ << ", your ";
        if (type_ == DrinkType::small)
            cout << "small coffee with ";
        if (type_ == DrinkType::medium)
            cout << "medium coffee with ";
        if (type_ == DrinkType::large)
            cout << "large coffee with ";
        for (auto e : addons_)
            cout << e << ", ";
        cout << "is ready. It will be $" << price_ << ", please." << endl;
    }
    // Alex, your medium coffee with sugar, honey, honey is ready. It will be $14, please.
private:
    std::string name_;
    int price_;
    DrinkType type_;
    vector<std::string> addons_;
};

class Honey : public Drink
{
public:
    Honey(Drink *drink) : drink_(drink){};
    int getPrice() const override { return 3; };
    // std::string getName() const override { return "Honey";};
    // void addPrice(){drink_->price_ += 3;}
    void addIngredient() override { drink_->putAddon("Honey"); };

private:
    Drink *drink_;
};

class Sugar : public Drink
{
public:
    Sugar(Drink *drink) : drink_(drink){};
    int getPrice() const override { return 1; };
    // std::string getName() const override { return "Sugar";};
    // void addPrice(){drink_->price_ += 3;}
    void addIngredient() override { drink_->putAddon("Sugar"); };

private:
    Drink *drink_;
};

class Cream : public Drink
{
public:
    Cream(Drink *drink) : drink_(drink){};
    int getPrice() const override { return 2; };
    // std::string getName() const override { return "Cream";};
    // void addPrice(){drink_->price_ += 3;}
    void addIngredient() override { drink_->putAddon("Cream"); };

private:
    Drink *drink_;
};

class Barista
{
public:
    Barista(Barista *successor = nullptr) : successor_(successor) {}
    virtual void handleRequest(vector<std::string> addons, Drink *myDrink)
    {
        if (successor_ != nullptr)
            successor_->handleRequest(addons, myDrink);
        else
            cout << "nobody can handle this request"
                 << endl;
    }

private:
    Barista *successor_;
};

// derived classes
class JuniorBarista : public Barista
{
public:
    JuniorBarista(Barista *successor = nullptr) : Barista(successor) {}
    void handleRequest(vector<std::string> addons, Drink *myDrink) override
    {
        if (addons.size() == 0)
        {
            myDrink->getName();
            myDrink->printDrink();
        }

        else
            Barista::handleRequest(addons, myDrink);
    }
};
// derived classes
class SeniorBarista : public Barista
{
public:
    SeniorBarista(Barista *successor = nullptr) : Barista(successor) {}
    void handleRequest(vector<std::string> addons, Drink *myDrink) override
    {
        bool honey = false;
        for(auto e: addons){
            if( e == "Honey")
                honey = true;
        }
        if (!honey){
            myDrink->getName();
            myDrink->printDrink();     
        }   
        else
            Barista::handleRequest(addons,myDrink);
    }
};

class Manager : public Barista
{
public:
    Manager(Barista *successor = nullptr) : Barista(successor) {}
    void handleRequest(vector<std::string> addons, Drink *myDrink) override
    {
        myDrink->getName();
        myDrink->printDrink();
    }
};
