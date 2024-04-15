// figures: class adapter pattern
// Ean Dodge
// 4/5/24

#include <iostream>

using std::cout; using std::endl; using std::cin;

// target interface
class Square {
public:
   virtual void draw() const =0;
   virtual void resize(int) = 0;
   virtual ~Square(){}
};

// adaptee/implementer
class LegacyRectangle{
public:
   LegacyRectangle(int topLeftX, 
		   int topLeftY, 
		   int bottomRightX, 
		   int bottomRightY): 
      topLeftX_(topLeftX), 
      topLeftY_(topLeftY), 
      bottomRightX_(bottomRightX), 
      bottomRightY_(bottomRightY){}
   
   void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY){
      topLeftX_ = topLeftX;
      topLeftY_ = topLeftY;
      bottomRightX_= bottomRightX;
      bottomRightY_ = bottomRightY;
   }

   int getTopLeftX() const { return topLeftX_;};
   int getTopLeftY() const { return topLeftX_;};
   int getBottomRightX() const { return bottomRightX_;};
   int getBottomRightY() const { return bottomRightY_;};

   void oldDraw() const {
      for(int i=0; i < bottomRightY_; ++i){
	 for(int j=0; j < bottomRightX_; ++j)
	    if(i >= topLeftY_  && j >= topLeftX_ ){
	       cout << '*';
          cout << ' ';
       }
	    else
	       cout << ' ';
	 cout << endl;
      }
   }
// defining top/left and bottom/right coordinates 
private: 
   int topLeftX_;
   int topLeftY_;
   int bottomRightX_;
   int bottomRightY_;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter: public Square, 
		     private LegacyRectangle {
public:
   SquareAdapter(int size): LegacyRectangle(0,0,size,size){};
   void draw() const override {
      oldDraw();
   }
   int size() {return getBottomRightY() - getTopLeftY();};
   void resize(int newSize){
      int bottomRight = getTopLeftY() + newSize;
      move(getTopLeftX(), getTopLeftY(), bottomRight, bottomRight);
   }
};


int main(){
   cout << "what size do you want the square?" << endl;
   int size;
   cin >> size;
   Square *square = new SquareAdapter(size);
   square->draw();
   cout << "give me a new size" << endl;
   cin >> size;
   square -> resize(size);
   square -> draw();
}

