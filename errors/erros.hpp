#ifndef CODIGOREPETIDO_HPP
#define CODIGOREPETIDO_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

class CodigoRepetido : public std::exception {
 public:
    virtual const char* what() const noexcept override {
        return  "ERRO: codigo repetido\n";
    }
};

#endif