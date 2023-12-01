#ifndef CODIGOREPETIDO_HPP
#define CODIGOREPETIDO_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

using namespace std;

<<<<<<< HEAD

class CodigoRepetido : public std::exception {
 public:
=======
void printColoredText(const string& text, int colorCode) {
    cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

class ComandoInvalido: public exception {
    public:
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    virtual const char* what() const noexcept override {
      printColoredText("Comando Inválido!\n", 31);
    }
<<<<<<< HEAD
};    
    class ArquivoInexistente : public std::exception {
=======
};

class OpcaoInvalida : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Opção inválida.\n";
    }
};
<<<<<<< HEAD
    class DadosIncorretos : public std::exception {
=======

class DadosIncorretos : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Dados incorretos.\n";
    }
};
<<<<<<< HEAD
    class CodigoInexistente : public std::exception {
=======

class CodigoRepetido : public exception {
 public:
    virtual const char* what() const noexcept override {
        return  "ERRO: Código repetido.\n";
    }
};    

class CodigoInexistente : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Código inexistente.\n";
    }
};

<<<<<<< HEAD
  class CPFRepetido : public std::exception {
=======
class CPFRepetido : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF repetido.\n";
    }
};

<<<<<<< HEAD

class CPFInexistente : public std::exception {
=======
class CPFInexistente : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF inexistente.\n";
    }
};

<<<<<<< HEAD
class OpcaoInvalida : public std::exception {
=======
class ArquivoInexistente : public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Arquivo inexistente.";
    }
};

class SemFilmesAlugados: public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: O cliente possui filmes alugados.\n";
    }
};

class SemFilmes: public exception {
    public:
    virtual const char* what() const noexcept override {
      printColoredText("ERRO: A locadora ainda não possui clientes cadastrados.\n", 31);
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
<<<<<<< HEAD
class FilmeFalta: public std::exception {
=======

class FilmeFalta: public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    private:
    int filmeId;
    public:
    FilmeFalta(int id) : filmeId(id) {}
    virtual const char* what() const noexcept override {
      return ("ERRO: Filme " + to_string(filmeId) + " em falta no estoque.\n").c_str();
    }
};
<<<<<<< HEAD
class SemClientes: public std::exception {
=======

class SemClientes: public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
      printColoredText("ERRO: A locadora ainda não possui filmes cadastrados.\n", 31);
    }
};
<<<<<<< HEAD
class AvaliacaoErrada: public std::exception {
=======

class ClienteBloqueado: public exception {
    public:
    virtual const char* what() const noexcept override {
      printColoredText("ERRO: Cliente bloqueado! Devolva os filmes antes de lugar novos.\n", 31);
    }
};

class AvaliacaoErrada: public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: O filme pode ser avaliado em no máximo 5.\n";
    }
};
<<<<<<< HEAD
class AvaliacaoErrada: public std::exception {
=======

class SemRecomendados: public exception {
>>>>>>> c833bb0f7afe0f393d63f8077e90d9cd84486eaf
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: Ainda não há filmes recomendados para essa cliente!\n";
    }
};

#endif