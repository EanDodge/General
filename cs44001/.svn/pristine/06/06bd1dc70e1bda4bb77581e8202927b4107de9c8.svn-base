// selecting oranges
// converting vectors to multimaps
// Mikhail Nesterenko
// 9/26/2022


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::multimap;

enum class Variety {orange, pear, apple};
vector<string> colors = {"red", "green", "yellow"};

struct Fruit{
   Variety v;
   string color; // red, green or orange
};


int main(){
   srand(time(nullptr));
   multimap <Variety, string> tree;

   // random fruit and color selection
   // for(auto f=tree.begin(); f!=tree.end(); ++f){
   //    f->v = static_cast<Variety>(rand() % 3);
   //    f->color = colors[rand()%3];
   // }
   tree.emplace(Variety::orange, "brown");
   int size = rand() % 100;
   for (int i= 0; i < size; ++i ){
      auto v = static_cast<Variety>(rand() % 3);
      auto color = colors[rand()%3];
      tree.insert(make_pair(v, color));
   }

   for (auto it = tree.lower_bound(Variety::orange); it != tree.upper_bound(Variety::orange);++it){
      cout << it->second << endl;
   }
   

   // printing colors of oranges
   // cout << "Colors of the oranges: " << endl;
   // for(const auto& e: tree) 
   //    if(e.first == Variety::orange) cout<< e.second << endl;

}


