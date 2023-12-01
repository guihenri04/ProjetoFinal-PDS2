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

class ClienteBloqueado : public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: cliente bloqueado! Devolva os filmes antes de alugar novos.\n"; 
    }
};
class SemFilmesAlugados: public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: não há filmes alugados.\n";
    }
};
class FilmeInexistente: public std::exception {
    private:
    int filmeId;
    public:
    FilmeInexistente(int id) : filmeId(id) {}
    virtual const char* what() const noexcept override {
        return ("ERRO: Filme " + to_string(filmeId) + " inexistente.\n").c_str();
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

#endif