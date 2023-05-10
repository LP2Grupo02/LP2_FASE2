#include <iostream>
#include <string>
using namespace std;
class Vector{
    public:
        int x,y;

        Vector(const int _x, const int _y)
        {
            x=_x;
            y=_y;
        }
};

Vector & operator + (const Vector &v1, const Vector &v2)
{
    return *( new Vector(v1.x + v2.x, v1.y + v2.y));
}

Vector & operator - (const Vector &v1, const Vector &v2)
{
    return *( new Vector(v1.x - v2.x, v1.y - v2.y));
}

ostream& operator << (ostream &o,const Vector &p)
{
    o << "("<< p.x << ", " << p.y << ")";
    return o;
}


int main()
{
    Vector A(10,20);

    Vector B(5,8);

    Vector C = A+B;

    Vector D = C-B;

    cout<<"A = "<<A<<"\n";
    cout<<"B = "<<B<<"\n";
    cout<<"C = "<<C<<"\n";
    cout<<"D = "<<D.x<<", "<<D.y<<"\n";
    return 0;
}