#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265 

class Triangle{
private:
    double a; 
    double b; 
    double Lc; 
    
public:
    Triangle(){
        a = 1;
        b = 1;
        Lc = 1;
    }

    Triangle(double a_, double b_, double Lc_){
        a = a_;
        b = b_;
        Lc = Lc_;
    }
    
    double getA(){ return a;}
    void setA(double a_){ a = a_; }
    double getB(){ return b; }
    void setB(double b_){ b = b_; }
    double getLc(){ return Lc; }
    void setLc(double Lc_){ Lc = Lc_; }
    
    double getC(){ return sqrt(a*a+b*b-2*a*b*cos(Lc*PI/180.0)); }

    double getP() { return a+b+getC(); }
    double getS() { return 1.0/2.0*a*b*sin(Lc*PI/180.0); }
};

class IsoscelesTriangle:public Triangle{
public:
    IsoscelesTriangle(double a_, double Lc_):Triangle(a_,a_,Lc_){}
};

class EquilateralTriangle: public IsoscelesTriangle{
public:
    EquilateralTriangle(double a_):IsoscelesTriangle(a_,60.0){}
};

class RightTriangle:public Triangle{
public:
    RightTriangle(double a_, double b_):Triangle(a_,b_,90.0){};
};

int main(){
    cout << "1 - Triangle\n";
    cout << "2 - Isosceles Triangle\n";
    cout << "3 - Equilateral Triangle\n";
    cout << "4 - Right Triangle\n";
    cout << "-->";
    int n;
    cin >> n;
    Triangle *t = new Triangle();
    if(n == 1){
        double a, b, Lc;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "Lc = ";
        cin >> Lc;
        t = new Triangle(a,b,Lc);
    }else if(n == 2){
        double a, Lc;
        cout << "a = ";
        cin >> a;
        cout << "Lc = ";
        cin >> Lc;
        t = new IsoscelesTriangle(a,Lc);
    }else if(n == 3){
        double a, Lc;
        cout << "a = ";
        cin >> a;
        t = new EquilateralTriangle(a);
    }else if(n == 4){
        double a, b;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        t = new RightTriangle(a,b);
    }
    
    cout << "P = " << t->getP() << endl;
    cout << "S = " << t->getS() << endl;
    return 0;
}
