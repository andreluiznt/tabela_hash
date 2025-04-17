#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

# include "primeiroNivel.cpp"

int main() {
    PrimeiroNivel tabela(100); // tabela Hash para armazenar 100 objetos

    tabela.inserir("João", "Marco");
    tabela.inserir("Marina", "");
    tabela.inserir("Julia", "");
    tabela.inserir("Antonio", "José");

    auto obj = tabela.buscar("João");
    if (obj != nullptr)
        cout << "Encontrado: " << obj->chave << " => " << obj->valor << endl;
    else
        cout << "Objeto não encontrado.\n";

    return 0;
}