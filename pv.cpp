/* Faça um programa em C++ que vai servir como ponto que vai servir como ponto de venda em um estabelecimento 
comercial. Declare as seguintes classes: cliente, venda e item;

O programa solicitará ao seu início:

- O CPF do cliente (long)
- O telefone do cliente (int)
- A quantidade de itens da venda (int)
- A forma de pagamento da venda (int 1 - cartão; 2 - dinheiro; 3 - pix)

Para cada item da venda, inserir:

- Codigo do item (int)
- Quantidade (int)
- Preco em reais (float)

Exibir todas as informações e o valor final da venda e sair;*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

class cliente {
    long cpf; // Long só aceita números com até 10 digitos, o cpf tem 11, mas vamos usar mesmo assim
    int telefone;

public:
    cliente(long c, int t): cpf(c), telefone(t){
        cout << "Cliente " << cpf << " criado" << endl;
    }
    ~cliente() {
        cout << "Cliente " << cpf << " removido" << endl;
    }

    long get_cpf() {
        return cpf;
    }
    void set_cpf(long c) {
        cpf = c;
    }
    
    int get_telefone(){
        return telefone;
    }
    void set_telefone(int t){
        telefone = t;
    }
};

class item {
    int codigo;
    int quantidade;
    float preco_unitario;
public:
    item(int c = 0, int q = 0, float p = 0):codigo(c), quantidade(q), preco_unitario(p){
        cout << "item " << codigo << " criado!" << endl;
    }
    ~item(){
        cout << "item " << codigo << " finalizado" << endl;
    }
    int get_codigo() {
        return codigo;
    }
    void set_codigo(int c){ 
        codigo = c;
    }

    int get_quantidade() {
        return quantidade;
    }
    void set_quantidade(int q){
        quantidade = q;
    }

    float get_preco_unitario(){
        return preco_unitario;
    }
    void set_preco_unitario(float p){
        preco_unitario = p;
    }
    void print_info(){
        cout << "Codigo item: " << codigo << endl;
        cout << "Quantidade item: " << quantidade << endl;
        cout << "Preco unitario item: " << preco_unitario << endl;
        cout << "Valor total item: " << preco_unitario*quantidade;
        cout << endl;
    }
};

class venda{
    int quantidade_item;
    int forma_pagamento;
    cliente* cli_venda;
    item* produtos;
public:
    venda(int q, int f, cliente* c, item* p):quantidade_item(q), forma_pagamento(f) {
        cli_venda = new cliente(c->get_cpf(), c->get_telefone());
        produtos = p;
        cout << "Venda com " << q << " croada" << endl;
    }
    ~venda(){
        delete cli_venda;
        delete[] produtos;
    }

    int get_quantidade_item(){ 
        return quantidade_item;
    }
    void set_quantidade_item(int q){
        quantidade_item = q;
    }

    int get_forma_pagamento(){
        return forma_pagamento;
    }
    void set_forma_pagamento(int f){
        forma_pagamento = f;
    }

    cliente* get_cliente(){
        return cli_venda;
    }
    void set_cliente(cliente* c) {
        cli_venda = c;
    }
    item* get_produtos() {
        return produtos;
    }
    void set_produtos(item* p){
        produtos = p;
    }
    float get_valor_final(){
        float valor_final = 0;
        for (int i = 0; i < quantidade_item; i++) {
            valor_final += (produtos[i].get_quantidade() * produtos[i].get_preco_unitario());
        }

        return valor_final;
    }

    void print_info(){
        cout << "CPF Cliente: " << cli_venda->get_cpf() << endl;
        cout << "Telefone cliente: " << cli_venda->get_telefone() << endl;
        cout << endl << endl;
        cout << "Quantidade de produtos: " << quantidade_item << endl;
        cout << "Forma de pagamento: " << forma_pagamento << endl;
        cout << "Itens da venda: " << endl;
        for (int i = 0; i < quantidade_item; i++){
            produtos[i].print_info();
        }
        cout << "===================================" << endl;
        cout << "Valor total da venda: R$ " << get_valor_final() << endl;
        cout << "===================================" << endl; 
    }
};

int main(void) {
    long cpf_cliente;
    int tel_cliente;
    cliente* cliente_venda;
    item* produtos;
    venda* minha_venda;

    cout << "PDV 1.0" << endl;
    cout << "======================================" << endl;
    cout << "Digite o cpf do cliente: ";
    cin >> cpf_cliente;
    cout << "Digite o telefone do cliente: ";
    cin >> tel_cliente; 

    cliente_venda = new cliente(cpf_cliente, tel_cliente);

    cout << "Digite quantos produtos diferentes na venda: ";
    int qtd_prod;
    cin >> qtd_prod;
    cout << "Digite a forma de pagamento: ";
    int forma_pag;
    cin >> forma_pag;
    cout << "DIgite as informações dos produtos ";
    produtos = new item[qtd_prod];
    for (int i = 0; i < qtd_prod; i++) {
        int cod_item;
        int qtd_item;
        float preco_item;
        cout << "Digite o código do produto " << (i+1) << ": ";
        cin >> cod_item;
        cout << "Digite a quantidade desse produto: ";
        cin >> qtd_item;
        cout << "Digite o preco desse item: ";
        cin >> preco_item;

        produtos[i].set_codigo(cod_item);
        produtos[i].set_quantidade(qtd_item);
        produtos[i].set_preco_unitario(preco_item);

    }
    minha_venda = new venda(qtd_prod, forma_pag, cliente_venda, produtos);

    minha_venda->print_info();

    delete minha_venda;


    return 0;
}