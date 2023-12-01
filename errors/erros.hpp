#ifndef CODIGOREPETIDO_HPP
#define CODIGOREPETIDO_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

using namespace std;

class ComandoInvalido: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("Comando Inválido!");
    }
};

class OpcaoInvalida : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Opção inválida.";
    }
};

class DadosIncorretos : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Dados incorretos.";
    }
};

class CodigoRepetido : public exception {
 public:
    virtual const char* what() const noexcept override {
        return  "ERRO: Código repetido.";
    }
};    

class CodigoInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Código inexistente.";
    }
};

class CPFRepetido : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF repetido.";
    }
};

class CPFInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF inexistente.";
    }
};

class ArquivoInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Arquivo inexistente.";
    }
};

class SemFilmesAlugados: public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: O cliente possui filmes alugados.";
    }
};

class SemFilmes: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: A locadora ainda não possui clientes cadastrados.");
    }
};

class FilmeInexistente : public exception {
private:
    string erro;
public:
    FilmeInexistente(int id) : erro("ERRO: Filme " + to_string(id) + " inexistente.") {}
    virtual const char* what() const noexcept override {
        return erro.c_str();
    }
};

class FilmeFalta: public exception {
    private:
    int filmeId;
    public:
    FilmeFalta(int id) : filmeId(id) {}
    virtual const char* what() const noexcept override {
      return ("ERRO: Filme " + to_string(filmeId) + " em falta no estoque.").c_str();
    }
};

class SemClientes: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: A locadora ainda não possui filmes cadastrados.");
    }
};

class ClienteBloqueado: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: Cliente bloqueado! Devolva os filmes antes de lugar novos.");
    }
};

class AvaliacaoErrada: public exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: O filme pode ser avaliado em no máximo 5.";
    }
};

class SemRecomendados: public exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: Ainda não há filmes recomendados para essa cliente!";
    }
};
class QuantidadeFilmesErrada: public exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: a quantidade de filmes alugados deve ser maior que 0.";
    }
};

#endif