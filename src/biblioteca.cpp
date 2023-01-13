#include "biblioteca.hpp"

int Biblioteca::getSenha(){
    return this->senhaAdministradora;
}
void Biblioteca::setSenha(int _novaSenha){
   this->senhaAdministradora = _novaSenha;
}

Biblioteca::Biblioteca(){

}

void Biblioteca::cadastrarUsuarios(Usuario _usuario){
    bool cadastrado = false;

    for (auto &usuario : this->usuarios){
        if (usuario.getMatricula() == _usuario.getMatricula()){
            cout<< "O usuário "<<_usuario.getNome()<<" já está cadastrado no sistema."<<endl;
            cadastrado = true;
        }
    }
    if(!cadastrado){
        this->usuarios.push_back(_usuario);
        cout << "O usuário " << _usuario.getNome() << " foi cadastrado no sistema." << endl;
    }
}

void Biblioteca::removerUsuarios(Usuario _usuario){
    bool removido = false;

    for (auto &usuario : this->usuarios){
        if (usuario.getMatricula() == _usuario.getMatricula()){
            cout << "O usuário " << _usuario.getNome() << " foi removido do sistema." << endl;
            removido = true;
        }
    }
    if(!removido){
        cout << "O usuário " << _usuario.getNome() << " não existe no sistema." << endl;
    }
}

void Biblioteca::cadastrarBibliotecarios(Bibliotecario _bibliotecario){
    bool cadastrado = false;

    for (auto &bibliotecario : this->bibliotecarios){
        if (_bibliotecario.getRegistro() == bibliotecario.getRegistro()){
            this->bibliotecarios.push_back(_bibliotecario);
            cout<< "O bibliotecário "<<_bibliotecario.getNome()<<" já está cadastrado no sistema."<<endl;
            cadastrado = true;
        }
    }
    if(!cadastrado){
        this->bibliotecarios.push_back(_bibliotecario);
        cout << "O bibliotecário " << _bibliotecario.getNome() << " foi cadastrado no sistema." << endl;
        
    }
}

void Biblioteca::removerBibliotecarios(Bibliotecario _bibliotecario){
    bool removido = false;

    for (auto &bibliotecario : this->bibliotecarios){
        if (bibliotecario.getRegistro() == _bibliotecario.getRegistro()){
            removido = true;
            cout <<"O bibliotecário "<<_bibliotecario.getNome()<<" foi removido do sistema."<<endl;

        }
    }
    if(!removido) {
        cout << "O bibliotecário " << _bibliotecario.getNome() << " não existe no sistema." << endl;
    }
}

Bibliotecario Biblioteca::procurarBibliotecario(int _registro){
    for (auto bibliotecario : this->bibliotecarios){
        if (bibliotecario.getRegistro() == _registro){
            return bibliotecario;
        }
    }
    Bibliotecario naoExistente;
    return naoExistente;
}

Usuario Biblioteca::procurarUsuario(int _matricula){
    for (auto usuario : this->usuarios) {
        if (usuario.getMatricula() == _matricula){
            return usuario;
        }
    }
    Usuario naoExistente;
    return naoExistente;
}

void Biblioteca::verBiblioteca(){
    
    cout << "===============" << endl;
    cout << "USUARIOS" << endl; 
    for (auto &usuario : this->usuarios){
        usuario.print();
        cout << "------------ " << endl;
    }
    cout << "==================" << endl;
    cout << "BIBLIOTECARIOS" << endl;
    for (auto bibliotecario : this->bibliotecarios){
        bibliotecario.print();
        cout << "---------------" << endl;
    }
    cout << "===============" << endl;
    cout << "ARMÁRIOS DISPONÍVEIS" << endl; 
    for (int i=0; i<armarios.size();i++){
        cout << armarios[i] << " ";
    }
    cout << endl << "===============" << endl;
    cout << "SALAS DISPONÍVEIS" << endl; 
    for (int i=0; i<salas.size();i++){
        cout << salas[i] << " ";
    }
    cout << endl;
}

void Biblioteca::erase(int _sala, int _armario){
    if (_armario==0){
        int x = 0;
        for (int i=0; i<this->salas.size();i++){
            if (salas[i]==_sala) x=i;
        }
        this->salas.erase(salas.begin()+x);
    }
    if (_sala==0){
        int x = 0;
        for (int i=0; i<this->armarios.size();i++){
            if (armarios[i]==_armario) x=i;
        }
        this->armarios.erase(armarios.begin()+x);
    }
}

bool Biblioteca::find(int _sala, int _armario){
    if (_armario == 0){
        if (salas.empty()){
        cout << "Não há salas disponíveis."<<endl;
        return false;
        }
        else {
            for (int i=0; i<this->salas.size();i++){
            if (salas[i]== _sala) return true;
            }
            cout << "A sala "<< _sala<< " não está disponível."<<endl;
            return false;
        }
    }
    if (_sala ==0){
        if (armarios.empty()){
        cout << "Não há armários disponíveis."<<endl;
        return false;
        }
        else {
            for (int i=0; i<this->armarios.size();i++){
            if (armarios[i]== _armario) return true;
            }
            cout << "O armário "<< _armario << " não está disponível."<<endl;
            return false;
        }
    }
    return false;   
}

void Biblioteca::emprestar(int _sala, int _armario, int _matricula){
    if (_armario == 0){
        if (find(_sala,0)){
            string _codigo = "Sala: " + to_string(_sala) + " emprestada para o usuário " + to_string(_matricula);
            reservas.setCodigo(_codigo);
            erase(_sala,0);
            cout << "Sala emprestada com sucesso" << endl;
        }
    }
    if (_sala == 0){
        if (find(0,_armario)){
            string _codigo = "Armário: " + to_string(_armario) + " emprestado para o usuário " + to_string(_matricula);
            reservas.setCodigo(_codigo);
            erase(0, _armario);
            cout << "Armário emprestado com sucesso" << endl;
        }
    }
} 

void Biblioteca::add(int _sala, int _armario){
  if (_sala == 0){
    for (int i=0; i<this->armarios.size();i++){
        if (armarios[i]==_armario){
            cout << "Armário já devolvido." << endl;
        }
    }
    armarios.push_back(_armario);
    sort(armarios.begin(), armarios.end());
  }

  if (_armario == 0){
    for (int i=0; i<this->salas.size();i++){
        if (salas[i]==_sala){
            cout << "Sala já devolvida." << endl;
        }
    }
    salas.push_back(_sala);
    sort(salas.begin(), salas.end());
  }
}

void Biblioteca::devolver(int _sala, int _armario, int _matricula){
    if (_armario == 0){
        add(_sala, 0);
        string _codigo = "Sala: " + to_string(_sala) + " emprestada para o usuário " + to_string(_matricula);
        reservas.removeCodigo(_codigo);
        cout << "Sala devolvida com sucesso" << endl;
    }
    if (_sala == 0){
        add(0, _armario);
        string _codigo = "Armário: " + to_string(_armario) + " emprestado para o usuário " + to_string(_matricula);
        reservas.removeCodigo(_codigo);
        cout << "Armário devolvido com sucesso" << endl;
    }
}

void Biblioteca::consultarReservas(){
    reservas.printReservas();
}
