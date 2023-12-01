#ifndef CODIGOREPETIDO_HPP
#define CODIGOREPETIDO_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

using namespace std;

void printColoredText(const std::string& text, int colorCode) {
    std::cout << "\033[" << colorCode << "m" << text << "\033[0m";
    }

class CodigoRepetido : public std::exception {
 public:
    virtual const char* what() const noexcept override {
        return  "ERRO: codigo repetido.\n";
    }
};    
    class ArquivoInexistente : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: arquivo inexistente.";
    }
};
    class DadosIncorretos : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: dados incorretos.\n";
    }
};
    class CodigoInexistente : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: código inexistente.\n";
    }
};

  class CPFRepetido : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF repetido.\n";
    }
};


class CPFInexistente : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF inexistente.\n";
    }
};

class OpcaoInvalida : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: opção de ordenação inválida.\n";
    }
};

class SemFilmesAlugados: public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: não há filmes alugados.\n";
    }
};
class FilmeInexistente : public exception {
private:
    string erro;
public:
    FilmeInexistente(int id) : erro("ERRO: Filme " + to_string(id) + " inexistente.\n") {}
    virtual const char* what() const noexcept override {
        return erro.c_str();
    }
};
class FilmeFalta: public std::exception {
    private:
    int filmeId;
    public:
    FilmeFalta(int id) : filmeId(id) {}
    virtual const char* what() const noexcept override {
      return ("ERRO: Filme " + to_string(filmeId) + " em falta no estoque.\n").c_str();
    }
};
class SemClientes: public std::exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: ainda não há clientes para listar.\n";
    }
};
class AvaliacaoErrada: public std::exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: O filme pode ser avaliado em no máximo 5\n";
    }
};
class AvaliacaoErrada: public std::exception {
    public:
    virtual const char* what() const noexcept override {
      printColoredText("Comando Inválido!\n", 31);
    }
};

#endif