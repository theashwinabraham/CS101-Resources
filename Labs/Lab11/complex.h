#include <cmath>
#include <iostream>
struct Complex{
    double real;
    double imag;
    Complex conjugate(){
        return {real, -imag};
    }
    double modulus(){
        return std::sqrt(real*real + imag*imag);
    }
    double argument(){
        return std::atan2(imag, real);
    }
    Complex add(Complex c){
        return {real+c.real, imag+c.imag};
    }
    Complex multiply(Complex c){
        return {real*c.real - imag*c.imag, imag*c.real + real*c.imag};
    }
    double abs_angle_between(Complex c){
        return std::acos((real*c.real+imag*c.imag)/(modulus()*c.modulus()));
    }
    void print(){
        if(imag>=0){
            std::cout << real << " + " << imag << "i" << std::endl;
        }
        else{
            std::cout << real << " - " << -imag << "i" << std::endl;
        }
        return;
    }
};
