#include "acervo.hpp"

using namespace std;

Acervo::Acervo(){
    for(auto genero : generos){
        acervo.insert(pair<string, list<Livro>>(genero, listaDefault));
    }
}

void Acervo::verLivrosEmprestados(){
    cout << "=========================================" << endl;
    cout << "Livros Emprestados: " << endl;
    for (int i = 0; i < this->historicoEmprestimo.size(); i++){
        if (this->historicoEmprestimo[i].getStatusEmprestimo()){
            this->historicoEmprestimo[i].getLivro().print();
            cout << "Responsavel pelo Emprestimo: " << endl; 
            this->historicoEmprestimo[i].getUsuario().print();
            cout << "//////////////////////////////////////////" << endl;
        }
    }
    return;
}

void Acervo::realizarEmprestimo(Usuario _usuario, Livro _livro){
    EmprestimoLivro emprestimo = EmprestimoLivro(_usuario, _livro);
    this->historicoEmprestimo.push_back(emprestimo);
    cout << "O livro" << _livro.getTitulo() << " foi emprestado para o Usuario " << endl;
    _usuario.print();
    cout << " com sucesso!" << endl;
    emprestimo.setStatusEmprestimo(true);
    return;
}

void Acervo::realizarDevolucao(Usuario &_usuario, Livro &_livro){
    for (int i = 0; i < this->historicoEmprestimo.size(); i++){
        if (this->historicoEmprestimo[i].getLivro().getCodigo() == _livro.getCodigo()){
            this->historicoEmprestimo[i].setStatusEmprestimo(false);
        }
    }
    cout << "O usuario " << endl; 
    _usuario.print(); 
    cout << "O livro " << _livro.getTitulo() << " foi devolvido com sucesso! Volte Sempre!" << endl; 
}

void Acervo::verAcervo(){
    map<string, list<Livro>>::iterator iterator;

    cout << "===========================" << endl;

    for (iterator = this->acervo.begin(); iterator != this->acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 
        
        cout << "ESTANTE DO GENERO: " << genero << endl;

        if (livros.size() > 0){
            for (auto &livro : livros){
                livro.print();
            }
            cout << "FIM DA ESTANTE: " << genero << endl;
            cout << "===========================" << endl;
        }else{
            cout << "ESTANTE VAZIA" << endl;
        }
    }
}

void Acervo::adicionarLivros(Livro _livro){
    bool adicionado = false;
    map<string, list<Livro>>::iterator iterator;
    
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 

        if(genero == _livro.getGenero()){ 
            for (auto &livro : livros){
                
                if (livro.getCodigo() == _livro.getCodigo()){
                    cout << "O livro " << _livro.getTitulo() << " já está cadastrado no acervo." << endl;
                    incrementarQtdExemplaresLivro(_livro.getGenero(), _livro.getTitulo(), _livro.qtdExemplares);
                    cout << "PS: agradecemos, o livro recebeu mais " << _livro.qtdExemplares << " exemplar(es)!!" << endl; 
                    this->numeroExemplares++;
                    adicionado = true;
                }
            }
            if(!adicionado){
                iterator->second.push_back(_livro);
                this->numeroExemplares = _livro.qtdExemplares;
                cout << "O livro " << _livro.getTitulo() << " foi cadastrado com sucesso!" << endl;
            }
        }
    }
}

void Acervo::removerLivros(Livro _livro){
    bool removido = false;    
    map<string, list<Livro>>::iterator iterator;
    
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 
        
        if(genero == _livro.getGenero()){ 
            for (auto &livro : livros){
                if (livro.getCodigo() == _livro.getCodigo()){
                    cout << "O livro " << _livro.getTitulo() << " foi removido com sucesso." << endl;
                    removido = true;
                }
            }
            if(!removido){
                livros.push_back(_livro);
                this->numeroExemplares--;
                cout << "O livro " << _livro.getTitulo() << " não consta no acervo." << endl;
            }
        }
    }
}

void Acervo::consultarAcervo(string _generoConsulta, string _tituloConsulta){
    map<string, list<Livro>>::iterator iterator;
    
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 

        if(genero == _generoConsulta){
            for (auto &livro : livros){
                if (_tituloConsulta == livro.getTitulo()){
                    livro.print();
                }
            }
        }

    }
}

void Acervo::incrementarQtdExemplaresLivro(string _generoConsulta, string _tituloConsulta, int _incremento){
     map<string, list<Livro>>::iterator iterator;
    
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 

        if(genero == _generoConsulta){
            for (auto &livro : iterator->second){
                if (_tituloConsulta == livro.getTitulo()){
                    livro.qtdExemplares += _incremento;
                }
            }
        }

    }
}

Livro Acervo::getLivro(string _generoConsulta, string _tituloConsulta){
    map<string, list<Livro>>::iterator iterator;
    
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        list<Livro> livros = iterator->second;
        string genero = iterator->first; 

        if(genero == _generoConsulta){
            for (auto &livro : livros){
                if (_tituloConsulta == livro.getTitulo()){
                    return livro;
                }
            }
        }
    }
    Livro naoExistente;
    return naoExistente;
}

void Acervo::adicionarGeneroNovo(string _generoNovo){
    map<string, list<Livro>>::iterator iterator;
    for (iterator = acervo.begin(); iterator != acervo.end(); ++iterator){
        string genero = iterator->first; 
        if(genero == _generoNovo){
            cout << "O gênero " << genero << " já existe." << endl << endl;
            return;
        }
    }
    acervo.insert(pair<string, list<Livro>>(_generoNovo, listaDefault));
    cout << "Obrigado por contribuir com a biblioteca. o gênero " << _generoNovo << " foi adicionado nas estante com sucesso!" << endl <<endl;
    return;
}
