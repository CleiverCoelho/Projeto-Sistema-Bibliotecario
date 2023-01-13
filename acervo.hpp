#ifndef ACERVO_HPP
#define ACERVO_HPP

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iterator>

#include "livro.hpp"
#include "emprestimoLivro.hpp"

using namespace std;

class Acervo{
    private:
        map<string, list<Livro>> acervo;
        vector<EmprestimoLivro> historicoEmprestimo;

    public:
        int numeroExemplares = 0;
        list<Livro> listaDefault;
        list<string> generos = {"romance" ,"ação" ,"aventura" ,"terror" ,"drama" ,"ficção cientifica", "outro"};
        
         /**
         * @brief Construtor que inicializa o acervo com gêneros literários associados a uma lista padrão.
         */
        Acervo();
        
         /**
         * @brief Método que adiciona um livro já instanciado, ou seja, cadastrado à coleção de livros. Assim que o livro é cadastrado no sistema,
         * uma mensagem de confirmação é exibida. Caso algum erro ocorra e o livro não seja adicionado, uma mensagem de erro é impressa.
         * @param _livro Livro que foi instanciado e se encontra pronta para adicioná-lo ao acervo.
         */
        void adicionarLivros(Livro _livro);
    
         /**
         * @brief Método que remove um livro já cadastrado à coleção de livros,ou seja, no acervo. Assim que o livro é removido no sistema, uma mensagem
         * de confirmação é exibida. Caso algum erro ocorra ou o livro não esteja no acervo, uma outra mensagem é impressa.
         * @param _livro Livro que se deseja remover do acervo.
         */
        void removerLivros(Livro _livro);
    
        /**
        * @brief Método que procura e imprime as informações de um livro. Esse método é utilizado para pesquisar se o livro desejado se encontra dispoível
        * no acervo. Se o livro existe, as informações do livro são printadas, caso contrario uma mensagem é exibida.
        * @param _generoConsulta Parametro que contém o gênero do livro a ser consultado.
        * @param _tituloConsulta Parâmetro que contem o titulo do livro a ser consultado.
        */
        void consultarAcervo(string, string);
    
         /**
         * @brief Método que retorna um livro consultado, caso contrário retorna um livro vazio, não existente.
         * @param _generoConsulta Parametro que contém o gênero do livro.
         * @param _tituloConsulta Parametro que contém o título do livro.
         * @return livro Livro retornado, caso ele exista.
         * @return naoExistente Livro sem parâmetros, vazio.
         */
        Livro getLivro(string, string);
    
         /**
         * @brief Método que incrementa a quantidade de exemplares de um livro em específico. Caso algum bibliotecário queira atualizar a quantidade de um
         * livro em específico no acervo.
         * @param _generoConsulta Parametro que contém o gênero do livro.
         * @param _tituloConsulta Parametro que contém o título do livro.
         * @param _incremento Parametro que contém a quantidade de exemplares do livro.
         */
        void incrementarQtdExemplaresLivro(string, string, int);
    
         /**
         * @brief Adiciona um novo gênero a coleção de estantes. Caso o gênero seja adicionado ou caso o mesmo já exista, uma mensagem é exibida.
         * @param _generoNovo Parametro que contém o gênero a ser adicionado.
         */
        void adicionarGeneroNovo(string);
    
         /**
         * @brief Método que imprime as estantes de cada gênero existente e seus respectivos livros associados.
         */
        void verAcervo();
        
         /**
         * @brief Método que realiza o emprestimo de livro.
         * @param Usuario Parâmetro que contém um Usuário.
         * @param Livro Parâmetro que contém um Livro.
         */
        void realizarEmprestimo(Usuario, Livro);
    
         /**
         * @brief Método que acessa os livros emprestados e printa as informações.
         */
        void verLivrosEmprestados();
    
         /**
         * @brief Método que acessa o histórico de livros emprestados e printa as informações.
         */
        void verHistoricoEmprestimo();
    
         /**
         * @brief Método que devolve o livro emprestado.
         * @param Usuario Parâmetro que contém um Usuário.
         * @param Livro Parâmetro que contém um Livro.
         */
        void realizarDevolucao(Usuario&, Livro&);

};

#endif
