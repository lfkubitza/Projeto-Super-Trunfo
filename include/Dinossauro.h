#ifndef Dinossauro_H
#define Dinossauro_H

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Cartas.h"

class Dinossauro: public Cartas {
private:
	float altura;
	float peso;
	float comprimento;
	int viveu_ha;
	bool super_trunfo;
public:
	std::stack<Dinossauro> stack_1d;
	std::stack<Dinossauro> stack_2d;

	//GETS
	float get_altura();
	float get_peso();
	float get_comprimento();
	int get_viveu_ha();
	bool get_super_trunfo();
	
	void imprime_carta() override;

	void inverte_pilhaD(std::stack<Dinossauro> *pilha);
	int compara_cartasD(Dinossauro carta1, Dinossauro carta2, std::string atributo);
	void jogada_playerD(std::stack<Dinossauro> *pilha_jogador, std::stack<Dinossauro> *pilha_adversario);
	bool valida_atributoD(std::string atributo);

	void cartas_dinossauro();
	void embaralhar_cartasD();
	void inicializar_pilhas_d();
	void jogard();

	//SETS
	void set_altura(float altura);
	void set_peso(float peso);
	void set_comprimento(float comprimento);
	void set_viveu_ha(int viveu_ha);
	void set_super_trunfo(bool super_trunfo);

};

#endif
