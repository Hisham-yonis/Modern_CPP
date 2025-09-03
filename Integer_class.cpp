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

    Integer(Integer &&obj)
    {
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }

    Integer &operator=(const Integer &obj)
    {
        if (this != &obj)
        {
            delete ptr;
            ptr = new int(obj.getVal());
        }
        return *this;
    }

    Integer &operator=(Integer &&obj) noexcept
    {
        if (this != &obj)
        {
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }

    Integer &operator=(int x)
    {
        delete ptr;
        ptr = new int(x);
        return *this;
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

    Integer &operator++()
    {
        setVal(getVal() + 1);
        return *this;
    }

    Integer operator++(int)
    {
        Integer temp = *this;
        this->setVal(this->getVal() + 1);
        return temp;
    }

    bool operator<(const Integer &obj) const
    {
        return this->getVal() < obj.getVal();
    }

    bool operator>(const Integer &obj) const
    {
        return this->getVal() > obj.getVal();
    }

    bool operator!=(const Integer &obj) const
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

ostream &operator<<(ostream &out, const Integer &obj)
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
