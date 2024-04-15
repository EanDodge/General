// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 9/30/2021


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using namespace std::placeholders;
struct Peaches{
   double weight; // oz
   bool ripe;  // ripe or not
   void print() const { cout << (ripe?"ripe":"green") << ", " <<  weight << endl; }
};


class myFunctor{
   public:
      myFunctor(double x) : weight_(x){};
      double operator() (double jam, Peaches peach) {
         if (peach.weight < weight_) return (jam + peach.weight);
         else return jam;
         } 
   private:
      double weight_;
};
// bool passingWeight(Peaches peach, double threshold){
//    return peach.weight < threshold;
// }



int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input basket size: ";
   int size;
   cin >> size;

   vector <Peaches> basket(size);

   // assign random weight and ripeness peaches in the basket
   // replace with generate()
   for(auto it = basket.begin(); it != basket.end(); ++it){
      it->weight = minWeight + 
	           static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
      it->ripe = rand() % 2;
   }

   generate(basket.begin(), basket.end(), [=]
   {Peaches temp; temp.weight = minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
    temp.ripe = rand() % 2; return temp;});

   
   // for_each() possibly
   for_each(basket.begin(),basket.end(),
      [&](Peaches temp){temp.print();});

   // moving all the ripe peaches from basket to peck
   // remove_copy_if() with back_inserter()/front_inserter() or equivalents
   vector<Peaches> peck;
   // for(auto it=basket.begin(); it != basket.end();)
   //    if(it->ripe){
	//  peck.push_front(std::move(*it));
	//  it=basket.erase(it);
   //    }else
	//  ++it;

   remove_copy_if(basket.begin(), basket.end(), back_inserter(peck), [](Peaches temp)
   {return !(temp.ripe);});
   //basket.erase(basket.begin(),rm);
   auto rm = remove_if(basket.begin(), basket.end(), [](Peaches temp)
   {return temp.ripe;});

   basket.erase(rm,basket.end());
   // for_each() possibly
   cout << "peaches remainng in the basket"<< endl;
   for_each(basket.begin(),basket.end(),
      [&](Peaches temp){temp.print();});
   

   cout << endl;

   // for_each() possibly
   cout << "peaches moved to the peck"<< endl;
   for_each(peck.begin(),peck.end(),
      [&](Peaches temp){temp.print();});


   // prints every "space" peach in the peck
   const int space=3; 
   cout << "\nevery " << space << "rd peach in the peck"<< endl;

   // replace with advance()/next()/distance()
   // no explicit iterator arithmetic
   
   auto it=peck.cbegin(); 
   auto beginIt = peck.cbegin();
   while(it != peck.cend() && distance(beginIt, it) < peck.size()){
         it->print();
         //cout << distance(it,beginIt) << " " << peck.size() << endl;
         advance(it, space);
         //cout << distance(it,beginIt) << " " << peck.size() << endl;
   }


   // putting all small ripe peaches in a jam
   // use a binder to create a functor with configurable max weight
   // accumulate() or count_if() then remove_if()
   const double weightToJam = 10.0;

   
   myFunctor passingWeight (weightToJam);
   auto binded = std::bind(passingWeight, _1, _2);
   double jamWeight = accumulate(peck.begin(), peck.end(), 0.0, binded);
   peck.erase(remove_if(peck.begin(), peck.end(), [weightToJam](Peaches temp)
   {return temp.weight < weightToJam;}),peck.end());

   // double jamWeight = 0; o
   // for(auto it=peck.begin(); it != peck.end();)
   //    if(it->weight < weightToJam){
	//  jamWeight += it->weight;
	//  it=peck.erase(it);
   //    }else
	//  ++it;

   cout << "Weight of jam is: " << jamWeight << endl;

}


