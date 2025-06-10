#include "Cartas.h"
#include <iostream>
#include <string>

std::string Cartas::get_nome(){
	return nome;
}
std::string Cartas::get_tipo(){
	return tipo;
}
void Cartas::set_nome(std::string nome){
	this-> nome = nome;
}
void Cartas::set_tipo(std::string tipo){
	this-> tipo = tipo;
}

bool Cartas::valida_atributo(std::string atributo) {
   if (atributo.compare("1") == 0)
        return true;
    else if (atributo.compare("2") == 0)
        return true;
    else if (atributo.compare("3") == 0)
        return true;
    else if (atributo.compare("4") == 0)
        return true;
    else if (atributo.compare("5") == 0)
        return true;
    else
        return false;
}
