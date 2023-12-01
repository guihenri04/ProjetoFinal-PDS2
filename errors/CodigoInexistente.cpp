#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;


class ArquivoInexistente : public std::exception {
 public:
    virtual const char* what() const noexcept override {
        return "ERRO: Arquivo inexistente!";
    }
};
