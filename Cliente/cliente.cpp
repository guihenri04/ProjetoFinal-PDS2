#include "cliente.hpp"
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

Cliente::Cliente(int cpf, string nome) {
    this -> cpf = cpf;
    this -> nome = nome;
    this -> pontos = 0;
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

/** @brief Método "lerCliente" classe "Cliente", utilizado especialmente para exibição.
 *  @details Esse método exibe para o usuário o cpf e o nome do cliente registrado na locadora.
 */

void Cliente::lerCliente(){
    cout << this -> cpf << " ";
    cout << this -> nome << endl;
}

/** @brief Método "alugar" da classe "Cliente", utilizado para registro.
 *  @details Esse método registra a quantidade de filmes alugados pelo cliente, lista esses filmes, adiciona pontos para uma
 * possível futura promoção e registra o histórico de filmes que já foram alugados pelo cliente.
 *  @param unidades Indica a quantidade de filmes alugados pelo cliente.
 *  @param filme Indica o filme alugado pelo cliente.
 *  @param filmesAlugados Armazena quais filmes estão alugados da locadora pelos clientes.
 *  @param historico Armazena os filmes alugados pelo cliente em seu historico.
 */

void Cliente::alugar(Filme* filme) {
    if (filme->unidades==0) {
        return;
    }
    this -> filmesAlugados.push_back(filme);
    this -> pontos++;
    this -> historico.push_back(filme);
}

/** @brief Método "devolver" da classe "Cliente", utilizado especialmente para controle.
 *  @details Esse método controla a quantidade e quais filmes foram alugados pelos clientes (o filme devolvido à locadora é retirado do vetor
 * filmesAlugados, para controle).
 */

void Cliente::devolver() {
    for (const auto& filme : this->filmesAlugados) {
        delete filme;
    }
    this->filmesAlugados.clear();
}

/** @brief Método "calcularSimilaridade" da classe "Cliente", utilizado para controle.
 *  @details Esse método analisa o filme alugado por um clinte diretamente do seu histórico e compara esse filme
 * com os filmes alugados por outro cliente, também de acordo com seu histórico. Caso esses filmes sejam iguais,
 * existe uma similaridade entre os gostos do clientes, a qual aumenta (a similaridade será importante para o
 * sistema de recomendação).
 *  @param similaridade Registra a quantidade de filmes similares com base no histórico dos clientes.
 *  @param filme1 Filme pertencente ao histórico do cliente 1.
 *  @param filme2 Filme pertencente ao histórico do cliente 2.
 *  @return Retorna a quantidade de filmes similares entre os dois clientes.
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

/** @brief Método "definirSimilares" da classe "Cliente", utilizado para fins de recomendação.
 *  @details Esse método recebe um vetor contendo três clientes e, a partir daí, realiza uma filtragem, comparando os filmes
 * assistidos por eles e objetivando encontrar aquele cliente com similaridade mais próxima à de um outro cliente específico. 
 * Caso esse vetor possua menos que três elementos, essa comparação não é realizada. Durante essa filtragem feita pelo método, são atribuidos
 * graus de similaridade baseados nos filmes assistidos pelos clientes, os quais serão utilizados para a elaboração de um "ranking" que listará 
 * aqueles clientes com gostos mais próximos à de um outro cliente específico. O cliente com maior grau de similaridade fica em primeiro lugar
 * e assim por diante. Por fim, eles são adicionados a um outro vetor ("similares") de acordo com o ranking previamente feito.
 * @param clientes Armazena até três clientes.
 * @param similares Armazena os clientes de acordo com a similaridade deles, utilizando como base o "ranking".
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
    int s1, s2, s3 = 0;
    Cliente* c1;
    Cliente* c2;
    Cliente* c3;
    for (Cliente* cliente : clientes) {
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
    this -> similares.push_back(c1);
    this -> similares.push_back(c2);
    this -> similares.push_back(c3);
}

/** @brief Método "recomendarPorSimilar" da classe "Cliente", utilizado para fins de recomendação.
 *  @details Esse método recebe um cliente como parâmetro (cliente mais similar encontrado pelo método anterior)
 * e percorre pelos filmes assistidos por ele, comparando-os com o do histórico de um outro cliente específico. Caso esse outro
 * cliente não tenha visto algum desses filmes similares, o filme é considerado inétido e recomendado à ele. Caso contrário, 
 * não. Pós isso, os filmes recomendados são adiconados à um outro vetor ("conjuntoRecomendados"). Caso existam filmes repetidos,
 * eles são excluidos pelo "set".
 * @param recomendados Armazena os filmes do cliente que foram considerados recomendados.
 * @param conjuntoRecomendados Armazena os filmes recomendados considerados inétidos.
 * @param aindaTemFilmes Determina se ainda existem filmes no vetor "historico".
 * @param inedito Determina se o filme é inétido ou não com base nos filmes do cliente com elevada similaridade.
 * @param filmeVisto Determina se o filme foi visto ou não por algum outro cliente específico.
 * @param recomendado Registra o filme recomendado com basse no histórico do cliente de elevada similaridade.
*/

vector <Filme*> Cliente::recomendarPorSimilar(Cliente* cliente) {
    vector <Filme*> recomendados;
    set<Filme*> conjuntoRecomendados;
    bool aindaTemFilmes = true;

    for (int i = 1; aindaTemFilmes; i++) {
        bool inedito = true;
        Filme* recomendado = cliente->historico[cliente->historico.size()-i];
        for (Filme* filmeVisto : this -> historico) {
            if (recomendado == filmeVisto) {
                inedito = false;
                break;
            }
        }
        if (inedito) {
            recomendados.push_back(recomendado);
            conjuntoRecomendados.insert(recomendado);
            break;
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
 * @details Esse método análisa os filmes similares de um determinado cliente e o histórico de filmes assistidos pelo mesmo.
 * Os filmes similares vistos pelo cliente são adicionados no vetor "recomendados", utilizando como base o método "recomendarPorSimilar". 
 * Caso o cliente não possua nenhum file similar ou seu histórico de filmes assistidos esteja vazio (nenhum filme foi visto), o método 
 * alerta sobre isso.
 * @param definirSimilares Define os filmes similares com base em um cliente específico.
*/

void Cliente::recomendar(vector <Cliente*> clientes) {
    this -> definirSimilares(clientes);
    if (this -> similares.size() == 0 || this-> historico.size()==0) {
        cout << "Ainda não há filmes recomendados." << endl;
        return;
    }
    this->recomendados.clear();
    for (Cliente* cliente : clientes) {
        if (this->cpf == cliente->cpf) {
            break;
        } else {
            vector <Filme*> recomendados = this -> recomendarPorSimilar(cliente); 
            for (Filme* filme : recomendados) {
                this -> recomendados.push_back(filme);
            }
        }
    }
}