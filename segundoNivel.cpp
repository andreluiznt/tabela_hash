#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Objeto {
    string chave;
    string valor;

    Objeto(string c, string v) : chave(c), valor(v) {}
};

class SegundoNivel {
    private:
        // vector de uma lista encadeada do tipo Objeto
        // o tipo 'Objeto' é estruturado com duas strings com 'Chave' e 'Valor'    
        // list é uma classe de Lista Encadeada implementada na Biblioteca 'List'
        vector<list<Objeto>> tabela;
        // tamanho da tabela
        int tamanho;

        // função hash do nível 2
        // transforma a string chave em um índice numérico que vai de 0 até tamanho - 1
        // esse índice vem da soma dos valores numéricos dos caracteres da chave (ASCII)
        int hash2(string chave) {
            int soma = 0;
            // um loop somando os valores ASCII de cada caracter presente na string
            for (char c : chave){
                soma += c;
            }
            // faz um hash simples retornando a posição
            return soma % tamanho;
        }
    
    public:
        // construtor da classe para o segundo nível
        // tamanho está sendo inicializado antes de entrar no corpo do construtor
        SegundoNivel(int n) : tamanho(n / 10) {
            // resize está redefinindo o vetor para ter o tamanho presente na variável "tamanho"
            tabela.resize(tamanho);
        }
        
        // função de inserção de novos objetos
        void inserir(string chave, string valor) {
            // chama a função hash para retornar a posição da chave
            int idx = hash2(chave);
            // adiciona o valor ao final do vetor presente na tabela[idx]
            tabela[idx].emplace_back(chave, valor);
        }
        
        // função que irá buscar o endereço de memória (Ponteiro) do tipo estruturado através da chave
        Objeto* buscar(string chave) {
            // calcula o hash
            int idx = hash2(chave);
            // loop de intervalo que permite iterar sobre todos os elementos do vetor
            for (auto& obj : tabela[idx]) {
                if (obj.chave == chave){
                    // retorna o ponteiro do objeto caso encontrado
                    return &obj;
                }
            }
            return nullptr;
        }
};