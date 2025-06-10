#ifndef Cartas_H
#define Cartas_H

#include <iostream>
#include <string>

class Cartas {
private:
	std::string nome;
	std::string tipo;
public:
	int player_atual = 1;

	//GETS
	std::string get_nome();
	std::string get_tipo();

	virtual void imprime_carta() = 0;

	bool valida_atributo(std::string atributo);

	//SETS
	void set_nome(std::string nome);
	void set_tipo(std::string tipo);
};

#endif
