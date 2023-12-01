#ifndef CODIGOREPETIDO_HPP
#define CODIGOREPETIDO_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

using namespace std;

/**
* @class ComandoInvalido
* @brief Classe de exceção para comandos inválidos. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um comando inválido é digitado pelo usuário.
*/
class ComandoInvalido: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("Comando Inválido!\nPara relembrar os comandos disponíveis, digite ME.");
    }
};

/**
* @class OpcaoInvalida
* @brief Classe de exceção para opções inválidas. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando uma opção inválido é digitado pelo usuário.
*/

class OpcaoInvalida : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Opção inválida.";
    }
};

/**
* @class DadosIncorretos
* @brief Classe de exceção para dados incorretos. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando dados incorretos são digitados pelo usuário.
*/

class DadosIncorretos : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Dados incorretos.";
    }
};

/**
* @class CodigoRepetido
* @brief Classe de exceção para códigos repetidos. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando códigos repetidos são digitados pelo usuário.
*/

class CodigoRepetido : public exception {
 public:
    virtual const char* what() const noexcept override {
        return  "ERRO: Código repetido.";
    }
};    

/**
* @class CodigoInexistente
* @brief Classe de exceção para códigos inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando códigos inexistentes são digitados pelo usuário.
*/

class CodigoInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Código inexistente.";
    }
};

/**
* @class CPFRepetido
* @brief Classe de exceção para CPF's repetidos. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um CPF repetido é digitados pelo usuário.
*/

class CPFRepetido : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF repetido.";
    }
};

/**
* @class CPFInexistente
* @brief Classe de exceção para CPF's inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um CPF inexistente é digitado pelo usuário.
*/

class CPFInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: CPF inexistente.";
    }
};

/**
* @class ArquivoInexistente
* @brief Classe de exceção para arquivos inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um arquivo inexistente é digitado pelo usuário.
*/

class ArquivoInexistente : public exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: Arquivo inexistente.";
    }
};

/**
* @class ArquivoInexistente
* @brief Classe de exceção para arquivos inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um arquivo inexistente é digitado pelo usuário.
*/

class SemFilmesAlugados: public std::exception {
    public:
    virtual const char* what() const noexcept override {
        return "ERRO: O cliente possui filmes alugados.";
    }
};

/**
* @class SemFilmes
* @brief Classe de exceção para filmes inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando a locadora ainda não possui filmes cadastrados.
*/

class SemFilmes: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: A locadora ainda não possui filmes cadastrados.");
    }
};

/**
* @class FilmeInexistente
* @brief Classe de exceção para filmes inexistentes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um id de um filme inexistente é digitado pelo usuário.
*/

class FilmeInexistente : public exception {
private:
    string erro;
public:
    FilmeInexistente(int id) : erro("ERRO: Filme " + to_string(id) + " inexistente.") {}
    virtual const char* what() const noexcept override {
        return erro.c_str();
    }
};

/**
* @class FilmeFalta
* @brief Classe de exceção para falta de filmes no estoque. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um id de um filme que está em falta no estoque é digitado pelo usuário.
*/

class FilmeFalta: public exception {
    private:
    int filmeId;
    public:
    FilmeFalta(int id) : filmeId(id) {}
    virtual const char* what() const noexcept override {
      return ("ERRO: Filme " + to_string(filmeId) + " em falta no estoque.").c_str();
    }
};

/**
* @class SemClientes
* @brief Classe de exceção para falta de clientes. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando a locadora não possui clientes cadastrados.
*/

class SemClientes: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: A locadora ainda não possui clientes cadastrados.");
    }
};

/**
* @class ClienteBloqueado
* @brief Classe de exceção para clientes bloqueados. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um cliente bloqueado deseja alugar mais filmes.
*/


class ClienteBloqueado: public exception {
    public:
    virtual const char* what() const noexcept override {
      return("ERRO: Cliente bloqueado! Devolva os filmes antes de lugar novos.");
    }
};

/**
* @class AvaliacaoErrada
* @brief Classe de exceção para avaliações erradas. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando uma nota de avaliação errada é digitada pelo usuário.
*/

class AvaliacaoErrada: public exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: O filme pode ser avaliado em no máximo 5.";
    }
};

/**
* @class SemRecomendados
* @brief Classe de exceção para clientes sem filmes recomendados. 
* @details Essa classe é usada para exibir uma mensagem de erro para quando um cliente ainda não possui filmes recomendados.
*/

class SemRecomendados: public exception {
    public:
    virtual const char* what() const noexcept override {
      return "ERRO: Ainda não há filmes recomendados para essa cliente!";
    }
};

#endif