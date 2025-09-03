#include <iostream>

using namespace std;

class Integer
{
private:
    int *ptr;

public:
    Integer()
    {
        ptr = new int;
    }

    Integer(int x)
    {
        ptr = new int{x};
    }

    Integer(const Integer &obj)
    {
        this->ptr = new int(obj.getVal());
    }

    void operator=(const Integer &obj)
    {
        this->ptr = new int(obj.getVal());
    }

    void operator=(int &x)
    {
        this->ptr = new int(x);
    }

    void setVal(int x)
    {
        *ptr = x;
    }

    int getVal() const
    {
        return *ptr;
    }

    //+ , - , * , ++ , -- , > , !=
    Integer operator+(const Integer &obj)
    {
        Integer z;
        *(z.ptr) = this->getVal() + obj.getVal();
        return z;
    }

    Integer operator-(const Integer &obj)
    {
        Integer z;
        *(z.ptr) = this->getVal() - obj.getVal();
        return z;
    }

    Integer operator*(const Integer &obj)
    {
        Integer z;
        *(z.ptr) = this->getVal() * obj.getVal();
        return z;
    }

    Integer operator/(const Integer &obj)
    {
        if (obj.getVal() == 0)
        {
            cout << "Error Division by 0 \n";
            return 0;
        }
        else
        {
            Integer z;
            *(z.ptr) = this->getVal() / obj.getVal();
            return z;
        }
    }

    Integer operator++()
    {
        this->setVal(this->getVal() + 1);
        return *this;
    }

    Integer operator++(int)
    {
        Integer temp = *this;
        this->setVal(this->getVal() + 1);
        return temp;
    }

    bool operator<(Integer obj)
    {
        return this->getVal() < obj.getVal();
    }

    bool operator>(Integer obj)
    {
        return this->getVal() > obj.getVal();
    }

    bool operator!=(Integer obj)
    {
        return this->getVal() != obj.getVal();
    }

    ~Integer()
    {
        delete ptr;
    }
};

istream &operator>>(istream &in, Integer &obj)
{
    int x;
    in >> x;
    obj.setVal(x);
    return in;
}

ostream &operator<<(ostream &out, Integer &obj)
{
    out << obj.getVal();
    return out;
}

int main()
{
    Integer x = 12;
    Integer y(x);
    y.setVal(7);
    Integer z;

    cout << "Enter z value : ";
    cin >> z;

    Integer a = x + y;

    if (a > z)
    {
        cout << "a is bigger than z " << endl;
    }

    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "z : " << z << endl;
    cout << "a : " << a << endl;

    return 0;
}
