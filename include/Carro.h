#ifndef Carro_H
#define Carro_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Cartas.h"

class Carro: public Cartas {
private:
	int cilindradas;
	int potencia;
	int velocidade;
	int peso;
	float comprimento;
	bool super_trunfo;
public:
	std::stack<Carro> stack_1c;
	std::stack<Carro> stack_2c;

	//GETS
	int get_cilindradas();
	int get_potencia();
	int get_velocidade();
	int get_peso();
	float get_comprimento();
	bool get_super_trunfo();

	void imprime_carta() override;

	void inverte_pilhaC(std::stack<Carro> *pilha);
	int compara_cartasC(Carro carta1, Carro carta2, std::string atributo);
	void jogada_playerC(std::stack<Carro> *pilha_jogador, std::stack<Carro> *pilha_adversario);
	bool valida_atributoC(std::string atributo);

	void cartas_carro();
	void embaralhar_cartasC();
    void inicializar_pilhas_c();
    void jogarc();

	//SETS
	void set_cilindradas(int cilindradas);
	void set_potencia(int potencia);
	void set_velocidade(int velocidade);
	void set_peso(int peso);
	void set_comprimento(float comprimento);
	void set_super_trunfo(bool super_trunfo);

};

#endif
