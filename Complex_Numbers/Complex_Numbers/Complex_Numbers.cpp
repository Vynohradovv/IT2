#include <iostream>

template< class T >
class Complex {

    template<typename U>
    friend std::ostream& operator<< (std::ostream&, const Complex<U>&);

public:
    explicit Complex(const T& Re = 0, const T& Im = 0);

    Complex operator+(const Complex&) const;
    Complex operator-(const Complex&) const;

private:
    T Re;
    T Im;
};

template< class T >
std::ostream& operator << (std::ostream& out, const Complex< T >& obj)
{
    return out << "Re = " << obj.Re << "  Im = " << obj.Im;
}

template <class T>
Complex<T>::Complex(const T& Re, const T& Im)
{
    this->Re = Re;
    this->Im = Im;
}

template <class T>
Complex<T> Complex<T>::operator+(const Complex<T>& other) const
{
    return Complex<T>(Re + other.Re, Im + other.Im);
}

template< class T >
Complex<T> Complex<T>::operator-(const Complex<T>& other) const
{
    return Complex<T>(Re - other.Re, Im - other.Im);
}

int main()
{
    Complex< int > A(12, 34), B(12, -24);

    std::cout << A + B << std::endl << A - B << std::endl;
    std::cin.get();

    return 0;
}
