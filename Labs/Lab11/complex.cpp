#include "complex.h"
#include<iostream>

int main(){
    double real, imag;
    double real2, imag2;
    std::cin >> real >> imag;
    std::cin >> real2 >> imag2;

    Complex c;
    c.real = real;
    c.imag = imag;

    Complex c2;
    c2.real = real2;
    c2.imag = imag2;

    std::cout << std::fixed;
    std::cout.precision(2);

    std::cout << "C1:\t\t";
    c.print();

    std::cout << "Modulus:\t" << c.modulus() << std::endl;
    std::cout << "Argument:\t" << c.argument() << std::endl;
    std::cout << "Angle b/w:\t" << c.abs_angle_between(c2) << std::endl;

    std::cout << "Conjugate:\t";
    c.conjugate().print();

    std::cout << "C1+C2:\t\t";
    c.add(c2).print();

    std::cout << "C1*C2:\t\t";
    c.multiply(c2).print();
}