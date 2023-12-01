#include "cliente.hpp"
#include "../errors/erros.hpp"
#include <set>

/**
* @file cliente.cpp
* @brief Construtor do arquivo "cliente.hpp" para identificação dos clientes.
* @details Esse construtor registra o cpf, o nome e a quantidade de pontos que cada cliente tem, para controle da própria locadora, 
* além de auxiliar em futuras promoções(pontos).
* @param cpf Armazena o cpf do cliente para identificação.
* @param nome Armazena o nome do cliente.
* @param pontos Armazena a quantidade de pontos que cada cliente tem para falicitar o controle de futuras promoções.
*/

Cliente::Cliente(long long cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
    this -> pontos = 0;
    this -> bloqueado = false;
    vector<Filme*> recomendados;
    vector<Cliente*> similares; 
    vector<Filme*> filmesAlugados; 
    vector<Filme*> historico;
    this -> recomendados = recomendados;
    this -> similares = similares;
    this -> filmesAlugados = filmesAlugados;
    this -> historico = historico;
}

/** @brief Destrutor da classe "Cliente".
 *  @details Esse destrutor trabalha na liberação de memória alocada nos vetores de ponteiros da classe "Cliente", fazendo o
 * controle manual dessa desalocação. Para cada elemento dentro desses vetores, ele realiza uma desalocação, ou seja,
 * deleta esse elemento do vetor.
 */

Cliente::~Cliente() {
    for (Filme* filme : filmesAlugados) {
        delete filme;
    }
    for (Filme* filme : historico) {
        delete filme;
    }
    for (Filme* filme : recomendados) {
        delete filme;
    }
    for (Cliente* cliente : similares) {
        delete cliente;
    }
};

/** 
 * @brief Método "lerCliente" classe "Cliente", utilizado especialmente para exibição.
 *  @details Esse método exibe para o usuário o cpf e o nome do cliente registrado na locadora.
 */

void Cliente::lerCliente(){
    cout << this -> cpf << " ";
    cout << this -> nome << endl;
}

/** 
 * @brief Método "alugar" da classe "Cliente", utilizado para registro.
 * @details Esse método registra a quantidade de filmes alugados pelo cliente, lista esses filmes, adiciona pontos para uma
 * possível futura promoção e registra o histórico de filmes que já foram alugados pelo cliente.
 * @param unidades Indica a quantidade de filmes alugados pelo cliente.
 * @param filme Indica o filme alugado pelo cliente.
 * @param filmesAlugados Armazena quais filmes estão alugados da locadora pelos clientes.
 * @param historico Armazena os filmes alugados pelo cliente em seu historico.
 */

void Cliente::alugar(Filme* filme) {
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
    this -> historico.push_back(filme);
    this -> bloqueado = true;
}

/** 
 * @brief Método "devolver" da classe "Cliente", utilizado especialmente para controle.
 *  @details Esse método controla a quantidade e quais filmes foram alugados pelos clientes (o filme devolvido à locadora é retirado do vetor
 * filmesAlugados, para controle).
 */

void Cliente::devolver() {
    this -> filmesAlugados.clear();
    this -> bloqueado = false;
}

/** 
 * @brief Método "calcularSimilaridade" da classe "Cliente", utilizado para controle.
 * @details Esse método analisa o filme alugado por um clinte diretamente do seu histórico e compara esse filme
 * com os filmes alugados por outro cliente, também de acordo com seu histórico. Caso esses filmes sejam iguais,
 * existe uma similaridade entre os gostos do clientes, a qual aumenta (a similaridade será importante para o
 * sistema de recomendação).
 * @param similaridade Registra a quantidade de filmes similares com base no histórico dos clientes.
 * @param filme1 Filme pertencente ao histórico do cliente 1.
 * @param filme2 Filme pertencente ao histórico do cliente 2.
 * @return Retorna a quantidade de filmes similares entre os dois clientes.
 */

int Cliente::calcularSimilaridade (Cliente* cliente2) {
    int similaridade = 0;
    for (Filme* filme1 : this -> historico) {
        for (Filme* filme2 : cliente2 -> historico) {
            if (filme1 == filme2) {
                similaridade++;
            }
        }
    }
    return similaridade;
}

/** 
 * @brief Método "definirSimilares" da classe "Cliente", utilizado para fins de recomendação.
 *  @details Esse método recebe um vetor de clientes e, a partir daí, realiza uma filtragem, em busca
 * de selecionar os 3 usuários com maior similaridade com o cliente atual, e colocá-los no seu 
 * atributo "similares". Caso esse vetor parâmetro possua menos que três clientes, essa comparação não 
 * precisa ser realizada, e os clientes já são alocados nos similares imediatamente. Caso haja mais 
 * de 3, a seleção prossegue. Para cada cliente do parâmetro, é calculado o grau de similaridade,
 * e comparado com os 3 clientes mais similares. Se o grau de similaridade for maior que algum,
 * esse ranking é reformulado para encaixar o novo cliente similar. O cliente com maior similaridade
 * fica em primeiro lugar e assim por diante. Depois de percorrer todo o vetor, os 3 clientes são
 * adicionados ao vetor "similares" de acordo com o ranking previamente feito.
 * @param clientes Armazena os clientes.
 * @param similares Armazena os 3 clientes de acordo com a similaridade deles, utilizando como base o "ranking".
 * @param c1 Cliente com maior grau de similaridade àquele recebido pelo método.
 * @param c2 Cliente com grau de similaridade intermediário àquele recebido pelo método.
 * @param c3 Cliente com menor grau de similaridade àquele recebido pelo método.
 * @param s1 Maior grau de similaridade.
 * @param s2 Grau de similaridade intermediário.
 * @param s3 Menor grau de similaridade.
*/
void Cliente::definirSimilares (vector <Cliente*> clientes) {
    if (clientes.size()<=3) {
        this -> similares = clientes;
        return;
    }   
    int s1 = -1, s2 = -1, s3 = -1;
    Cliente* c1 = nullptr;
    Cliente* c2 = nullptr;
    Cliente* c3 = nullptr;
    for (Cliente* cliente : clientes) {
        if (cliente->cpf==this->cpf) {
            continue;
        }
        int similaridade = this -> calcularSimilaridade(cliente);
        if (similaridade > s1) {
            s3 = s2;
            s2 = s1;
            s1 = similaridade;
            c3 = c2;
            c2 = c1;
            c1 = cliente;
        } else if (similaridade > s2) {
            s3 = s2;
            s2 = similaridade;
            c3 = c2;
            c2 = cliente;
        } else if (similaridade > s3) {
            s3 = similaridade;
            c3 = cliente;
        }
    }

    this->similares.clear();
    if (c1!=nullptr) {
        this -> similares.push_back(c1);
    }
    if (c2!=nullptr) {
        this -> similares.push_back(c2);
    }
    if (c3!=nullptr) {
        this -> similares.push_back(c3);
    }
    return;
}

/** 
 * @brief Método "recomendarPorSimilar" da classe "Cliente", utilizado para fins de recomendação.
 *  @details Esse método recebe um cliente como parâmetro e percorre os filmes assistidos por ele,
 * comparando-os com os filmes no histórico do cliente atual. Caso o cliente atual não tenha visto
 * o filme, o filme é considerado inédito. Caso contrário, o filme é ignorado. Pós isso, os filmes
 * inéditos são adiconados à um outro vetor ("conjuntoRecomendados"). Caso existam filmes repetidos,
 * eles são excluidos utilizando "set".
 * @param recomendados Armazena os filmes do cliente que foram considerados recomendados.
 * @param conjuntoRecomendados Armazena os filmes recomendados considerados inétidos.
 * @param aindaTemFilmes Determina se ainda existem filmes no vetor "historico".
 * @param inedito Determina se o filme é inétido ou não com base nos filmes do cliente com elevada similaridade.
 * @param filmeVisto Determina se o filme foi visto ou não por algum outro cliente específico.
 * @param recomendado Registra o filme recomendado com base no histórico do cliente de elevada similaridade.
*/

vector <Filme*> Cliente::recomendarPorSimilar(Cliente* cliente) {
    vector <Filme*> recomendados;
    set<Filme*> conjuntoRecomendados;
    bool aindaTemFilmes = true;

    if (cliente->historico.size()<=0) {
        return recomendados;
    }

    for (int i = 1; aindaTemFilmes; i++) {
        bool inedito = true;
        Filme* recomendado = cliente->historico[cliente->historico.size()-i];
        for (Filme* filmeVisto : this -> historico) {
            if (recomendado == filmeVisto) {
                inedito = false;
            }
        }
        if (inedito) {
            recomendados.push_back(recomendado);
            conjuntoRecomendados.insert(recomendado);
        }
        if (cliente->historico.size()-i == 0) {
            aindaTemFilmes = false;
            break;
        }
    }
    
    recomendados.assign(conjuntoRecomendados.begin(), conjuntoRecomendados.end());
    return recomendados;
} 

/**
 * @brief Método "recomendar" da classe "Cliente", utilizado para fins de recomendação.
 * @details Esse método recebe como parâmetro um vetor de clientes e retorna, a partir deles, um vetor
 * de filmes recomendados. Para isso, ele começa definindo os clientes de gosto mais similar ao cliente
 * atual, pelo método "definirSimilares". Caso depois dessa chamada não existam clientes similares ou o
 * cliente atual ainda não tenha alugado nenhum filme na locadora, o método retorna que ainda é impossível
 * recomendar filmes à esse cliente. Se não, é utilizado o método "recomendarPorSimilar" para que cada
 * um dos clientes no vetor "similares" forneça um vetor de filmes, que se juntarão em um só vetor de 
 * filmes recomendados, que fica no atributo "recomendados".
 * @param definirSimilares Define os filmes similares com base em um cliente específico.
*/

void Cliente::recomendar(vector <Cliente*> clientes) {
    try {
        this->recomendados.clear();
        this->definirSimilares(clientes);

        if (this->similares.size() == 0) {
            throw SemRecomendados();
            return;
        }

        set<Filme*> conjuntoRecomendados;

        for (Cliente* cliente : this->similares) {
            vector<Filme*> recomendadosCliente = this->recomendarPorSimilar(cliente);
            for (Filme* filme : recomendadosCliente) {
                conjuntoRecomendados.insert(filme);
            }
        }

        this->recomendados.assign(conjuntoRecomendados.begin(), conjuntoRecomendados.end());

        if (this->recomendados.size() == 0) {
            throw SemRecomendados();
            return;
        }
    } catch (SemRecomendados &e) {
        cerr << e.what() << endl;
    }
}