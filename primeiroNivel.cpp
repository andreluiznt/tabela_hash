# include "segundoNivel.cpp"

class PrimeiroNivel {
    private:
        vector<SegundoNivel*> tabela1;
        int tamanhoTotal;

        // FUNÇÃO HASH NÍVEL 1 - transforma a string chave em um índice numérico que vai de 0 até tamanho - 1
        // Esse índice vem da soma dos valores numéricos dos caracteres da chave (ASCII)
        int hash1(string chave) {
            int soma = 0;
            for (char c : chave){
                //um fator multiplicador 3 para os valores ASCII dos caracteres
                // ajuda a distribuir melhor os valores no índice da tabela, mas com um intervalo fixo de 0 a 9
                soma += c * 3;
            }
            return soma % 10;
        }
    
    public:
        PrimeiroNivel(int n) : tamanhoTotal(n) {
            tabela1.resize(10, nullptr);
        }
    
        void inserir(string chave, string valor) {
            int idx1 = hash1(chave);
            if (tabela1[idx1] == nullptr) {
                tabela1[idx1] = new SegundoNivel(tamanhoTotal);
            }
            tabela1[idx1]->inserir(chave, valor);
        }
    
        Objeto* buscar(string chave) {
            int idx1 = hash1(chave);
            if (tabela1[idx1] == nullptr) return nullptr;
            return tabela1[idx1]->buscar(chave);
        }
    
        ~PrimeiroNivel() {
            for (auto ptr : tabela1) {
                delete ptr;
            }
        }
};