#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Rectangle
{
private:
    int len;
    int width;
    char *color;

public:
    Rectangle(int l, int w, const char *c)
    {
        color = new char[strlen(c) + 1];
        strcpy(color, c);
        len = l;
        width = w;
    }

    Rectangle()
    {
        len = 0;
        width = 0;
        color = nullptr;
    }

    ~Rectangle()
    {
        delete[] color;
    }
    Rectangle(Rectangle &ob)
    {
        color = new char(strlen(ob.color) + 1);
        strcpy(color, ob.color);
        len = ob.len;
        width = ob.width;
    }
    Rectangle *clone()
    {
        Rectangle *r = new Rectangle;
        r->color = new char(strlen(color) + 1);
        // strcpy(r->color, color);
        r->len = len;
        r->width = width;
        return r;
    }
    int getPerimeter()
    {
        int perimeter = 2 * (len + width);
        return perimeter;
    }
    int getArea()
    {
        int area = len * width;
        return area;
    }
    const char *getColor()
    {
        return color;
    }
    void setColor(const char *c)
    {
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }
    int getlen()
    {
        return len;
    }
    int getwidth()
    {
        return width;
    }
    // void setvalues(int l, int w, const char *c)
    // {
    //     len = l;
    //     width = w;
    //     delete[] color;
    //     color = new char[strlen(c) + 1];
    //     strcpy(color, c);
    // }
};

class Triangle
{

private:
    int a;
    int b;
    int c;
    char *color;

public:
    Triangle(int x, int y, int z, const char *col)
    {
        a = x;
        b = y;
        c = z;
        color = new char(strlen(col) + 1);
        strcpy(color, col);
    }

    Triangle()
    {
        a = 0;
        b = 0;
        c = 0;
        color = nullptr;
    }

    ~Triangle()
    {
        delete[] color;
    }
    Triangle(Triangle &ob)
    {
        color = new char(strlen(ob.color) + 1);
        strcpy(color, ob.color);
        a = ob.a;
        b = ob.b;
        c = ob.c;
    }
    Triangle *clone()
    {
        Triangle *r = new Triangle;
        r->color = new char(strlen(color) + 1);
        // strcpy(r->color, color);
        r->a = a;
        r->b = b;
        r->c = c;
        return r;
    }
    int getPerimeter()
    {
        return a + b + c;
    }
    double getArea()
    {
        double perim = a + b + c;
        double semi = perim / 2;
        double area = sqrt(semi * (semi - a) * (semi - b) * (semi - c));
        return area;
    }
    const char *getColor()
    {
        return color;
    }
    void setColor(const char *col)
    {
        delete[] color;
        color = new char(strlen(col) + 1);
        strcpy(color, col);
    }
    int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
    int getc()
    {
        return c;
    }
    // void setvalues(int x, int y, int z, const char *col)
    // {
    //     a = x;
    //     b = y;
    //     c = z;
    //     delete[] color;
    //     color = new char(strlen(col) + 1);
    //     strcpy(color, col);
    // }
};
class Circle
{
private:
    int radi;
    char *color;

public:
    Circle(int rad, const char *c)
    {
        radi = rad;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }

    Circle()
    {
        radi = 0;
        color = nullptr;
    }
    ~Circle()
    {
        delete[] color;
    }
    Circle(Circle &ob)
    {
        color = new char(strlen(ob.color) + 1);
        strcpy(color, ob.color);
        radi = ob.radi;
    }
    Circle *clone()
    {
        Circle *r = new Circle;
        // r->color = new char(strlen(color) + 1);
        strcpy(r->color, color);
        r->radi = radi;
        return r;
    }
    double getPerimeter()
    {

        return 2 * M_PI * radi;
    }
    double getArea()
    {
        return M_PI * pow(radi, 2);
    }
    const char *getColor()
    {
        return color;
    }
    void setColor(const char *c)
    {
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }
    int getrad()
    {
        return radi;
    }
    void setvalues(int r, const char *c)
    {
        radi = r;
        delete[] color;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }
};
class ShapeCollection
{
private:
    Rectangle **rec;
    Triangle **tri;
    Circle **cir;
    int rc;
    int tc;
    int cc;
    int r,t,c;

public:
    ShapeCollection(){
        rc = 1;
        tc = 1;
        cc = 1;
        rec = new Rectangle*[rc];
        tri = new Triangle*[tc];
        cir = new Circle*[cc];
        r=0;
        t=0;
        c=0;

    }
    ~ShapeCollection()
    {
        for(int i = 0; i < r; i++)
        {
            delete rec[i];
        }
        for(int i = 0; i < t; i++)
        {
            delete tri[i];
        }
        for(int i = 0; i < c; i++)
        {
            delete cir[i];
        }
        delete[] rec;
        delete[] tri;
        delete[] cir;

    }
    void resizeRect(int newCapacity){
        Rectangle **newrec = new Rectangle*[newCapacity];
        for (int i = 0; i < r; i++)
        {
            newrec[i] = rec[i]->clone();
        }
        delete[] rec;
        rec = newrec;
        cout << "Increasing capacity of Rectangle from " << rc << " to " << newCapacity << endl;
        rc = newCapacity;
    }
    void resizeTri(int newCapacity){
        Triangle **newtri = new Triangle*[newCapacity];
        for (int i = 0; i < t; i++)
        {
            newtri[i] = tri[i]->clone();
        }
        delete[] tri;
        tri = newtri;
        cout << "Increasing capacity of Traingle from " << tc << " to " << newCapacity << endl;
        tc = newCapacity;
    }
    void resizeCir(int newCapacity){
        Circle **newcir = new Circle*[newCapacity];
        for (int i = 0; i < c; i++)
        {
            newcir[i] = cir[i]->clone();
        }
        delete[] cir;
        cir = newcir;
        cout << "Increasing Capacity of circle from" << cc << " to " << newCapacity << endl;
        cc = newCapacity;
    }
    void add(Rectangle &rect)
    {
        if (r >= rc)
        {
            resizeRect(rc * 2);
        }
        rec[r] = new Rectangle(rect);
        r++;
    }
    void add(Circle &circ)
    {
        if (c >= rc)
        {
            resizeCir(c * 2);
        }
        cir[c] = new Circle(circ);
        c++;
    }
    void add(Triangle &tria)
    {
        if (t >= tc)
        {
            resizeTri(tc * 2);
        }
        tri[t] = new Triangle(tria);
        t++;
    }
    int getRectCount()
    {
        return r;
    }
    int getCircCount()
    {
        return c;
    }
    int getTriCount()
    {
        return t;
    }
    void printRectangles()
    {
        for (int i = 0; i < r; i++)
        {
            cout << "Rectangle " << i << ":";
            cout << " length: " << rec[i]->getlen() << " Width: " << rec[i]->getwidth() << endl;
        }
    }
    void printTriangles()
    {
        for (int i = 0; i < t; i++)
        {
            cout << "Traingle " << i;
            cout << ": a: " << tri[i]->geta() << " b: " << tri[i]->getb() << " c: " << tri[i]->getc() << endl;
        }
    }
    void printCircles()
    {
        for (int i = 0; i < c; i++)
        {
            cout << "Cicle " << i;
            cout << ": Radius: " << cir[i]->getrad() << endl;
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
    When constructing the ShapeCollection class, you will create dynamic for 
    rectangles, triangles and circles. You have to dynamically allocate memory for this.
    */ 
    ShapeCollection shapes;
    /* IMPORTANT: You need to pass the objects by value to the add functions
    If you pass by value, the copy constructor will be called and the dynamically
    allocated memory will be copied. So, you have to write copy contructor so that 
    memory allocation is properly done and no double free error occurs.
    */ 
 
 
    shapes.add(r1);
    shapes.add(t1);
    shapes.add(c1);
 
    Rectangle r2(15, 25, "Black");
    Rectangle r3(150, 225, "Green");
    shapes.add(r2);
    shapes.add(r3);
    Triangle t2(5, 12, 13, "White");
    shapes.add(t2);
    cout<<"                          "<<endl;
    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircCount() << endl;
    cout << "--------------------------------------" << endl;
 
    shapes.printRectangles();
    shapes.printTriangles();
    shapes.printCircles();
 
    return 0;
}