#include "locadora.hpp"

/**
* @file locadora.cpp
* @brief Construtor do arquivo "locadora.hpp" para armazenagem dos clientes e filmes da locadora.
* @details Esse construtor utiliza os vetores "filmes" e "clientes" para armazenar os filmes e clientes
* da locadora, respectivavente. Depois atribui a esses vetores os membros de dados correspondentes da classe,
* no caso, atribui os membros "filmes" e "clientes" à eles.
* @param filmes Armazena os filmes da locadora.
* @param clientes Armazena os clientes da locadora.
*/

Locadora::Locadora() {
    vector<Filme*> filmes;
    vector<Cliente*> clientes;
    this -> filmes = filmes;
    this -> clientes = clientes;
}

/**
* @brief Destrutor do arquivo "locadora.hpp".
* @details Esse destrutor é responsável pela liberação manual de mémoria alocada para os vetores
* "filmes" e "clientes" a partir de um loop de repetição "for". O destrutor percorre os vetores e 
* para cado elemento deles, ele realiza um delete, liberando a memória anteriormente alocada.
* @param filme Elemento do vetor "filmes".
* @param cliente Elemento do vetor "clientes".
*/

Locadora::~Locadora() {
    for (Filme* filme : filmes) {
        delete filme;
    }
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
}

/**
 * @brief Método "cadastrarFilme" da classe "Locadora", utilizado especialmente para controle e registro.
 * @details Esse método é responsável por adicionar um novo filme à locadora. Ele recebe 
 * como parâmetros o tipo do filme, a quantidade de unidades que serão registradas, o id de 
 * identificação do filme, seu título e também a categoria na qual ele pertence. A partir daí,
 * o método verifica o id do filme, seu tipo, categoria e unidades. Caso o id do filme ainda não esteja registrado
 * na locadora, o tipo e categoria do filme forem válidos e existirem unidades suficientes, o filme é registrado, caso contrário, não.
 * @param tipo Armazena o tipo do filme (DVD ou fita).
 * @param unidades Armazena a quantidade de unidades do filme.
 * @param id Armazena o id de identificação do filme.
 * @param titulo Armazena o título do filme.
 * @param categoria Armazena a categoria do filme.
*/

void Locadora::cadastrarFilme(char tipo, int unidades, int id, const string& titulo, const char& categoria) {
    int n=filmes.size();
    for (int i=0; i<n; i++) { // codigo repetido
        if (id == filmes[i]->id) {
            cout << "ERRO: codigo repetido\n";
            return;
        }
    }
    if (tipo != 'F' && tipo !='D') { // tipo invalido
        cout << "ERRO: dados incorretos\n";
        return;
    }
    if (tipo == 'D') {
        if(categoria!= 'E' && categoria!= 'L' && categoria!= 'P') { // categoria invalida
            cout << "ERRO: dados incorretos\n";
            return;
        }
    } 
    if (unidades<0 || id<0) { // unidades ou id negativos
        cout << "ERRO: dados incorretos\n";
        return;
    }

    Filme* novoFilme = nullptr;
    if (tipo=='F') {
        novoFilme = new Fita(id, titulo, unidades);
    } else if (categoria == 'E') {
        novoFilme = new dvdEstoque(id, titulo, unidades);
    } else if (categoria == 'L') {
        novoFilme = new dvdLancamento(id, titulo, unidades);
    } else if (categoria == 'P') {
        novoFilme = new dvdPromocao(id, titulo, unidades);
    } 

    if (novoFilme!=nullptr) {
        filmes.push_back(novoFilme);
        cout << "Filme "<< novoFilme->id <<" cadastrado com sucesso\n";
    }
}

/** 
 * @brief Método "removerFilme" da classe "Locadora", utilizado para registro e controle.
 * @details Esse método remove um filme da locadora. Ele recebe como parâmetro o id de identificação do
 * filme e, a partir daí, percorre o vetor "filmes" procurando o filme com esse id, utilizando a funcão
 * "find_if". Caso esse filme seja encontrado, o método o retira do vetor "filmes" e, portanto, da locadora.
 * Caso contrário, o método exibe uma mensagem de erro e não retira nenhum filme da locadora.
 */  

void Locadora::removerFilme(int id) {
    auto it = find_if(filmes.begin(), filmes.end(),
        [id](Filme* filme) { return filme->id == id; });

    if (it != filmes.end()) {
        delete *it; 
        filmes.erase(it);
        cout << "Filme " << id << " removido com sucesso.\n";
    } else {
        cout << "ERRO: código inexistente.\n"; // Id invalido
    }
}

/**
 * @brief Método "listarFilmes" da classe "Locadora", utilizado especialmente para exibição.
 * @details Esse método é responsável por listar os filmes da locadora. Ele recebe 
 * como parâmetros a opção de listagem desejada pelo usuário. Caso essa opção seja inválida, o método
 * exibe uma mensagem de erro e retorna. O mesmo ocorre caso ainda não existam filmes para listar. Caso
 * a opção de listagem seja válida e existam filmes para serem listados, o método cria umma cópia do vetor "filmes"
 * da locadora e ordena com base na opção fornecida, seja por id ou título.
 * @param opcao Armazena a opção de ordenação dos filmes.
*/

void Locadora::listarFilmes(char opcao) {
    if (opcao != 'C' && opcao != 'T') {
        cout << "ERRO: opção de ordenação inválida.\n";
        return;
    }
    if(this->filmes.size()==0) {
        cout << "Ainda não há filmes para listar." << endl;
        return;
    }
   filmesOrdenados = filmes;

    auto compara = [opcao](const Filme* a, const Filme* b) {
        if (opcao == 'C') {
            return a->id < b->id;
        } else {
            return a->titulo < b->titulo;
        }
    };

   sort(filmesOrdenados.begin(), filmesOrdenados.end(), compara);

    for (const auto& filme : filmesOrdenados) {
        filme->lerFilme();
    }
}

/** 
 * @brief Método "cadastrarFilme" da classe "Locadora", utilizado para controle e registro.
 * @details Esse método cadastra um novo cliente à locadora. Ele recebe como parâmetros o nome e o cpf
 * de um determinado cliente. A partir daí, ele percorre o vetor "clientes" da locadora e verifica se o cpf 
 * do cliente já está cadastrado. Caso esteja, o método exibe uma mensagem de erro informando sobre isso e retorna.
 * Caso o cpf informado seja inválido, o método também exibe uma mensagem de erro e retorna. Por fim, caso o cpf
 * ainda não esteja cadastrado na locadora e seja válido, o cliente é adicionado ao vetor "clientes" da locadora e,
 * portanto, cadastrado na mesma, de forma que o método exibe uma mensagem informando que o cadastro foi um sucesso.
 * @param cpf Armazena o cpf do cliente.
 * @param nome Armazena o nome do cliente.
 */

void Locadora::cadastrarCliente(long long cpf, string nome) {
    int n= clientes.size();
    for (int i=0; i<n; i++) {
        if (cpf == clientes[i]->cpf) { // CPF repetido
            cout << "ERRO: CPF repetido\n";
            return;
        }
    }
    if (cpf<10000000000 || cpf>99999999999) { // CPF invalido
        cout << "ERRO: dados incorretos\n";
        return;
    }

    Cliente* cliente = new Cliente(cpf, nome);
    this -> clientes.push_back(cliente);
    cout << "Cliente "<< cliente->nome <<" cadastrado com sucesso\n";
}

/** 
 * @brief Método "removerCliente" da classe "Locadora", utilizado para controle e registro.
 * @details Esse método remove um cliente já cadastrado na locadora. Ele recebe como parâmetro o cpf
 * de um cliente, o qual indica o cpf do cliente a ser removido. A partir daí, o método percorre o vetor 
 * "clientes" da locadora à procura do cliente com o cpf informado, utilizando a função "find_if". Caso esse
 * cliente seja encontrado, ele é removido do vetor e, portanto, da locadora, de forma que o método exibe uma 
 * mensagem informando sobre isso. Caso contrário, uma mensagem de erro é exibida.
 */

void Locadora::removerCliente(long long cpf) {
    auto it = find_if(this->clientes.begin(), this->clientes.end(),
                           [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });

    if (it == clientes.end()) { // CPF não encontrado
        cout << "ERRO: dados incorretos.\n";
        return;
    } else {
        delete *it;
        cout << "Cliente removido com sucesso\n";
        this->clientes.erase(it);
    }
}

/** 
 * @brief Método "listarClientes" da classe "Locadora", utilizado para exibição.
 * @details Esse método lista os clientes cadastrados na locadora. Ele recebe o parâmetro "opção" e verifica
 * se a opção de ordenação é valida. Se não for válida, o método exibe uma mensagem de erro. Caso o vetor 
 * "clientes" esteja vazio, significa que não há clientes cadastrado na locadora, então o método exibe uma 
 * mensagem avisando sobre isso. Caso a opção de ordenação seja válida e existirem clientes cadastrados na locadora,
 * o método lista esses clientes de acordo com o cpf ou nome.
 * @param opcao Armazena a opção de listagem dos clientes (nome ou cpf).
 */
 void Locadora::listarClientes(char opcao){

    if (opcao != 'C' && opcao != 'N') {
        cout << "ERRO: opção de ordenação inválida.\n";
        return;
    }
    if (this->clientes.size()==0) {
        cout << "Ainda não há clientes para listar." << endl;
        return;
    }

    clientesOrdenados = clientes;

    auto compara = [opcao](const Cliente* a, const Cliente* b) {
        if (opcao == 'C') {
            return a->cpf < b->cpf;
        } else {
            return a->nome < b->nome;
        }
    };

   sort(clientesOrdenados.begin(), clientesOrdenados.end(), compara);

    for (const auto& cliente : clientesOrdenados) {
        cliente->lerCliente();
    }
}

/**
 * @brief Método "aluguel" da classe "locadora", utilizado especialmente para controle e registro.
 * @details O método recebe como parâmetros o cpf de um cliente que deseja alugar um filme e o id de 
 * identificação desse mesmo filme. A partir daí, ele percorre o vetor "clientes", procurando pelo cpf
 * informado e o vetor "filmes", procurando pelo id do filme informado. Caso o cliente ou o filme não existirem,
 * o método exibe uma mensagem de erro. Caso contrário, ocorre uma verificação para saber se ainda existem
 * cópias do filme disponíveis para locação. Caso existam, o método registra que o filme foi alugado
 * pelo cliente. Caso contrário, o método informa que não existem mais unidades do filme disponiveis para
 * aluguel. Além disso, o método possibilita o aluguel de vários filmes ao mesmo tempo.
*/
void Locadora::aluguel(long long cpf, vector<int> id) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; }); // encontra cliente

    Cliente* cliente = nullptr;
    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else { // cpf inexistente
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    if (cliente->bloqueado==true) {
        cout << "ERRO: cliente bloqueado! Devolva os filmes antes de alugar novos." << endl;
        return;
    }
    
    bool alugou = false;
    vector<int> inexistentes;
    vector<int> emFalta;

    cout << endl << "Cliente " << cliente->cpf << " " << cliente->nome << " alugou os filmes: " << endl;
    for (int id : id) { // para cada um dos codigos 
        auto itFilme = find_if(filmes.begin(), filmes.end(),
            [id](Filme* filme) { return filme->id == id; }); // encontra filme

        Filme* filme = nullptr;
        if (itFilme != this->filmes.end()) {
            filme = *itFilme;
        } else { // filme inexistente
            inexistentes.push_back(id);
        }

        if (filme!=nullptr) {
            bool aindaTemCopias = filme->serAlugado();
            if (aindaTemCopias) {
                cliente->alugar(filme);
                filme->lerFilme();
                alugou = true;
            } else { // filme em falta
                emFalta.push_back(id);
            }
        }
    }
    for (int id : inexistentes) {
        cout << "ERRO: Filme " << id << " inexistente" << endl;
    }
    for (int id : emFalta) {
        cout << "ERRO: Filme " << id << " em falta no estoque" << endl;
    }
    if (alugou) {
        this->bloqueados.push_back(cliente);
    }

}

/**
 * @brief Método "devolucao" da classe "Locadora", utilizado especialmente para controle e registro.
 * @details O método recebe como parâmetros o cpf de um cliente e os dias nos quais ele ficou com um
 * filme alugado. A partir daí, a função procura pelo cpf informado no vetor "clientes". Caso esse cliente
 * não exista, o método exibe uma mensagem de erro. Caso contrário, ocorre uma busca pela lista de filmes
 * alugados por esse cliente e calcula quanto ele deve pagar com base nos dias que ele ficou com o filme alugado.
 * Além disso, o método verifica se o cliente em questão possui mais de 10 pontos. Caso possua, ocorre uma 
 * aplicação de 10% de desconto sobre o valor do aluguel. Por fim, o método exibe o valor que o cliente terá
 * que pagar e chama outros dois métodos: "serDevolvido()", para registrar que o filme foi devolvido à locadora
 * e "devolver()", para registrar que o cliente devolveu o filme à locadora.
 * @param dias Armazena a quantidade de dias que um cliente ficou com o filme alugado.
*/

void Locadora::devolucao(long long cpf, int dias) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });
    Cliente* cliente;

    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else {
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    cout << "Cliente " << cpf << " " << cliente -> nome << " devolveu os filmes:" << endl;
    int total = 0;
    if (cliente->filmesAlugados.size()==0) {
        cout << "ERRO: não há filmes alugados" << endl;
    }
    for (const auto& filme : cliente -> filmesAlugados) {
        cout << filme -> id << " " ;
        int valor = filme -> calcularValor(dias);
        cout << valor << endl;
        total += valor;
    }

    if(cliente->pontos>10) {
        cout << "Você ganhou um desconto de 10%. Obrigado pela fidelidade!" << endl;
        cout << "De: R$" << total << endl;
        total = 0.9 * total;
        cout << "por: R$" << total << endl;
        cliente->pontos = cliente->pontos - 10;
    }
    
    cout << "Total a pagar: R$" << total << endl;
    for (const auto& filme : cliente -> filmesAlugados) {
        filme -> serDevolvido();
        cliente->bloqueado=false;
    }
    cliente -> devolver();
    auto it = find(this -> bloqueados.begin(), this -> bloqueados.end(), cliente);
    this -> bloqueados.erase(it);
}

/**
 * @brief Método "recomendarFilmes" da classe "Locadora".
 * @details O método recebe como parâmetro um cpf e procura no vetor "clientes" pelo cliente com o cpf informado.
 * Se o cliente não for encontrado, uma mensagem de erro é exibida. Caso contrário, ocorre a chamada do método
 * "recomendar()" para o cliente em questão, o qual recomenda filmes com base nos gostos desse cliente e nos gostos 
 * de outros clientes da locadora que são considerados similares à ele. Por fim, a função percorre a lista de filmes 
 * recomendados e chama o método "lerFilme()", o qual exibe informações sobre os filmes recomendados na tela.
*/

void Locadora::recomendarFilmes(long long cpf) {
    auto itCliente = find_if(this->clientes.begin(), this->clientes.end(),
        [cpf](const Cliente* cliente) { return cliente->cpf == cpf; });
    Cliente* cliente;

    if (itCliente != this->clientes.end()) {
        cliente = *itCliente;
    } else {
        cout << "ERRO: CPF inexistente\n";
        return;
    }

    cout << endl << "Filmes recomendados para " << cliente->nome << ":" << endl;
    cliente -> recomendar(this -> clientes);

    for (Filme* filme : cliente -> recomendados) {
        filme -> lerFilme();
    }

}

/**
 * @brief Método "avaliarFilme" da classe "Locadora".
 * @details O método recebe como parâmetros o id de identificação de um filme e a nota dada à ele
 * por um cliente. A partir daí, o método percorre o vetor "filmes" procurando pelo id informado.
 * Caso o filme não seja encontrado, o método exibe uma mensagem de erro. Caso contrário, ocorre a
 * chamada do método "serAvaliado()", o qual atribui a nota dada pelo cliente à esse filme em questão.
 * @param nota Armazena a nota recebida por um filme.
*/

void Locadora::avaliarFilme(int id, float nota) {
    auto itFilme = std::find_if(filmes.begin(), filmes.end(),
        [id](Filme* filme) { return filme->id == id; });
    Filme* filme;

    if (itFilme != this->filmes.end()) {
        filme = *itFilme;
    } else { // filme inexistente
        cout << "ERRO: Filme " << id<< " inexistente\n";
        return;
    }
    
    filme->serAvaliado(nota);
    cout << "Filme "<< filme->id <<" avaliado com sucesso\n";    
}



void Locadora::listarBloqueados() {
    if(this->bloqueados.size()<=0) {
        cout << "Não há clientes bloqueados!" << endl;
        return;
    }
    cout << "Os seguintes clientes estão bloqueados:" << endl;
    for (Cliente* cliente : this -> bloqueados) {
        cliente->lerCliente();
    }
}