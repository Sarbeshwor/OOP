#include <iostream>
#include <cmath>
#include<cstring>


using namespace std;

class Rectangle{
    private:
    int len;
    int width;
    char * color;
    public:
    Rectangle(int l, int w, const char* c){
        color= (char *) malloc(strlen(c)+1);
        strcpy(color, c);
         len = l;
         width = w;

        
    }
      
    Rectangle(){
        len=0; width=0; color=nullptr;
    }

    ~Rectangle(){
        free(color);
    }
    int getPerimeter(){
        int perimeter = 2*(len+width);
        return perimeter;
    }
    int getArea(){
        int area = len * width;
        return area;
    }
    const char* getColor(){
        return color;
    }
    void setColor(const char *c){
        free(color);
        color= (char *) malloc(strlen(c)+1);
        strcpy(color,c);
        
    }
    

};

class Triangle{

private:
    int a;
    int b;
    int c;
    char *color;
public:
    Triangle(int x, int y, int z, const char * col){
        a=x;
        b=y;
        c=z;
        color= (char *) malloc(strlen(col)+1);
        strcpy(color, col);
    }
    
     Triangle(){
        a=0;
        b=0;c=0;
        color=nullptr;
     }

    ~Triangle(){
        free(color);
    }
    int getPerimeter(){
        return a+b+c;
    }
    double getArea(){
       double perim= a+b+c;
       double semi=perim/2;
       double area= sqrt(semi * (semi-a)* (semi-b) * (semi-c));
       return area;
    

    }
   const char * getColor(){
    return color;
   }
   void setColor(const char* col){
    free(color);
     color= (char *) malloc(strlen(col)+1);
        strcpy(color, col);


   }
  

};
 class Circle{
        private:
        int r;
        char *color;
        public:
       Circle(int rad, const char * c) {
    r = rad; 
    color = (char *) malloc(strlen(c) + 1);
    strcpy(color, c);
}
 
          Circle(){
            r=0;
            color=nullptr;
        }
        ~Circle(){
            free(color);
        }
        int getPerimeter(){

            return 2*M_PI*r;
        }
        int getArea(){
            return M_PI * pow(r,2);
        }
        const char *getColor(){
            return color;
        }
        void setColor(const char * c){
            free(color);
            color= (char *) malloc(strlen(c)+1);
            strcpy(color, c);

        }
   };
class ShapeCollection{
    private:
    Rectangle rec[100];
    Triangle tri[100];
    Circle cir[100];
    int rc;
    int tc;
    int cc;
    
    public:
    ShapeCollection() : rc(0), tc(0), cc(0) {}

    void addRectangle(const Rectangle & r){
        rec[rc++]=r;
    }
    void addCircle(const Circle & c){
        cir[cc++]=c;
    }
    void addTriangle(const Triangle & t){
        tri[tc++]=t;
    }
    int getRectCount(){
        return rc;
    }
    int getCircCount(){
        return cc;
    }
    int getTriCount(){
        return tc;
    }
    void printRectangles(){
        for (int i = 0; i <rc; i++)
        {
           cout << "Rectangle Number " << i << endl;
           cout << "length" << rec[i].getlen << endl;
        }
        
    }
    void printTriangles()
    {
        for (int i = 0; i < tc; i++)
        {
            cout << "Traingle Number " << i << endl;

        }
        
    }
    void printCircles(){
        for (int i = 0; i < cc; i++)
        {
           cout << "Cicle Number " << i << endl;

        }
        
    }
};

int main() {
    // Create rectangle with length, width, color
    Rectangle r1(10, 20, "Red");
    // The Color is stored using malloc, which will be freed during destruction
    cout << "Rectangle Perimeter: " << r1.getPerimeter() << endl;
    cout << "Rectangle Area: " << r1.getArea() << endl;
    cout << "Rectangle Color: " << r1.getColor() << endl;
    // When changing the color, you need to free the memory of the old color
    // and allocate new memory for the new color
    r1.setColor("Yellow");
    cout << "Rectangle Color: " << r1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create triangle with a, b, c, color. (a, b, c are lengths of the sides)
    Triangle t1(3, 4, 5, "Blue");
    cout << "Triangle Perimeter: " << t1.getPerimeter() << endl;
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "Triangle Area: " << t1.getArea() << endl;
    t1.setColor("Orange");
    cout << "Triangle Color: " << t1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    // Create circle with radius, color
    Circle c1(7, "Green");
    cout << "Circle Perimeter: " << c1.getPerimeter() << endl;
    cout << "Circle Area: " << c1.getArea() << endl;
    cout << "Circle Color: " << c1.getColor() << endl;
    c1.setColor("Purple");
    cout << "Circle Color: " << c1.getColor() << endl;
    cout << "--------------------------------------" << endl;
 
    /*
    When constructing the ShapeCollection class, you will create static arrays for 100 
    rectangles, triangles and circles. You don’t have to dynamically allocate memory for this.
    */ 
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by reference to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied, leading to double free errors when things go 
    out of scope. Once passed by reference, do not directly store the reference in 
    the array. Instead, copy the data from the reference to the array element.
    We will see better ways to handle this in the upcoming sessions.
    */ 
    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);
 
    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);
 
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
 
    return 0;
}