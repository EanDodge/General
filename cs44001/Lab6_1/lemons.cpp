// picking the best quality lemons
// converting vectors to priority queue
// Mikhail Nesterenko
// 2/17/2023


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::priority_queue;

const int maxBoxSize = 30;
const int highestQuality = 10;

int main() {
    srand(time(nullptr));
    int box(rand() % maxBoxSize + 1); // random box size
    priority_queue<double> lemon;
    // random quality assingment
    for (int i = 0; i < box; ++i){
        lemon.push(static_cast<double>(rand()) / RAND_MAX * highestQuality);
    }

    cout << "Here are the lemons (best first): ";

    for ( int i = 0; i < box; ++i){
        cout << lemon.top() << endl;
        lemon.pop();
    }
}