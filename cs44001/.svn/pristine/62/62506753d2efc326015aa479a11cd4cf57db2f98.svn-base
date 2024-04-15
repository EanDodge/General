// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Mikhail Nesterenko
// 09/26/2022


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};

double getWeight (const double min, const double max){
   return( min + static_cast<double>(rand())/RAND_MAX*(max - min));
}



int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   // assign random weight and color to apples in the crate
   // replace with generate()
   // for(auto it = crate.begin(); it != crate.end(); ++it){
   //     it->weight = minWeight + 
	//             static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
   //    it->color = rand() % 2 == 1 ? "green" : "red";
   // }
   generate(crate.begin(), crate.end(),
   [&] {Apples temp; temp.weight = getWeight(minWeight,maxWeight);
         temp.color = rand() % 2 == 1 ? "green" : "red";return temp;});


    // for_each() possibly
   // cout << "all appleas"<< endl;
   // for(const auto &e: crate) {
   //    e.print();
   // }
   for_each(crate.begin(),crate.end(),
      [&](Apples temp){temp.print();});

   
   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // count_if()
   int cnt = 0;
   // for(auto it = crate.cbegin(); it != crate.cend(); ++it) 
   //    if(it->weight > toFind) ++cnt;
   cnt = count_if(crate.begin(), crate.end(), [&] (Apples temp)
   {return temp.weight > toFind;});

   cout << "There are " << cnt << " apples heavier than " 
	<< toFind << " oz" <<  endl;

   // find_if()
   cout << "at positions ";
   // for(int i=0; i < size; ++i)
   //    if(crate[i].weight > toFind)
	//  cout << i << ", ";
   // cout << endl;
   auto it = crate.begin();
   int count = -1;
   while ( it != crate.end() ){
      it = find_if(it, crate.end(), [&](Apples temp){++count;return temp.weight > toFind;});
      if ( it != crate.end()){ 
         cout << count << ", ";
         ++it;
      }
   }cout << endl;


   // max_element()
   // double heaviest = crate[0].weight;
   // for(int i=1; i < size; ++i)
   //    if(crate[i].weight > heaviest) heaviest = crate[i].weight; 

   auto max = max_element(crate.begin(), crate.end(), [](const Apples& lhs, const Apples& rhs)
   {return lhs.weight < rhs.weight;});
   cout << "Heaviest apple weighs: " << max->weight << " oz" << endl;


   // for_each() or accumulate()
   double sum = 0;
   // for(int i=0; i < size; ++i)
   //    sum += crate[i].weight;

   // sum = accumulate(crate.cbegin(), crate.cend(), 0.0, [](const Apples& lhs, const Apples& rhs)
   // {return lhs.weight + rhs.weight;});

   for_each(crate.begin(),crate.end(),
      [&](Apples temp){sum += temp.weight;});
   cout << "Total apple weight is: " << sum << " oz" << endl;


   // transform();
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;
   // for(int i=0; i < crate.size(); ++i)
   //    crate[i].weight += toGrow;
   transform(crate.begin(), crate.end(), crate.begin(), [=](Apples temp)
   {temp.weight += toGrow; return temp;});

   // remove_if()
   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;

   auto rm = remove_if(crate.begin(), crate.end(), [=](Apples temp)
   {return temp.weight < minAccept;});

   crate.erase(rm,crate.end());
   // removing small apples
   // nested loops, replace with a single loop modification idiom
   // bool removed;
   // do{
   //    removed = false;
   //    for(auto it = crate.begin(); it != crate.end(); ++it)
	//  if(it->weight < minAccept){
	//     crate.erase(it);
	//     removed = true;
	//     break;
   //     }
   // }while(removed);
   // cout << "removed " << size - crate.size() << " elements" << endl;


   // bubble sort, replace with sort()
   // bool swapped;
   // do{
   //    swapped = false;
   //    for(int i=0; i < crate.size()-1; ++i)
	//  if(crate[i].weight > crate[i+1].weight){
	//     std::swap(crate[i], crate[i+1]);
	//     swapped = true;
	//  }
   // }while(swapped);

   sort(crate.begin(), crate.end(), [](const Apples& lhs, const Apples& rhs)
   {return lhs.weight < rhs.weight;});
   // for_each() possibly
   for_each(crate.begin(),crate.end(),
      [&](Apples temp){temp.print();});

}


