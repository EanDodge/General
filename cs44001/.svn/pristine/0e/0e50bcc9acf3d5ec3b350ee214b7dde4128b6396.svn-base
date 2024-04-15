// filled/hollow figures demonstrates Bridge Design Pattern,
// square is either hollow or square and is painted with two characters,
// it is bridged over Figure --> Fill abstract body/handle
// Ean Dodge
// 4/2/2024

#include <iostream>

using std::cout; using std::endl; using std::cin;

// abstract body 
class Fill{
public:
   Fill(char border, char internal): border_(border), internal_(internal){}
   virtual char getBorder()=0;
   virtual char getInternal()=0;
   virtual ~Fill() {}
protected:
   char border_;
   char internal_;
};

// concrete body
class Hollow: public Fill{
public:
   Hollow(char border, char internal):Fill(border, internal){}
   char getBorder() override {return border_;}
   char getInternal() override {return ' ';}
   ~Hollow() override {}
};


// another concrete body
class Filled: public Fill {
public:
   Filled(char border, char internal ):Fill(border, internal){}
   char getBorder() override {return border_;}
   char getInternal() override {return border_;}
   ~Filled() override {}
};

class FullyFilled: public Fill {
public:
   FullyFilled(char border, char internal ):Fill(border, internal){}
   char getBorder() override {return border_;}
   char getInternal() override {return internal_;}
   ~FullyFilled() override {}
};

class RandomFilled: public Fill {
public:
   RandomFilled(char border, char internal ):Fill(border, internal){}
   char getBorder() override {return rand() % 2 ? internal_: border_;}
   char getInternal() override {return rand() % 2 ? internal_: border_;}
   ~RandomFilled() override {}
};

// abstract handle
class Figure {
public:
   Figure(int size, Fill* fill): size_(size), fill_(fill){}
   virtual void draw() =0;
   virtual ~Figure(){}
protected:
   int size_;
   Fill *fill_;
};

// concrete handle
class Square: public Figure{
public:
   Square(int size, Fill* fill): Figure(size, fill){}
   void draw() override;

};

void Square::draw(){
   for(int i=0; i < size_; ++i){
      for(int j=0; j < size_; ++j)
	 if(i==0 || j==0 || i==size_-1 || j==size_-1 )
	    cout << fill_ -> getBorder();
	 else
	    cout << fill_ -> getInternal();
      cout << endl;
   }
}

int main(){
   srand(time(nullptr));
   /*
   Fill* hollowPaintJ = new Hollow('&');
   Fill* filledPaintStar = new Filled('@');

   
   Figure *smallBox = new Square(7, hollowPaintJ);
   Figure *bigBox = new Square(15, filledPaintStar);
   
   smallBox->draw();
   cout << endl;
   bigBox -> draw();
   */
   
  
   // ask user for figure parameters
   cout << "Enter border character: "; 
            char bchar; cin >> bchar;
    cout << "Enter internal character: "; 
            char ichar; cin >> ichar;
   // cout << "Filled or hollow? [f/h] "; 
   //         char ifFilled; cin >> ifFilled;
   cout << "Enter size: "; int size; cin >> size;
  
   /*
   Figure *userBox = new Square(size, ifFilled == 'f'? 
	       static_cast<Fill *>(new Filled(fchar)):
	       static_cast<Fill *>(new Hollow(fchar))
	       ); 
   */
      
    
   Figure *userBox = new Square(size, new Filled(bchar, ichar));
   userBox -> draw();
   cout << endl;
   Figure *userBox1 = new Square(size, new Hollow(bchar, ichar));
   userBox1 -> draw();
   cout << endl;
   Figure *userBox2 = new Square(size, new FullyFilled(bchar, ichar));
   userBox2 -> draw();
   cout << endl;
   Figure *userBox3 = new Square(size, new RandomFilled(bchar, ichar));
   userBox3 -> draw();

   
   
   cout << endl;
   
}

