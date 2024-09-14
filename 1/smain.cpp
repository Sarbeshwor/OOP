#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class Rectangle
{
    double length, width;
    char *color;

public:
    Rectangle(double l, double w, const char *c)
    {
        this->length = l;
        this->width = w;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }

    Rectangle()
    {
        length = 0;
        width = 0;
        color = new char[20];
    }
    ~Rectangle()
    {
        delete[] color;
    }
    double getPerimeter();
    double getArea();
    char *getColor();
    void setColor(const char *c);
    double getlength() { return length; }
    double getwidth() { return width; }
};

double Rectangle::getPerimeter()
{
    double peri = 2 * (length + width);
    return peri;
}
double Rectangle::getArea()
{
    double area = length * width;
    return area;
}
char *Rectangle::getColor()
{
    return color;
}
void Rectangle::setColor(const char *c)
{
    delete[] color;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
}

class Triangle
{
    double a, b, c;
    char *color;

public:
    Triangle(double x, double y, double z, const char *c)
    {
        this->a = x;
        this->b = y;
        this->c = z;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }
    Triangle()
    {
        a = b = c = 0;
        color = new char[20];
    }
    ~Triangle()
    {
        delete[] color;
    }
    double getPerimeter();
    double getArea();
    char *getColor();
    void setColor(const char *c);
    double geta() { return a; }
    double getb() { return b; }
    double getc() { return c; }
};
double Triangle::getPerimeter()
{
    return a + b + c;
}
double Triangle::getArea()
{
    double s = getPerimeter() / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

char *Triangle::getColor()
{
    return color;
}

void Triangle::setColor(const char *c)
{
    delete[] color;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
}

class Circle
{
    double radius;
    char *color;

public:
    Circle(double r, const char *c)
    {
        this->radius = r;
        color = new char[strlen(c) + 1];
        strcpy(color, c);
    }
    Circle()
    {
        radius = 0;
        color = new char[20];
    }
    ~Circle()
    {
        delete[] color;
    }
    double getPerimeter();
    double getArea();
    char *getColor();
    void setColor(const char *c);
    double getr() { return radius; }
};
double Circle::getPerimeter()
{
    return 2 * M_PI * radius;
}
double Circle::getArea()
{
    return M_PI * pow(radius, 2);
}

char *Circle::getColor()
{
    return color;
}

void Circle::setColor(const char *c)
{
    delete[] color;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
}

class ShapeCollection
{
    int r, t, d;
    Rectangle rect[100];
    Triangle tri[100];
    Circle cir[100];

public:
    ShapeCollection()
    {
        r = 0;
        t = 0;
        d = 0;
    }
    void addRectangle(Rectangle &ob)
    {
        rect[r++] = ob;
    }
    void addTriangle(Triangle &ob)
    {
        tri[t++] = ob;
    }
    void addCircle(Circle &ob)
    {
        cir[d++] = ob;
    }
    int getRectCount()
    {
        return r;
    }
    int getTriCount()
    {
        return t;
    }
    int getCircount()
    {
        return d;
    }
    void printRectangle();
    void printTriangle();
    void printCircle();
};

void ShapeCollection::printRectangle()
{
    for (int i = 0; i < r; i++)
    {
        cout << "Rectangle " << i << "--> length: " << rect[i].getlength() << "  width: " << rect[i].getwidth() << endl;
    }
}
void ShapeCollection::printTriangle()
{
    for (int i = 0; i < t; i++)
    {
        cout << "Triangle  " << i << "--> a: " << tri[i].geta() << "  b: " << tri[i].getb() << "  c: " << tri[i].getc() << endl;
    }
}
void ShapeCollection::printCircle()
{
    for (int i = 0; i < d; i++)
    {
        cout << "Circle    " << i << "--> r: " << cir[i].getr() << endl;
    }
}
int main()
{
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

    ShapeCollection shapes;

    shapes.addRectangle(r1);
    shapes.addTriangle(t1);
    shapes.addCircle(c1);

    Rectangle r2(15, 25, "Black");
    shapes.addRectangle(r2);
    Triangle t2(5, 12, 13, "White");
    shapes.addTriangle(t2);

    cout << "Number of Rectangles: " << shapes.getRectCount() << endl;
    cout << "Number of Triangles: " << shapes.getTriCount() << endl;
    cout << "Number of Circles: " << shapes.getCircount() << endl;
    cout << "--------------------------------------" << endl;

    shapes.printRectangle();
    shapes.printTriangle();
    shapes.printCircle();

    return 0;
}
